#ifndef SUPORTINGMETHODS_H
#define SUPORTINGMETHODS_H

#include <iostream>
#include <sstream>

#include "Markup.h"

using namespace std;

class SupportingMethods {

public:
    static char loadCharacter();
    static string loadLine();
    static int loadInteger();
    static double loadDouble();
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
    static int conversionFromStringToInt(string number);
    static string conversionFromIntToString(int number);
   /* static string dateToString(int date);
    static int dateToInt(string date);
*/
    static double calculateDifferenceBetweenIncomesAndExpenses();
};



#endif // SUPORTINGMETHODS_H
