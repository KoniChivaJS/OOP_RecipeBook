//
// Created by eduard on 26.03.24.
//

#include "User.h"

User::User() {

}

User::User(string &newLogin, string &newPassword, string &newEmail, bool admin)
    :login(newLogin),password(newPassword),email(newEmail),isAdmin(admin){

}

User::~User() {

}
