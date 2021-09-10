#include "TransactionsFile.h"

void TransactionsFile::addTransactionToFile(Transaction transaction){
    CMarkup xmlFile;
    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("TRANSACTIONS")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("TRANSACTIONS");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem("TRANSACTION");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", to_string(transaction.getId()));
    xmlFile.AddElem("USERID", to_string(transaction.getUserId()));
    xmlFile.AddElem("DATE", SupportingMethods::converseDateToString(transaction.getDate()));
    xmlFile.AddElem("AMOUNT", SupportingMethods::converseAmountToShortString(transaction.getAmount()));
    xmlFile.AddElem("GROUP", transaction.getGroup());
    xmlFile.AddElem("TYPE", transaction.getType());
    xmlFile.OutOfElem();

    xmlFile.Save(getFilename());
}


vector<Transaction> TransactionsFile::loadTransactionsFromFile(int loggedInUserId) {
    vector <Transaction> transactionsVector;
    Transaction transaction;
    CMarkup xmlFile;

    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();

    if (xmlFile.FindElem("TRANSACTIONS")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("TRANSACTION")) {
            xmlFile.IntoElem();
            xmlFile.FindElem("ID");
            int id = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));
            if (userId == loggedInUserId) {
                xmlFile.FindElem("DATE");
                string dateFromFile = xmlFile.GetData();
                int date = SupportingMethods::converseDateToInt(dateFromFile);

                xmlFile.FindElem("AMOUNT");
                string amountFromFile = xmlFile.GetData();
                double amount = stod(amountFromFile.substr());

                xmlFile.FindElem("GROUP");
                string group = xmlFile.GetData();

                xmlFile.FindElem("TYPE");
                string type = xmlFile.GetData();

                transaction.setId(id);
                transaction.setUserId(userId);
                transaction.setDate(date);
                transaction.setAmount(amount);
                transaction.setGroup(group);
                transaction.setType(type);

                transactionsVector.push_back(transaction);
            }
            xmlFile.OutOfElem();
        }
    }
    return transactionsVector;
}

int TransactionsFile::getNumberOfTransactionsInFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();
    int numberOfTransactions = 0;

    if (xmlFile.FindElem("TRANSACTIONS")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("TRANSACTION")) {
            numberOfTransactions++;
        }
    }
    return numberOfTransactions;
}
