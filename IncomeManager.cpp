#include "IncomeManager.h"

void IncomeManager::addIncome() {

    Income income = giveNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << endl << "income had beed saved" << endl << endl;
    system("pause");

}



Income IncomeManager::giveNewIncomeData() {
    Income income;

    string incomeDate;
    cout << "please enter income date [yyyy-mm-dd]/[if today select 'T']: ";
    incomeDate = SupportingMethods::loadLine();

    double incomeAmount;
    cout << "enter income amount [0.0]: ";
    incomeAmount = SupportingMethods::loadDouble();

    string incomeGroup;
    cout << "enter income group: ";
    incomeGroup = SupportingMethods::loadLine();

    income.setId(getNewIncomeId());
    income.setUserId(LOGGDED_IN_USER_ID);
    income.setDate(incomeDate);
    income.setAmount(incomeAmount);
    income.setGroup(incomeGroup);

    return income;
}


int IncomeManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else {
        return incomes.back().getId()+1;
    }
}
