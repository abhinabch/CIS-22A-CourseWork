/*********************************************************************
* Name: Abhinab Chatterjee  
* Week 3 - Day 1: Ask for a correct expression
* Editor(s) used: Visual Studio
* Compiler(s) used: Microsoft C++ 
* Description: "AskForCorrectExpression" will read in 2 different numbers for the operands and an operator. It will handle errors when 
* the user does not enter a number or a negative value by repeatedly printing out an error message and ask for a new number. Similarly, 
* if the user enters an unsupported operator, it will repeatedly ask for a new operator.
* This program manages courses taken by a student.
**********************************************************************/

#include <iostream>
using namespace std;

int main() {
    int operand1;
    int operand2;
    char operator1;

    //1st operand
    while (true) {
        cout << "Please enter the first operand: ";
        cin >> operand1;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(1000, '\n'); // easiest way to clear the buffer
            cout << "Unable to read the number for the first operand. Please try again." << endl;
            continue;
        }
        if (operand1 < 0) {
            cout << "The first operand cannot be negative. Please try again." << endl;
            continue;
        }
        cin.ignore(1000, '\n');
        break;
    }

    //2nd operand
    while (true) {
        cout << "Please enter the second operand: ";
        cin >> operand2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Unable to read the number for the second operand. Please try again." << endl;
            continue;
        }
        if (operand2 < 0) {
            cout << "The second operand cannot be negative. Please try again." << endl;
            continue;
        }
        cin.ignore(1000, '\n');
        break;
    }

    //operator
    while (true) {
        cout << "Please enter the expression operator: ";
        cin >> operator1;
        cin.ignore(1000, '\n');
        if (operator1 == '+' || operator1 == '-' || operator1 == '*' || operator1 == '/' || operator1 == '%') {
            break;
        }
        else {
            cout << "Unsupported operator. Please try again." << endl;
            continue;
        }
    }

    
    //operator calculation
    int result = 0;
    if (operator1 == '+') {
        result = operand1 + operand2;
    }
    else if (operator1 == '-') {
        result = operand1 - operand2;
    }
    else if (operator1 == '*') {
        result = operand1 * operand2;
    }
    else if (operator1 == '/') {
        result = operand1 / operand2;
    }
    else if (operator1 == '%') {
        result = operand1 % operand2;
    }

    //printing
    cout << "   " << operand1 << "    " << operator1 << "    " << operand2 << "    =    " << result << endl;

    return 0;
}
