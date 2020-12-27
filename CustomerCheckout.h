/*******************************
File Name: CustomerCheckout.h
Author: Naveed Sheikh
Revision Date: 12/26/2020
Description: This application checkout station where the user selects the products and amount to checkout
*******************************/
#ifndef SDDS_CUSTOMERCHECKOUT_H
#define SDDS_CUSTOMERCHECKOUT_H

struct ShoppingCart {
    int product_id = 0;
    double price = 0;
    int quantity = 0;
};

int mainMenu();
int employeeLogin(int employeeID);
double findProduct(int product_id);
int addToCart(struct ShoppingCart cart[]);
void displayProducts(struct ShoppingCart cart[], int productCount);
int checkout(struct ShoppingCart cart[], int employeeID, int productCount);

#endif