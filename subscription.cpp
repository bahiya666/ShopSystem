#include "subscription.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

subscription :: subscription (std::string n, int bN, int r, char p, float d) : service (n, bN, r, p)
{
    yearDiscount =d;
}

subscription :: ~ subscription ()
{}

float subscription :: price (std::string s)
{
    std::stringstream ss(s);
    int time;
    char timePeriod;
    ss >> time >> timePeriod;

    float totalPrice=0.0;
    if (timePeriod == 'y') 
    {   
        totalPrice = static_cast<float>(rate * time) / 100.0;
        totalPrice *= (1.0 - yearDiscount);
    } 

    return totalPrice;
}

void subscription :: print()
{
    std::cout << "subscription{" << getBarcode() << "}{" << getName() << "}{R" << rate << "/";
    
    if (period == 'h') 
    {
        std::cout << "hour";
    } 
    else if (period == 'd') 
    {
        std::cout << "day";
    } 
    else if (period == 'w') 
    {
        std::cout << "week";
    } 
    else if (period == 'm') 
    {
        std::cout << "month";
    } 
    else 
    {
        std::cout << "year";
    }

    std::cout << "}{" << (yearDiscount * 100) << "%}" << std::endl;
}
