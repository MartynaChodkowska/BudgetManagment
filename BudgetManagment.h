#ifndef BUDGETMANAGMENT_H
#define BUDGETMANAGMENT_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class BudgetManagment {
    UserManager userManager;

public:
    BudgetManagment(string usersFilename) : userManager(usersFilename){};
    // ~BudgetManagment();
    void registerUser();
    int logInUser();
//   void addIncome();
//   void addExpense();
//   void currentMonthBalanceSheet();
//   void previousMonthBalanceSheet();
//   void selectedPeriodBalanceSheet();
    void loggedInUserPasswordChange();
    void logOutUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void displayAllUsers();
};




#endif // BUDGETMANAGMENT_H
