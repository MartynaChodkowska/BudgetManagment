#include "ExpensesFile.h"

void ExpensesFile::addTransactionToFile(Transaction transaction) {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("EXPENSES")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSE");
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSEID", to_string(transaction.getId()));
    xmlFile.AddElem("USERID", to_string(transaction.getUserId()));
    xmlFile.AddElem("DATE", SupportingMethods::converseDateToString(transaction.getDate()));
    xmlFile.AddElem("ITEM", transaction.getItem());
    xmlFile.AddElem("AMOUNT", SupportingMethods::converseAmountToShortString(transaction.getAmount()));
    xmlFile.OutOfElem();

    xmlFile.Save(getFilename());
}

vector<Transaction> ExpensesFile::loadTransactionsFromFile(int loggedInUserId) {
    vector <Transaction> transactionsVector;
    Transaction transaction;
    CMarkup xmlFile;

    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();

    if (xmlFile.FindElem("EXPENSES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("EXPENSE")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("ID");
            int id = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));
            if (userId == loggedInUserId) {
                xmlFile.FindElem("DATE");
                string dateFromFile = xmlFile.GetData();
                int date = SupportingMethods::converseDateToInt(dateFromFile);

                xmlFile.FindElem("ITEM");
                string item = xmlFile.GetData();

                xmlFile.FindElem("AMOUNT");
                string amountFromFile = xmlFile.GetData();
                double amount = stod(amountFromFile.substr());

                transaction.setId(id);
                transaction.setUserId(userId);
                transaction.setDate(date);
                transaction.setItem(item);
                transaction.setAmount(amount);

                transactionsVector.push_back(transaction);
            }
            xmlFile.OutOfElem();
        }
    }
    return transactionsVector;
}

int ExpensesFile::getNumberOfTransactionsInFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();
    int numberOfTransactions = 0;

    if (xmlFile.FindElem("EXPENSES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("EXPENSE")) {
            numberOfTransactions++;
        }
    }
    return numberOfTransactions;
}
