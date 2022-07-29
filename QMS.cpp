#include <iostream>
#include "QMS.h"
#include <fstream>
using namespace std;

void QMS::passwordValidator(string pass) {
    bool passwordValid = false;
    
    //no need for continue statements, if first "if" is true, it will automatically skip the rest "else ifs"
    
    while (!passwordValid) {
        if (pass.length() < 8) {
            cout << "Password is too short" << endl; // pass is too short
            cout << "Enter pass again: ";
            cin >> pass;

            //find_first_of matches first character of string...if no match returns string::npos

        } else if (pass.find_first_of("0123456789") == string::npos) {
            cout << "Password must contain at least one number" << endl; // pass must contain at least one number
            cout << "Enter pass again: ";
            cin >> pass;

        } else if (pass.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos) {
            cout << "Password must contain at least one lowercase letter" << endl; // pass must contain at least one lowercase letter
            cout << "Enter pass again: ";
            cin >> pass;

        } else if (pass.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) {
            cout << "Password must contain at least one uppercase letter" << endl; // pass must contain at least one uppercase letter
            cout << "Enter pass again: ";
            cin >> pass;

        } else if (pass.find_first_of("!@#$%^&*()_+") == string::npos) {
            cout << "Password must contain at least one special character" << endl; // pass must contain at least one special character
            cout << "Enter pass again: ";
            cin >> pass;

        } else {
            cout << "Password is valid" << endl;
            passwordValid = true; //break loop if all conditions true
        }
    }
}

QMS::QMS(int loginID, string password) {
    this->loginID = loginID; // assign loginID
    this->password = password; // assign password
    fstream db = fstream("db.txt", ios::app); // open db.txt
    if (db.is_open()) {
        db << loginID << " " << password << endl; // write loginID and password to db.txt
    } else {
        cout << "Error opening file" << endl;
    }

}

int QMS::getLoginID() {
    return loginID; // return loginID
}

string QMS::getPassword() {
    return password; // return password
}


