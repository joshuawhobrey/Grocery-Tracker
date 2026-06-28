#include "GroceryItem.h"

GroceryItem::GroceryItem() {
    itemName = "";
    itemQuantity = 0;
}

GroceryItem::GroceryItem(string name, int quantity) {
    itemName = name;
    itemQuantity = quantity;
}

string GroceryItem::getName() {
    return itemName;
}

int GroceryItem::getQuantity() {
    return itemQuantity;
}

void GroceryItem::addQuantity(int amount) {
    itemQuantity += amount;
}