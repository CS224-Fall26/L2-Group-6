#ifndef SAVEMANAGER_HPP
#define SAVEMANAGER_HPP
#include <string>
#include "Inventory.hpp"
using namespace std;
class SaveManager {
public:
    static bool saveGame(string filename, string playerName,
                         const Inventory& inventory, int attempts, int successes, int hints);
    static bool loadGame(string filename, string& playerName,
                         Inventory& inventory, int& attempts, int& successes, int& hints);
};
#endif
