#ifndef SHELF
#define SHELF
#include <iostream>
#include "Item.h"
#include "..\Vector\Vector.cpp"
#include "Warehouse.h"

class Shelf {

    unsigned int name, itemCount, itemCapacity;
    Vector<Item> items;

    public:
    Shelf();
    Shelf(int name);

    void addItem(Item &item, int pos);
    int getItemCount();
    bool isSFull();

    bool isEmpty(int pos);

    friend class Warehouse;
};
#endif