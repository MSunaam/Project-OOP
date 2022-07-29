//
// Created by Muhammad Sunaam on 29/07/2022.
//

#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>

Student::Student() {
    loginId = "";
    password = "";
    marks = 0;
}

Student::Student(string loginId, string password) : QMS(loginId, password) {
    this->loginId = loginId;
    this->password = password;
    ofstream outflie;
    outflie.open("/Users/muhammadsunaam/Desktop/Project-OOP/Student/studentLogin.txt", ios::app);
    outflie << loginId << endl;
    outflie << password << endl;
    outflie.close();
}

void Student::login() {
    ifstream loginFile;
    loginFile.open("/Users/muhammadsunaam/Desktop/Project-OOP/Student/studentLogin.txt");
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
                this->loginId = loginId;
                loginFile >> line;
                if (line.find(password) != string::npos) { //if password is found in file
                    cout << "Login successful" << endl; //login successful
                    this->password = password;
                    marks = 0;
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

void Student::checkMarks() {
    ifstream marksFile;
    marksFile.open("/Users/muhammadsunaam/Desktop/Project-OOP/Student/"+loginId+"student.txt");
    string line;
    while(getline(marksFile, line)) {
        cout << line << endl;
    }
    marksFile.close();
}

void Student::takeQuiz() {
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
    ifstream exam;
    if (subject == 1) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/Calc.txt", ios::in);
        subjectName = "Calculus 2";
    }
    else if (subject == 2) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/AP.txt", ios::in);
        subjectName = "Applied Physics";
    }
    else if (subject == 3) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/IMT.txt", ios::in);
        subjectName = "Introduction to Management";
    }
    else if (subject == 4) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/islamiat.txt", ios::in);
        subjectName = "Islamiat";
    }
    else if (subject == 5) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/OOP.txt", ios::in);
        subjectName = "Object Oriented Programming";
    }
    else if (subject == 6) {
        exam.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Quiz/DLD.txt", ios::in);
        subjectName = "Digital Logic Design";
    }
    else {
        cout << "Invalid subject number" << endl;
    }

    if (!exam) {
        cerr << "Error opening file" << endl;
        exit(1);
    }
    marks = 0; //initialize marks to 0
    //get password

    string password;
    getline(exam, password);
    cout << "Enter password: " << endl;
    string userPassword;
    cin >> userPassword;
    int temp = 0;
    while (temp < 3) {
        if (userPassword == password) {
            cout << "Password correct" << endl;
            break;
        }
        else {
            cout << "Password incorrect " << temp + 1 << " tries remaining" << endl;
            temp++;
            cout << "Enter password: " << endl;
            cin >> userPassword;
        }
    }
    if (temp == 3) {
        cout << "3 incorrect tries" << endl;
        exit(1);
    }

    int timeAllowed;
    int numberOfQuestions;
    int totalMarks;
    string line;
    getline(exam, line);
    timeAllowed = getNumberFromString(line); //get the time allowed from the second line
    getline(exam, line);
    numberOfQuestions = getNumberFromString(line); //get the number of questions from the first line
    getline(exam, line);
    totalMarks = getNumberFromString(line); //get the total marks from the third line
    cout << "Time allowed: " << timeAllowed << endl;
    cout << "Number of questions: " << numberOfQuestions << endl;
    cout << "Total marks: " << totalMarks << endl;

    //setting time check

    time_t startTime = time(0); //get the current time
    time_t currentTime = time(0); //get the current time

    int questionAttempted = 0;

    while ((currentTime - startTime < timeAllowed) and (questionAttempted < numberOfQuestions)) {

        currentTime = time(0); //get the current time

        for (int i = 0; i < numberOfQuestions; i++) {
            cout << "Question " << i + 1 << ": " << endl;
            getline(exam, line);
            cout << line << endl;
            cout << "a) ";
            getline(exam, line);
            cout << line << endl;
            cout << "b) ";
            getline(exam, line);
            cout << line << endl;
            cout << "c) ";
            getline(exam, line);
            cout << line << endl;
            cout << "d) ";
            getline(exam, line);
            cout << line << endl;
            char correct_answer;
            exam.get(correct_answer); //get the correct answer from the file
            cout << "Enter Answer: ";
            char user_answer;
            cin >> user_answer;
            while ((int(user_answer) < 97 || int(user_answer) > 97 + 4) && (int(user_answer) < 65 || int(user_answer) > 65 + 4)) {
                cout << "Invalid answer" << endl;
                cout << "Enter Answer: ";
                cin >> user_answer;
            }
            if (user_answer == correct_answer) {
                cout << "Correct!" << endl;
                questionAttempted++;
                marks++;
            }
            else {
                cout << "Wrong!" << endl;
                questionAttempted++;
            }
        }

    }

    if (currentTime - startTime >= timeAllowed) {
        cout << "Time up!" << endl;
    }
    cout << "Exam Ended" << endl;
    exam.close();

    gradeExam(subjectName);


}

int Student::getNumberFromString(string s) {
        stringstream str_strm;
        str_strm << s; //convert the string s into stringstream
        string temp_str;
        int temp_int;
        while (!str_strm.eof()) {
            str_strm >> temp_str; //take words into temp_str one by one
            if (stringstream(temp_str) >> temp_int) { //try to convert string to int
                return temp_int; //return the int
            }
            temp_str = ""; //clear temp string
        }
    }

void Student::gradeExam(string s) {
    ofstream results;
    results.open("/Users/muhammadsunaam/Desktop/PROJECT/untitled folder 2/Student/"+loginId+"student.txt", ios::app);
    results << "Login ID: " << loginId << endl;
    results << "Subject: " << s << endl;
    results << "Marks: " << marks << endl;
    results.close();
}

