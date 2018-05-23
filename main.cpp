#include <iostream>
#include <fstream>
#include "Driver.h"

using namespace std;
//Driver
int main(){
    Driver *drive=new Driver();
    bool isValid=false;
    string tFile;
    string token;
    while(!isValid){
        cout<<"Enter your Test File: ";
        cin>>tFile;
        cout<<endl;
        //input users file to check
        ifstream testFile(tFile.c_str());
        if(!testFile){
            cout<<tFile<<" is not a readable file."<<endl;
        }else{
            //adds whole line to token
            while(getline(testFile,token)){
                //checks if the line is empty - do nothing
                //handles empty lines and empty files
                if(token==""){

                }
                else{
                    drive->commander(token);
                }
            }
            isValid=true;
        }


                    // Bringing file pointer back to top, clearing flags.
        testFile.clear();
        testFile.seekg(0, ios::beg);

    }



    return 0;
}
