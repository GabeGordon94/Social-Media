#include "Driver.h"
#include "SocialNetwork.h"
#include "Message.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <locale>

using namespace std;

/**Gabriel Gordon
This Driver takes in a line from the read in file
It parses that line by the comma and adds it to a vector
The first element in the line/vector should be the command
It then allocates the command to the corresponding function in the socialNetwork class
*/

Driver::Driver(){
    //**DO YOU NEED??**
}
/**
void Driver::commander(string command, string initiatorFirstName, string initiatorLastName){

}
*/

void Driver::commander(string line){
    vector<string> use;//holds the line parsed by commas

    stringstream data(line);

    //splits line into vector
    while(getline(data,str,',')){
        use.push_back(str);
    }

    //ensures command is uppercase
    locale loc;
    for(int i=0;i<use[0].length();i++){
        use[0]=toupper(use[0][i],loc);
    }
    //for any command that only requires command and one first/last name
    if(use.size()==3){
        command=use[0];
        initiatorFirstName=use[1];
        initiatorLastName=use[2];
    }
    //for any command that requires command and two first/last names
    else if(use.size()==5){
        command=use[0];
        initiatorFirstName=use[1];
        initiatorLastName=use[2];
        rFirstName=use[3];
        rLastName=use[4];

    //for messages
    }else if(use.size()==6){
        command=use[0];
        initiatorFirstName=use[1];
        initiatorLastName=use[2];
        rFirstName=use[3];
        rLastName=use[4];
        message=use[5];

    //handles bad input
    }else{
        cout<<line<<endl;
        cout<<BADINPUT<<endl;
        cout<<SPACER<<endl;
    }

    if(command==ADDPERSON){
        //add person to social network
        facebook->createPerson(initiatorFirstName,initiatorLastName);
    }
    else if(command==MESSAGE){
        //send message
        Message *nMessage=new Message(initiatorFirstName,initiatorLastName,rFirstName,rLastName,message);
        facebook->sendMessage(nMessage);
    }
    else if(command==REQUEST){
        facebook->requestFriend(initiatorFirstName,initiatorLastName,rFirstName,rLastName);
    }
    else if(command==ACCEPT){
        //accept next friend request on queue
        facebook->acceptRequest(initiatorFirstName,initiatorLastName);
    }
    else if (command==BLOCK){
        //block person
        facebook->block(initiatorFirstName,initiatorLastName,rFirstName,rLastName);
    }
    else if(command==LISTFRIENDS){
        //prints list of friends
        facebook->listFriends(initiatorFirstName,initiatorLastName);
    }
    else if(command==LISTPENDING){
        //prints pending friend requests
        facebook->listPending(initiatorFirstName,initiatorLastName);
    }
    else if(command==LISTMESSAGES){
        //prints messsage list
        facebook->listMessages(initiatorFirstName,initiatorLastName);
    }
    else if(command==LISTBLOCKED){
        //prints list of blocked people
        facebook->listBlocked(initiatorFirstName,initiatorLastName);
    }
    else if(command==UNFRIEND){
        //unfriends recipient from initiator
        facebook->unfriend(initiatorFirstName,initiatorLastName,rFirstName,rLastName);
    }
    else if(command==AREFRIENDS){
        //checks if they are friends
        facebook->areFriends(initiatorFirstName,initiatorLastName,rFirstName,rLastName);

    //handles improper command
    }else{
        cout<<line<<endl;
        cout<<NOTCOMMAND<<endl;
        cout<<SPACER<<endl;
    }
}




Driver::~Driver()
{
    //dtor
}
