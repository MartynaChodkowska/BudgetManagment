#include "TransactionManager.h"

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

    double amount;
    cout << "enter transaction amount [0.00]: ";
    amount = SupportingMethods::loadDouble();
    //sprawdzanie czy z kropka, jesli nie (przecinek) - zamiana na kropke

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

vector<Transaction> TransactionManager::findIncomesFromMonth(int month, int year, int numberOfMonths) {
    int monthFromTransaction = 0, yearFromTransaction = 0;
    vector<Transaction> transactionsFromPeriod;

    for (int j = 0; j <= numberOfMonths; j++) {
        for(int i = 0; i < incomes.size(); i++) {
            monthFromTransaction = SupportingMethods::getMonthFromCustomDate(incomes[i].getDate());
            yearFromTransaction = SupportingMethods::getYearFromCustomDate(incomes[i].getDate());
            if (monthFromTransaction == month && yearFromTransaction == year) {
                transactionsFromPeriod.push_back(incomes[i]);
            }
        }
        if (month < 12)
            month++;
        else {
            year++;
            month = 1;
        }
    }

    return transactionsFromPeriod;
}

vector<Transaction> TransactionManager::findExpensesFromMonth(int month, int year, int numberOfMonths) {
    int monthFromTransaction = 0, yearFromTransaction = 0;
    vector<Transaction> transactionsFromPeriod;

    for (int j = 0; j <= numberOfMonths; j++) {
        for(int i = 0; i < expenses.size(); i++) {
            monthFromTransaction = SupportingMethods::getMonthFromCustomDate(expenses[i].getDate());
            yearFromTransaction = SupportingMethods::getYearFromCustomDate(expenses[i].getDate());
            if (monthFromTransaction == month && yearFromTransaction == year) {
                transactionsFromPeriod.push_back(expenses[i]);
            }
        }
        if (month < 12)
            month++;
        else {
            year++;
            month = 1;
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
            cout << "amount: " << incomesToDisplay[i].getAmount() << "\t";
            cout << "group: " << incomesToDisplay[i].getItem() << endl;
            totalIncomes += incomesToDisplay[i].getAmount();
        }
    } else
        cout << "there is no transaction this month";

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
            cout << "amount: " << expensessToDisplay[i].getAmount() << "\t";
            cout << "group: " << expensessToDisplay[i].getItem() << endl;
            totalExpenses += expensessToDisplay[i].getAmount();
        }
    } else
        cout << "there is no transaction this month";

    cout << endl << endl;
    totalExpensesAmount = totalExpenses;
}

void TransactionManager::displayBalance() {
    cout << showpoint << setprecision (SupportingMethods::countNumbers(totalIncomesAmount)+2);
    cout << "total Incomes:\t" << totalIncomesAmount << endl;
    cout << showpoint << setprecision (SupportingMethods::countNumbers(totalExpensesAmount)+2);
    cout << "total Expenses:\t" << totalExpensesAmount << endl;
    cout << showpoint << setprecision (SupportingMethods::countNumbers(totalIncomesAmount)+2);
    cout <<  "final Balance:\t" << totalIncomesAmount - totalExpensesAmount << endl << endl;
    system("pause");
}

void TransactionManager::displayTransactionsFromSelectedMonth(int startMonth, int startYear, int numberOfMonths) {
    vector<Transaction> incomes = findIncomesFromMonth(startMonth, startYear, numberOfMonths);
    sort (incomes.begin(), incomes.end());
    vector<Transaction> expenses = findExpensesFromMonth(startMonth, startYear, numberOfMonths);
    sort (expenses.begin(), expenses.end());

    system("cls");
    displayIncomes(incomes);
    displayExpenses(expenses);
    displayBalance();
}

void TransactionManager::displayTransactionsFromCurrentMonth() {
    displayTransactionsFromSelectedMonth(SupportingMethods::getMonthFromCurrentDate(),SupportingMethods::getYearFromCurrentDate(), 1);
}

void TransactionManager::displayTransactionsFromPreviousMonth() {
    displayTransactionsFromSelectedMonth(SupportingMethods::getMonthFromCurrentDate()-1,SupportingMethods::getYearFromCurrentDate(), 1);
}

void TransactionManager::displayTransactionsFromSelectedPeriod() {
    string date = "";
    int startDateInteger = 0, endDateInteger = 0;
    int startMonth = 0, startYear = 0, endMonth = 0, endYear = 0;
    int displayingMonth = 0, displayingYear = 0;
    int numberOfMonths = 0;

    do {
        cout << "please enter starting date [yyyy-mm]:";
        date = SupportingMethods::loadLine();
        date+="-01";
    } while(!SupportingMethods::isDateCorrect(date));

    startDateInteger = SupportingMethods::converseDateToInt(date);
    startMonth = SupportingMethods::getMonthFromCustomDate(startDateInteger);
    startYear = SupportingMethods::getYearFromCustomDate(startDateInteger);

    do {
        cout << "please enter ending date [yyyy-mm]:";
        date = SupportingMethods::loadLine();
        date+="-01";
    } while(!SupportingMethods::isDateCorrect(date));

    endDateInteger = SupportingMethods::converseDateToInt(date);
    endMonth = SupportingMethods::getMonthFromCustomDate(endDateInteger);
    endYear = SupportingMethods::getYearFromCustomDate(endDateInteger);


    if ((endYear < startYear) || (endMonth < startMonth&& endYear == startYear)) {
        cout << "selected period is wrong.." << endl;
        system("pause");
    } else
        numberOfMonths = (endDateInteger-startDateInteger)/100;
    displayTransactionsFromSelectedMonth(startMonth, startYear, numberOfMonths);

}
