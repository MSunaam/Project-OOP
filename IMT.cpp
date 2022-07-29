#include "IMT.h"
IMT::IMT(int loginID, int password, int mins = 0, string pass = "ABCD") : Teacher(loginID, password, mins, pass) {
	writepass();
	writeTimer();
}
void IMT::writepass() const {
	if (getPass() != "ABCD") {
		fstream file("IMT.txt");
		file << getpass() << endl;
		file.close();
	}
}
void IMT::writeTimer() const {
	if (getTimer != 0) {
		fstream file("IMT.txt");
		file << getTimer() << endl;
		file.close();	
	}
}
void IMT::addques() {
	int num;
	string questions;
	string A, B, C, D;
	cout << "Enter how many question do you want to add?" << endl;
	cin >> num;
	fstream file("IMT.txt", ios::app);
	for (int i; i < num; i++) {
		cout << "Enter questions " << i + 1 << endl;
		cin.ignore('\n', 256);
		getline(cin, questions);
		cout << "Enter first option" << endl;
		cin.ignore('\n', 256);
		getline(cin, A);
		cout << "Enter 2nd option" << endl;
		cin.ignore('\n', 256);
		getline(cin, B);
		cout << "Enter third option" << endl;
		cin.ignore('\n', 256);
		getline(cin, C);
		cout << "Enter fourth option" << endl;
		cin.ignore('\n', 256);
		getline(cin, D);
		file << "Q" << i + 1 << ":" << endl;
		file << questions << endl << A << endl << B << endl << C << endl << D << endl << endl;
	}
}