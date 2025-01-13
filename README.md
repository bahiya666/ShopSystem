Overview:
This project is a system that models a shop with various products, services, and subscriptions. The system handles adding items to the shop, calculating their prices, and managing purchases. The items include products, bulk products, discounted products, services, subscriptions, and labor. Each item can be added, priced, and purchased with specific parameters such as time, discount, and quantity.

Classes and Functionality:
1. item Class (item.h)
  Represents a general item with a name and a barcode.
  The barcode is stored as a boolean array where each bit represents a part of the barcode.
  Methods:
  getName(): Returns the name of the item.
  getBarcode(): Returns a string representing the barcode in both visual format and decimal.
2. product Class (product.h)
  Inherits from the item class.
  Represents a basic product with a name, barcode, value, and amount.
  Method:
  price(s): Takes the quantity as input and calculates the total price for the product.
3. discountedProduct Class (discountedProduct.h)
  Inherits from the product class.
  Represents a product that has a discount.
  Method:
  price(s): Takes the quantity as input and calculates the price with the discount applied.
4. bulk Class (bulk.h)
  Inherits from the product class.
  Represents a bulk product with a quantity discount.
  Method:
  price(s): Takes the quantity as input and applies the discount when enough items are bought (based on the specified discountAmount).
5. service Class (service.h)
  Inherits from the item class.
  Represents a service with a rate and a time period.
  Method:
  price(s): Takes time and period as input and calculates the price of the service.
  buy(s): Prints the purchase confirmation for the service.
6. subscription Class (subscription.h)
  Inherits from the service class.
  Represents a subscription service with a discount applied for annual subscriptions.
  Method:
  price(s): Calculates the total price for the subscription based on the time period and discount.
7. labor Class (labor.h)
  Inherits from the service class.
  Represents a labor service, which applies worker rates to the cost of a service.
  Method:
  price(s): Takes time and period as input and calculates the labor price based on worker rates.
8. shop Class (shop.h)
  Represents a shop that manages a collection of items.
  Methods:
  addItem(i): Adds a single item to the shop.
  addItems(i, n): Adds multiple items to the shop.
  buyItems(s): Takes item names and purchase data, calculates total costs, and prints the results.
  printItems(): Prints details of all items in the shop.
  removeItem(s): Removes an item from the shop by name.

Compilation and Running:
Prerequisites:
  A C++ compiler (e.g., GCC or Clang).
  C++11 or higher.
Instructions:
  Download all the required source files (e.g., item.h, product.h, service.h, etc.).
Compile the files using a C++ compiler:
g++ -o shop_simulation main.cpp item.cpp product.cpp service.cpp discountedProduct.cpp bulk.cpp labor.cpp subscription.cpp shop.cpp
Run the compiled program:
./shop_simulation

Notes:
The main() function will simulate the creation of items and their purchase.
The system supports different item types like products, bulk items, discounted products, and services with different pricing models.
Memory management is handled with dynamic allocation (new and delete) for arrays and objects.
