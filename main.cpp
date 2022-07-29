#include <iostream>
#include "QMS.h"
#include "admin.h"
#include "student.h"
using namespace std;

int main() {


    Student s1("0918", "sunaam");
    s1.login();
    s1.takeQuiz();


    return 0;
}
