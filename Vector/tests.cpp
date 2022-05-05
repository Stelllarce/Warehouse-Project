// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
#include <iostream>
#include "vector.cpp"
    using std::cout;
    using std::endl;
int main() {


Vector<char> v1;
v1.pushBack('a');
v1.pushBack('b');
v1.pushBack('c');
v1.pushBack('d');
v1.pushBack('e');
v1.pushBack('f');

v1.print();


}