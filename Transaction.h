#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction {
    int id, userId, date;
    string item;
    double amount;

public:
    //Transaction(int newId, int newUserId, int, double, string);
    bool operator< (const Transaction &other) const {
        return date < other.date;
    }
    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};


#endif // TRANSACTION_H
