#include <iostream>
#include "Stringh.h"

int main() { 

    String a;
    while (std::cin >> a)
    {
        if (a == String("end"))
        {
            break;
        }
        
    }
    
    // String name1("Jonathan");
    // String name2("Bob");
    // String name3("josh");
    // String a = name1 + name2 ;
    // std::cout << a << '\n';

    // std::cout << "First name check "<< name1 << " " << name2 << '\n';
    // std::cout << "Capacity check b swap "<< name1.get_size() << " " << name2.get_size() << std::endl;
    // //name1.my_pop_back();
    // name1.my_swap(name2);

    // std::cout << "Capacity check after swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    // std::cout << "Name check after swap " << name1 << " " << name2 << '\n';
    // std::cout << "Name check after swap " << name1.get_back() << " " << name2.get_back() << std::endl;

}