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

    char Rack;
    unsigned int shelf, quantity, idn;

    public:

    //constructors
    Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity);
    Item(const Item& other);

    void setIdn(int pos);
    void addComment();
    bool operator!=(const Item& i);
    bool operator==(const Item& i);
    //getters
    char getRack();
    unsigned int getShelf();

    //operators
    Item& operator++();//prefix
    Item& operator--();

};

#endif