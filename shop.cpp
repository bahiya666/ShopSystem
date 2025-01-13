#include "shop.h"
#include <iostream>
#include <string>
#include <sstream>

shop::shop() : items(NULL), numItems(0) 
{}

shop::~shop() 
{
    for (int i = 0; i < numItems; ++i) 
    {
        delete items[i];
    }
    delete[] items;
}

int shop::itemIndex(std::string n) 
{
    for (int i = 0; i < numItems; ++i) 
    {
        if (items[i]->getName() == n) 
        {
            return i;
        }
    }
    return -1; 
}

void shop :: addItem (item* i)
{
    int index = itemIndex(i->getName());

    if (index == -1)
    {
        int newSize = numItems + 1;
        item** newItems = new item*[newSize];
        
        for (int j = 0; j < numItems; ++j) 
        {
            newItems[j] = items[j];
        }

        newItems[numItems] = i;
        
        delete[] items;
        items = newItems;
        numItems++;
    } 
    else 
    {
        std::cout << "Item already in shop" << std::endl;
    }
}
    
void shop::addItems(item** i, int n) 
{
    for (int j = 0; j < n; ++j) 
    {
        int index = itemIndex(i[j]->getName());
        
        if (index == -1) 
        {
            int newSize = numItems + 1;
            item** newItems = new item*[newSize];

            for (int k = 0; k < numItems; ++k) 
            {
                newItems[k] = items[k];
            }

            // Add the new item to the end
            newItems[numItems] = i[j];

            // Delete the old items array and update with the new one
            delete[] items;
            items = newItems;
            numItems++;
        } 
        else 
        {
            std::cout << "Item already in shop" << std::endl;
        }
    }
}

void shop::buyItems(std::string s) 
{
    std::stringstream ss(s);
    std::string itemName, purchaseData;
    float total = 0.0;

    while (std::getline(ss, itemName, ':') && std::getline(ss, purchaseData, '|')) {
        int index = itemIndex(itemName);
        if (index != -1) 
        {
            items[index]->buy(purchaseData);
            total += items[index]->price(purchaseData);
        } else 
        {
            std::cout << "Couldn't find {" << itemName << "}" << std::endl;
        }
    }

    std::cout.precision(2);
    std::cout << "Total: R {" << std::fixed << total << "}"<< std::endl;
}

void shop::printItems() 
{
    for (int i = 0; i < numItems; ++i) 
    {
        items[i]->print();
    }
}

void shop::removeItem(std::string s) 
{
    int index = itemIndex(s);

    if (index != -1) 
    {
        delete items[index];

        for (int i = index; i < numItems - 1; ++i) 
        {
            items[i] = items[i + 1];
        }

        item** newItems = new item*[numItems - 1];
        
        for (int i = 0; i < numItems - 1; ++i) 
        {
            newItems[i] = items[i];
        }

        delete[] items;
        
        items = newItems;
        numItems--;
    } 
    
    else 
    {
        std::cout << "Item not found" << std::endl;
    }
}
