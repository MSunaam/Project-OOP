//
// Created by Muhammad Sunaam on 29/07/2022.
//

#ifndef UNTITLED_FOLDER_2_STUDENT_H
#define UNTITLED_FOLDER_2_STUDENT_H
#include <string>
#include "QMS.h"

class Student : public QMS {
private:
    string loginId, password;
    int marks;
public:
    Student(); //default constructor
    Student(string, string); // constructor
    void login() override; // function to login
    void checkMarks(); // function to check marks
    void takeQuiz(); // function to take quiz
    int getNumberFromString(string);
    void gradeExam(string s); // function to grade exam
};

#endif //UNTITLED_FOLDER_2_STUDENT_H
