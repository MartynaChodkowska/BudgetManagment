#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction{
    int id, userId, date;
    double amount;
    string group, type;

public:
    //Transaction(int newId, int newUserId, int, double, string);
    bool operator< (const Transaction &other) const{
    return date < other.date;
    }
    int getId();
    int getUserId(); //is it necessary?
    int getDate();
    double getAmount();
    string getGroup();
    string getType();

    void setId(int newId);
    void setUserId(int newUserId); //is it necessary?
    void setDate(int newDate);
    void setAmount(double newAmount);
    void setGroup(string newGroup);
    void setType(string newType);

};


#endif // TRANSACTION_H
