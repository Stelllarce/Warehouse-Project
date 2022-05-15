#include "Warehouse.h"
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

void writeToLog(Vector<String> v, Item item) {
    //requires date and quantuty to be converted to string
    
}
void writeToHistory(Vector<String>& v, Item item, const char* prefix) {

    String log(prefix);
    String qnt;
    qnt.toString(item.getQuantity());
    log = log + item.getName();
    log = log + String(" by ");
    log = log + item.getManufact();
    log = log + String(" by ");
    log = log + String(" ,expiring on: ");
    log = log + item.getExpirationS();
    log = log + String(" ,quantity: ");
    log = log + qnt;
    log = log + String(" ,got in the warehouse on: ");
    log = log + item.getGotinS();
    log = log + String(" ,location: ");
    log = log + item.getLocation();

    v.pushBack(log); 
}
int main() {
    Warehouse johnson("Johnson");
    String userInput;
    Vector<String> history;

    cout  << "-----------------------Welcome to " << johnson.getName() << " warehouse interface!-----------------------\n";
    cout << "To check available commands type 'help'" << '\n';
    cout << "Enter a command: ";
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

        if (userInput == String("add")) {
        String answer;
        do
        {
            Item itemToAdd;
            Vector<Item> itemList;
            int i = 0;
            cout << "Enter the item you want to add\n";
            cin >> itemToAdd;
            itemList.pushBack(itemToAdd);
            johnson.addItemWarehouse(itemList[i]);                
            cout << "Item added succesfully!\n";
            i++;
            writeToHistory(history, itemToAdd, "Added ");
            
            cout << "Do you wish to add another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
        }
        
        if (userInput == String("get")) {
        String answer;
        do
        {
    
            Item itemToAdd;
            Vector<Item> itemList;
            int i = 0;
            cout << "Enter the item you want to extract\n";
            cin >> itemToAdd;
            itemList.pushBack(itemToAdd);
            johnson.extractItem(itemList[i]);                
            cout << "Item extracted succesfully!\n";
            writeToHistory(history, itemToAdd, "Extracted ");
            
            cout << "Do you wish to extract another item?\n";
            cin >> answer;
        } while (answer == String("yes"));
        }

        if (userInput == String("history"))
        {
            history.print();
        }
        
        if (userInput == String("clear"))
        {
            Date today;
            cout << "Enter todays date:\n";
            cin >> today;
            johnson.clear(today);
        }

        if (userInput == String("end"))
        {
            cout << "Closing the program...";
            break;
        }
        

    }
    return 0;
}
