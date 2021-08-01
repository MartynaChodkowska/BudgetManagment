#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "IncomesFile.h"
#include "Operation.h"
#include "SupportingMethods.h"

using namespace std;

class IncomeManager {
    const int LOGGDED_IN_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    Income giveNewIncomeData();
    void displayIncomesFromSelectedMonth(int month);
    int getNewIncomeId();

public:
    IncomeManager(string incomesFilename, int loggedInUserId)
        : incomesFile (incomesFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        incomes = incomesFile.loadIncomesFromFile(loggedInUserId);
    };

    void addIncome();
    void displayIncomesFromCurrentMonth();
    void displayIncomesFromPreviousMonth();
    void displayIncomesFromSelectedPeriod(int startMonth, int endMonth);

};


#endif // INCOMEMANAGER_H
