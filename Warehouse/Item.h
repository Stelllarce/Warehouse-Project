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

<<<<<<< HEAD
    unsigned int rack, shelf, idn, quantity;
=======
    char rack;
    unsigned int shelf, idn, quantity;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

    public:

    //constructors
    Item();
    Item(String description, String manufacturer, Date expiration, Date gotIn,  unsigned int quantity);
    Item(const Item& other);

    //mutators
<<<<<<< HEAD
    void setLocation(unsigned int rack, unsigned int shelf, unsigned int idn);
=======
    //void setIdn(int pos);
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    void addComment();

    //compare operators
    bool operator!=(const Item& i);
    bool operator==(const Item& i);

    //getters
<<<<<<< HEAD
    unsigned int getRack();
=======
    String& log();
    char getRack();
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
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

<<<<<<< HEAD
    void save();

=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    friend std::istream& operator>>(std::istream& is, Item& d);    
};
    std::istream& operator>>(std::istream& is, Item& d);    

#endif