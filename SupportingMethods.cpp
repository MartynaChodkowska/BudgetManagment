#include "SupportingMethods.h"

int SupportingMethods::getDayFromCustomDate(int date) {

    return date%100;
}

int SupportingMethods::getDayFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%d", &actualTimeTM);

    return atoi(bufor);
}

int SupportingMethods::getNumberOfDaysInMonth(int month, int year) {
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        return 31;
    else if (month==4 || month==6 || month==9 || month==11)
        return 30;
    else if (month == 2)
        if(isYearIntercalary(year))
            return 29;
        else return 28;
}

bool SupportingMethods::isYearIntercalary(int year) {
    if (((year%4 == 0) && (year%100 != 0)) || year%400 == 0) {
        return true;
    } else {
        return false;
    }
}

string SupportingMethods::getCurrentDate() {
    string date = "";

    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%Y", &actualTimeTM);
    date += bufor;
    date += '-';
    strftime(bufor, sizeof(bufor), "%m", &actualTimeTM);
    date += bufor;
    date += '-';
    strftime(bufor, sizeof(bufor), "%d", &actualTimeTM);
    date += bufor;

    return date;
}

int SupportingMethods::converseDateToInt(string dateToConvert) {
    int dateInt = 0;

    dateToConvert = dateToConvert.erase(4,1);
    dateToConvert = dateToConvert.erase(6,1);
    dateInt = SupportingMethods::conversionFromStringToInt(dateToConvert);

    return dateInt;
}

string SupportingMethods::converseDateToString(int dateToConvert) {
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


bool SupportingMethods::isDateCorrect(string dateToBeChecked) {
    int date = 0, year = 0, month = 0, day = 0;
    date = converseDateToInt(dateToBeChecked);
    year = getYearFromCustomDate(date);
    month = getMonthFromCustomDate(date);
    day = getDayFromCustomDate(date);

    if (dateToBeChecked.size() != 10) {
        cout << "date format is wrong. try again." << endl;
        return false;
    } else if (year > getYearFromCurrentDate() || year < 0) {
        cout << "this is a future year. try again." << endl;
        return false;
    } else if (month < 0 || month > 12) {
        cout << "there is no such month. try again." << endl;
        return false;
    } else if (day < 0 || day > getNumberOfDaysInMonth(month, year)) {
        cout << "month " << month << " has " << getNumberOfDaysInMonth(month, year) << " days. Try again." << endl;
        return false;
    } else if (year == getYearFromCurrentDate() && (month > getMonthFromCurrentDate())) {
        cout << "this date is in the future. try again." << endl;
        return false;
    } else if (year == getYearFromCurrentDate() && (month == getMonthFromCurrentDate() && day > getDayFromCurrentDate())) {
        cout << "this date is in the future. try again." << endl;
        return false;
    } else
        return true;
}

int SupportingMethods::getMonthFromCustomDate(int date) {
    int temp = date%100;
    int month = (date-temp)/100;
    month = month%100;

    return month;
}

int SupportingMethods::getMonthFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%m", &actualTimeTM);

    return atoi(bufor);
}

int SupportingMethods::getYearFromCustomDate(int date) {
    int temp = date%10000;
    int year = (date - temp)/10000;

    return year;
}

int SupportingMethods::getYearFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%Y", &actualTimeTM);

    return atoi(bufor);
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

char SupportingMethods::selectOptionFromDateMenu() {
    char selection;

    cout << "please enter operation date - select option:" << endl;
    cout << "1. Current date" << endl;
    cout << "2. Custom date" << endl;
    selection = loadCharacter();

    return selection;
}

int SupportingMethods::conversionFromStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportingMethods::conversionFromIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportingMethods::converseAmountToShortString(double amount) {
    string shortAmount = to_string(amount);
    size_t found = shortAmount.find(".");

    if (found != string::npos)
        shortAmount = shortAmount.substr(0,found+3);

    return shortAmount;
}

int SupportingMethods::countNumbers(int number) {
    int amountOfNumbers =0, temp = 0;
    do {
        temp = number%10;
        number -=temp;
        number= number/10;
        amountOfNumbers ++;
    } while (number !=0);
    return amountOfNumbers;
}
