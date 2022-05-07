#include "Warehouse.h"
#include <iostream>

using std::cin;
using std::cout;

void writeToLog();

int main() {
    Warehouse johnson("Johnson");
    String userInput;
    Vector<String> history;
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

        if (userInput == String("add"))
        {
            String a("Added item ");
            Item itemToAdd;
            cout << "Enter the item you want to add\n";
            cin >> itemToAdd;
            String cat = a + itemToAdd.getName();
            johnson.addItemWarehouse(itemToAdd);
            history.pushBack(String());
        }

        if (userInput == String("get"))
        {
            /* code */
        }
        
        if (userInput == String("history"))
        {
            /* code */
        }
        
        if (userInput == String("clear"))
        {
            /* code */
        }

        if (userInput == String("end"))
        {
            break;
        }
        
    }
    
    


    return 0;
}
