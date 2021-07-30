#ifndef SUPORTINGMETHODS_H
#define SUPORTINGMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class SupportingMethods {

public:
    static char loadCharacter();
    static string loadLine();
    static int loadInteger();
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();
    static int conversionFromStringToInt();
    static string conversionFromIntToString(int number);
    static double calculateDifferenceBetweenIncomesAndExpenses();


};



#endif // SUPORTINGMETHODS_H
