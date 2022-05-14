#ifndef RACK
#define RACK
#include "../Vector/Vector.h"
#include "Warehouse.h"
#include "Shelf.h"
class Shelf; 
class Rack {

    private:
    
    Vector<Shelf> shelfs;
    unsigned int name;
    unsigned int haveSpace;
    static int shelfCapacity;
    
    public:

    Rack();
    Rack(unsigned int name);
    Rack(const Rack&);
    Rack(Rack&&);
    Rack& operator=(const Rack&);

    bool isRFull() const;
    void spaceCheck();
    
    friend class Warehouse;
};


#endif