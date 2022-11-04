#ifndef WARE_H
#define WARE_H

#include <iostream>
#include "string.h"

class Ware
{
public:
    Ware(std::string name, int anzahl);
    std::string getName();
    int getAnzahl();
    void setAnzahl(int amount);
    void addAmount(int amount);
    static const int minAmount;
private:
    std::string name = "";
    int anzahl;
};

#endif // WARE_H
