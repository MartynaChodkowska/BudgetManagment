#include "BudgetManagment.h"

void BudgetManagment::registerUser() {
    userManager.registerUser();
}

void BudgetManagment::logInUser() {
    userManager.logInUser();
    if(userManager.isUserLoggedIn()) {
        transactionManager = new TransactionManager (INCOMES_FILENAME, EXPENSES_FILENAME, userManager.getLoggedInUserId());
    }
}

void BudgetManagment::addIncome() {
    transactionManager->addIncome();
}

void BudgetManagment::addExpense() {
    transactionManager->addExpense();
}

void BudgetManagment::currentMonthBalanceSheet() {
    transactionManager->displayTransactionsFromCurrentMonth();
}

void BudgetManagment::previousMonthBalanceSheet(){
    transactionManager->displayTransactionsFromPreviousMonth();
}

void BudgetManagment::selectedPeriodBalanceSheet(){
    transactionManager->displayTransactionsFromSelectedPeriod();
}

void BudgetManagment::loggedInUserPasswordChange() {
    userManager.loggedInUserPasswordChange();
}

void BudgetManagment::logOutUser() {
    userManager.logOutUser();
    delete transactionManager;
    transactionManager = NULL;
}

bool BudgetManagment::isUserLoggedIn() {
    if (userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

char BudgetManagment::selectOptionFromMainMenu() {
    return SupportingMethods::selectOptionFromMainMenu();
}

char BudgetManagment::selectOptionFromUserMenu() {
    return SupportingMethods::selectOptionFromUserMenu();
}
