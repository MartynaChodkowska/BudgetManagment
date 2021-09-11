#include "Transaction.h"

int Transaction::getId() {
    return id;
}

int Transaction::getUserId() {
    return userId;
}

int Transaction::getDate() {
    return date;
}

double Transaction::getAmount() {
    return amount;
}

string Transaction::getGroup() {
    return group;
}

string Transaction::getType() {
    return type;
}

void Transaction::setId(int newId) {
    id = newId;
}

void Transaction::setUserId(int newUserId) {
    userId = newUserId;
}


void Transaction::setDate(int newDate) {
    date = newDate;
}
void Transaction::setAmount(double newAmount) {
    amount = newAmount;
}

void Transaction::setGroup(string newGroup) {
    group = newGroup;
}

void Transaction::setType(string newType) {
    type = newType;
}
