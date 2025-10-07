#include "expense.h"

Expense::Expense() : description(""), amount(0.0) {}

Expense::Expense(string desc, double amt) : description(desc), amount(amt) {}

string Expense::getDescription() const {
    return description;
}

double Expense::getAmount() const {
    return amount;
}

void Expense::setDescription(string desc) {
    description = desc;
}

void Expense::setAmount(double amt) {
    amount = amt;
}

bool Expense::containsString(string searchStr) const {
    return description.find(searchStr) != string::npos;
}