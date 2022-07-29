#include "Teacher.h"
#ifndef CALCULUS2_H
#define CALUCLUS2_H

class Calculus2 : public Teacher {
	public:
		Calculus2(int loginID, int password, int mins = 0, string pass = "ABCD");
		void writePass() const;
		void writeTimer() const;
		void addQues();
};

#endif

