#ifndef PERSON_H
#define PERSON_H

#include "Message.h"
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
class Message;
class Person
{
    public:
        Person(string firstName,string lastName);
        void addFriendrequest(Person *request);
        bool AcceptFriend();
        void Blocking(Person *loser);
        void Unfriending(Person *byebye);
        void Messenging(Message *m);
        void Output();
        void printFriends();
        void printPending();
        void printMessages();
        void printBlocked();
        string getName();
        bool isFriends(Person *isHe);
        bool isBlocked(Person *p);
        friend ostream& operator<<(ostream& os,const Person& p);
        virtual ~Person();
    private:
        string _firstName;
        string _lastName;
        queue<Person*> _friendRequestList;
        vector <Person*> _friendsList;
        vector <Person*> _blockedList;
        vector<Message*> _messages;
        int position;
        bool isFriend;
        //These prevent any magic Numbers
        const string NEVERFRIEND=" was not found on the friends List of ";
        const string NOLONGERFRIENDS=" is no longer friends with ";
        const string FRIENDLIST="Friends List: ";
        const string PENDINGLIST="Pending Friends Queue: ";
        const string MESSAGELIST="Messages are: ";
        const string BLOCKEDLIST="Blocked List: ";
        const string BLOCKEDMESSAGE=" is blocked by ";
        const string SPACER="-----------------";

};

#endif // PERSON_H
