#pragma once
#include "Teacher.h"
using namespace std;
class Islamiat : public Teacher
{
public:
	Islamiat(int loginID, int password, int mins = 0, string pass = "ABCD");
	void writepass() const;
	void writeTimer() const;
	void addques();
};
