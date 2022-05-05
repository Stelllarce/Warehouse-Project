#include <iostream>
#include "../String/Stringh.h"
#include "Date.h"
#include "Item.h"

Item::Item(): description(String()), manufacturer(String()), gotIn(Date()), expiration(Date()), rack('\0'), shelf(0), idn(0), quantity(0), comment(String()) {}


Item::Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity): 
description(description), expiration(expiration), gotIn(gotIn), manufacturer(manufacturer), quantity(quantity){}

Item::Item(const Item& other) {

    description = other.description;
    manufacturer = other.manufacturer;
    gotIn = other.gotIn;
    expiration = other.expiration;
    comment = other.comment;
    quantity = other.quantity;
    idn = other.idn;
}

void Item::addComment() {

    String comment;
    std::cin >> comment;
    this->comment = comment;
}

void Item::setIdn(int pos) {

    String idn;
    if (pos < 10)
    {
        /* code */
    }
    
}


Item& Item::operator++() {

    quantity++;
    return *this;
}

Item& Item::operator--() {

    quantity--;
    return *this;
}
 bool Item::operator!=(const Item& i) {

     return (description != i.description || manufacturer != i.manufacturer);
 }
 bool Item::operator==(const Item& i) {

     return (description == i.description && manufacturer == i.manufacturer);
 }

 Item& operator=(const Item& i);