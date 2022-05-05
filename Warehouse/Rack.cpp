#include "Rack.h"

bool Rack::isFull() {

    int i = 0, count = 0;
    while (shelf.getAt(i).isFull() && i < haveSpace) 
    {
        count++;
        i++;
    }
    return count == haveSpace;
}
Vector<Shelf>& Rack::getVector() {

    return shelf;
}
