#include "SocialNetwork.h"
#include "Message.h"
#include <map>
#include <string>
#define NULL 0

/**Gabriel Gordon
The Social Network Class holds all the Person Objects in the hashtable
This is the userface essentially
It receives the command function from the Driver
Then it calls the appropriate Person Object if they exist
*/

using namespace std;
SocialNetwork::SocialNetwork()
{
    //create hash table that holds people
    //***check if need since it's in header****
    //map<string,Person*> _peopleHashtable;
}
void SocialNetwork::createPerson(string first,string last){
    //create person
    //add person to hashtable
    Person *newPerson=new Person(first,last);
    _peopleHashtable.insert(make_pair(first+last,newPerson));

}

void SocialNetwork::sendMessage(Message *message){
    //parameter is message object
    //send message
    fName=message->getRecipientsFirstName();
    lName=message->getRecipientsLastName();
    if((_peopleHashtable[fName+lName]!=NULL)&&(_peopleHashtable[message->getSendersFirstName()+message->getSendersLastName()]!=NULL)){
        _peopleHashtable[fName+lName]->Messenging(message);
    }else{}
}

void SocialNetwork::requestFriend(string initiatorFirst,string initiatorLast,string rFirst,string rLast){
    //if person exists in social network
    //add to friend request queue
    if((_peopleHashtable[initiatorFirst+initiatorLast]!=NULL)&&(_peopleHashtable[rFirst+rLast]!=NULL)){
        _peopleHashtable[rFirst+rLast]->addFriendrequest(_peopleHashtable[initiatorFirst+initiatorLast]);
    }else{}
}

void SocialNetwork::acceptRequest(string first,string last){
    if(_peopleHashtable[first+last]!=NULL){
        if(_peopleHashtable[first+last]->AcceptFriend()){
            cout<<_peopleHashtable[first+last]->getName()+ACCEPTEDMESSAGE<<endl;
        }else{}
    cout<<SPACER<<endl;
    }else{}
    //accept persons next friend request
}
void SocialNetwork::block(string initiatorFirst,string initiatorLast,string rFirst,string rLast){
    //add recipient to initiators block list
    if((_peopleHashtable[initiatorFirst+initiatorLast]!=NULL)&&(_peopleHashtable[rFirst+rLast]!=NULL)){
        _peopleHashtable[rFirst+rLast]->Blocking(_peopleHashtable[initiatorFirst+initiatorLast]);
    }else{}
}
void SocialNetwork::listFriends(string first,string last){
    //prints persons friend list
    //Person use=new Person(first,last);
    if(_peopleHashtable[first+last]!=NULL){
        _peopleHashtable[first+last]->printFriends();
    }else{}
}
void SocialNetwork::listPending(string first,string last){
    //prints persons friend request list
    //Person use=new Person(first,last);
    if(_peopleHashtable[first+last]!=NULL){
        _peopleHashtable[first+last]->printPending();
    }else{}
}
void SocialNetwork::listMessages(string first,string last){
    //prints persons message list
    //Person use=new Person(first,last);
    if(_peopleHashtable[first+last]!=NULL){
        _peopleHashtable[first+last]->printMessages();
    }else{}
}
void SocialNetwork::listBlocked(string first,string last){
    //prints blocked list
    //Person use=new Person(first,last);
    if(_peopleHashtable[first+last]!=NULL){
        _peopleHashtable[first+last]->printBlocked();
    }else{}
}
void SocialNetwork::unfriend(string initiatorFirst,string initiatorLast,string rFirst,string rLast){
    //removes recipient from initiators friend list
    if((_peopleHashtable[initiatorFirst+initiatorLast]!=NULL)&&(_peopleHashtable[rFirst+rLast]!=NULL)){
        _peopleHashtable[rFirst+rLast]->Unfriending(_peopleHashtable[initiatorFirst+initiatorLast]);
    }else{}
}
void SocialNetwork::areFriends(string first1,string last1,string first2,string last2){
    //prints first1/last1 are/are not friends
    //checks list of friends

    if((_peopleHashtable[first1+last1]!=NULL)&&(_peopleHashtable[first2+last2]!=NULL)){
        if(_peopleHashtable[first2+last2]->isFriends(_peopleHashtable[first1+last1])){
            //if true then friends/else not friends
            //Friends!
            cout<<_peopleHashtable[first1+last1]->getName()<<ISFRIENDS<<_peopleHashtable[first2+last2]->getName()<<endl;
            cout<<SPACER<<endl;
        }else{
            //Not friends
            cout<<_peopleHashtable[first1+last1]->getName()<<NOTFRIENDS<<_peopleHashtable[first2+last2]->getName()<<endl;
            cout<<SPACER<<endl;
        }
    }else{}
}
//friend operator - overrides operators
ostream& operator<<(ostream& os,const SocialNetwork& n){
    os<<"\nSocial Network: "<<endl;
    map<string,Person*>::const_iterator x;
    map<string,Person*> checker=n._peopleHashtable;
    for(x=n._peopleHashtable.begin();x!=n._peopleHashtable.end();x++){
        string c=x->first;
        if(checker[c]!=NULL){
            os<<*x->second<<endl;
        }
    }
}


SocialNetwork::~SocialNetwork()
{
    //de-constructor
}
