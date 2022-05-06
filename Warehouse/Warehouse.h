#ifndef WAREHOUSE
#define WAREHOUSE

#include <iostream>
#include "../Vector/Vector.h"
#include "../String/Stringh.h"
#include "Item.h"
#include "Rack.h"

class Warehouse {

    private:

    String name;
    Vector<Rack> racks;
    unsigned int haveSpaces, warehouseCapacity;

    bool seek(Item addedItem, int& slider1, int& slider2, int& slider3);
    
    public:

    Warehouse(String name);

    void addItemW(Item& i);


};

    std::ostream& operator<<(std::ostream& stream, const Warehouse& d);
#endif