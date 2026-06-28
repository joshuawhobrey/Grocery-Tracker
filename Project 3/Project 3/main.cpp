#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "GroceryItem.h"

using namespace std;

int main() {
    ifstream inFS;
    ofstream outFS;
    string fileItem;

    map<string, GroceryItem> inventory;

    int menuChoice = 0;
    string input;

    // 1. Open and read the daily input file
    inFS.open("CS210_Project_Three_Input_File.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
        return 1;
    }

    // Populate the map
    while (!inFS.eof()) {
        inFS >> fileItem;

        if (!inFS.fail()) {
            if (inventory.count(fileItem) == 1) {
                // Key exists, update the quantity safely inside the object
                inventory.at(fileItem).addQuantity(1);
            }
            else {
                // Key does not exist, create a new encapsulated GroceryItem
                GroceryItem newItem(fileItem, 1);
                inventory.emplace(fileItem, newItem);
            }
        }
    }
    inFS.close();

    // 2. Create the backup file automatically
    outFS.open("frequency.dat");
    if (!outFS.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
        return 1;
    }

    // Write frequencies to the backup file utilizing the class getters
    for (pair<string, GroceryItem> element : inventory) {
        outFS << element.second.getName() << " " << element.second.getQuantity() << endl;
    }
    outFS.close();

    // 3. Run the user interface
    while (menuChoice != 4) {
        cout << endl;
        cout << "==== Corner Grocer Menu ====" << endl;
        cout << "1. Find item frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            cout << "Enter the item to search for: ";
            cin >> input;
            if (inventory.count(input) > 0) {
                cout << input << " appears " << inventory.at(input).getQuantity() << " times." << endl;
            }
            else {
                cout << input << " appears 0 times." << endl;
            }
            break;

        case 2:
            for (pair<string, GroceryItem> element : inventory) {
                cout << element.second.getName() << " " << element.second.getQuantity() << endl;
            }
            break;

        case 3:
            for (pair<string, GroceryItem> element : inventory) {
                cout << element.second.getName() << " ";
                // Nested loop to print the correct number of asterisks
                for (int i = 0; i < element.second.getQuantity(); i++) {
                    cout << "*";
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}