#ifndef SHELF
#define SHELF
#include "Item.h"
#include "../vector/vector.h"
class Shelf {

    unsigned int name, itemCount, itemCapacity = 100;
    Item items[100];

    public:
    Shelf(unsigned int name);
    ~Shelf();

    int getItemCount();
    void addItem(Item item);
    bool isFull();
};
#endif