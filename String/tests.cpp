#include <iostream>
#include "Stringh.h"

int main() { 

    String name1("Jonathan");
    String name2("Bradley");

    std::cout << "First name check "<< name1 << " " << name2 << '\n';
    std::cout << "Capacity check b swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    name1.my_pop_back();

    std::cout << "Capacity check after swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    std::cout << "Name check after swap " << name1 << " " << name2 << '\n';
    std::cout << "Name check after swap " << name1.get_back() << " " << name2.get_back() << std::endl;

}