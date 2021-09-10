#ifndef SUPORTINGMETHODS_H
#define SUPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Markup.h"
#include <time.h>
#include <ctime>

using namespace std;

class SupportingMethods {
    static int getDayFromCustomDate(int date);
    static int getDayFromCurrentDate();
    static int getNumberOfDaysInMonth(int month, int year);
    static bool isYearIntercalary(int year);
public:
   // SupportingMethods() {    }
    static string getCurrentDate();
    static int converseDateToInt(string operationDate);
    static string converseDateToString(int operationDate);
    static bool isDateCorrect(string operatioDate);
    static int getMonthFromCustomDate(int date);
    static int getMonthFromCurrentDate();
    static int getYearFromCustomDate(int date);
    static int getYearFromCurrentDate();

    static char loadCharacter();
    static string loadLine();
    static int loadInteger();
    static double loadDouble();
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
    static char selectOptionFromDateMenu();
    static int conversionFromStringToInt(string number);
    static string conversionFromIntToString(int number);
    static string converseAmountToShortString(double amount);
    static int countNumbers(int number);

};



#endif // SUPORTINGMETHODS_H
