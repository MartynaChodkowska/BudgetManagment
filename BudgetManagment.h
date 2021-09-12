#ifndef BUDGETMANAGMENT_H
#define BUDGETMANAGMENT_H

#include <iostream>

#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetManagment {

    UserManager userManager;
    TransactionManager *transactionManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    BudgetManagment(string usersFilename, string incomesFilename, string expensesFilename)
        : userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename){
        transactionManager = NULL;
    };
    ~BudgetManagment() {
        delete transactionManager;
        transactionManager = NULL;
    };
    void registerUser();
    void logInUser();
    void addIncome();
    void addExpense();
    void currentMonthBalanceSheet();
    void previousMonthBalanceSheet();
    void selectedPeriodBalanceSheet();
    void loggedInUserPasswordChange();
    void logOutUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif // BUDGETMANAGMENT_H
