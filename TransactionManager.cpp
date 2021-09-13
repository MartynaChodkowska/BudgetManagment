#include "TransactionManager.h"


Transaction TransactionManager::giveNewTransactionData(string type) {
    Transaction transaction;
    char selection;
    string date = "";

    do {
        selection = SupportingMethods::selectOptionFromDateMenu();
        if (selection == '1') {
            date = SupportingMethods::getCurrentDate();
            cout << "transaction date: " << date << endl;
        } else if (selection == '2') {
            cout << "please enter transaction date [yyyy-mm-dd]:";
            date = SupportingMethods::loadLine();
        }
    } while(!SupportingMethods::isDateCorrect(date));

    string amountFromUser = "";
    cout << "enter transaction amount [0.00]: ";
    amountFromUser = SupportingMethods::loadLine();
    double amount = SupportingMethods::makeDoubleAmount(amountFromUser);


    string item = "";
    cout << "enter transaction group: ";
    item = SupportingMethods::loadLine();

    transaction.setId(getNewTransactionId(type));
    transaction.setUserId(LOGGDED_IN_USER_ID);
    transaction.setDate(SupportingMethods::converseDateToInt(date));
    transaction.setItem(item);
    transaction.setAmount(amount);

    return transaction;
}

int TransactionManager::getNewTransactionId(string type) {
    int numberOfTransaction = 0;
    if (type == "income")
        numberOfTransaction = incomesFile.getNumberOfTransactionsInFile();
    else
        numberOfTransaction = expensesFile.getNumberOfTransactionsInFile();
    return numberOfTransaction + 1;
}

vector<Transaction> TransactionManager::findIncomesFromMonth(int startDate, int endDate) {
    int transactionDate = 0;
    vector<Transaction> transactionsFromPeriod;

    for(int i = 0; i < incomes.size(); i++) {
        transactionDate = incomes[i].getDate();
        if (transactionDate >= startDate && transactionDate <= endDate) {
            transactionsFromPeriod.push_back(incomes[i]);
        }
    }
    return transactionsFromPeriod;
}

vector<Transaction> TransactionManager::findExpensesFromMonth(int startDate, int endDate) {
    int transactionDate = 0;
    vector<Transaction> transactionsFromPeriod;

    for(int i = 0; i < expenses.size(); i++) {
        transactionDate = expenses[i].getDate();
        if (transactionDate >= startDate && transactionDate <= endDate) {
            transactionsFromPeriod.push_back(expenses[i]);
        }
    }
    return transactionsFromPeriod;
}


void TransactionManager::displayIncomes(vector<Transaction> incomesToDisplay) {
    double totalIncomes = 0;
    cout << ">>>> INCOMES <<<<" << endl;
    if (!incomesToDisplay.empty()) {
        for(int i = 0; i < incomesToDisplay.size(); i++) {
            cout << "date: " << SupportingMethods::converseDateToString(incomesToDisplay[i].getDate()) << " ";
            cout << showpoint << setprecision (SupportingMethods::countNumbers(incomesToDisplay[i].getAmount())+2);
            cout << "group: " << incomesToDisplay[i].getItem() << "\t\t";
            cout << "amount: " << incomesToDisplay[i].getAmount() << endl;

            totalIncomes += incomesToDisplay[i].getAmount();
        }
    } else
        cout << "there is no transaction";

    cout << endl << endl;
    totalIncomesAmount = totalIncomes;
}

void TransactionManager::displayExpenses(vector<Transaction> expensessToDisplay) {
    double totalExpenses = 0;

    cout << ">>>> EXPENSES <<<<" << endl;
    if(!expensessToDisplay.empty()) {
        for(int i = 0; i < expensessToDisplay.size(); i++) {
            cout << "date: " << SupportingMethods::converseDateToString(expensessToDisplay[i].getDate()) << " ";
            cout << showpoint << setprecision (SupportingMethods::countNumbers(expensessToDisplay[i].getAmount())+2);
            cout << "group: " << expensessToDisplay[i].getItem() << "\t\t";
            cout << "amount: " << expensessToDisplay[i].getAmount() << endl;

            totalExpenses += expensessToDisplay[i].getAmount();
        }
    } else
        cout << "there is no transaction";

    cout << endl << endl;
    totalExpensesAmount = totalExpenses;
}

