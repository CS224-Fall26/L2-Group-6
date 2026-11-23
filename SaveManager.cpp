#include "SaveManager.hpp"
#include <fstream>
using namespace std;
bool SaveManager::saveGame(string filename, string playerName,
                           const Inventory& inventory, int attempts, int successes, int hints) {
    ofstream file(filename.c_str());
    if (!file.is_open()) return false;
    file << "ELEMENTORIA2" << endl;
    file << playerName << endl;
    file << attempts << " " << successes << " " << hints << endl;
    file << inventory.getUnlockedCount() << endl;
    for (int i = 0; i < inventory.getUnlockedCount(); i++) {
        file << inventory.getElement(i) << endl;
    }
    return file.good();
}
bool SaveManager::loadGame(string filename, string& playerName,
                           Inventory& inventory, int& attempts, int& successes, int& hints) {
    ifstream file(filename.c_str());
    if (!file.is_open()) return false;
    string version, loadedName, names[28];
    int a, s, h, count;
    getline(file, version);
    if (version != "ELEMENTORIA2") return false;
    getline(file, loadedName);
    if (loadedName.empty() || !(file >> a >> s >> h >> count)) return false;
    if (a < 0 || s < 0 || h < 0 || s > a || count < 4 || count > 28) return false;
    file.ignore(1000, '\n');
    for (int i = 0; i < count; i++) {
        if (!getline(file, names[i]) || names[i].empty()) return false;
        for (int j = 0; j < i; j++) {
            if (names[i] == names[j]) return false;
        }
    }
    // Four starting elements must be in every save.
    bool start[4] = {false, false, false, false};
    for (int i = 0; i < count; i++) {
        if (names[i] == "Fire") start[0] = true;
        if (names[i] == "Water") start[1] = true;
        if (names[i] == "Earth") start[2] = true;
        if (names[i] == "Air") start[3] = true;
    }
    for (int i = 0; i < 4; i++) if (!start[i]) return false;
    Inventory loaded;
    for (int i = 0; i < count; i++) loaded.unlockElement(names[i]);
    if (loaded.getUnlockedCount() != count) return false;
    inventory = loaded;
    playerName = loadedName;
    attempts = a;
    successes = s;
    hints = h;
    return true;
}