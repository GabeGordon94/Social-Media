#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "SocialNetwork.h"
#include "Message.h"

using namespace std;

class Driver
{
    public:
        Driver();
        void commander(string line);
        virtual ~Driver();
    private:
        //vector<string> use;
        SocialNetwork *facebook=new SocialNetwork();
        string command;
        string initiatorFirstName;
        string initiatorLastName;
        string rFirstName;
        string rLastName;
        string message;
        string str;
        int size;
        //These prevent magic numbers
        const string BADINPUT="^^improper input - line skipped";
        const string ADDPERSON="P";
        const string MESSAGE="M";
        const string REQUEST="F";
        const string ACCEPT="A";
        const string BLOCK="B";
        const string LISTFRIENDS="L";
        const string LISTPENDING="N";
        const string LISTMESSAGES="E";
        const string LISTBLOCKED="R";
        const string UNFRIEND="U";
        const string AREFRIENDS="Q";
        const string COMMA=",";
        string temp;
        const string NOTCOMMAND="^^This is not an acceptable command - line skipped";
        const string SPACER="-----------------";

};

#endif // DRIVER_H
