#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <string>
#include <fstream>
#include "QMS.h"

using namespace std;

class Teacher : public QMS {
	public:
		Teacher(int loginID, int password, int mins = 0, string pass = "ABCD");
		string getPass() const;
		int getTimer() const;
		virtual void writePass() const = 0;
		virtual void writeTimer() const = 0;
		virtual void addQues() = 0;
	private:
		string pass;
		int mins;
};

#endif
