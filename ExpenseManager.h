#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <iomanip> // setprecision

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
  //  double totalExpenses;
    Expense giveNewExpenseData();
    int getNewExpenseId();
    vector<Expense> findExpensesFromMonth(int month, int year);
    vector<Expense> sortExpenses(vector<Expense> expensesToSort);
    vector<Expense> getExpensesToDisplay(int month, int year);
    double calculateTotalExpensesAmount(vector<Expense> expenses);
    double calculateBalance (IncomeManager &incomes, ExpenseManager &expenses);
    void displayExpensesFromSelectedMonth(int month, int year);

public:
    ExpenseManager(string expensesFilename, int loggedInUserId)
        : expensesFile (expensesFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        expenses = expensesFile.loadExpensesFromFile(loggedInUserId);
    };
    void addExpense();
    void displayExpensesFromCurrentMonth();
    void displayExpensesFromPreviousMonth();
    void displayExpensesFromSelectedPeriod(int startMonth, int endMonth);
};


#endif // EXPENSEMANAGER_H
