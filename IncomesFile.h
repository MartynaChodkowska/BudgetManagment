#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>

#include "Markup.h"
#include "XMLFile.h"
#include "Transaction.h"
#include "SupportingMethods.h"

using namespace std;

class IncomesFile :public XMLFile {
    Transaction transaction;
public:
    IncomesFile(string incomesFilename)
        : XMLFile (incomesFilename)
    {};
    void addTransactionToFile(Transaction transaction);
    vector<Transaction> loadTransactionsFromFile(int loggedInUserId);
    int getNumberOfTransactionsInFile();
};

#endif // INCOMESFILE_H
