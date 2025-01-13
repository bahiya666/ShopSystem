#include "service.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

service :: service (std::string n, int bN, int r, char p) : item (n,bN)
{
    rate = r;
    period = p;
}

service :: ~service()
{}

void service::buy(std::string s) 
{
    float rand = price(s);

    std::stringstream ss(s);
    int time;
    std::string periodStr;
    ss >> time >> periodStr;

    

    std::string word;
    if (periodStr == "h") {
        word = "hours";
    } else if (periodStr == "d") {
        word = "days";
    } else if (periodStr == "w") {
        word = "weeks";
    } else if (periodStr == "m") {
        word = "months";
    } else {
        word = "years";
    }

    std::cout << "Bought{" << time << word << "}{" << getName() << "}{R" << std::fixed << std::setprecision(2) << rand << "}" << std::endl;
}

float service::price(std::string s) 
{
    std::istringstream ss(s);
    int time;
    std::string periodStr;
    ss >> time >> periodStr;

    

    float totalCost = 0.0;

    switch (period)
    {
        case 'h':  // R/hour
            if (periodStr == "h") {
                totalCost = rate * time;
            }
            else if (periodStr == "d") {
                totalCost = rate * time * 24.0;
            }
            else if (periodStr == "w") {
                totalCost = rate * time * 24.0 * 7.0;
            }
            else if (periodStr == "m") {
                totalCost = rate * time * 24.0 * 7.0 * 4.0;
            }
            else {
                totalCost = rate * time * 24.0 * 7.0 * 4.0 * 12.0;
            }
            break;

        case 'd': // R/day
            if (periodStr == "h") {
                totalCost = rate * (time / 24.0);
            }
            else if (periodStr == "d") {
                totalCost = rate * time;
            }
            else if (periodStr == "w") {
                totalCost = rate * time * 7.0;
            }
            else if (periodStr == "m") {
                totalCost = rate * time * 7.0 * 4.0;
            }
            else {
                totalCost = rate * time * 7.0 * 4.0 * 12.0;
            }
            break;

        case 'w': // R/month
            if (periodStr == "h") {
                totalCost = rate * (time / 168.0);
            }
            else if (periodStr == "d") {
                totalCost = rate * (time / 7.0);
            }
            else if (periodStr == "w") {
                totalCost = rate * time;
            }
            else if (periodStr == "m") {
                totalCost = rate * time * 4.0;
            }
            else {
                totalCost = rate * time * 4.0 * 12.0;
            }
            break;

        case 'm': // R/week
            if (periodStr == "h") {
                totalCost = rate * (time / 672.0);
            }
            else if (periodStr == "d") {
                totalCost = rate * (time / 28.0);
            }
            else if (periodStr == "w") {
                totalCost = rate * (time / 4.0);
            }
            else if (periodStr == "m") {
                totalCost = rate * time;
            }
            else {
                totalCost = rate * time * 12.0;
            }
            break;

        default: // R/year
            if (periodStr == "h") {
                totalCost = rate * (time / 8064.0);
            }
            else if (periodStr == "d") {
                totalCost = rate * (time / 336.0);
            }
            else if (periodStr == "w") {
                totalCost = rate * (time / 48.0);
            }
            else if (periodStr == "m") {
                totalCost = rate * (time / 12.0);
            }
            else {
                totalCost = rate * time;
            }
            break;
    }

    return totalCost;
}

void service :: print()
{
    std::cout << "service{" <<getBarcode() << "}{" << getName() << "}{R" << rate << "/" ;
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
    
    std::cout << "}" << std::endl;
}
