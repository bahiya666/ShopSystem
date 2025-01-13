#include "labor.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

labor :: labor (std::string n, int bN, int r, char p, int* wR, int num) : service (n, bN, r, p)
{
    numWorkers = num;
    if (wR != NULL)
    {
        workerRates = new int [numWorkers];
        if (wR != NULL)
        {
            for (int i =0; i<num; i++)
            {
                workerRates[i] = wR[i];
            }
        }
    }
    
}

labor :: ~labor()
{
    if (workerRates != NULL) 
    {
        delete [] workerRates;
        workerRates = NULL;
    }
}

float labor::price(std::string s)
{
    float sum=0;
    float Rand=service::price(s);
    
    for(int i = 0;i<numWorkers;i++)
    {
        sum+=workerRates[i]*Rand;
    }

    return sum;
}

void labor :: print()
{
    std::cout << "labor{" << getBarcode() << "}{" <<getName() << "}{R" << rate << "/";

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

    std::cout << "}{[";
    
    for (int i = 0; i < numWorkers; ++i) {
        std::cout << workerRates[i];
        if (i < numWorkers - 1) {
            std::cout << ", ";
        }
    }
    
    std::cout << "]}" << std::endl;

}