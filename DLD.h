#include "Teacher.h"
#ifndef DLD_H
#define DLD_H

class DLD : public Teacher {
	public:
		DLD(int loginID, int password, int mins = 0, string pass = "ABCD");
		void writePass() const;
		void writeTimer() const;
		void addQues();
};

#endif

