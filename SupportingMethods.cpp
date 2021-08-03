#include "SupportingMethods.h"

string SupportingMethods::conversionFromIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportingMethods::conversionFromStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char SupportingMethods::loadCharacter() {
    string input = "";
    char sign  = {0};

    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "It is not a single character. Please try again." << endl;
    }
    return sign;
}

string SupportingMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int SupportingMethods::loadInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It is not a number. Please try again. " << endl;
    }
    return number;
}

double SupportingMethods::loadDouble() {
    string input = "";
    double number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It is not a number. Please try again. " << endl;
    }
    return number;

}

char SupportingMethods::selectOptionFromMainMenu() {
    char selection;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Sign In" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = loadCharacter();

    return selection;
}

char SupportingMethods::selectOptionFromUserMenu() {
    char selection;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance sheet (current month)" << endl;
    cout << "4. Display balance sheet (previous month)" << endl;
    cout << "5. Display balance sheet (selected period)" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Password change" << endl;
    cout << "7. Sign out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your selection: ";
    selection = loadCharacter();

    return selection;
}

string SupportingMethods::dateToString(int dateToConvert) {
    string day = "", month = "", year = "", dateString = "";
    int temp = 0;

    temp = dateToConvert%100;
    dateToConvert = dateToConvert/100;
    day = to_string(temp);
    if (day.size() ==1 )
        day = "0" + day;

    temp = dateToConvert%100;
    dateToConvert = dateToConvert/100;
    month = to_string(temp);
    if (month.size() ==1 )
        month = "0" + month;

    year = to_string(dateToConvert);

    dateString = year+"-"+month+"-"+day;
    return dateString;
}

int SupportingMethods::dateToInt(string dateToConvert) {
    int dateInt = 0;

    dateToConvert = dateToConvert.erase(4,1);
    dateToConvert = dateToConvert.erase(6,1);
    dateInt = conversionFromStringToInt(dateToConvert);

    return dateInt;
}
