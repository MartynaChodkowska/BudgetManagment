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
            int expenseId = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("DATE");
            string expenseDate = xmlFile.GetData();

            xmlFile.FindElem("AMOUNT");
            double expenseAmount = atof(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("GROUP");
            string expenseGroup = xmlFile.GetData();

            expense.setId(expenseId);
            expense.setUserId(userId);
            expense.setDate(expenseDate);
            expense.setAmount(expenseAmount);
            expense.setGroup(expenseGroup);

            expensesVector.push_back(expense);

            xmlFile.OutOfElem();
        }
    }
    return expensesVector;
}
