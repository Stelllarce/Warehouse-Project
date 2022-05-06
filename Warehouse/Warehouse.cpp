#include "Warehouse.h"

const unsigned int warehouseCap = 0;

Warehouse::Warehouse(String name): name{name}, haveSpaces(warehouseCap), warehouseCapacity(warehouseCap) {

    char index = 1;
    for (int i = 0; i < warehouseCapacity; i++)
    {
        racks.pushBack(Rack(index));
        index++;
    }
}  

void Warehouse::addItemW(Item& i) {

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                seek(i, j, k)
            }
            
        }
        
    }
    
}
void seek(Item addedItem, Vector<Rack> rack, int& slider1, int& slider2, int& slider3) {

    for (int i = slider1; i < count; i++)
    {
        for (int j = slider2; j < count; j++)
        {
            for (int k = slider3; k < count; k++)
            {
                rack[i].
            }
            
        }
        
    }
    
}