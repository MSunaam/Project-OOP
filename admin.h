//
// Created by Muhammad Sunaam on 04/07/2022.
//

#ifndef PROJECT_1_ADMIN_H
#define PROJECT_1_ADMIN_H
#include <string>
using namespace std;
class Admin : public QMS {
public:
    Admin(int loginId, string password);
    void checkResult() const;
    void checkExams() const;
    void checkLoginDetails(int) const;
};

#endif //PROJECT_1_ADMIN_H
