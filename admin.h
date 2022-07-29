//
// Created by Muhammad Sunaam on 29/07/2022.
//

#ifndef UNTITLED_FOLDER_2_ADMIN_H
#define UNTITLED_FOLDER_2_ADMIN_H
#include "QMS.h"
#include <string>
using namespace std;

class Admin : public QMS {
private:
    string password, loginId;
public:
    Admin(); //default constructor
    Admin(string, string); // constructor
    void login() override; // function to login
    void createAccount(); // function to create account
    void checkMarks(); // function to check marks
};

#endif //UNTITLED_FOLDER_2_ADMIN_H
