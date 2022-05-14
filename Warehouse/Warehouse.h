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
<<<<<<< HEAD
    unsigned int haveSpaces;
    static int warehouseCapacity;
=======
    unsigned int haveSpaces, warehouseCapacity;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

    bool seek(Item addedItem, int& slider1, int& slider2, int& slider3);
    bool placeItem(Item& addedItem);
    bool sort(Item& item, int& slider1, int& slider2, int& slider3);
    
    public:

    Warehouse();
    Warehouse(String name);

<<<<<<< HEAD
    //void SaveToFile(const char* file);

    void addItemWarehouse(Item i);
    void extractItem(Item I);
    void printItems();
    void clear(Date today);
=======
    void addItemWarehouse(Item i);
    void printItems();

>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

};

#endif