#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequencies;

public:
    // Constructor
    GroceryTracker(map<string, int> data);

    // Getters
    int getItemFrequency(string item);
    map<string, int> getAllItems();
};

#endif