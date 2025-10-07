// Print Reciept.cpp 
// Name: Abhinab Chatterjee
// Date: 1/20/2025
// Assignment: Week 2: Print Receipt

#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
    string item;
    double priceOfItem;
    int quantity;
    char ifGift;
    string occasionName;

    cout << "Please enter the name of the item: ";
    cin >> item;

    cout << "Please enter the price for each item: ";
    cin >> priceOfItem;

    cout << "Please enter the quantity: ";
    cin >> quantity;

    cout << "Is this a gift? (Y/N): ";
    cin >> ifGift;

    cout << "Please enter the description of the occasion: ";
    cin >> occasionName;

    double subtotal = priceOfItem * quantity;
    double tax = subtotal * 0.10; 
    double total = subtotal + tax;

    cout << "========== RECEIPT ==========" << endl;
    cout << "Name:       " << item << endl;
    cout << fixed << setprecision(2);
    cout << "Price:      $" << priceOfItem << endl;
    cout << "Quantity:   " << quantity << endl;
    cout << "Subtotal:   $" << subtotal << endl;
    cout << "Tax:        $" << tax << endl;
    cout << "Total:      $" << total << endl;
    cout << "Gift (y/n): " << ifGift << endl;
    cout << "Occasion:  " << occasionName << endl;
    cout << "============================" << endl;

}
