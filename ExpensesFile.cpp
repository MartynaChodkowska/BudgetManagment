#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("EXPENSES")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("EXPENSES");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem("EXPENSE");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", to_string(expense.getId()));
    xmlFile.AddElem("USERID", to_string(expense.getUserId()));
    xmlFile.AddElem("DATE", expense.getDate());
    xmlFile.AddElem("AMOUNT", to_string(expense.getAmount()));
    xmlFile.AddElem("GROUP", expense.getGroup());
    xmlFile.OutOfElem();

    xmlFile.Save(getFilename());
}


vector<Expense> ExpensesFile::loadExpensesFromFile(int loggedInUserId) {
    vector <Expense> expensesVector;
    Expense expense;
    CMarkup xmlFile;

    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();

    if (xmlFile.FindElem("EXPENSES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("EXPENSE")) {
            xmlFile.IntoElem();

            xmlFile.FindElem("EXPENSEID");
            int id = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));
            if (userId == loggedInUserId) {
                xmlFile.FindElem("DATE");
                string date = xmlFile.GetData();

                xmlFile.FindElem("AMOUNT");
                double amount = atof(MCD_2PCSZ(xmlFile.GetData()));

                xmlFile.FindElem("GROUP");
                string group = xmlFile.GetData();

                expense.setId(id);
                expense.setUserId(userId);
                expense.setDate(date);
                expense.setAmount(amount);
                expense.setGroup(group);

                expensesVector.push_back(expense);

                xmlFile.OutOfElem();
            }
        }
    }
    return expensesVector;
}

int ExpensesFile::getNumberOfExpensesInFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();
    int numberOfExpenses = 0;

    if (xmlFile.FindElem("EXPENSES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("EXPENSE")) {
            numberOfExpenses++;
        }
    }

    return numberOfExpenses;
}
