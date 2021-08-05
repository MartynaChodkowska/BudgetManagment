#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <time.h>
#include <ctime>

#include "SupportingMethods.h"

using namespace std;

class DateManager {
    static int getYearFromCustomDate(int date);
    static int getMonthFromCustomDate(int date);
    static int getDayFromCustomDate(int date);
    static int getYearFromCurrentDate();
    static int getMonthFromCurrentDate();
    static int getDayFromCurrentDate();
    static int getNumberOfDaysInMonth(int month, int year);
    static bool isYearIntercalary(int year);

  //  static int converseCurrentDateToInt();

public:
    static string getCurrentDate();
    static int converseDateToInt(string operationDate);
    static string converseDateToString(int operationDate);
    static bool isDateCorrect(string operatioDate);
};

#endif // DATEMANAGER_H
