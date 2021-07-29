#include "User.h"

int User::getId() {
    return id;
}
string User::getName() {
    return name;
}
string User::getSecondname() {
    return secondname;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}

void User::setId(int newId) {
    id = newId;
}
void User::setName(string newName) {
    name = newName;
}
void User::setSecondname(string newSecondname) {
    secondname = newSecondname;
}
void User::setLogin(string newLogin) {
    login = newLogin;
}
void User::setPassword(string newPassword) {
    password = newPassword;
}
