//
// Created by Muhammad Sunaam on 30/06/2022.
//

#ifndef PROJECT_1_QMS_H
#define PROJECT_1_QMS_H

#include <string>
using std::string;

class QMS{
private:
    int loginID; // login ID
    string password; // password
public:
    void passwordValidator(string pass); // validates pass 1 uppercase letter and 1 lowercase letter and 1 number and 1 special character and 8 characters long minimum.
    QMS(int loginID, string password); // constructor
    int getLoginID(); // get login ID
    string getPassword(); // get password

};

#endif //PROJECT_1_QMS_H
