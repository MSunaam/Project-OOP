#include <iostream>
#include "QMS.h"
#include "admin.h"
#include "student.h"
using namespace std;

int main() {


    cout << "Welcome to the QMS" << endl;
    cout << "Please select an option" << endl;
    cout << "1. Login as Admin" << endl;
    cout << "2. Login as Student" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;
    while(choice < 1 || choice > 3) {
        cout << "Invalid choice" << endl;
        cin >> choice;
    }
    while(choice != 3) {
        cout << "Welcome to the QMS" << endl;
        cout << "Please select an option" << endl;
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Student" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        while(choice < 1 || choice > 3) {
            cout << "Invalid choice" << endl;
            cin >> choice;
        }
        if (choice == 1) {
            Admin admin;
            admin.login();
            cout << "Please select an option" << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Check Marks" << endl;
            cout << "3. Exit" << endl;
            int choiceAdmin;
            cin >> choiceAdmin;
            while (choiceAdmin < 1 || choiceAdmin > 3) {
                cout << "Invalid choice" << endl;
                cin >> choiceAdmin;
            }
            if (choiceAdmin == 1) {
                admin.createAccount();
            } else if (choiceAdmin == 2) {
                admin.checkMarks();
            } else if (choiceAdmin == 3) {
            }
        } else if (choice == 2) {
            Student student;
            student.login();
            cout << "Please select an option" << endl;
            cout << "1. Take Quiz" << endl;
            cout << "2. Check Marks" << endl;
            cout << "3. Exit" << endl;
            int choiceStudent;
            cin >> choiceStudent;
            while (choiceStudent < 1 || choiceStudent > 3) {
                cout << "Invalid choice" << endl;
                cin >> choiceStudent;
            }
            if (choiceStudent == 1) {
                student.takeQuiz();
            } else if (choiceStudent == 2) {
                student.checkMarks();
            } else if (choiceStudent == 3) {
            }
        } else if (choice == 3) {
            cout << "Goodbye" << endl;
        }
    }

    return 0;
}
