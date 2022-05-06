#include "Warehouse.h"

const unsigned int warehouseCap = 5;

Warehouse::Warehouse(String name): name{name}, haveSpaces(warehouseCap), warehouseCapacity(warehouseCap) {

    char index = 1;
    for (int i = 0; i < warehouseCapacity; i++)
    {
        racks.pushBack(Rack(index));
        index++;
    }
}  

void Warehouse::addItemW(Item& I) {

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (seek(I, i, j, k))//if similar item is found
                {
                    //sorting algorithm
                }
                else
                {
                    //place on the first empty space (requires isEmpty() from Item class)
                }
                
            }
            
        }
        
    }
    
}
bool Warehouse::seek(Item addedItem, int& slider1, int& slider2, int& slider3) {

    for (int i = slider1; i < 5; i++)
    {
        for (int j = slider2; j < 5; j++)
        {
            for (int k = slider3; k < 10; k++)
            {
                if (addedItem == racks[i].shelfs[i].items[i])
                {
                    return true;
                }
                else 
                {
                    slider1 = slider2 = slider3 = 0;
                    return false;
                }

            }
            
        }
        
    }
    
}