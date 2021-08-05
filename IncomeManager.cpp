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
    char selection;

    string date = "";
    do{
        selection = SupportingMethods::selectOptionFromDateMenu();
        if (selection == '1') {
            date = DateManager::getCurrentDate();
            cout << "operation date: " << date << endl;
        } else if (selection == '2') {
            cout << "please enter operation date [yyyy-mm-dd]:";
            date = SupportingMethods::loadLine();
        }
    }
    while(!DateManager::isDateCorrect(date));


    double amount;
    cout << "enter income amount [0.00]: ";
    amount = SupportingMethods::loadDouble();

    string group;
    cout << "enter income group: ";
    group = SupportingMethods::loadLine();

    income.setId(getNewIncomeId());
    income.setUserId(LOGGDED_IN_USER_ID);
    income.setDate(DateManager::converseDateToInt(date));
    income.setAmount(amount);
    income.setGroup(group);

    return income;
}

int IncomeManager::getNewIncomeId() {
    int numberOfIncomes = incomesFile.getNumberOfIncomesInFile();
    return numberOfIncomes + 1;
}
