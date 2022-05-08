#include "Warehouse.h"
#include <iostream>

using std::cin;
using std::cout;

void writeToLog();

int main() {
    Warehouse johnson("Johnson");
    String userInput;
    //Vector<String> history;
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

        String answer;
        do
        {
            if (userInput == String("add"))
            {
                Item itemToAdd;
                cout << "Enter the item you want to add\n";
                cin >> itemToAdd;
                johnson.addItemWarehouse(itemToAdd);
                cout << "Item added succesfully!\n";
                //history.pushBack(String());
            }
            cout << "Do you wish to add another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
        

        do
        {
            if (userInput == String("get"))
            {
                Item itemToAdd;
                cout << "Enter the item you want to extract\n";
                cin >> itemToAdd;
                johnson.extractItem(itemToAdd);
                cout << "Item extracted succesfully!\n";
                //history.pushBack(String());
            }
            cout << "Do you wish to extract another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
        
        if (userInput == String("history"))
        {
            //history.print();//should be done with a file, cant think of a way to make it with a vector
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
