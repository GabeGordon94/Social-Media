#include "Message.h"
#include "Person.h"

#include <string>
#include <iostream>

using namespace std;

Message::Message(string sendersFirstName,string sendersLastName,string recipientFirstName,string recipientLastName,string message){
    _sFirst=sendersFirstName;
    _sLast=sendersLastName;
    _rFirst=recipientFirstName;
    _rLast=recipientLastName;
    _text=message;
}
string Message::getSendersFirstName(){
    return _sFirst;
}
string Message::getSendersLastName(){
    return _sLast;
}
string Message::getRecipientsFirstName(){
    return _rFirst;
}
string Message::getRecipientsLastName(){
    return _rLast;
}
string Message::getMessage(){
    return _text;
}

Message::~Message()
{
    //dtor
}
