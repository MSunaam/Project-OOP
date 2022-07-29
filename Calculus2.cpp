#include "Calculus2.h"

Calculus2::Calculus2(int loginID, int password, int mins = 0, string pass = "ABCD")
	:Teacher(loginID, password, mins, pass) {
	writePass();
	writeTimer();
}
void Calculus2::writePass() const {
	if (getPass() != "ABCD") {
		fstream file("Calculus2.txt");
		file << getPass() << endl;
		file.close();
	}
}
void Calculus2::writeTimer() const {
	if (getTimer() != 0) {
		fstream file("Calculus2.txt");
		file << getTimer() << endl << endl;
		file.close();
	}
}
void Calculus2::addQues() {
	int num;
	string question;
	string A, B, C, D;
	cout << "How many questions do you want to add?" << endl;
	cin >> num;
	fstream file("Calculus2.txt", ios::app);
	file << "Total Questions : " << num << endl;
	cout << "How many marks?" << endl;
	cin >> num;
	file << "Total Marks : " << num << endl;
	for (int i = 0; i < num; i++) {
		cout << "Enter question " << i + 1 << endl;
		cin.ignore('\n', 256);
		getline(cin, question);
		cout << "Enter first option" << endl;
		cin.ignore('\n', 256);
		getline(cin, A);
		cout << "Enter second option" << endl;
		cin.ignore('\n', 256);
		getline(cin, B);
		cout << "Enter third option" << endl;
		cin.ignore('\n', 256);
		getline(cin, C);
		cout << "Enter fourth option" << endl;
		cin.ignore('\n', 256);
		getline(cin, D);
		file << "Q" << i + 1 << " : " << endl;
		file << question << endl << A << endl << B << endl << C << endl << D << endl << endl;
	}
}