#include "Shelf.h"
#include "Item.h"

int Shelf::itemCapacity = 5;

Shelf::Shelf(): name(0), itemCount(0), items(Vector<Item>()) {}

Shelf::Shelf(unsigned int name): name{name}, itemCount(0) {

    for (int i = 0; i < this->itemCapacity; i++)
    {
        items.pushBack(Item());
    }
    
}

bool Shelf::isSFull() { return itemCount == itemCapacity; }

int Shelf::getItemCount() { return itemCount; }

void Shelf::addItem(Item &item, int pos) {

    if (itemCount == itemCapacity)
    {
        std::cout << "The shelf is full!" << '\n';
    }
    
    items.placeAt(pos, item);
    itemCount++;
}

bool Shelf::isEmpty(int pos) { return items[pos].getName() == "-1"; }
