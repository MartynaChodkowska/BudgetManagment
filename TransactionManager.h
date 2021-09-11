#ifndef TRANSACTIONMANGER_H
#define TRANSACTIONMANGER_H

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <iomanip> // setprecision

#include "Transaction.h"
#include "TransactionsFile.h"
#include "SupportingMethods.h"

using namespace std;

class TransactionManager {
    const int LOGGDED_IN_USER_ID;
    vector <Transaction> transactions;
    TransactionsFile transactionsFile;
    double totalIncomesAmount, totalExpensesAmount;

    Transaction giveNewTransactionData();
    int getNewTransactionId();
    vector<Transaction> findTransactionsFromMonth(int month, int year, int numberOfMonths);
    vector<Transaction> sortTransactions(vector<Transaction> transactionsToSort);
    vector<Transaction> getTransactionsToDisplay(int month, int year, int numberOfMonths);
    void displayIncomes(vector<Transaction> incomesToDisplay);
    void displayExpenses(vector<Transaction> expensessToDisplay);
    void displayBalance();
    void displayTransactionsFromSelectedMonth(int month, int year, int numberOfMonths);

public:
    TransactionManager(string transactionsFilename, int loggedInUserId)
        : transactionsFile (transactionsFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        transactions = transactionsFile.loadTransactionsFromFile(loggedInUserId);
    };
    void addTransaction(string transactionType);
    void displayTransactionsFromCurrentMonth();
    void displayTransactionsFromPreviousMonth();
    void displayTransactionsFromSelectedPeriod();
};


#endif // TRANSACTIONMANGER_H
