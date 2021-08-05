#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "ExpensesFile.h"
#include "Operation.h"
#include "SupportingMethods.h"
#include "DateManager.h"

using namespace std;

class ExpenseManager {
    const int LOGGDED_IN_USER_ID;
    vector <Expense> expenses;
    ExpensesFile expensesFile;
    Expense giveNewExpenseData();
    void displayExpensesFromSelectedMonth(int month);
    int getNewExpenseId();

public:
    ExpenseManager(string expensesFilename, int loggedInUserId)
        : expensesFile (expensesFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        expenses = expensesFile.loadExpensesFromFile(loggedInUserId);
    };

    void addExpense();
    void displayexpensesFromCurrentMonth();
    void displayexpensesFromPreviousMonth();
    void displayexpensesFromSelectedPeriod(int startMonth, int endMonth);

};


#endif // EXPENSEMANAGER_H
