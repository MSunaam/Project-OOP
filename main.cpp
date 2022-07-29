#include "Islamiat.h"
#include "IMT.h"
#include "AppliedPhysics.h"
#include "Calculus2.h"
#include "DLD.h"
#include "OOP.h"
#include "Student.h"
#include "Admin.h"

int main() {
	int x = 10;
	cout << *(&x);
	system("color 0B");
	string n;
	int m{};
	int num{ 0 };
	string CMSID;
	string password;
	int timer;
	string passwo;
	Teacher* t1;
	Student* s2;
	Admin* q3;

	while (true) {
	jump4:
	jump3:
	jump2:
	jump1:
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "------------------------------------------" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "--------Quiz Management System------------" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "------------------------------------------" << endl;
		cout << endl << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "------------------------------------------" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "|  1.          Teacher                   |" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "|  2.          Student                   |" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "|  3.          Admin                     |" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "|  4.          Exit                      |" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "------------------------------------------" << endl;
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}
		cout << "------------------------------------------" << endl;
		cout << endl << endl;
		cout << "\t\t\t\t\t\t Select Your Choice ->> ";
		cin >> num;
		if (num == 4) {
			break;
		}
		while (num == 0)
		{
			if (num == 4)
			{
				goto jump4;
				break;
			}
			cin.clear();
			if (num != 1 && num != 2 && num != 3) {
				cout << "\t\t\tPlease enter a valid choice" << endl;
				num = 0;
				continue;
			}
			cin.ignore(10, '\n');
		}
		if (num == 1) {
			cout << "Press enter to get teacher panel" << endl;
			cin.get();
			system("cls");
			cout << " ====== LOG IN ======";
			cout << "\n\n\n\n\n";
			cout << "Enter your CMS ID" << endl;
			cin >> CMSID;
			cout << "Enter your password" << endl;
			cin.ignore(256, '\n');
			getline(cin, passwo);
			t1 = new Teacher(CMSID, passwo, 0, "ABCD");
			cout << "Successfully logged in. Press enter to continue" << endl;
			cin.get();
			while (true) {
				system("cls");
				cout << "Select the subject in which you want to add the question" << endl;
				cout << "1.    Islamiat" << endl;
				cout << "2.    IMT" << endl;
				cout << "3.    Applied Physics" << endl;
				cout << "4.    OOP" << endl;
				cout << "5.    Digital Logic Design" << endl;
				cout << "6.    Calculus II" << endl;
				cout << "7.    Exit" << endl;
				cout << "\t\t\t\t Select Your Choice ->> ";
				cin >> num;
				if (num == 7)
				{
					goto jump1;
					break;
				}
				cin.clear();
				if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7) {
					cout << "\t\t\tInvalid choice enter a valid choice" << endl;
					cin >> num;
				}
				cout << "Press y to add password to quiz" << endl;
				cin >> password;
				cin.ignore(256, '\n');
				if (password == "y") {
					cout << "Enter quiz password" << endl;
					getline(cin, password);
				}
				else {
					password = "ABCD";
				}
				cout << "Press for 1 to add timer to quiz" << endl;
				cin >> timer;
				if (timer == 1) {
					cout << "Enter quiz timer" << endl;
					cin >> timer;
				}
				else {
					timer = 0;
				}
				switch (num) {
				case 1:
					t1 = new Islamiat(CMSID, passwo, timer, password);
					break;
				case 2:
					t1 = new IMT(CMSID, passwo, timer, password);
					break;
				case 3:
					t1 = new AppliedPhysics(CMSID, passwo, timer, password);
					break;
				case 4:
					t1 = new OOP(CMSID, passwo, timer, password);
					break;
				case 5:
					t1 = new DLD(CMSID, passwo, timer, password);
					break;
				case 6:
					t1 = new Calculus2(CMSID, passwo, timer, password);
					break;
				}
			}
		}
		if (num == 2) {
			cout << "Welcome to Student Panel. Press enter to get the Student panel" << endl;
			cin.get();
			system("cls");
			cout << " ====== LOG IN ======";
			cout << "\n\n\n\n\n";
			cout << "Enter your CMS ID" << endl;
			cin >> CMSID;
			cout << "Enter your password" << endl;
			cin.ignore(256, '\n');
			getline(cin, passwo);
			s2 = new Student(CMSID, passwo);
			cout << "Successfully logged in. Press enter to continue" << endl;
			cin.get();

			cout << "1.  Give exam" << endl;
			cout << "2.  Grade Exam" << endl;
			cout << "4. Check Result" << endl;
			cout << "3.  Exit" << endl;

			cin >> num;
			if (num == 3) {
				goto jump2;
				break;

			}

			cin.clear();
			if (num != 1 && num != 2 && num != 3 && num != 4) {
				cout << "\t\t\tInvalid choice enter a valid choice" << endl;
				cin >> num;
			}
			else if (num == 1) {
				s2->takeQuiz();
				break;
			}
			else if (num == 2) {
				s2->gradeExam();
				break;
			}
			else if (num == 4) {
				s2->checkMarks();
			}
		}
		if (num == 3) {
			cout << "Welcome to Admin Panel. Press enter to get the Admin panel" << endl;
			cin.get();
			system("cls");
			cout << " ====== LOG IN ======";
			cout << "\n\n\n\n\n";
			cout << "Enter your ID" << endl;
			cin >> CMSID;
			cout << "Enter your password" << endl;
			cin.ignore(256, '\n');
			getline(cin, passwo);
			q3 = new Admin(CMSID, passwo);
			cout << "Successfully logged in. Press enter to continue" << endl;
			cin.get();

			cout << "1.   Check Marks" << endl;
			cout << "2.   Create Account of Student/Teacher" << endl;
			cout << "5.   Exit" << endl;
			cin >> num;
			if (num == 5) {
				goto jump3;
				break;
			}
			if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) {
				cout << "Invalid choice" << endl;
				cout << "Enter again" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> num;
			}
			if (num == 1) {
				q3->checkMarks();
			}
			else if (num == 2) {
				q3->createAccount();
			}
		}
	}
	return 0;
}
