#include "Shelf.h"
#include "Item.h"

bool Shelf::isFull() { return itemCount == itemCapacity; }

int Shelf::getItemCount() { return itemCount; }

Shelf::Shelf(unsigned int name): name{name} {

    for (int i = 0; i < 10; i++)
    {
        items.pushBack(Item())
    }
    
}