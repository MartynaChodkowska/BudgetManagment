#include "TransactionManager.h"

void TransactionManager::addTransaction(string transactionType) {

    system("cls");
    cout << "\t>>>>  adding " << transactionType << " transaction  <<<<" << endl << endl;
    Transaction transaction = giveNewTransactionData();
    transaction.setType(transactionType);

    transactions.push_back(transaction);
    transactionsFile.addTransactionToFile(transaction);

    cout << endl << "transaction had been saved" << endl << endl;
    system("pause");

}

Transaction TransactionManager::giveNewTransactionData() {
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

    string group;
    cout << "enter transaction group: ";
    group = SupportingMethods::loadLine();

    transaction.setId(getNewTransactionId());
    transaction.setUserId(LOGGDED_IN_USER_ID);
    transaction.setDate(SupportingMethods::converseDateToInt(date));
    transaction.setAmount(amount);
    transaction.setGroup(group);

    return transaction;
}


int TransactionManager::getNewTransactionId() {
    int numberOfTransaction = transactionsFile.getNumberOfTransactionsInFile();
    return numberOfTransaction + 1;
}

vector<Transaction> TransactionManager::findTransactionsFromMonth(int month, int year) {
    int monthFromTransaction = 0, yearFromTransaction = 0;
    vector<Transaction> transactionsFromMonth;

    for(int i = 0; i < transactions.size(); i++) {
        monthFromTransaction = SupportingMethods::getMonthFromCustomDate(transactions[i].getDate());
        yearFromTransaction = SupportingMethods::getYearFromCustomDate(transactions[i].getDate());
        if (monthFromTransaction == month && yearFromTransaction == year) {
            transactionsFromMonth.push_back(transactions[i]);
        }
    }
    return transactionsFromMonth;
}

vector<Transaction> TransactionManager::sortTransactions(vector<Transaction> transactionsToSort) {
    sort (transactionsToSort.begin(), transactionsToSort.end());

    return transactionsToSort;
}

vector<Transaction> TransactionManager::getTransactionsToDisplay(int monthToDisplay, int yearToDisplay) {
    vector<Transaction> transactions = findTransactionsFromMonth(monthToDisplay, yearToDisplay);
    transactions = sortTransactions(transactions);

    return transactions;
}

void TransactionManager::displayIncomes(vector<Transaction> incomesToDisplay) {
    double totalIncomes = 0;
    cout << ">>>> INCOMES <<<<" << endl;
    //cout << "related to month & year " << endl; // add supporting method which converse monthToDisplay&yearToDisplay to string
    if (!incomesToDisplay.empty()) {
        for(int i = 0; i < incomesToDisplay.size(); i++) {
            cout << "date: " << SupportingMethods::converseDateToString(incomesToDisplay[i].getDate()) << " ";
            cout << showpoint << setprecision (SupportingMethods::countNumbers(incomesToDisplay[i].getAmount())+2);
            cout << "amount: " << incomesToDisplay[i].getAmount() << "\t";
            cout << "group: " << incomesToDisplay[i].getGroup() << endl;
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
    // cout << "related to month & year " << endl; // add supporting method which converse monthToDisplay&yearToDisplay to string
    if(!expensessToDisplay.empty()) {
        for(int i = 0; i < expensessToDisplay.size(); i++) {
            cout << "date: " << SupportingMethods::converseDateToString(expensessToDisplay[i].getDate()) << " ";
            cout << showpoint << setprecision (SupportingMethods::countNumbers(expensessToDisplay[i].getAmount())+2);
            cout << "amount: " << expensessToDisplay[i].getAmount() << "\t";
            cout << "group: " << expensessToDisplay[i].getGroup() << endl;
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

void TransactionManager::displayTransactionsFromSelectedMonth(int monthToDisplay, int yearToDisplay) {
    vector<Transaction> transactions = getTransactionsToDisplay(monthToDisplay, yearToDisplay);
    vector<Transaction> expenses, incomes;

    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getType() == "INCOME")
            incomes.push_back(transactions[i]);
        else if (transactions[i].getType() == "EXPENSE")
            expenses.push_back(transactions[i]);
        else {
            cout << "there is no such type of transaction.." << endl;
            system("pause");
        }
    }
    system("cls");
    displayIncomes(incomes);
    displayExpenses(expenses);
    displayBalance();
}

void TransactionManager::displayTransactionsFromCurrentMonth() {
    displayTransactionsFromSelectedMonth(SupportingMethods::getMonthFromCurrentDate(),SupportingMethods::getYearFromCurrentDate());
}

