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
    xmlFile.AddElem("INCOMEID", to_string(income.getId()));
    xmlFile.AddElem("USERID", to_string(income.getUserId()));
    xmlFile.AddElem("DATE", income.getDate());
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

            xmlFile.FindElem("INCOMEID");
            int incomeId = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("USERID");
            int userId = atoi(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("DATE");
            string incomeDate = xmlFile.GetData();

            xmlFile.FindElem("AMOUNT");
            double incomeAmount = atof(MCD_2PCSZ(xmlFile.GetData()));

            xmlFile.FindElem("GROUP");
            string incomeGroup = xmlFile.GetData();

            income.setId(incomeId);
            income.setUserId(userId);
            income.setDate(incomeDate);
            income.setAmount(incomeAmount);
            income.setGroup(incomeGroup);

            incomesVector.push_back(income);

            xmlFile.OutOfElem();
        }
    }
    return incomesVector;
}
