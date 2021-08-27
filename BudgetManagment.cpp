#include "BudgetManagment.h"

void BudgetManagment::registerUser() {
    userManager.registerUser();
}

void BudgetManagment::logInUser() {
    userManager.logInUser();
    if(userManager.isUserLoggedIn()) {
        incomeManager = new IncomeManager(INCOMES_FILENAME, userManager.getLoggedInUserId());
        expenseManager = new ExpenseManager (EXPENSES_FILENAME, userManager.getLoggedInUserId());
        balanceManager = new BalanceManager();
    }
}

void BudgetManagment::addIncome() {
    incomeManager->addIncome();
}

void BudgetManagment::addExpense() {
    expenseManager->addExpense();
}

void BudgetManagment::currentMonthBalanceSheet() {
    incomeManager->displayIncomesFromCurrentMonth();
    expenseManager->displayExpensesFromCurrentMonth();

}

void BudgetManagment::loggedInUserPasswordChange() {
    userManager.loggedInUserPasswordChange();
}

void BudgetManagment::logOutUser() {
    userManager.logOutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
    delete balanceManager;
    balanceManager = NULL;
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
