#include <iostream>

#include "BudgetManagment.h"

using namespace std;

int main() {
    BudgetManagment budget("Users.xml", "Incomes.xml", "Expenses.xml");

    char selection;

    while (true) {
        if (!budget.isUserLoggedIn()) {
            selection = budget.selectOptionFromMainMenu();
            switch (selection) {
            case '1':
                budget.registerUser();
                break;
            case '2':
                budget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            selection = budget.selectOptionFromUserMenu();
            switch (selection) {
            case '1':
                budget.addIncome();
                break;
            case '2':
                budget.addExpense();
                break;
            case '3':
                budget.currentMonthBalanceSheet();
                break;
            case '4':
                budget.previousMonthBalanceSheet();
                break;
            case '5':
                budget.selectedPeriodBalanceSheet();
                break;
            case '6':
                budget.loggedInUserPasswordChange();
                break;
            case '7':
                budget.logOutUser();
                break;
            }
        }
    }
    return 0;
}


