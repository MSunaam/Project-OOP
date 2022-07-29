#include "Teacher.h"

Teacher::Teacher(int loginID, int password, int mins = 0, string pass = "ABCD")
	:QMS(loginID, password), pass{ pass }, mins{ mins } {}
string Teacher::getPass() const {
	return pass;
}
int Teacher::getTimer() const {
	return mins;
}