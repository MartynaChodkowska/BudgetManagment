#include <iostream>

#include "BudgetManagment.h"

using namespace std;

int main() {
    BudgetManagment budget("Users.xml");

    budget.displayAllUsers();
    //budget.registerUser();
    budget.logInUser();

    return 0;
}
