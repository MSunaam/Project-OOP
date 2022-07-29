#include "Teacher.h"
#ifndef OOP_H
#define OOP_H

class OOP : public Teacher {
	public:
		OOP(int loginID, int password, int mins = 0, string pass = "ABCD");
		void writePass() const;
		void writeTimer() const;
		void addQues();
};

#endif

