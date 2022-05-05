#ifndef RACK
#define RACK
#include "Shelf.h"
#include "../vector/vector.h"
class Rack {

    private:
    
    char name;
    unsigned int haveSpace = 10;
    Shelf shelf[10];

    public:

    Rack();
    Rack(char name, int haveSpace, Shelf* shelf);
    Vector<Shelf>& getVector();

    bool isFull();
};


#endif