#include "Date.h"

int Date::getDay() {
    return day;
}
int Date::getMonth() {
    return month;
}
int Date::getYear() {
    return year;
}

void Date::setDay(int newDay) {
    day = newDay;
}
void Date::setMonth(int newMonth) {
    month = newMonth;
}
void Date::setYear(int newYear) {
    year = newYear;
}
