#include "discountedProduct.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

discountedProduct :: discountedProduct (std::string n, int bN, int v, int a ,float d) : product (n, bN, v,a )
{
    discount = d;
}

discountedProduct :: ~discountedProduct()
{}

float discountedProduct :: price (std::string s)
{
    int p;
    std::istringstream ss (s);
    ss >> p;

    float total;

    total = (p*value) * (1.0- (discount));  // CHECK CALCULATION
    return total;
}

void discountedProduct :: print()
{
    std::cout << "discountedProduct{" << getBarcode() << "}{" << getName() << "}{R" << value <<"}{" << amount
    << "}{" <<std::fixed << std::setprecision(2) << discount * 100 << "%" << "}" << std::endl;
} 