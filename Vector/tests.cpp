// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
#include <iostream>
#include "Vector.cpp"
    using std::cout;
    using std::endl;

class Geeks
{
    int id;
    public:
    void getid(int id) { this->id = id; } 
     
    
};

int main() {


Vector<char> v1;
v1.pushBack('a');
v1.pushBack('b');
v1.pushBack('c');
v1.pushBack('d');
v1.pushBack('e');
v1.pushBack('f');

v1.removeAt(3);
v1.placeAt(3, 'D');
v1.print();

}