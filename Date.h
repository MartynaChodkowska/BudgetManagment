#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
int day, month, year;

public:
    int getDay();
    int getMonth();
    int getYear();

    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);

};

#endif
