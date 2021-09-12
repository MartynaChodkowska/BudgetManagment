#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>

#include "Markup.h"
#include "XMLFile.h"
#include "Transaction.h"
#include "SupportingMethods.h"

using namespace std;

class ExpensesFile :public XMLFile {
    Transaction transaction;
    //Transaction getTransactionData();

public:
    ExpensesFile(string expensesFilename)
        : XMLFile (expensesFilename)
    {};
    void addTransactionToFile(Transaction transaction);
    vector<Transaction> loadTransactionsFromFile(int loggedInUserId);
    int getNumberOfTransactionsInFile();
};

#endif // EXPENSESFILE_H
