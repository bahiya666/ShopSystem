#include <iostream>
#include <string>
#include "item.h"
#include "product.h"
#include "service.h"
#include "bulk.h"
#include "discountedProduct.h"
#include "labor.h"
#include "subscription.h"
#include "shop.h"

int main() {
    item **items = new item *[6];
    items[0] = new product("productName", 5, 5, 5);
    items[1] = new bulk("bulkName", 0, 5, 5, 0.1, 8);
    items[2] = new discountedProduct("discountedProductName", 0, 5, 5, 0.1);

    items[3] = new service("serviceName", 0, 10, 'y');
    items[4] = new subscription("subscriptionName", 0, 10, 'y', 0.1);
    int *workers = new int[1];
    workers[0] = 10;
    items[5] = new labor("laborName", 0, 10, 'y', workers, 1);
    delete[] workers;

    for (int i = 0; i < 6; i++) {
        items[i]->print();
    }

    for (int i = 0; i < 3; i++) {
        items[i]->buy("5");
    }

    for (int i = 3; i < 6; i++) {
        items[i]->buy("5 w");
    }

    for (int i = 0; i < 6; i++) {
        delete items[i];
    }
    delete[] items;

return 0;
