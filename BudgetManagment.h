#ifndef BUDGETMANAGMENT_H
#define BUDGETMANAGMENT_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class BudgetManagment {

    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    BudgetManagment(string usersFilename, string incomesFilename, string expensesFilename)
        : userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename) {
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~BudgetManagment() {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };
    void registerUser();
    void logInUser();
    void addIncome();
    void addExpense();
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
