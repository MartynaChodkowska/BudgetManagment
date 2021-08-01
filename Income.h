#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Operation.h"

using namespace std;

class Income :public Operation{
    string group;
public:
   // Income() : Operation(){};
    string getGroup();
    void setGroup(string newGroup);
};


#endif // INCOME_H
