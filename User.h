//
// Created by eduard on 26.03.24.
//

#ifndef LAB2_1_USER_H
#define LAB2_1_USER_H

#include <iostream>
#include <string>
using namespace std;
class User {
private:
    string login;
    string password;
    string email;
    bool isAdmin;
public:
    User();
    User(string &newLogin,string &newPassword,string &newEmail,bool admin);
    ~User();
};


#endif //LAB2_1_USER_H
