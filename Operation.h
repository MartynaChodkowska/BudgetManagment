#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation {
    int id, userId, date;
    double amount;

public:
    bool operator< (const Operation &other) const{
    return date < other.date;
    }
    int getId();
    int getUserId(); //is it necessary?
    int getDate();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId); //is it necessary?
    void setDate(int newDate);
    void setAmount(double newAmount);
};


#endif // OPERATION_H
