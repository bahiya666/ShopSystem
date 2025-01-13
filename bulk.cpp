#include "bulk.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

bulk :: bulk (std::string n, int bN, int v, int a, float dP, int dA) : product ( n, bN, v, a)
{
    discountPercentage = dP;
    discountAmount = dA;
}

bulk :: ~bulk ()
{}

float bulk :: price (std::string s)
{
    std::istringstream ss (s);
    int S;
    ss >> S;

    float totalPrice = 0.0;
    int groups = S / discountAmount;
    int remainder = S % discountAmount;

    totalPrice += groups * discountAmount * value * (1.0 - discountPercentage);

    totalPrice += remainder * value;

    return totalPrice;
}

void bulk :: print ()
{
    std::cout << "bulk{" << getBarcode() << "}{" <<getName() << "}{R" << value << "}{" << amount
              << "}{" << std::fixed << std::setprecision(2) << discountPercentage * 100 << "%"
              << "}{" << discountAmount << "}" << std::endl;
}
