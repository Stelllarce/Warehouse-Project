#include <iostream>
#include "Item.h"
#include "..\Vector\Vector.cpp"

using std::cin;
int main() {

    Date d1(2022, 03, 05);
    Date d2(2022, 04, 05);
    Item vodka("Vodka", "SImens", d1, d2,  5);
    Item vodka2("Vodka2", "SImens", d1, d2,  3);
    vodka.printItem();
    
    Vector<Item> v;
    v.pushBack(Item());
    v.pushBack(vodka2);
    
    std::cout << "1" <<  v.getCapacity() << std::endl;
     

}   