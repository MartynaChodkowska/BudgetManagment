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

    string date;
    do{
            cout << "please enter expense date [yyyy-mm-dd]/[if today select 'T']: ";
    date = SupportingMethods::loadLine();
    }
    while(!DateManager::isDateCorrect(date));

    double amount;
    cout << "enter expense amount [0.0]: ";
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
