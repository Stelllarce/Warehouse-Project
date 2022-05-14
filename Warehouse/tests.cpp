#include <iostream>
<<<<<<< HEAD
#include "Shelf.h"

=======
<<<<<<< HEAD
#include "Shel.h"

=======
#include "Item.h"
#include "..\Vector\Vector.cpp"
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master

using std::cin;
int main() {

    Date d1(2022, 03, 05);
    Date d2(2022, 04, 05);
    Item vodka("Vodka", "SImens", d1, d2,  5);
<<<<<<< HEAD
    Item vodka2("Vodka", "SImens", d1, d2,  3);
    vodka.printItem();
    
    Shelf s(2);
    s.addItem(vodka, 0);


=======
<<<<<<< HEAD
    Item vodka2("Vodka", "SImens", d1, d2,  3);
    vodka.printItem();
    
    Shelf s(2);
    s.addItem(vodka, 0);
    // int i = 0;
    // while (i < 2)
    // {
    //     i++; //
    //     Item newItem;
    //     std::cin >> newItem;
    //     s.addItem(newItem, i);
    // }
    
=======
    Item vodka2("Vodka2", "SImens", d1, d2,  3);
    vodka.printItem();
    
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master
    Vector<Item> v;
    v.pushBack(Item());
    v.pushBack(vodka2);
    
<<<<<<< HEAD
    std::cout << "Ic? " << s.getItemCount() <<  v.getCapacity() << std::endl;
=======
<<<<<<< HEAD
    std::cout << "Ic? " << s.getItemCount() <<  v.getCapacity() << std::endl;
=======
    std::cout << "1" <<  v.getCapacity() << std::endl;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master
     

}   