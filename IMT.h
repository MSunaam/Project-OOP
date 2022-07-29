#pragma once
#include "Teacher.h"
using namespace std;
class IMT : public Teacher
{
public:
	IMT(int loginID, int password, int mins = 0, string pass = "ABCD");
	void writepass() const;
	void writeTimer() const;
	void addques();
};

