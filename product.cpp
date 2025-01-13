#include "product.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

product :: product (std::string n, int bN, int v, int a) : item (n, bN)
{
    value = v;
    amount = a;
}

product :: ~product()
{}

void product :: buy (std::string s)
{
    int n =0;
    int buy =0;
    std::istringstream ss(s);
    ss >> n;

    if (n > amount)
    {
        buy = amount;
        amount=0;
    }
    else
    {
        buy = n;
        amount-=n;
    }

    std::cout << "Bought {" << n << "}{" << getName() << "}{R" << std::fixed << std::setprecision(2) 
    << price(s) <<"}"<< std::endl;
    
}

float product :: price (std::string s)
{
    int numToBuy;
    std::istringstream(s) >> numToBuy;
    
    if (numToBuy > amount) 
    {
        numToBuy = amount;
    }

    return static_cast<float>(numToBuy * value);
}

void product :: print()
{
    std::cout << "product{" << getBarcode() << "}{" << getName()<< "}{R" << value << "}{" << amount << "}" << std::endl;

}
