/*********************************************************************
* Name: Abhinab Chatterjee
* Project: SimplePay Class Implementation
* Editor(s) used: Visual Studio
* Compiler(s) used: windows
* Description:
* This program manages working hour information including hours worked and pay rate
**********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class SimplePay {
private:
    int hours;
    double payRate;

public:
    SimplePay(int h = 0, double pr = 0.0) {
        hours = h;
        payRate = pr;
    }

    /*********************************************************************
    * Function: calculatePay
    * Description: Calculates the total pay amount including overtime
    *
    * Return:
    * Total pay amount
    **********************************************************************/

    double calculatePay() const {
        if (hours > 40) {
            return (40*payRate) + ((hours - 40) * payRate * 1.5);
        }
        return hours * payRate;
    }

    /*********************************************************************
    * Function: toString
    * Description: Provides a string of the pay information
    *
    * Return:
    * string containing hours, pay rate, and total pay
    **********************************************************************/
    string toString() const {
        double totalPay = calculatePay();
        char buffer[100];
        snprintf(buffer, sizeof(buffer),
            "HOURS(%d) PAY-RATE($%.2f) PAY-AMOUNT($%.2f)",
            hours, payRate, totalPay);
        return string(buffer);
    }

    bool payMore(const SimplePay& otherPay) const {
        return calculatePay() > otherPay.calculatePay();
    }

    int getHours() const { return hours; }

    double getPayRate() const { return payRate; }
};

/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
    SimplePay pay1(45, 10.0);
    SimplePay pay2(50, 10.0);

    cout << "Pay 1: " << pay1.toString() << endl;
    cout << "Pay 2: " << pay2.toString() << endl;

    if (pay2.payMore(pay1)) {
        cout << "Pay 2 is more than Pay 1 ;0" << endl;
    }
    else {
        cout << "Pay 2 is not more than Pay 1;(" << endl;
    }

    return 0;
}