#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector<User> users;
    UsersFile usersFile;
    User giveNewUserData();
   // int getNewUserData(User newUser);
    int getNewUserId();
    bool isLoginExists(string login);
   // bool isUserLoginExists();

public:
    UserManager(string usersFilename) : usersFile(usersFilename) {
        loggedInUserId = 0;
        users = usersFile.loadUsersFromFile();
    }
    void registerUser();
    void logInUser();
    void loggedInUserPasswordChange();
    void logOutUser();
    void getLoggedInUserId();
    void setLoggedInUserId();
    void displayAllUsers();
};


#endif // USERMANAGER_H
