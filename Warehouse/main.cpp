#include "Warehouse.h"
#include <iostream>
<<<<<<< HEAD
#include <cstring>
=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

using std::cin;
using std::cout;

<<<<<<< HEAD
void writeToLog(Vector<String> v, Item item) {
    //requires date and quantuty to be converted to string
    
}
void writeToHistory(Vector<String>& v, Item item, const char* prefix) {

    String log(prefix);
    log = item.getName() + String(" ");
    log = log + item.getManufact();
    log = log + String(" ");
    log = log + item.getExpiration().getDate();
    v.pushBack(log);
}
=======
void writeToLog();
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

int main() {
    Warehouse johnson("Johnson");
    String userInput;
<<<<<<< HEAD
    //Vector<String> history;
=======
<<<<<<< HEAD
    //Vector<String> history;
=======
    Vector<String> history;
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master
    cout  << "Welcome to warehouse interface!\n";
    cout << "To check available commands type 'help'" << '\n';
    while (cin >> userInput) 
    {
        if (userInput == String("help"))
        {
            cout << "display - diplays current items stored in the warehouse\n";
            cout << "add - adds an item to the warehouse\n";
            cout << "get - extracts the desired item from the warehouse\n";
            cout << "history - brings out recent changes logs\n";
            cout << "clear - clears the expired or the about-to-expire items from the warehouse\n";
            cout << "end - closes the program\n";
        }
        
        if (userInput == String("display"))
        {
            cout << "Displaying available items:\n";
            johnson.printItems();
        }

<<<<<<< HEAD
        if (userInput == String("add")) {
        String answer;
        do
        {
            
            
            Item itemToAdd;
            cout << "Enter the item you want to add\n";
            cin >> itemToAdd;
            johnson.addItemWarehouse(itemToAdd);                
            cout << "Item added succesfully!\n";
            //history.pushBack(String());
            
            cout << "Do you wish to add another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
        }
        
        if (userInput == String("get")) {
        String answer;
        do
        {
    
            Item itemToAdd;
            cout << "Enter the item you want to extract\n";
            cin >> itemToAdd;
            johnson.extractItem(itemToAdd);                
            cout << "Item extracted succesfully!\n";
            //history.pushBack(String());
            
            cout << "Do you wish to extract another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
=======
        if (userInput == String("add"))
        {
            Item itemToAdd;
            cout << "Enter the item you want to add\n";
            cin >> itemToAdd;
            johnson.addItemWarehouse(itemToAdd);
            //history.pushBack(String());
        }

        if (userInput == String("get"))
        {
            /* code */
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
        }
        
        if (userInput == String("history"))
        {
<<<<<<< HEAD
            //history.print();//should be done with a file, cant think of a way to make it with a vector
=======
<<<<<<< HEAD
            //history.print();//should be done with a file, cant think of a way to make it with a vector
=======
            /* code */
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
>>>>>>> upstream/master
        }
        
        if (userInput == String("clear"))
        {
<<<<<<< HEAD
            Date today;
            cout << "Enter todays date:\n";
            cin >> today;
            johnson.clear(today);
=======
            /* code */
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
        }

        if (userInput == String("end"))
        {
            break;
        }
        
    }
    
    


    return 0;
}
