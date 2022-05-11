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


<<<<<<< HEAD
Vector<int> v1;
v1.pushBack(2022);
v1.pushBack(21);
v1.pushBack(1);
v1.pushBack(2);
=======
Vector<char> v1;
v1.pushBack('a');
v1.pushBack('b');
v1.pushBack('c');
v1.pushBack('d');
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
v1.pushBack('e');
v1.pushBack('f');

v1.removeAt(3);
v1.placeAt(3, 'D');
v1.print();
<<<<<<< HEAD
cout << '\n';
cout << v1[0] << v1[1] << endl;
=======

>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
}