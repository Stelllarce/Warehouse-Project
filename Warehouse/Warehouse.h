#ifndef WAREHOUSE
#define WAREHOUSE

#include <iostream>
#include "../String/Stringh.h"
#include "Item.h"
#include "Rack.h"

class Warehouse {

    private:

    unsigned int haveSpaces;
    Rack* racks;

    public:
    Warehouse();
    Warehouse(char section, unsigned int Warehouse, String in);
    Warehouse(const Warehouse& other);

    void addItem(Item i);

    

};

    std::ostream& operator<<(std::ostream& stream, const Warehouse& d);
#endif