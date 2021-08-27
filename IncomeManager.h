#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <iomanip> //setprecision

#include "Income.h"
#include "IncomesFile.h"
#include "Operation.h"
#include "SupportingMethods.h"
#include "DateManager.h"

using namespace std;

class IncomeManager {
    const int LOGGDED_IN_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;
    Income giveNewIncomeData();
    int getNewIncomeId();
    vector<Income> findIncomesFromMonth(int month, int year);
    vector<Income> sortIncomes(vector<Income> incomesToSort);
    vector<Income> getIncomesToDisplay(int month, int year);

public:
    IncomeManager(string incomesFilename, int loggedInUserId)
        : incomesFile (incomesFilename), LOGGDED_IN_USER_ID (loggedInUserId) {
        incomes = incomesFile.loadIncomesFromFile(loggedInUserId);
    };
    void addIncome();
    double displayIncomesFromSelectedMonth(int month, int year);
    /* void displayIncomesFromCurrentMonth();
     void displayIncomesFromPreviousMonth();
     void displayIncomesFromSelectedPeriod(int startMonth, int endMonth);
    */
};


#endif // INCOMEMANAGER_H
