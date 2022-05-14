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


Vector<int> v1;
v1.pushBack(2022);
v1.pushBack(21);
v1.pushBack(1);
v1.pushBack(2);
v1.pushBack('e');
v1.pushBack('f');

v1.removeAt(3);
v1.placeAt(3, 'D');
v1.print();
cout << '\n';
cout << v1[0] << v1[1] << endl;
}