/*******************************
File Name: CheckoutMain.cpp
Author: Naveed Sheikh
Revision Date: 12/26/2020
Description: This application checkout station where the user selects the products and amount to checkout
*******************************/
#include <iostream>
#include <string>
#include "CustomerCheckout.h"
using namespace std;
int main() {
    int choice = -1;
    while (choice != 0) {
        choice = mainMenu();
        switch (choice) {
        case 0:
            break;
        case 1:
            int employeeID;
            cout << "Enter the employee ID: ";
            cin >> employeeID;

            if (employeeLogin(employeeID) == 0) {
                cout << "The employee does not exist." << endl;
            }
            else {
                ShoppingCart cart[5];
                cout << "You are logged in." << endl;
                int cartSize = addToCart(cart);
                displayProducts(cart, cartSize);
                checkout(cart, employeeID, cartSize);
            }
            break;
        default:
            cout << "ERROR!: no case matches your selection." << endl << endl;
            break;
        }
    }
    cout << "Good bye!..." << endl;
    return 0;
}