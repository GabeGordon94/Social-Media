#include "Person.h"
#include "Message.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

/**Gabriel Gordon
This is the Person Object
It holds all the member data private to the Person
The functions are called by the social Network class and some are returned
IMPORTANT: All functions are already checked that Person exists in SocialNetwork
*/

using namespace std;

Person::Person(string firstName,string lastName)
{
    _firstName=firstName;
    _lastName=lastName;
    //create friend request list of Persons
    //queue<Person*> _friendRequestList;
    //create friends list of Persons
    //vector <Person*> _friendsList;
    //create block list of Persons
    //vector <Person*> _blockedList;
    //create message map of Persons
   // vector<Message*> _messages;
}
void Person::addFriendrequest(Person *request){
    //already checked if they exist in social network
    //this is checking that they're not blocked and not friends yet
    if((!isBlocked(request))&&(!isFriends(request))){
        _friendRequestList.push(request);
    }
}

bool Person::AcceptFriend(){
    //add friend from friend request to friends list
    //check if friend is in blocked list
    if((!isBlocked(_friendRequestList.front()))&&(!isFriends(_friendRequestList.front()))){
        //not blocked - add to friends list
        _friendsList.push_back(_friendRequestList.front());
        _friendRequestList.pop();
        return true;
    }else{
        //blocked so dont add to friends list
        //get rid of request
        _friendRequestList.pop();
        return false;
    }
    //send message to requestor
    //deny friend request - no message
}
void Person::Blocking(Person *loser){
    //if they are a friend - unfriend them and block them
    //if not friend then just block
    if(isFriends(loser)){
        _blockedList.push_back(loser);
        Unfriending(loser);
    }else{
        _blockedList.push_back(loser);
    }
}

void Person::Unfriending(Person *byeBye){
    //take Person off friends list
    isFriend=true;
    for(int i=0;i<_friendsList.size();i++){
        if((_friendsList[i]->getName())==byeBye->getName()){
            position=i;
            isFriend=false;//no longer your friend
        }
    }
    if(isFriend){
        cout<<byeBye->getName()+NEVERFRIEND+_firstName+" "+_lastName<<endl;
    }else{
        _friendsList.erase(_friendsList.begin()+position);
        cout<<_firstName+" "+_lastName+NOLONGERFRIENDS+byeBye->getName()<<endl;
    }
    cout<<SPACER<<endl;
}
//***NEEDS WORK***
void Person::Messenging(Message *m){

    //if person is not in blocked list*****
    _messages.push_back(m);
    //else dont add
}
void Person::Output(){
    //Person can print itself and individual lists
    cout<<_firstName<<" "<<_lastName<<endl<<endl;
    printPending();
    printFriends();
    printMessages();
    printBlocked();
}
void Person::printFriends(){
    //print out individual friends list
    cout<<_firstName+" "+_lastName+" "+FRIENDLIST<<endl;
    for(int i=0;i<_friendsList.size();i++){
        cout<<_friendsList[i]->getName()<<endl;
    }
    cout<<SPACER<<endl;
}
void Person::printPending(){
    //print out pending friends stack
    cout<<_firstName+" "+_lastName+" "+PENDINGLIST<<endl;
    for(int i=0;i<_friendRequestList.size();i++){
        cout<<_friendRequestList.front()->getName()<<endl;
        _friendRequestList.pop();
    }
    cout<<SPACER<<endl;
}
void Person::printMessages(){
    //print out message map
    cout<<_firstName+" "+_lastName+" "+MESSAGELIST<<endl;
    for(int i=0;i<_messages.size();i++){
        cout<<_messages[i]->getMessage()<<endl;
    }
    cout<<SPACER<<endl;
}
void Person::printBlocked(){
    //print blocked list
    cout<<_firstName+" "+_lastName+" "+BLOCKEDLIST<<endl;
    for(int i=0;i<_blockedList.size();i++){
        cout<<_blockedList[i]->getName()<<endl;
    }
    cout<<SPACER<<endl;
}
string Person::getName(){
    //returns name with a space
    return _firstName+" "+_lastName;
}

bool Person::isFriends(Person *isHe){
     if(std::find(_friendsList.begin(),_friendsList.end(),isHe)!=_friendsList.end()){
        //found in blocked list
        return true;
    }else{
        return false;
    }

}

bool Person::isBlocked(Person *p){
    if(std::find(_blockedList.begin(),_blockedList.end(),p)!=_blockedList.end()){
        //found in blocked list
        cout<<p->getName()+BLOCKEDMESSAGE+getName()<<endl;
        cout<<SPACER<<endl;
        return true;
    }else{
        return false;
    }
}
ostream& operator<<(ostream& os,const Person& p){
    os<<p._firstName+" "+p._lastName<<endl;
    os<<p.FRIENDLIST<<endl;
    if(p._friendsList.size()!=0){
        for(int i=0;i<p._friendsList.size();i++){
            os<<p._friendsList[i]->getName()<<endl;
        }
        os<<p.SPACER<<endl;
    }

    os<<p.PENDINGLIST<<endl;
    queue<Person*> pending=p._friendRequestList;
    if(pending.size()!=0){
        while(!pending.empty()){
            os<<pending.front()->getName()<<endl;
            pending.pop();
        }
        os<<p.SPACER<<endl;
    }
    os<<p.MESSAGELIST<<endl;
    if(p._messages.size()!=0){
        for(int i=0;i<p._messages.size();i++){
            os<<p._messages[i]->getMessage()<<endl;
        }
        os<<p.SPACER<<endl;
    }

    os<<p.BLOCKEDLIST<<endl;
    if(p._blockedList.size()!=0){
        for(int i=0;i<p._blockedList.size();i++){
            os<<p._blockedList[i]->getName()<<endl;
    }
    os<<p.SPACER<<endl;

    }

}


Person::~Person()
{
    //dtor
}
