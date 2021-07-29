#ifndef OPERATION_H
#define OPERARTION_H

#include <iostream>

using namespace std;

class Operation{
int id;
string date, amount;

public:
    int getId();
    string getDate();
    string getAmount();

    void setId(int newId);
    void setDate(string newDate);
    void setAmount(string newAmount);
};


#endif // OPERATION_H
