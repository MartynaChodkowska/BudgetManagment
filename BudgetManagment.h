#ifndef BUDGETMANAGMENT_H
#define BUDGETMANAGMENT_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"

using namespace std;

class BudgetManagment {

    UserManager userManager;
    IncomeManager *incomeManager;
    const string INCOMES_FILENAME;

public:
    BudgetManagment(string usersFilename, string incomesFilename)
        : userManager(usersFilename), INCOMES_FILENAME(incomesFilename) {
        incomeManager = NULL;
    };
    ~BudgetManagment() {
        delete incomeManager;
        incomeManager = NULL;
    };
    void registerUser();
    void logInUser();
    void addIncome();
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
