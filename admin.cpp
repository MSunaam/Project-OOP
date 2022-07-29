//
// Created by Muhammad Sunaam on 29/07/2022.
//
#include "admin.h"
#include <iostream>
#include <fstream>
using namespace std;


Admin::Admin(string id, string pass) : QMS(id, pass) {
    password = pass;
    loginId = id;
    ofstream outfile;
    outfile.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/loginAdmin.txt", ios::app);
    outfile << loginId << endl;
    outfile << password << endl;
    outfile.close();
}

Admin::Admin() {
    //empty because admin account/object cannot be created this way
}

void Admin::login() {
    ifstream loginFile;
    loginFile.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/loginAdmin.txt");
    //checking to see if new login id is in file
    cout << "Please enter login Id: ";
    cin >> loginId;
    cout << "Please enter password: ";
    cin >> password;
    string line;
    bool loginSuccessful = false;
    if (loginFile.is_open()){
        while(getline(loginFile, line)) { //while there is a line in the file
            if (line.find(loginId) != string::npos) { //if login id is found in file
                loginFile >> line;
                if (line.find(password) != string::npos) { //if password is found in file
                    cout << "Login successful" << endl; //login successful
                    loginSuccessful = true;
                }
                else {
                    cout << "Password incorrect" << endl; //password incorrect
                    cin.clear(); cin.ignore(254,'\n');
                    login();
                }
            }
        }
        if (!loginSuccessful) {
            cout << "Login Id not found" << endl; //login id not found
            cin.clear(); cin.ignore(254,'\n');
            login();
        }
        loginFile.close(); //close file
    }
    else {
        cerr << "File not found" << endl; //file not found
        return; //exit function
    }
}

void Admin::createAccount() {
    ofstream loginFile; //login file
    loginFile.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/login.txt", ios::app); //opening login file in append mode
    if(loginFile.is_open()) {
        cout << "Please enter login Id: "; //prompting user to enter login id
        cin >> loginId; //getting login id from user
        cout << "\nPlease enter password: "; //prompting user to enter password
        cin >> password;
        passwordValidator(password); //validate password
        loginFile << loginId << endl << password << endl;
        cout << "Account created" << endl;
        loginFile.close(); //closing login file
    } else {
        cerr << "File not found" << endl; //file not found
    }
}

void Admin::checkMarks() {
    cout << "Please enter login Id: "; //prompting user to enter login id
    cin >> loginId; //getting login id from user
    ifstream marks;
    marks.open(loginId+".txt"); //opening marks file
    if (marks.is_open()) {
        string line;
        while(getline(marks, line)) { //while there is a line in the file
            cout << line << endl; //printing line
        }
        marks.close(); //closing marks file
    } else {
        cerr << "File not found" << endl; //file not found
    }
}


