#ifndef BUDGETMANAGMENT_H
#define BUDGETMANAGMENT_H

#include <iostream>

#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetManagment {

    UserManager userManager;
    TransactionManager *transactionManager;
    const string TRANSACTIONS_FILENAME;

public:
    BudgetManagment(string usersFilename, string transactionsFilename)
        : userManager(usersFilename), TRANSACTIONS_FILENAME(transactionsFilename){
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
//   void selectedPeriodBalanceSheet();
    void loggedInUserPasswordChange();
    void logOutUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};




#endif // BUDGETMANAGMENT_H
