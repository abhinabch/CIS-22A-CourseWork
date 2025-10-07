/*********************************************************************
* Name: Abhinab Chatterjee
* Project 3: Assignment Object Command
* Editor(s) used: Visual Studio
* Compiler(s) used: Windows
* Description:
* This program manages variable assignments with commands to add, list, and show statistics
**********************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Assignment {
private:
    string variableName;
    int value;

public:
    Assignment(string name = "", int val = 0) {
        variableName = name;
        value = val;
    }

    string getVarName() const { return variableName; }
    int getValue() const { return value; }

    string toString() const {
        string result = variableName;
        while (result.length() < 10) result += " ";
        result += "= ";
        string numStr = to_string(value);
        while (numStr.length() < 8) numStr = " " + numStr;
        result += numStr;
        return result;
    }
};

/*********************************************************************
* Function: Checks if a variable name follows naming rules
*
* Parameters:
* name (IN): The variable name to validate
* Return: true if valid, false if invalid
**********************************************************************/

bool isValidName(const string& name) {
    if (name.empty()) return false;

    if (isdigit(name[0])) return false;

    for (char c : name) {
        if (!isalnum(c)) return false;
    }
    return true;
}

/*********************************************************************
* Function: Adds a new assignment to the collection after validation
*
* Parameters:
* assignments (IN): The vector of Assignment objects to modify
* Return: NONE
**********************************************************************/

void addAssignment(vector<Assignment>& assignments) {
    string input;
    cout << "Please enter an assignment: ";
    getline(cin, input);

    istringstream iss(input);

    string name, op, valStr;

    iss >> name >> op >> valStr;

    if (op != "=") {
        cout << "Invalid assignment operator. ;(" << endl;
        return;
    }
    if (!isValidName(name)) {
        cout << "Invalid variable name.;(" << endl;
        return;
    }


    bool isNumber = true;
    for (char c : valStr) {
        if (!isdigit(c) && c != '-' && c != '+') {
            isNumber = false;
            break;
        }
    }
    if (!isNumber || valStr.empty()) {
        cout << "The assignment value is not a number." << endl;
        return;
    }

    int value = stoi(valStr);
    assignments.push_back(Assignment(name, value));
    cout << assignments.back().toString() << endl;
}

/*********************************************************************
* Function: Displaying all assignments in the collection
*
* Parameters:
* assignments (IN): The vector of Assignment objects to display
* Return: NONE
**********************************************************************/

void listAssignments(const vector<Assignment>& assignments) {

    if (assignments.empty()) {
        
        cout << "Unfortunately there is no assignment." << endl;
        return;
    }

    cout << "All assignments:" << endl;
    for (const Assignment& a : assignments) {
        cout << a.toString() << endl;
    }
}

/*********************************************************************
* Function: Calculates and displays statistics about assignments
*
* Parameters:
* assignments (IN): The vector of Assignment objects to analyze
* Return: NONE
**********************************************************************/

void showStats(const vector<Assignment>& assignments) {
    if (assignments.empty()) {
        cout << "Unfortunately there is no assignment." << endl;
        return;
    }

    int pos = 0, neg = 0;
    int maxValue = INT_MIN, minValue = INT_MAX;
    Assignment larg, small;

    for (const Assignment& a : assignments) {
        int val = a.getValue();
        if (val > 0) pos++;
        else if (val < 0) neg++;

        if (val > maxValue) {
            maxValue = val;
            larg = a;
        }
        if (val < minValue) {
            minValue = val;
            small = a;
        }
    }

    cout << "Total number of assignments:          " << assignments.size() << endl;
    cout << "Total number of positive assignments: " << pos << endl;
    cout << "Total number of negative assignments: " << neg << endl;
    cout << "The largest assignment:               " << larg.toString() << endl;
    cout << "The smallest assignment:              " << small.toString() << endl;
}


/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
    vector<Assignment> assignments;

    cout << "Welcome to assignment recording program." << endl;

    while (true) {
        cout << "Please enter a command (add, list, stats or exit): ";
        string command;
        getline(cin, command);

        if (command == "add") {
            addAssignment(assignments);
        }
        else if (command == "list") {
            listAssignments(assignments);
        }
        else if (command == "stats") {
            showStats(assignments);
        }
        else if (command == "exit") {

            break;
        }
        else {
            cout << "Unsupported command. Please try again. ;(" << endl;
        }
    }

    cout << "Thank you. Goodbye. Come back soon!" << endl;
    return 0;
}