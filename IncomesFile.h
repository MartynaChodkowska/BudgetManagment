#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <stdlib.h> //atof
#include <fstream>
#include <vector>

#include "Markup.h"
#include "XMLFile.h"
#include "Income.h"


using namespace std;

class IncomesFile :public XMLFile {
    Income income;
    Income getIncomeData();


public:
    IncomesFile(string incomesFilename)
        : XMLFile (incomesFilename)
    {};
    void addIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile(int loggedInUserId);
        int getNumberOfIncomesInFile();
};


#endif // INCOMESFILE_H
