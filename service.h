#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "item.h"

class service : public item
{
    protected: 
        int rate; // for a period of service
        char period; // time unit defualt is year

    public:
        service (std::string n, int bN, int r,char p);
        ~service();
        void buy (std::string s);
        float price (std::string s);
        void print();

};

#endif

