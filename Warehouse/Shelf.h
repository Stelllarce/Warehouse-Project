#ifndef SHELF
#define SHELF
#include <iostream>
#include "Item.h"
#include "..\Vector\Vector.cpp"
#include "Warehouse.h"

class Shelf {

    Vector<Item> items;
    unsigned int name, itemCount;
    static int itemCapacity;

    public:
    Shelf();
    Shelf(unsigned int name);

    void addItem(Item &item, int pos);
    int getItemCount();
    bool isSFull();

    bool isEmpty(int pos);

    friend class Warehouse;
};
#endif