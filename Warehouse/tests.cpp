#include <iostream>
#include "Shelf.h"


using std::cin;
int main() {

    Date d1(2022, 03, 05);
    Date d2(2022, 04, 05);
    Item vodka("Vodka", "SImens", d1, d2,  5);
    Item vodka2("Vodka", "SImens", d1, d2,  3);
    vodka.printItem();
    
    Shelf s(2);
    s.addItem(vodka, 0);


    Vector<Item> v;
    v.pushBack(Item());
    v.pushBack(vodka2);
    
    std::cout << "Ic? " << s.getItemCount() <<  v.getCapacity() << std::endl;
     

}   