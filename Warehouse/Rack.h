#ifndef RACK
#define RACK
#include "Shelf.h"
#include "../Vector/Vector.h"
class Rack {

    private:
    Shelf a;
    Vector<Shelf> shelfs;
    char name;
    unsigned int haveSpace, shelfCapacity;
    
    public:

    Rack(char name);

    bool  isRFull() const;
    void spaceCheck();
    
};


#endif