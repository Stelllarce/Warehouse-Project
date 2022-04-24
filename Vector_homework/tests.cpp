#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "vector.cpp"
//Can't seem to extcract vector from the main fucniton.
Vector v1;
//Prob not the right way, but compilator accepts it this way.
TEST_CASE("Vector reset?") {
//Perhaps define v1 in every other test dunction?
    std::cout << "Capacity?" << std::endl;
    CHECK(v1.getCapacity() == 1);
    std::cout << "Size?" << std::endl;
    CHECK(v1.getSize() == 0);
}
TEST_CASE("Other vector tests") {

    v1.pushBack(10);
    v1.pushBack(14);
    v1.pushBack(18);
    v1.pushBack(15);
    v1.pushBack(100);
    std::cout << "First element should be 10" << std::endl;
    v1.getFirst();
    std::cout << "Last element should be 100" << std::endl;
    v1.getLast();
    std::cout << "Should be 15" << std::endl;
    v1.getAt(3); 
    CHECK(v1.getSize() == 5);
    std::cout << "Vector after pushes" << std::endl;
    v1.print();

    v1.removeAt(2);
    CHECK(v1.getSize() == 4);
    std::cout << "18 should not be present" << std::endl;
    v1.print();

    v1.removeAt(0);
    CHECK(v1.getSize() == 3);
    std::cout << "10 should not be present" << std::endl;
    v1.print();

    v1.popBack();
    v1.popBack();
    v1.popBack();

    CHECK(v1.isEmpty() == true);

    v1.assign(5, 10);
    std::cout << "Vector after assign" << std::endl;
    v1.print();
}