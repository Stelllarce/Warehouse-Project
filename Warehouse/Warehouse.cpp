#include "Warehouse.h"
#include <exception>
#include <fstream>

int Warehouse::warehouseCapacity = 5;

Warehouse::Warehouse(): name(String()), racks(Vector<Rack>()), haveSpaces(0) {}

Warehouse::Warehouse(String name): name{name}, haveSpaces(warehouseCapacity) {

    char index = 1;
    for (int i = 0; i < warehouseCapacity; i++)
    {
        racks.pushBack(Rack(index));
        index++;
    }
}  

void Warehouse::addItemWarehouse(Item I) {
    int i, j, k;
    i = j = k = 0;
    if (seek(I, i, j, k))//if similar item is found
    {
        //sorting algorithm
        if(sort(I, i, j, k)) 
        { 
            I.save("Items.txt");
            return;
        }
    }
    std::cout << "didnt";
    //if similar item is not found (or sorting attempt has failed) place the item on the first empty space found
    //the algorithm sorts the items by going through all first positions on every shelf
    //and then going to every second and so on, until it finds a suitable space
    // if( !(placeItem(I)) ) 
    // {
    //     throw std::runtime_error("Warehouse is full!");
    //     return;
    // }
    if(!placeItem(I)) { std::cout << "nay"; }
    std::cout << "\ndhidnt";
    I.save("Items.txt");
    return;
    
}
bool Warehouse::seek(Item addedItem, int& slider1, int& slider2, int& slider3) {

    for (int i = slider1; i < warehouseCapacity; i++)
    {
        for (int j = slider2; j < Rack::shelfCapacity; j++)
        {
            for (int k = slider3; k < Shelf::itemCapacity; k++)
            {
                if (addedItem == racks[i].shelfs[j].items[k])
                {
                    return true;
                }

            }
            
        }
        
    }
    return false;
}

bool Warehouse::placeItem(Item& addedItem) {

    for (int i = 0; i < Shelf::itemCapacity; i++)
    {
        for (int j = 0; j < warehouseCapacity; j++)
        {
            for (int k = 0; k < Rack::shelfCapacity; k++)
            {               
                if (racks[j].shelfs[k].isEmpty(i))
                {
                    racks[j].shelfs[k].addItem(addedItem, i);
                    addedItem.setLocation(j, k, i); 
                    return true;
                }                
            }
            
        }
        
    }
    return false;
}

bool Warehouse::sort(Item& item, int& slider1, int& slider2, int& slider3) {

    //increase quantity if same expiration
    if (item.getExpiration() == racks[slider1].shelfs[slider2].items[slider3].getExpiration())
    {
        racks[slider1].shelfs[slider2].items[slider3].increaseQuantity(item.getQuantity());
        return true;
    }

    //if k + 1 or k - 1 is empty, place (k being the position of the item with the same name but different expiration)
    if (racks[slider1].shelfs[slider2].isEmpty(slider3 + 1))
    {
        racks[slider1].shelfs[slider2].addItem(item, slider3 + 1);
        item.setLocation(slider1, slider2, slider3 + 1); 
        return true;
    }
    if (racks[slider1].shelfs[slider2].isEmpty(slider3 - 1) && slider3 > 0)
    {
        racks[slider1].shelfs[slider2].addItem(item, slider3 - 1);
        item.setLocation(slider1, slider2, slider3 - 1); 
        return true;
    }

    //place on adjecent shelf
    if ( !(racks[slider1].shelfs[slider2 + 1].isSFull()) )
    {
        int a = 0;
        while (!(racks[slider1].shelfs[slider2 + 1].isEmpty(a)) || a < 5 /*item cap*/ )
        {
            a++;
        }
        racks[slider1].shelfs[slider2 + 1].addItem(item, a);
        item.setLocation(slider1, slider2 + 1, slider3); 

        return true;
    }
    if ( !(racks[slider1].shelfs[slider2 - 1].isSFull()) && slider2 > 0)
    {
        int b = 0;
        while (!(racks[slider1].shelfs[slider2 - 1].isEmpty(b)) || b < 5 /*item cap*/ )
        {
            b++;
        }
        racks[slider1].shelfs[slider2 - 1].addItem(item, b);
        item.setLocation(slider1, slider2 - 1, slider3); 

        return true;
    }

    //place on adjecent racks
    racks[slider1 + 1].spaceCheck();//calculate the available shelfs on that rack
    if ( !(racks[slider1 + 1].isRFull()))
    {
        for (int i = 0; i < Rack::shelfCapacity; i++)
        {
            if (!(racks[slider1 - 1].shelfs[i].isSFull()))
            {
                int b = 0;
                while (!(racks[slider1].shelfs[slider2 - 1].isEmpty(b)) || b < 5 /*item cap*/ )
                {
                    b++;
                }
                racks[slider1].shelfs[slider2].addItem(item, b);
                item.setLocation(slider1, slider2, slider3); 
                return true;
            }
             
        }
    }
    racks[slider1 - 1].spaceCheck();//calculate the available shelfs on that rack
    if ( !(racks[slider1 - 1].isRFull()) && slider1 > 0)
    {
        for (int i = 0; i < Rack::shelfCapacity; i++)
        {
            if (!(racks[slider1 - 1].shelfs[i].isSFull()))
            {
                int b = 0;
                while (!(racks[slider1].shelfs[slider2 - 1].isEmpty(b)) || b < 5 /*item cap*/ )
                {
                    b++;
                }
                racks[slider1].shelfs[slider2].addItem(item, b);
                item.setLocation(slider1, slider2, slider3); 
                return true;   
            }
             
        }
        
    }
    
    return false;
    
    
}

void Warehouse::printItems() {

    for (int i = 0; i < warehouseCapacity; i++)
    {
        for (int j = 0; j < Rack::shelfCapacity; j++)
        {
            for (int k = 0; k < Shelf::itemCapacity; k++)
            {
                racks[i].shelfs[j].items[k].printItem();
            }
            
        }
        
    }
    
}

void Warehouse::extractItem(Item I) {
    int i, j, k;
    i = j = k = 0;
    if (seek(I, i, j, k)) 
    {
        racks[i].shelfs[j].items[k].printItem();
        racks[i].shelfs[j].items.placeAt(k, Item());
    }
}

void Warehouse::clear(Date today) {

    for (int i = 0; i < warehouseCapacity; i++)
    {
        for (int j = 0; j < Rack::shelfCapacity; j++)
        {
            for (int k = 0; k < Shelf::itemCapacity; k++)
            {
                if (racks[i].shelfs[j].items[k].getExpiration() <= today)
                {
                    std::cout << "Item to remove: ";
                    racks[i].shelfs[j].items[k].printItem();
                    racks[i].shelfs[j].items[k].save(today.getDate().cStr());
                    racks[i].shelfs[j].items.placeAt(k, Item());
                    std::cout << "\nItem removed\n";
                }
            }
            
        }
        
    }
    
}

// void Warehouse::SaveToFile(const char* fileName) {

//     String fileName1 = String(fileName) + String(".txt");
//     std::ofstream file(fileName1.cStr());
//     for (int i = 0; i < warehouseCapacity; i++)
//     {
//         for (int j = 0; j < Rack::shelfCapacity; j++)
//         {
//             for (int k = 0; k < Shelf::itemCapacity; k++)
//             {
//                 racks[i].shelfs[j].items[k].save(file);
//             }
            
//         }
        
//     }
//     file.close();    
// }

String Warehouse::getName() { return name; }