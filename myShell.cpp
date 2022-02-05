/* 
Name: Chaney Chantipaporn
Class: CPSC - 351
Assigment: Programming Assignment 1

Commnands to support:
dir
help
bol
path
tasklist
notepad
echo (mi)
color (mi)
ping  (mi)
*/

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <vector> 
#include <sstream> 
#include <thread>
using namespace std;


string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

void threadEx(char* s) {
    cout << "Executing thread..." << endl;
    system(s);
}

int main ()
{
    char userInput[100];
    string myStr;  
    vector<string> supportedCommands = {"dir\n","help\n", "vol\n", "path\n", "tasklist\n", "notepad\n", "echo", "color", "ping"};
    cout << "Welcome to myShell\n\n";
    while(1) {
        cout << "==>";
        fgets(userInput, 100, stdin);
        int str_size = sizeof(userInput) / sizeof(char);
        myStr = convertToString(userInput, str_size);
        if(!strcmp(userInput, "exit\n") || !strcmp(userInput, "Exit\n")) {
            cout << "Thanks for using myShell!" << endl;
            return 0;
        } 
        for (string i: supportedCommands) {
            // Will execute the command if its in the supported list
            if (myStr.find(i) != string::npos) {
                system(userInput);
                break;
            }
            //If the loop is at ping and ping is not a substr, then the command dne or is not supported
            else if (i == "ping" && !(myStr.find("ping") != string::npos)){
                cout << "Command not supported, creating thread..." << endl;
                thread first(threadEx, userInput);
                first.join();
                break;
            }
        }
    }
    return 0;
}