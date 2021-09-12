#ifndef TRANSACTIONMANGER_H
#define TRANSACTIONMANGER_H

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <iomanip> // setprecision

#include "Transaction.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "SupportingMethods.h"

using namespace std;

class TransactionManager {
    const int LOGGDED_IN_USER_ID;
    vector <Transaction> incomes, expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    double totalIncomesAmount, totalExpensesAmount;

    Transaction giveNewTransactionData(string transactionType);
    int getNewTransactionId(string transactionType);
    vector<Transaction> findIncomesFromMonth(int month, int year, int numberOfMonths);
    vector<Transaction> findExpensesFromMonth(int month, int year, int numberOfMonths);
    void displayIncomes(vector<Transaction> incomesToDisplay);
    void displayExpenses(vector<Transaction> expensessToDisplay);
    void displayBalance();
    void displayTransactionsFromSelectedMonth(int month, int year, int numberOfMonths);

public:
    TransactionManager(string incomesFilename, string expensesFilename, int loggedInUserId)
        : incomesFile(incomesFilename), expensesFile(expensesFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        incomes = incomesFile.loadTransactionsFromFile(loggedInUserId);
        expenses = expensesFile.loadTransactionsFromFile(loggedInUserId);
    };
    void addIncome();
    void addExpense();
    void displayTransactionsFromCurrentMonth();
    void displayTransactionsFromPreviousMonth();
    void displayTransactionsFromSelectedPeriod();
};


#endif // TRANSACTIONMANGER_H
