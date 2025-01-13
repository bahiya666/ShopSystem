#include "item.h"
#include <string>
#include <sstream>

item :: item (std::string n, int bN)
{
    name = n;
    int temp = bN;
    int counter = 0;

    while (temp > 0)
    {
        temp/=2;
        counter++;
    }

    barcodeLength = counter;
    barcode = new bool [barcodeLength];

    temp = bN;
    for (int i = barcodeLength - 1; i >= 0; i--) 
    {
        barcode[i] = (temp % 2 == 1);
            temp /= 2;
    }
}

item :: ~item ()
{
    delete [] barcode;
    barcode= NULL;
}

std::string item :: getName()
{
    return name;
}

std::string item :: getBarcode()
{
    std::stringstream s;
    s << "[";

    for (int i =0 ; i< barcodeLength ; i++)
    {
        if (barcode[i]== 0)
        {
            s << " ";
        }
        else 
        {
            s << "|";
        }
    }

    s << "](";

    int decimal =0;

    for (int i = 0; i < barcodeLength; i++) 
    {
        decimal *= 2;
        if (barcode[i]) 
        {
            decimal += 1;
        }
    }

    s << decimal <<")";

    return s.str();
} 