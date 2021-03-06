#ifndef WAREHOUSE
#define WAREHOUSE

#include "../Vector/Vector.h"
#include "../String/Stringh.h"
#include "Rack.h"
#include <iostream>

class Warehouse {

    private:

    String name;
    Vector<Rack> racks;
    unsigned int haveSpaces;
    static int warehouseCapacity;

    bool seek(Item addedItem, int& slider1, int& slider2, int& slider3);
    bool placeItem(Item& addedItem);
    bool sort(Item& item, int& slider1, int& slider2, int& slider3);
    
    public:

    Warehouse();
    Warehouse(String name);

    String getName();
    //void SaveToFile(const char* file);

    void addItemWarehouse(Item i);
    void extractItem(Item I);
    void printItems();
    void clear(Date today);

};

#endif