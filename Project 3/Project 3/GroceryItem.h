#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>

using namespace std;

class GroceryItem {
private:
    string itemName;
    int itemQuantity;

public:
    // Constructors to set the private variables
    GroceryItem();
    GroceryItem(string name, int quantity);

    // Getters to retrieve the data safely
    string getName();
    int getQuantity();

    // Modifiers
    void addQuantity(int amount);
};

#endif