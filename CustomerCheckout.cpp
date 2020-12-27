/*******************************
File Name: CustomerCheckout.cpp
Author: Naveed Sheikh
Revision Date: 12/26/2020
Description: This application checkout station where the user selects the products and amount to checkout
*******************************/
#include <iostream>
#include <string>
#include <vector>
#include "CustomerCheckout.h"
using namespace std;

vector<int> employees{ 1, 2, 3, 4, 5, 6 };

//Parallel arrays to store product id and prices
int products[5] = { 1,2,3,4,5 };
double prices[5] = { 1.99, 2.99, 3.99, 4.99, 5.99 };

int mainMenu() {
    int option;
    cout << "******************** Main Menu ********************" << endl;
    cout << "1) Login" << endl;
    cout << "0) Exit" << endl;
    cout << "Enter an option (0-1): ";
    cin >> option;
    while (option != 0 && option != 1) {
        cout << "******************** Main Menu ********************" << endl;
        cout << "1) Login" << endl;
        cout << "0) Exit" << endl;
        cout << "You entered a wrong value. Enter an option (0-1): ";
        cin >> option;
    }
    return option;
}

int employeeLogin(int employeeID) {
    int found = 0;
    std::vector<int>::iterator i;
    for (i = employees.begin(); i != employees.end(); i++)
        if (*i == employeeID)
            found = 1;
    return found;
}

double findProduct(int product_id) {
    double price = 0;
    if (product_id <= 6 && product_id > 0)
        price = prices[product_id - 1];
    return price;
}

int addToCart(struct ShoppingCart cart[]) {
    int prodID, quantity;
    int choice = 1;
    int cartSize = 0;
    bool foundProduct = true;

    cout << "-------------- Add Products to Cart --------------" << endl;
    // run as long as cart size is less than 5 and the user has not entered 0 to exit
    while (cartSize < 5 && choice != 0) {

        // if it is not the first iteration of the loop and the previous product was found, ask the user if they wish to add another product or exit
        if (cartSize != 0 && foundProduct == true) {
            cout << "Enter 1 to add more products or 0 to checkout: ";
            cin >> choice;
        }

        if (choice == 1) {
            cout << "Enter the product ID: ";
            cin >> prodID;
            //find the price of the product, if product with ID prodID is not found, price will be 0
            double price = findProduct(prodID);

            // if product was found, output the price and ask user to enter the quantity, otherwise ouput error message
            if (price != 0) {
                cout << "Product Price: " << price << endl;
                cout << "Enter the product Quantity: ";
                cin >> quantity;

                // enter the productID, price, and quantity into the cart
                cart[cartSize].price = price;
                cart[cartSize].product_id = prodID;
                cart[cartSize].quantity = quantity;
                // increase cart size by 1
                cartSize++;

                foundProduct = true;
            }
            else {
                cout << "The product does not exists. Try again..." << endl;
                foundProduct = false;
            }

        }
        else if (choice != 1 && choice != 0) {
            cout << "Error! Invalid choice, please try again." << endl;
        }
    }
    return cartSize;
}

void displayProducts(struct ShoppingCart cart[], int productCount) {
    double total = 0;

    cout << "------- Ordered Products ---------" << endl;

    for (size_t i = 0; i < productCount; i++) {
        cout << "---Item " << i + 1 << endl;
        cout << "Product ID: " << cart[i].product_id << endl;
        cout << "Price: " << cart[i].price << endl;
        total += cart[i].price * cart[i].quantity;
        cout << "Quantity: " << cart[i].quantity << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << total << endl;
}

int checkout(struct ShoppingCart cart[], int employeeID, int productCount) {
    int result = -1;
    char choice = '\0';
    do {
        cout << "Would you like to checkout? (Y/y or N/n) ";
        cin >> choice;
        if (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N')
            cout << "Wrong input. Try again..." << endl;
    } while (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N');

    if (choice == 'n' || choice == 'N') {
        cout << "The order is cancelled." << endl;
        result = 0;
    }
    else {
        result = 1;
        cout << "The order is successfully completed." << endl;
    }
    return result;
}
