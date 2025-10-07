// Print Expressions With Options.cpp 
// Name: Abhinab Chatterjee
// Date: 1/20/2025
// Assignment: Week 2: Print Expressions With Options
// this assignment was a little more difficult ;)

#include <iostream>
using namespace std;

int main() {
    int operand1;
    int operand2;
    char option;

    cout << "Please enter the first operand: ";
    cin >> operand1;
    if (operand1 < 0) {
        cout << "The first operand is not valid." << endl;
        return 0;
    }

    cout << "Please enter the second operand: ";
    cin >> operand2;
    if (operand2 < 0) {
        cout << "The second operand is not valid." << endl;
        return 0;
    }

    cout << "Please enter the printing option ('A' or 'B'): ";
    cin >> option;

    if (option != 'A' && option != 'B') {
        cout << "Unsupported printing option." << endl;
        return 0;
    }

    cout << operand1 << "    +    " << operand2 << "    =    " << (operand1 + operand2) << endl;
    cout << operand1 << "    -    " << operand2 << "    =    " << (operand1 - operand2) << endl;

    if (option == 'A') {
        cout << operand1 << "    *    " << operand2 << "    =    " << (operand1 * operand2) << endl;
        if (operand2 != 0) {
            cout << operand1 << "    /    " << operand2 << "    =    " << (operand1 / operand2) << endl;
            cout << operand1 << "    %    " << operand2 << "    =    " << (operand1 % operand2) << endl;
        }
        else {
            cout << operand1 << "    /    " << operand2 << "    =    Error: Division by zero" << endl;
            cout << operand1 << "    %    " << operand2 << "    =    Error: Division by zero" << endl;
        }
    }

    return 0;
}

