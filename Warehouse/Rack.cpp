#include "Rack.h"

const unsigned int rackCap = 0;

Rack::Rack(char name): name{name}, haveSpace(rackCap), shelfCapacity(rackCap) {

    int index = 1;
    for (int i = 0; i < shelfCapacity; i++)
    {
        Shelf newShelf(index);
        shelfs.placeAt(i, newShelf);
        index++;
    }
    
}

void Rack::spaceCheck() {

    int count = 0;
    for (int i = 0; i < shelfCapacity; i++)
    {
        count += (shelfs.getAt(i).isSFull()) ? count++ : 0;
    }
    haveSpace -= count;
}

bool Rack::isRFull() const { return haveSpace == 0; }
