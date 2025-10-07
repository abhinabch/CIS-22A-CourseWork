/*********************************************************************
* Name: Abhinab Chatterjee
* Week 4 -  Compute Change
* Editor(s) used: Visual Studio
* Compiler(s) used: Microsoft C++
* Description: This program calculates and shows the breakdown of change into bills and coins with the correct amount.
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
* denomination (IN): The value of the current bill
* name (IN): The display name of the unit
*
* Return: The updated remaining change after processing this unit
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
        change = calculateBillsOrCoins(change, 100.00, "$100 bill");
        change = calculateBillsOrCoins(change, 50.00, "$50 bill");
        change = calculateBillsOrCoins(change, 20.00, "$20 bill");
        change = calculateBillsOrCoins(change, 10.00, "$10 bill");
        change = calculateBillsOrCoins(change, 5.00, "$5 bill");
        change = calculateBillsOrCoins(change, 1.00, "$1 bill");
        change = calculateBillsOrCoins(change, 0.50, "50-cent coin");
        change = calculateBillsOrCoins(change, 0.25, "25-cent coin");
        change = calculateBillsOrCoins(change, 0.10, "10-cent coin");
        change = calculateBillsOrCoins(change, 0.05, "5-cent coin");
        change = calculateBillsOrCoins(change, 0.01, "penny");
    }

    return 0;
}