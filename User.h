#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{

int id;
string name, secondname, login, password;

public:
    User(){};
    int getId();
    string getName();
    string getSecondname();
    string getLogin();
    string getPassword();

    void setId(int newId);
    void setName(string newName);
    void setSecondname(string newSecondname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
};

#endif // USER_H
