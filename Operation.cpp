#include "Operation.h"

int Operation::getId() {
    return id;
}
string Operation::getDate() {
    return date;
}
string Operation::getAmount() {
    return amount;
}

void Operation::setId(int newId) {
    id = newId;
}
void Operation::setDate(string newDate) {
    date = newDate;
}
void Operation::setAmount(string newAmount) {
    amount = newAmount;
}
