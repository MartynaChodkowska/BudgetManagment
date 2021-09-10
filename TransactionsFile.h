#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H

#include <iostream>

#include "Markup.h"
#include "XMLFile.h"
#include "Transaction.h"
#include "DateManager.h"

using namespace std;

class TransactionsFile :public XMLFile {
    Transaction transaction;
    Transaction getExpenseData();

public:
    TransactionsFile(string transactionFilename)
        : XMLFile (transactionFilename)
    {};
    void addTransactionToFile(Transaction transaction);
    vector<Transaction> loadTransactionsFromFile(int loggedInUserId);
    int getNumberOfTransactionsInFile();
};

#endif // TRANSACTIONSFILE_H
