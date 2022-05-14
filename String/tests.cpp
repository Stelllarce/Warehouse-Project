#include <iostream>
#include "Stringh.h"

int main() { 

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> upstream/master
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
<<<<<<< HEAD
=======

    // std::cout << "First name check "<< name1 << " " << name2 << '\n';
    // std::cout << "Capacity check b swap "<< name1.get_size() << " " << name2.get_size() << std::endl;
    // //name1.my_pop_back();
    // name1.my_swap(name2);

    // std::cout << "Capacity check after swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    // std::cout << "Name check after swap " << name1 << " " << name2 << '\n';
    // std::cout << "Name check after swap " << name1.get_back() << " " << name2.get_back() << std::endl;
=======
    String name1("Jonathan");
    String name2("Jonatha");
    bool a = name1 == name2;
    std::cout << a;
>>>>>>> upstream/master

    // std::cout << "First name check "<< name1 << " " << name2 << '\n';
    // std::cout << "Capacity check b swap "<< name1.get_size() << " " << name2.get_size() << std::endl;
    // //name1.my_pop_back();
    // name1.my_swap(name2);

<<<<<<< HEAD
    // std::cout << "Capacity check after swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    // std::cout << "Name check after swap " << name1 << " " << name2 << '\n';
    // std::cout << "Name check after swap " << name1.get_back() << " " << name2.get_back() << std::endl;
=======
    std::cout << "Capacity check after swap "<< name1.get_size() << " " << name2.get_capacity() << std::endl;
    std::cout << "Name check after swap " << name1 << " " << name2 << '\n';
    std::cout << "Name check after swap " << name1.get_back() << " " << name2.get_back() << std::endl;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master

}