#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

class Expense {
private:
    string description;
    double amount;

public:
    Expense();

    Expense(string desc, double amt);

    string getDescription() const;
    double getAmount() const;

    void setDescription(string desc);
    void setAmount(double amt);

    bool containsString(string searchStr) const;
};

#endif