#include <iostream>

#include "BudgetManagment.h"

using namespace std;

int main()
{
    BudgetManagment budget("Users.txt");

    budget.registerUser();

    return 0;
}
