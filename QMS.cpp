//
// Created by Muhammad Sunaam on 29/07/2022.
//

#include "QMS.h"
#include <iostream>
using namespace std;


QMS::QMS() {
    password = "";
    loginId = "";
}

QMS::QMS(string loginId, string password) {
    password = password;
    loginId = loginId;
}

bool QMS::passwordValidator(string pass) {

    //no need for continue statements, if first "if" is true, it will automatically skip the rest "else ifs"

    while (true) {
        if (pass.length() < 8) {
            cout << "Password is too short" << endl; // pass is too short
            cout << "Enter pass again: ";
            cin >> pass;

            //find_first_of matches first character of string...if no match returns string::npos

        }
        else if (pass.find_first_of("0123456789") == string::npos) {
            cout << "Password must contain at least one number" << endl; // pass must contain at least one number
            cout << "Enter pass again: ";
            cin >> pass;

        }
        else if (pass.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos) {
            cout << "Password must contain at least one lowercase letter" << endl; // pass must contain at least one lowercase letter
            cout << "Enter pass again: ";
            cin >> pass;

        }
        else if (pass.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            cout << "Password must contain at least one uppercase letter" << endl; // pass must contain at least one uppercase letter
            cout << "Enter pass again: ";
            cin >> pass;

        }
        else if (pass.find_first_of("!@#$%^&*()_+") == string::npos) {
            cout << "Password must contain at least one special character" << endl; // pass must contain at least one special character
            cout << "Enter pass again: ";
            cin >> pass;

        }
        else {
            cout << "Password meets all Conditions" << endl; // pass meets all prerequisites
            return true;
        }
    }
}

