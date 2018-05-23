#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include "Person.h"


using namespace std;
class Person;
class Message
{
    public:
        Message(string sendersFirstName,string sendersLastName,string recipientFirstName,string recipientLastName,string message);
        string getSendersFirstName();
        string getSendersLastName();
        string getRecipientsFirstName();
        string getRecipientsLastName();
        string getMessage();
        virtual ~Message();
    private:
        string _rFirst;
        string _rLast;
        string _sFirst;
        string _sLast;
        string _text;

};

#endif // MESSAGE_H
