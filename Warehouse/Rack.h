#ifndef RACK
#define RACK
#include "Shelf.h"
#include "../Vector/Vector.h"
#include "Warehouse.h"
class Rack {

    private:
    Shelf a;
    Vector<Shelf> shelfs;
    char name;
    unsigned int haveSpace;
    static int shelfCapacity;
    
    public:

    Rack(char name);

    bool  isRFull() const;
    void spaceCheck();
    
    friend class Warehouse;
};


#endif