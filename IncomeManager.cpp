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
    do {
        selection = SupportingMethods::selectOptionFromDateMenu();
        if (selection == '1') {
            date = DateManager::getCurrentDate();
            cout << "operation date: " << date << endl;
        } else if (selection == '2') {
            cout << "please enter operation date [yyyy-mm-dd]:";
            date = SupportingMethods::loadLine();
        } else
            cout << "there is no such option... try again" << endl;
    } while(!DateManager::isDateCorrect(date));


    double amount;
    cout << "enter income amount [0.00]: ";
    amount = SupportingMethods::loadDouble();
    //sprawdz czy kropka czy przecinek

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

vector<Income> IncomeManager::findIncomesFromMonth(int month, int year) {
    int monthFromIncome = 0, yearFromIncome = 0;
    vector<Income> IncomesFromMonth;

    for(int i = 0; i < incomes.size(); i++) {
        monthFromIncome = DateManager::getMonthFromCustomDate(incomes[i].getDate());
        yearFromIncome = DateManager::getYearFromCustomDate(incomes[i].getDate());
        if (monthFromIncome == month && yearFromIncome == year) {
            IncomesFromMonth.push_back(incomes[i]);
        }
    }
    return IncomesFromMonth;
}

vector<Income> IncomeManager::sortIncomes(vector<Income> incomesToSort) {
    sort (incomesToSort.begin(), incomesToSort.end());

    return incomesToSort;
}

vector<Income> IncomeManager::getIncomesToDisplay(int monthToDisplay, int yearToDisplay) {
    vector<Income> incomes = findIncomesFromMonth(monthToDisplay, yearToDisplay);
    incomes = sortIncomes(incomes);

    return incomes;
}

double IncomeManager::displayIncomesFromSelectedMonth(int monthToDisplay, int yearToDisplay) {
    double totalIncomes = 0;
    vector<Income> incomes = getIncomesToDisplay(monthToDisplay, yearToDisplay);
    system("cls");
    cout << ">>>> INCOMES <<<<" << endl << endl;
    cout << "related to month & year " << endl; // add supporting method which converse monthToDisplay&yearToDisplay to string

    for(int i = 0; i < incomes.size(); i++) {
        cout << "date: " << DateManager::converseDateToString(incomes[i].getDate()) << " ";
        cout << showpoint << setprecision (SupportingMethods::countNumbers(incomes[i].getAmount())+2);
        cout << "amount: " << incomes[i].getAmount() << "\t";
        cout << "group: " << incomes[i].getGroup() << endl;
        totalIncomes += incomes[i].getAmount();
    }
    return totalIncomes;
}

