#include "BudgetManagment.h"

void BudgetManagment::registerUser() {
    userManager.registerUser();
}

void BudgetManagment::logInUser() {
    return userManager.logInUser();
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

void BudgetManagment::displayAllUsers() {
    userManager.displayAllUsers();
}
