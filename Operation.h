#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation {
    int id, userId;
    string date;
    double amount;

public:
    //Operation();
    int getId();
    int getUserId(); //is it necessary?
    string getDate();
    double getAmount();

    void setId(int newId);
    void setUserId(int newUserId); //is it necessary?
    void setDate(string newDate);
    void setAmount(double newAmount);
};


#endif // OPERATION_H
