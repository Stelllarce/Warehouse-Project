#include "Shelf.h"
#include "Item.h"

<<<<<<< HEAD
int Shelf::itemCapacity = 5;

Shelf::Shelf(): name(0), itemCount(0), items(Vector<Item>()) {}

Shelf::Shelf(unsigned int name): name{name}, itemCount(0) {
=======
const unsigned int itemCap = 5;

Shelf::Shelf(): name(0), itemCount(0), itemCapacity(0), items(Vector<Item>()) {}

Shelf::Shelf(unsigned int name): name{name}, itemCount(0), itemCapacity(itemCap) {
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

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

bool Shelf::isEmpty(int pos) { return items[pos].getName() == "\0"; }
