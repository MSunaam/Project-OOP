//
// Created by Muhammad Sunaam on 30/06/2022.
//

#ifndef PROJECT_1_STUDENT_H
#define PROJECT_1_STUDENT_H
#include "QMS.h"
#include <fstream>
#include <vector>
using namespace std;

class Student: public QMS {
private:
    fstream results; // file stream for results
    int marks; // marks of the exam
public:
    Student(int loginID, string password); // constructor
    void checkResult() const; // check result
    void takeExam(); // take exam
    void gradeExam(string subjectName,int marks); // grade exam
    int getNumberFromString(string s); // get number from string

};

#endif //PROJECT_1_STUDENT_H
