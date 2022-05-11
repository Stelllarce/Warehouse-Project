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
<<<<<<< HEAD
    unsigned int haveSpace;
    static int shelfCapacity;
=======
    unsigned int haveSpace, shelfCapacity;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    
    public:

    Rack(char name);

    bool  isRFull() const;
    void spaceCheck();
    
    friend class Warehouse;
};


#endif