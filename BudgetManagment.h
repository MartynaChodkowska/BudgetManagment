#ifndef BUDGET_MANAGMENT_H
#define BUDGET_MANAGMENT_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class BudgetManagment {
    UserManager userManager;

public:
   // BudgetManagment();
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
};




#endif // BUDGET_MANAGMENT_H
