<<<<<<< HEAD
#include "../String/Stringh.h"
#include "Date.h"
#include "Item.h"
#include <iostream>
#include <fstream>
=======
#include <iostream>
#include "../String/Stringh.h"
#include "Date.h"
#include "Item.h"
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

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
<<<<<<< HEAD
    std::cout << "Enter name: ";
    is >> d.description; 
    std::cout <<"\nEnter manufacturer: "; 
    is >> d.manufacturer;
    std::cout << "\nEnter quantity: ";
    is >> d.quantity;
    std::cout << "\nEnter current date: "; 
    is >> d.gotIn;
    std::cout << "\nEnter expiration date: ";
    is >> d.expiration;
=======

    is >> "Enter name: " >> d.description >> "\nEnter manufacturer: " >> d.manufacturer >> "\nEnter current date: " >> d.gotIn >> "\nEnter expiration date: " >> d.expiration;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    std::cout << "Would you like to add a comment? Type 'yes' to add\n";
    String temp;
    is >> temp;
    if (temp == String("yes"))
    {
        d.addComment();
    }
    return is;
    

}  

<<<<<<< HEAD
=======
String& Item::log() {

    String temp;
    temp = description + String(" by ") + manufacturer;
    temp = temp + manufacturer;

    temp = temp + String ("Quantity: ");
}

>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
void Item::setLocation(unsigned int rack, unsigned int shelf, unsigned int idn) {

    this->rack = rack;
    this->shelf= shelf;
    this->idn = idn;
}
<<<<<<< HEAD

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

void Item::save() {
    std::ofstream file("Items.txt");
    if (!file.is_open())
    {
        throw std::runtime_error("Eroor");
        return;
    }
    
    file << description << " " << manufacturer << " " << quantity << " GotIn: " << gotIn << " EXP: " << expiration << " " << rack << "." << shelf << "." << idn << "\nComment:\n" << comment;
    file.close();


}

=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
