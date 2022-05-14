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

    unsigned int rack, shelf, idn, quantity;

    public:

    //constructors
    Item();
    Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity);
    Item(const Item& other);

    //mutators

    void setLocation(unsigned int rack, unsigned int shelf, unsigned int idn);
    void addComment();

    //compare operators
    bool operator!=(const Item& i);
    bool operator==(const Item& i);

    //getters

    unsigned int getRack();
    //String& log();
    unsigned int getShelf();
    String getName() const;
    String getManufact() const;
    Date getExpiration();
    String getExpirationS();
    unsigned int getQuantity();


    //operators
    Item& operator=(const Item& i);
    void operator++();//prefix
    void operator--();
    void increaseQuantity(unsigned int increment);
    void decreaseQuantity(unsigned int decrement);

    void printItem();

    void save();

    friend std::istream& operator>>(std::istream& is, Item& d);    
};
    std::istream& operator>>(std::istream& is, Item& d);    

#endif