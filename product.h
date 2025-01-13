#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "item.h"

class product : public item
{
    protected:
        int value; // price of one item
        int amount; //number of items available
    
    public:
        product (std::string n, int bN, int v, int a);
        ~product();
        void buy (std::string s);
        float price (std::string);
        void print ();
};

#endif