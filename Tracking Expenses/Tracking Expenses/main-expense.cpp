#include <iostream>
#include <fstream>
#include <string>
#include "expense.h"
using namespace std;

const int MAX_ENTRIES = 100;
const string DATA_FILE = "expenses.txt";

void displayMenu();
void showExpenses(Expense expenses[], int count);
void addExpense(Expense expenses[], int& count);
void searchStringExpenses(Expense expenses[], int count);
void searchAmountExpenses(Expense expenses[], int count);
void loadFileExpenses(Expense expenses[], int& count);
void saveFileExpenses(Expense expenses[], int count);

int main() {
    Expense expenses[MAX_ENTRIES];
    int count = 0;

    loadFileExpenses(expenses, count);

    int choice;
    do {
        displayMenu();
        cout << "Enter your option please: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showExpenses(expenses, count);
        }
        else if (choice == 2) {
            addExpense(expenses, count);
        }
        else if (choice == 3) {
            searchStringExpenses(expenses, count);
        }
        else if (choice == 4) {
            searchAmountExpenses(expenses, count);
        }
        else if (choice == 5) {
            saveFileExpenses(expenses, count);
            cout << "Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\nExpense Tracking Menu:\n";
    cout << "1. Show All\n";
    cout << "2. Spend\n";
    cout << "3. Search expenses containing this string\n";
    cout << "4. Search expenses with greater than or equal to this amount\n";
    cout << "5. Exit\n";
}
void showExpenses(Expense expenses[], int count) {
    if (count == 0) {
        cout << "There is no expense entry available.\n";
    }
    else {
        cout << "Expenses:\n";
        for (int i=0; i < count; i++) {
            cout << "AMOUNT(" << expenses[i].getAmount() << ") DESC(" << expenses[i].getDescription() << ")\n";
        }
    }
}

void addExpense(Expense expenses[], int& count) {
    if (count >= MAX_ENTRIES) {
        cout << "Maximum number of entries has been reached.\n";
        return;
    }

    string description;
    double num;

    cout << "Please enter the description for the expense: ";
    getline(cin, description);

    if (description.empty()) {
        cout << "Description cannot be empty.\n";
        return;
    }

    cout << "Please enter the amount: ";
    cin >> num;

    if (num <= 0) {
        cout << "Invalid amount ;( Amount cannot be negative or zero.\n";
        return;
    }

    expenses[count] = Expense(description, num);
    count++;

    cout << "AMOUNT(" << num << ") DESC(" << description << ")\n";
}

void searchStringExpenses(Expense expenses[], int count) {
    string searchStr;
    cout << "Please enter the search string: ";
    getline(cin, searchStr);

    bool found = false;
    for (int i=0; i < count; i++) {
        if (expenses[i].containsString(searchStr)) {
            cout << "AMOUNT(" << expenses[i].getAmount() << ") DESC(" << expenses[i].getDescription() << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No expenses found with the string: " << searchStr << "\n";
    }
}

void searchAmountExpenses(Expense expenses[], int count) {
    double amount;
    cout << "Please enter the amount: ";
    cin >> amount;

    bool found = false;
    for (int i=0; i < count; i++) {
        if (expenses[i].getAmount() >= amount) {
            cout << "AMOUNT(" << expenses[i].getAmount() << ") DESC(" << expenses[i].getDescription() << ")\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No expenses found with amount greater than/equal to: " << amount << "\n";
    }
}

void loadFileExpenses(Expense expenses[], int& count) {
    ifstream inFile(DATA_FILE);
    if (!inFile) {
        cout << "No existing data file found. Starting with an empty list.\n";
        return;
    }

    string desc;
    double amount;
    while (getline(inFile, desc)) {
        inFile >> amount;
        inFile.ignore();
        expenses[count] = Expense(desc, amount);
        count++;
    }

    inFile.close();
}

void saveFileExpenses(Expense expenses[], int count) {
    ofstream outFile(DATA_FILE);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i<count; i++) {
        outFile << expenses[i].getDescription() << "\n"<< expenses[i].getAmount() << "\n";
    }

    outFile.close();
}