#include <iostream>
#include "../String/Stringh.h"
#include "Date.h"
#include "Item.h"

Item::Item(): description(String()), 
manufacturer(String()), 
gotIn(Date()), 
expiration(Date()), 
rack(0), 
shelf{0}, 
idn{0}, 
quantity(0), 
comment(String()) {}


Item::Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity): 
description(description), 
expiration(expiration), 
gotIn(gotIn), 
manufacturer(manufacturer), 
quantity(quantity),
shelf(0), 
idn(0),
rack(0) {}

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

void Item::operator++() {

    quantity++;
    return;
}

void Item::operator--() {

    quantity--;
    return;
}
 bool Item::operator!=(const Item& i) {

     return (description != i.description || manufacturer != i.manufacturer);
 }
 bool Item::operator==(const Item& i) {

     return (description == i.description && manufacturer == i.manufacturer);
 }

 Item& Item::operator=(const Item& i) {

     if (this != &i)
     {
         description = i.description;
         manufacturer = i.manufacturer;
         gotIn = i.gotIn;
         expiration = i.expiration;
         comment = i.comment;
         rack = i.rack;
         shelf = i.shelf;
         idn = i.idn;
         quantity = i.quantity;
     }
     return *this;
 }

String Item::getName() const { return description; }

String Item::getManufact() const {return manufacturer; }

void Item::printItem() {

    std::cout << "Name: " << description << "\nManufacturer: " << manufacturer << "\nGotin: " << gotIn << "\nExpiration date: " << expiration << "\nQuantity: " << quantity << "\nRack: " << rack << "\nShelf " << shelf << "\nIdentification number: " << idn << "\nComment:\n\n" << comment;
}

unsigned int Item::getQuantity() { return quantity; }

void Item::increaseQuantity(unsigned int increment) {

    quantity += increment;
    return;
}
void Item::decreaseQuantity(unsigned int decrement) {

    quantity -= decrement;
    return;
}

Date Item::getExpiration() {

    return expiration;
}

std::istream& operator>>(std::istream& is, Item& d) {

    is >> "Enter name: " >> d.description >> "\nEnter manufacturer: " >> d.manufacturer >> "\nEnter current date: " >> d.gotIn >> "\nEnter expiration date: " >> d.expiration;
    std::cout << "Would you like to add a comment? Type 'yes' to add\n";
    String temp;
    is >> temp;
    if (temp == String("yes"))
    {
        d.addComment();
    }
    return is;
    

}  

String& Item::log() {

    String temp;
    temp = description + String(" by ") + manufacturer;
    temp = temp + manufacturer;

    temp = temp + String ("Quantity: ");
}

void Item::setLocation(unsigned int rack, unsigned int shelf, unsigned int idn) {

    this->rack = rack;
    this->shelf= shelf;
    this->idn = idn;
}
