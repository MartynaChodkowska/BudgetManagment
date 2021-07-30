#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector<User> users;
    //UsersFile usersFile;
    User giveNewUserData();
    int getNewUserData(User newUser);
    int getNewUserId();
    bool isLoginExists(string login);
    bool isUserLoginExists();

public:
    UserManager() {
        loggedInUserId = 0;
    }
    void registerUser();
    int logInUser();
    void loggedInUserPasswordChange();
    void logOutUser();
    void getLoggedInUserId();
    void setLoggedInUserId();
};


#endif // USERMANAGER_H
