# CustomerCheckout

## Overview of Application 

This application is a simple cash register where a user can purchase products. An employee first logs in using an existing employee ID and then adds items to cart using a product ID. The program gets the price associated with the product. The user specifies the quantity for the product. Once the user is done adding all the products to the card, they can check out. Once the user selects this option, they are given a summary of the cart including the total. From here, the user can either finalize the order or cancel the order. Once that is done, the user can checkout as many customers as they would like and then exit once done. 


## Sample Run

```bash
******************** Main Menu ********************
1) Login
0) Exit
Enter an option (0-1): 9
******************** Main Menu ********************
1) Login
0) Exit
You entered a wrong value. Enter an option (0-1): 1
Enter the employee ID: 9
The employee does not exist.
******************** Main Menu ********************
1) Login
0) Exit
Enter an option (0-1): 1
Enter the employee ID: 1
You are logged in.
-------------- Add Products to Cart --------------
Enter the product ID: 1
Product Price: 1.99
Enter the product Quantity: 1
Enter 1 to add more products or 0 to checkout: 1
Enter the product ID: 2
Product Price: 2.99
Enter the product Quantity: 3
Enter 1 to add more products or 0 to checkout: 0
------- Ordered Products ---------
---Item 1
Product ID: 1
Price: 1.99
Quantity: 1
---Item 2
Product ID: 2
Price: 2.99
Quantity: 3
----------------------------------
Total: 10.96
Would you like to checkout? (Y/y or N/n) y
The order is successfully completed.
******************** Main Menu ********************
1) Login
0) Exit
Enter an option (0-1): 0
Good bye!...

```

## What I learned

In this program I implemented STL container vector to store the data for employee IDs and made parallel arrays to store the data for the product ID and the price corresponding to the product. I used the struct data type to hold the information for the shopping cart. In the main, I implemented a switch case for the user menu. 


## Issues I faced and how I overcame them

An issue that I faced when making this program was figuring out how to store the data type product. Since a product had a price and id associated with it, I needed a data type that would easily store the price and ID at the same index to make the data retrieval very easy. The solution that I came up with was using parallel arrays to store the data. This way, the array for product ID and price are of the same size and product ID at index n corresponds to product price at index n, making data retrieval very simple. 


## What I would do to improve this application

What I would do to improve this application would be to store the data in some sort of file format. This way, the data can be read and written to easily and the data can be saved past the lifetime of the application. This would also be beneficial when storing a large amount of data. Another thing that I would improve in my program would be to try using a different method to store the data type for products. I can consider using an STL container to store pointers to a customer data type for type product, where each pointer to product has a name, ID, and price. 
