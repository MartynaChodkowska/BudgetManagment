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

    string expenseDate;
    cout << "please enter expense date [yyyy-mm-dd]/[if today select 'T']: ";
    expenseDate = SupportingMethods::loadLine();

    double expenseAmount;
    cout << "enter expense amount [0.0]: ";
    expenseAmount = SupportingMethods::loadDouble();

    string expenseGroup;
    cout << "enter expense group: ";
    expenseGroup = SupportingMethods::loadLine();

    expense.setId(getNewExpenseId());
    expense.setUserId(LOGGDED_IN_USER_ID);
    expense.setDate(expenseDate);
    expense.setAmount(expenseAmount);
    expense.setGroup(expenseGroup);

    return expense;
}


int ExpenseManager::getNewExpenseId() {
      int numberOfExpenses = expensesFile.getNumberOfExpensesInFile();
  return numberOfExpenses + 1;
}
