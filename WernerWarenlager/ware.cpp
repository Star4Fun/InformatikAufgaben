#include "ware.h"

Ware::Ware(std::string name, int anzahl)
{
    this->name = name;
    this->anzahl = anzahl;
}

std::string Ware::getName() {
    return name;
}


int Ware::getAnzahl() {
    return this->anzahl;
}

void Ware::setAnzahl(int amount) {
    this->anzahl = amount;
}

void Ware::addAmount(int amount) {
    setAnzahl(amount + getAnzahl());
}
