#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Operation.h"

using namespace std;

class Expense :public Operation{
    string group;
public:
   // Expense() : Operation(){};
    string getGroup();
    void setGroup(string newGroup);
};


#endif // EXPENSE_H
