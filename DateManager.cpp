#include "DateManager.h"

int DateManager::getYearFromCustomDate(int date) {
    int temp = date%10000;
    int year = (date - temp)/10000;

    return year;
}

int DateManager::getMonthFromCustomDate(int date) {
    int temp = date%100;
    int month = (date-temp)/100;
    month = month%100;

    return month;
}

int DateManager::getDayFromCustomDate(int date) {

    return date%100;
}

string DateManager::converseDateToString(int dateToConvert) {
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


int DateManager::converseDateToInt(string dateToConvert) {
    int dateInt = 0;

    dateToConvert = dateToConvert.erase(4,1);
    dateToConvert = dateToConvert.erase(6,1);
    dateInt = SupportingMethods::conversionFromStringToInt(dateToConvert);

    return dateInt;
}

bool DateManager::isDateCorrect(string dateToBeChecked) {
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

string DateManager::getCurrentDate() {
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

int DateManager::getYearFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%Y", &actualTimeTM);

    return atoi(bufor);
}

int DateManager::getMonthFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%m", &actualTimeTM);

    return atoi(bufor);
}

int DateManager::getDayFromCurrentDate() {
    time_t actualTime;
    time(&actualTime);
    tm actualTimeTM = * localtime (&actualTime);

    char bufor [64];
    strftime(bufor, sizeof(bufor), "%d", &actualTimeTM);

    return atoi(bufor);
}

int DateManager::getNumberOfDaysInMonth(int month, int year) {
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        return 31;
    else if (month==4 || month==6 || month==9 || month==11)
        return 30;
    else if (month == 2)
        if(isYearIntercalary(year))
            return 29;
        else return 28;
}

bool DateManager::isYearIntercalary(int year) {
    if (((year%4 == 0) && (year%100 != 0)) || year%400 == 0) {
        return true;
    } else {
        return false;
    }
}
