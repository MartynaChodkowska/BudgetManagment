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