void TransactionManager::displayBalance() {
    cout << showpoint << setprecision (SupportingMethods::countNumbers(totalIncomesAmount)+2);
    cout << "total Incomes:\t" << totalIncomesAmount << endl;
    cout << showpoint << setprecision (SupportingMethods::countNumbers(totalExpensesAmount)+2);
    cout << "total Expenses:\t" << totalExpensesAmount << endl;
    double balanace = totalIncomesAmount - totalExpensesAmount;
    cout << showpoint << setprecision (SupportingMethods::countNumbers(balanace)+2);
    cout <<  "final Balance:\t" << balanace << endl << endl;
    system("pause");
}

void TransactionManager::displayTransactionsFromSelectedMonths(int startDate, int endDate) {
    vector<Transaction> incomes = findIncomesFromMonth(startDate, endDate);
    sort (incomes.begin(), incomes.end());
    vector<Transaction> expenses = findExpensesFromMonth(startDate, endDate);
    sort (expenses.begin(), expenses.end());

    system("cls");
    displayIncomes(incomes);
    displayExpenses(expenses);
    displayBalance();
}

void TransactionManager::addIncome() {

    system("cls");
    cout << ">>>>  adding INCOME transaction  <<<<" << endl << endl;
    Transaction income = giveNewTransactionData("income");

    incomesFile.addTransactionToFile(income);
    incomes.push_back(income);

    cout << endl << "income had been saved" << endl << endl;
    system("pause");
}

void TransactionManager::addExpense() {

    system("cls");
    cout << ">>>>  adding EXPENSE transaction  <<<<" << endl << endl;
    Transaction expense = giveNewTransactionData("expense");

    expensesFile.addTransactionToFile(expense);
    expenses.push_back(expense);

    cout << endl << "expense had been saved" << endl << endl;
    system("pause");
}

void TransactionManager::displayTransactionsFromCurrentMonth() {
    string date = SupportingMethods::getCurrentDate();
    int startDate =0, endDate = 0, currentDate = SupportingMethods::converseDateToInt(date);
    int numberOfDaysInMonth = SupportingMethods::getNumberOfDaysInMonth(SupportingMethods::getMonthFromCurrentDate(), SupportingMethods::getYearFromCurrentDate());

    startDate = currentDate - currentDate%100 + 1;
    endDate = currentDate - currentDate%100 + numberOfDaysInMonth;

    displayTransactionsFromSelectedMonths(startDate, endDate);
}

void TransactionManager::displayTransactionsFromPreviousMonth() {
    string date = SupportingMethods::getCurrentDate();
    int startDate =0, endDate = 0, currentDate = SupportingMethods::converseDateToInt(date);
    int numberOfDaysInMonth = SupportingMethods::getNumberOfDaysInMonth(SupportingMethods::getMonthFromCurrentDate()-1, SupportingMethods::getYearFromCurrentDate());

    startDate = currentDate - currentDate%100 - 100 + 1;
    endDate = currentDate - currentDate%100 - 100 + numberOfDaysInMonth;

    displayTransactionsFromSelectedMonths(startDate, endDate);
}

void TransactionManager::displayTransactionsFromSelectedPeriod() {
    string date = "";
    int startDateInteger = 0, endDateInteger = 0;
    int startMonth = 0, startYear = 0, endMonth = 0, endYear = 0;
    int displayingMonth = 0, displayingYear = 0;
    int numberOfMonths = 0;

    do {
        cout << "please enter starting date [yyyy-mm-dd]:";
        date = SupportingMethods::loadLine();
    } while(!SupportingMethods::isDateCorrect(date));

    startDateInteger = SupportingMethods::converseDateToInt(date);
    startMonth = SupportingMethods::getMonthFromCustomDate(startDateInteger);
    startYear = SupportingMethods::getYearFromCustomDate(startDateInteger);

    do {
        cout << "please enter ending date [yyyy-mm-dd]:";
        date = SupportingMethods::loadLine();
    } while(!SupportingMethods::isDateCorrect(date));

    endDateInteger = SupportingMethods::converseDateToInt(date);
    endMonth = SupportingMethods::getMonthFromCustomDate(endDateInteger);
    endYear = SupportingMethods::getYearFromCustomDate(endDateInteger);

    if ((endYear < startYear) || (endMonth < startMonth&& endYear == startYear)) {
        cout << "selected period is wrong.." << endl;
        system("pause");
    }

    displayTransactionsFromSelectedMonths(startDateInteger, endDateInteger);
}
