#ifndef SHOP_H
#define SHOP_H

#include "item.h"
#include <string>

class shop 
{
    private:
        int numItems;
        item** items;

    public:
        shop();
        ~shop();

        int itemIndex(std::string n);
        void addItem(item* i);
        void addItems(item** i, int n);
        void buyItems(std::string s);
        void printItems();
        void removeItem(std::string s);


};

#endif