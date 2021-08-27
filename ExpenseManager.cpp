#include "ExpenseManager.h"

void ExpenseManager::addExpense() {

    Expense expense = giveNewExpenseData();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout << endl << "expense had been saved" << endl << endl;
    system("pause");

}



Expense ExpenseManager::giveNewExpenseData() {
    Expense expense;
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
        }

    } while(!DateManager::isDateCorrect(date));

    double amount;
    cout << "enter expense amount [0.00]: ";
    amount = SupportingMethods::loadDouble();

    string group;
    cout << "enter expense group: ";
    group = SupportingMethods::loadLine();

    expense.setId(getNewExpenseId());
    expense.setUserId(LOGGDED_IN_USER_ID);
    expense.setDate(DateManager::converseDateToInt(date));
    expense.setAmount(amount);
    expense.setGroup(group);

    return expense;
}


int ExpenseManager::getNewExpenseId() {
    int numberOfExpenses = expensesFile.getNumberOfExpensesInFile();
    return numberOfExpenses + 1;
}

vector<Expense> ExpenseManager::findExpensesFromMonth(int month, int year) {
    int monthFromExpense = 0, yearFromExpense = 0;
    vector<Expense> expensesFromMonth;

    for(int i = 0; i < expenses.size(); i++) {
        monthFromExpense = DateManager::getMonthFromCustomDate(expenses[i].getDate());
        yearFromExpense = DateManager::getYearFromCustomDate(expenses[i].getDate());
        if (monthFromExpense == month && yearFromExpense == year) {
            expensesFromMonth.push_back(expenses[i]);
        }
    }
    return expensesFromMonth;
}

vector<Expense> ExpenseManager::sortExpenses(vector<Expense> expensesToSort) {
    sort (expensesToSort.begin(), expensesToSort.end());

    return expensesToSort;
}

vector<Expense> ExpenseManager::getExpensesToDisplay(int monthToDisplay, int yearToDisplay) {
    vector<Expense> expenses = findExpensesFromMonth(monthToDisplay, yearToDisplay);
    expenses = sortExpenses(expenses);

    return expenses;
}

double ExpenseManager::calculateTotalExpensesAmount (vector<Expense> expenses) {
    double totalAmount = 0;
    for(int i = 0; i < expenses.size(); i++) {
        totalAmount += expenses[i].getAmount();
    }
    totalExpenses = totalAmount;

    return totalAmount;
}


void ExpenseManager::displayExpensesFromSelectedMonth(int monthToDisplay, int yearToDisplay) {

    vector<Expense> expenses = getExpensesToDisplay(monthToDisplay, yearToDisplay);
    cout << ">>>> EXPENSES <<<<" << endl << endl;
    cout << "related to month & year " << endl; // add supporting method which converse monthToDisplay&yearToDisplay to string

    for(int i = 0; i < expenses.size(); i++) {
        cout << "date: " << DateManager::converseDateToString(expenses[i].getDate()) << " ";
        cout << showpoint << setprecision (SupportingMethods::countNumbers(expenses[i].getAmount())+2);
        cout << "amount: " << expenses[i].getAmount() << "\t";
        cout << "group: " << expenses[i].getGroup() << endl;
    }

}

void ExpenseManager::displayExpensesFromCurrentMonth() {
    displayExpensesFromSelectedMonth(DateManager::getMonthFromCurrentDate(),DateManager::getYearFromCurrentDate());
    system ("pause");
}

