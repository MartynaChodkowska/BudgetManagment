#include "Operation.h"

int Operation::getId() {
    return id;
}
int Operation::getUserId() {
    return userId;
}
string Operation::getDate() {
    return date;
}
double Operation::getAmount() {
    return amount;
}

void Operation::setId(int newId) {
    id = newId;
}
void Operation::setUserId(int newUserId) {
    userId = newUserId;
}
void Operation::setDate(string newDate) {
    date = newDate;
}
void Operation::setAmount(double newAmount) {
    amount = newAmount;
}
