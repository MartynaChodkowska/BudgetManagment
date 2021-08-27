#ifndef SUPORTINGMETHODS_H
#define SUPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Markup.h"

using namespace std;

class SupportingMethods {
  // double totalIncomes;
  //  double totalExpenses;
public:
    SupportingMethods() {
    }
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
