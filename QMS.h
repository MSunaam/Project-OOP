//
// Created by Muhammad Sunaam on 29/07/2022.
//

#ifndef UNTITLED_FOLDER_2_QMS_H
#define UNTITLED_FOLDER_2_QMS_H
#include <string>
using namespace std;
class QMS{
private:
    string password, loginId;
public:
    QMS(); //default constructor
    QMS(string, string); // constructor
    virtual void login() = 0; // pure virtual function
    bool passwordValidator(string); // function to validate password

};

#endif //UNTITLED_FOLDER_2_QMS_H
