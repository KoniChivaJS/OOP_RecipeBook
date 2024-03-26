//
// Created by eduard on 26.03.24.
//

#include "User.h"

#include <utility>

User::User(string newLogin, string newPassword, string newEmail, bool admin)
    :login{std::move(newLogin)},password{std::move(newPassword)},email{std::move(newEmail)},isAdmin{admin}{}

User::~User() {

}

bool User::getAdmin() {
    return this->isAdmin;
}

string User::getLogin() {
    return this->login;
}

string User::getPassword() {
    return this->password;
}

string User::getEmail() {
    return this->email;
}

