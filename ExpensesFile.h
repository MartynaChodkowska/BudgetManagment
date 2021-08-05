#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <stdlib.h> //atof
#include <fstream>
#include <vector>

#include "Markup.h"
#include "XMLFile.h"
#include "Expense.h"
#include "SupportingMethods.h"
#include "DateManager.h"


using namespace std;

class ExpensesFile :public XMLFile {
    Expense expense;
    Expense getExpenseData();

public:
    ExpensesFile(string expenseFilename)
        : XMLFile (expenseFilename)
    {};
    void addExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int loggedInUserId);
    int getNumberOfExpensesInFile();


};


#endif // EXPENSESFILE_H
