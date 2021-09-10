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
    int getNewUserId();
    bool isLoginExists(string login);
    void displayIncomesFromSelectedMonth(int monthToDisplay, int yearToDisplay);

public:
    UserManager(string usersFilename) : usersFile(usersFilename) {
        loggedInUserId = 0;
        users = usersFile.loadUsersFromFile();
    }
    void registerUser();
    void logInUser();
    void loggedInUserPasswordChange();
    void logOutUser();
    int getLoggedInUserId();
    void setLoggedInUserId(); //is it necessary?
    bool isUserLoggedIn();

  //  void displayIncomesFromCurrentMonth();
  //  void displayIncomesFromPreviousMonth();
  //  void displayIncomesFromSelectedPeriod(int startMonth, int endMonth);
};


#endif // USERMANAGER_H
