#ifndef SHELF
#define SHELF
#include <iostream>
#include "Item.h"
#include "..\Vector\Vector.cpp"
#include "Warehouse.h"

class Shelf {

<<<<<<< HEAD
    Vector<Item> items;
    unsigned int name, itemCount;
    static int itemCapacity;
=======
    unsigned int name, itemCount, itemCapacity;
    Vector<Item> items;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

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