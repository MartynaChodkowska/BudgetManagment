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

    string date;
    cout << "please enter income date [yyyy-mm-dd]/[if today select 'T']: ";
    date = SupportingMethods::loadLine();

    double amount;
    cout << "enter income amount [0.0]: ";
    amount = SupportingMethods::loadDouble();

    string group;
    cout << "enter income group: ";
    group = SupportingMethods::loadLine();

    income.setId(getNewIncomeId());
    income.setUserId(LOGGDED_IN_USER_ID);
    income.setDate(SupportingMethods::dateToInt(date));
    income.setAmount(amount);
    income.setGroup(group);

    return income;
}


int IncomeManager::getNewIncomeId() {
  int numberOfIncomes = incomesFile.getNumberOfIncomesInFile();
  return numberOfIncomes + 1;
}
