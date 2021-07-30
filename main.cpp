#include <iostream>

#include "BudgetManagment.h"

using namespace std;

int main() {
    BudgetManagment budget("Users.xml");

    budget.displayAllUsers();
    budget.registerUser();

    return 0;
}
