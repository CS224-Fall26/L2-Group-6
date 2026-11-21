#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <string>
using namespace std;
class Inventory {
    string items[28];
    int count;
public:
    Inventory();
    void reset();
    bool unlockElement(string name);
    bool hasElement(string name) const;
    string getElement(int index) const;
    int getUnlockedCount() const;
};
#endif
