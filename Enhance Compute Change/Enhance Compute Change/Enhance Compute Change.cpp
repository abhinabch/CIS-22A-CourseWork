/*********************************************************************
* Name: Abhinab Chatterjee
* Week 5 -  Enhance Compute Change
* Editor(s) used: Visual Studio
* Compiler(s) used: Microsoft C++
* Description: This program calculates and shows the breakdown of change into bills and coins with the correct amount using arrays
* to store the units.
**********************************************************************/


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*********************************************************************
* Function: Processes a single unit when making change, counting
*           how many of that unit can be used and subtracting
*           their total value from the remaining amount.
*
* Parameters:
* remaining (IN/OUT): The remaining change
* denomination (OUT): The value of the current bill
* name (IN): The display name of the unit
*
* Return: The remaining change after processing this unit
**********************************************************************/
double calculateBillsOrCoins(double remaining, double unit, const string& name) {
    int count = 0;

    while (remaining + 0.001 >= unit) {
        count++;
        remaining -= unit;
    }

    if (count > 0) {
        cout << count << " " << name;
        if (count > 1) {
            if (name == "penny") {
                cout << "ies";
            }
            else {
                cout << "s";
            }
        }
        else if (name == "penny" && count == 1) {
            cout << "";
        }
        cout << endl;
    }

    return remaining;
}

/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
    const int NUM_UNITS = 11;
    double denominations[NUM_UNITS] = {
        100.00, 50.00, 20.00, 10.00, 5.00, 1.00,
        0.50, 0.25, 0.10, 0.05, 0.01
    };

    string names[NUM_UNITS] = {
        "$100 bill", "$50 bill", "$20 bill", "$10 bill", "$5 bill",
        "$1 bill", "50-cent coin", "25-cent coin", "10-cent coin",
        "5-cent coin", "penny"
    };

    double purchase, tendered;

    cout << "Enter the purchase amount: ";
    cin >> purchase;
    cout << "Enter the tendered amount: ";
    cin >> tendered;

    double change = tendered - purchase;
    change = round(change * 100) / 100;

    cout << fixed << setprecision(2);
    cout << "Your change: $" << change << endl;

    if (change > 0.001) {
        for (int i = 0; i < NUM_UNITS; i++) {
            change = calculateBillsOrCoins(change, denominations[i], names[i]);
        }
    }

    return 0;
}