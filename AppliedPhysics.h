#include "Teacher.h"
#ifndef APPLIEDPHYSICS_H
#define APPLIEDPHYSICS_H

class AppliedPhysics : public Teacher {
	public:
		AppliedPhysics(int loginID, int password, int mins = 0, string pass = "ABCD");
		void writePass() const;
		void writeTimer() const;
		void addQues();
};

#endif
