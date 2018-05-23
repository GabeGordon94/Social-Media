#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H
#include "Message.h"
#include "Person.h"
#include <map>
#include <string>
//#define NULL 0

using namespace std;
class SocialNetwork
{
    public:
        SocialNetwork();
        void createPerson(string first,string last);
        void sendMessage(Message *message);
        void requestFriend(string initiatorFirst,string initiatorLast,string rFirst,string rLast);
        void acceptRequest(string first,string last);
        void block(string initiatorFirst,string initiatorLast,string rFirst,string rLast);
        void listFriends(string first,string last);
        void listPending(string first,string last);
        void listMessages(string first,string last);
        void listBlocked(string first,string last);
        void unfriend(string initiatorFirst,string initiatorLast,string rFirst,string rLast);
        void areFriends(string first1,string last1,string first2,string last2);
        friend ostream& operator<<(ostream& os,const SocialNetwork& n);
        virtual ~SocialNetwork();
    private:
        map<string,Person*> _peopleHashtable;
        string fName;
        string lName;
        //magic numbers handler
        const string ACCEPTEDMESSAGE=" has accepted a friend!";
        const string SPACER="-----------------";
        const string ISFRIENDS=" is friends with ";
        const string NOTFRIENDS=" is not friends with ";
        const string COMMA=",";
        //const string DONTEXIST="These people do not exist in the Social Network";


};

#endif // SOCIALNETWORK_H
