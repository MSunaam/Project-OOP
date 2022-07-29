//
// Created by Muhammad Sunaam on 30/06/2022.
//

#include "Student.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;


Student::Student(int loginID, string password) : QMS(loginID, password) {}

void Student::gradeExam(string name, int marks) {
    results.open("results.txt", ios::app);
    results << "Login ID: " << this->getLoginID() << endl;
    results << "Subject Name: " << name << endl;
    results << "Marks: " << marks << endl;
    results.close();
}

void Student::takeExam() {

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
    marks = 0; //initialize marks to 0
    //get password

    string password;
    getline(exam,password);
    cout << "Enter password: " << endl;
    string userPassword;
    cin >> userPassword;
    int temp = 0;
    while (temp < 3) {
        if (userPassword == password) {
            cout << "Password correct" << endl;
            break;
        } else {
            cout << "Password incorrect " << temp+1 << "tries remaining" << endl;
            temp++;
            cout << "Enter password: " << endl;
            cin >> userPassword;
        }
    }
    if(temp == 3) {
        cout << "3 incorrect tries" << endl;
        exit(1);
    }

    int timeAllowed;
    int numberOfQuestions;
    string line;
    getline(exam,line);
    numberOfQuestions = getNumberFromString(line); //get the number of questions from the first line
    getline(exam,line);
    timeAllowed = getNumberFromString(line); //get the time allowed from the second line

    //setting time check

    time_t startTime = time(0); //get the current time
    time_t currentTime = time(0); //get the current time

    while(currentTime - startTime < timeAllowed) {

    currentTime = time(0); //get the current time

        for (int i; i < numberOfQuestions; i++) {
            cout << "Question " << i+1 << ": " << endl;
            getline(exam,line);
            cout << line << endl;
            cout << "a) ";
            getline(exam,line);
            cout << line << endl;
            cout << "b) ";
            getline(exam,line);
            cout << line << endl;
            cout << "c) ";
            getline(exam,line);
            cout << line << endl;
            cout << "d) ";
            getline(exam,line);
            cout << line << endl;
            char correct_answer;
            exam.get(correct_answer); //get the correct answer from the file
            cout << "Enter Answer: ";
            char user_answer;
            cin >> user_answer;
            while((int(user_answer) < 97 || int(user_answer) > 97+4) && (int(user_answer) < 65 || int(user_answer) > 65+4)) {
                cout << "Invalid answer" << endl;
                cout << "Enter Answer: ";
                cin >> user_answer;
            }
            if(user_answer == correct_answer) {
                cout << "Correct!" << endl;
                marks++;
            } else {
                cout << "Wrong!" << endl;
            }
        }

    }

    if(currentTime - startTime >= timeAllowed) {
        cout << "Time up!" << endl;
    }
    exam.close();

    gradeExam(subjectName, marks);

}

int Student::getNumberFromString(string s) {
    stringstream str_strm;
    str_strm << s; //convert the string s into stringstream
    string temp_str;
    int temp_int;
    while(!str_strm.eof()) {
        str_strm >> temp_str; //take words into temp_str one by one
        if(stringstream(temp_str) >> temp_int) { //try to convert string to int
            return temp_int; //return the int
        }
        temp_str = ""; //clear temp string
    }
}

void Student::checkResult() const {
    fstream temp = fstream("results.txt", ios::in);
    if(!temp) {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    string line;
    while(getline(temp,line)) {
        cout << line << endl;
    }
}



