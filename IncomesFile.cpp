#include "IncomesFile.h"

void IncomesFile::addIncomeToFile(Income income) {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());

    if (!xmlFile.FindElem("INCOMES")) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("INCOMES");
    }
    xmlFile.IntoElem();
    xmlFile.AddElem("INCOME");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID", to_string(income.getId()));
    xmlFile.AddElem("USERID", to_string(income.getUserId()));
   // string tempDate = SupportingMethods::dateToString(income.getDate());
    xmlFile.AddElem("DATE", DateManager::converseDateToString(income.getDate()));
    xmlFile.AddElem("AMOUNT", to_string(income.getAmount()));
    xmlFile.AddElem("GROUP", income.getGroup());
    xmlFile.OutOfElem();

    xmlFile.Save(getFilename());
}


vector<Income> IncomesFile::loadIncomesFromFile(int loggedInUserId) {
    vector <Income> incomesVector;
    Income income;
    CMarkup xmlFile;

    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();

    if (xmlFile.FindElem("INCOMES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("INCOME")) {
            xmlFile.IntoElem();

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));
            if (userId == loggedInUserId) {

                xmlFile.FindElem("ID");
                int id = atoi(MCD_2PCSZ(xmlFile.GetData()));

                xmlFile.FindElem("DATE");
                string date = xmlFile.GetData();

                xmlFile.FindElem("AMOUNT");
                double amount = atof(MCD_2PCSZ(xmlFile.GetData()));

                xmlFile.FindElem("GROUP");
                string group = xmlFile.GetData();

                income.setId(id);
                income.setUserId(userId);
                income.setDate(DateManager::converseDateToInt(date));
                income.setAmount(amount);
                income.setGroup(group);

                incomesVector.push_back(income);
            }
            xmlFile.OutOfElem();
        }
    }
    else cout << "incomes list is empty" ;
    return incomesVector;
}


int IncomesFile::getNumberOfIncomesInFile() {
    CMarkup xmlFile;
    xmlFile.Load(getFilename());
    xmlFile.ResetMainPos();
    int numberOfIncomes = 0;

    if (xmlFile.FindElem("INCOMES")) {
        xmlFile.IntoElem();
        while(xmlFile.FindElem("INCOME")) {
            numberOfIncomes++;
        }
    }

    return numberOfIncomes;
}
