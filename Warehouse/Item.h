#ifndef ITEM_H
#define ITEM_H

#include "../String/Stringh.h"
#include "Date.h"


class Item {

    private:

    String description;
    String manufacturer;
    Date gotIn;
    Date expiration;
    String comment;

    char rack;
    unsigned int shelf, idn, quantity;

    public:

    //constructors
    Item();
    Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity);
    Item(const Item& other);

    //mutators
    //void setIdn(int pos);
    void addComment();

    //compare operators
    bool operator!=(const Item& i);
    bool operator==(const Item& i);

    //getters
    char getRack();
    unsigned int getShelf();
    String getName() const;
    String getManufact() const;
    Date getExpiration();
    unsigned int getQuantity();


    //operators
    Item& operator=(const Item& i);
    void operator++();//prefix
    void operator--();
    void increaseQuantity(unsigned int increment);
    void decreaseQuantity(unsigned int decrement);

    void printItem();

};

#endif