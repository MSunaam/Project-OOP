//
// Created by Muhammad Sunaam on 04/07/2022.
//

#include "QMS.h"
#include "admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin(int loginId, string password) : QMS(loginId,password) {}

void Admin::checkResult() const {
    cout << "Enter Login ID of Student: " << endl;
    int loginID;
    cin >> loginID;
    fstream result; // file stream for results
    result.open("results.txt", ios::in);
    if (result.is_open()) {
        while (result.good()) {
            string line;
            getline(result, line);
            if (line.find(to_string(loginID)) != string::npos) { // if loginID is found in results.txt
                for (int i; i<3; i++) {
                    getline(result, line);
                    cout << line << endl;
                }                                              // print the results of the exam
            }
        }
    } else {
        cout << "Student not found" << endl;
    }
}

void Admin::checkExams() const {
    cout << "Which Subject Exam do you want to take?" << endl;
    int subject; //will be used to store the subject number
    cout << "1: Calculus 2" << endl;
    cout << "2: Applied Physics" << endl;
    cout << "3: Introduction to Management" << endl;
    cout << "4: Islamiat" << endl;
    cout << "5: Object Oriented Programming" << endl;
    cout << "6: Digital Logic Design" << endl;
    cin >> subject; //store the subject number
    while (subject > 7 || subject < 1) {
        cout << "Invalid subject number" << endl;
        cout << "Which Subject Exam do you want to take?" << endl;
        cout << "1: Calculus 2" << endl;
        cout << "2: Applied Physics" << endl;
        cout << "3: Introduction to Management" << endl;
        cout << "4: Islamiat" << endl;
        cout << "5: Object Oriented Programming" << endl;
        cout << "6: Digital Logic Design" << endl;
        cin >> subject;
    }
    string subjectName; //will be used to store the subject name
    fstream exam;
    if(subject == 1) {
        exam.open("Calculus 2.txt", ios::in);
        subjectName = "Calculus 2";
    } else if(subject == 2) {
        exam.open("Applied Physics.txt", ios::in);
        subjectName = "Applied Physics";
    } else if(subject == 3) {
        exam.open("Introduction to Management.txt", ios::in);
        subjectName = "Introduction to Management";
    } else if(subject == 4) {
        exam.open("Islamiat.txt", ios::in);
        subjectName = "Islamiat";
    } else if(subject == 5) {
        exam.open("Object Oriented Programming.txt", ios::in);
        subjectName = "Object Oriented Programming";
    } else if(subject == 6) {
        exam.open("Digital Logic Design.txt", ios::in);
        subjectName = "Digital Logic Design";
    } else {
        cout << "Invalid subject number" << endl;
    }

    if(!exam){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    string line;
    while(getline(exam, line)) {
        cout << line << endl;
    }
}

void Admin::checkLoginDetails(int loginId) const {
    fstream loginDetails; // file stream for login details
    loginDetails.open("db.txt", ios::in);
    if (loginDetails.is_open()) {
        while (loginDetails.good()) {
            string line;
            getline(loginDetails, line);
            if (line.find(to_string(loginId)) != string::npos) { // if loginId is found in db.txt
                for (int i; i<3; i++) {
                    getline(loginDetails, line);
                    cout << line << endl; //login Id
                    getline(loginDetails, line);
                    cout << line << endl; //password
                }                                              // print the login details
            }
        }
    } else {
        cout << "Student not found" << endl;
    }
}




