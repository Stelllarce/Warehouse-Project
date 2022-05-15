#include "../String/Stringh.h"
#include "Date.h"
#include "Item.h"
#include <iostream>
#include <fstream>

Item::Item(): description(String("-1")), 
manufacturer(String()), 
gotIn(Date()), 
expiration(Date()), 
rack(0), 
shelf{0}, 
idn{0}, 
quantity(0), 
comment(String()),
location(String()) {}


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

String Item::getExpirationS() {

    return expiration.getDate();
}

std::istream& operator>>(std::istream& is, Item& d) {
    std::cout << "Enter name: ";
    is >> d.description; 
    std::cout <<"Enter manufacturer: "; 
    is >> d.manufacturer;
    std::cout << "Enter quantity: ";
    is >> d.quantity;
    std::cout << "Enter current date in YYYY.MM.DD: "; 
    is >> d.gotIn;
    is.ignore();
    std::cout << "Enter expiration date in YYYY.MM.DD: "; 
    is >> d.expiration;
    is.ignore();
    std::cout << "Would you like to add a comment? Type 'nocomment' is you dont\n";
    is >> d.comment;
    if (d.comment == String("nocomment"))
    {
        d.comment  = String();
    }
    
    return is;
    

}  

void Item::setLocation(unsigned int rack, unsigned int shelf, unsigned int idn) {

    this->rack = rack;
    this->shelf= shelf;
    this->idn = idn;
}

// void Item::save(std::ofstream &os) {

//     os.write(description.cStr(), description.get_size());
//     os.write(manufacturer.cStr(), manufacturer.get_size());
//     os.write((char*)&quantity, sizeof(quantity));
//     os.write((char*)&gotIn.year, 4);
//     os.write((char*)&gotIn.month, sizeof(gotIn.month));
//     os.write((char*)&gotIn.day, sizeof(gotIn.day));
//     os.write(comment.cStr(), comment.get_size());
//     os.write((char*)&quantity, sizeof(quantity));
//     os.write((char*)&rack, sizeof(rack));
//     os.write((char*)&shelf, sizeof(shelf));
//     os.write((char*)&idn, sizeof(idn));


// }

void Item::save(const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Error");
        return;
    }
    
    file << description << " " << manufacturer << " " << quantity << " GotIn: " << gotIn << " EXP: " << expiration << " " << rack << "." << shelf << "." << idn << "\nComment:\n" << comment;
    file.close();


}

void Item::setLocationString() {

    String R, S, I;
    R.toString(rack);
    S.toString(shelf);
    I.toString(idn);

    location = R + String("-");
    location = location + S;
    location = location + String(".");
    location = location + I;

}

Date Item::getGotin() { return gotIn; }

String Item::getGotinS() {

    return gotIn.getDate();
}

String Item::getLocation() { return location; }

