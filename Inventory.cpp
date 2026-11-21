#include "Inventory.hpp"
using namespace std;
Inventory::Inventory() { reset(); }
void Inventory::reset() {
    count = 0;
    unlockElement("Fire");
    unlockElement("Water");
    unlockElement("Earth");
    unlockElement("Air");
}
bool Inventory::hasElement(string name) const {
    for (int i = 0; i < count; i++) {
        if (items[i] == name) return true;
    }
    return false;
}
bool Inventory::unlockElement(string name) {
    if (name.empty() || hasElement(name) || count >= 28) return false;
    items[count] = name;
    count++;
    return true;
}
string Inventory::getElement(int index) const {
    if (index < 0 || index >= count) return "";
    return items[index];
}
int Inventory::getUnlockedCount() const { return count; }
