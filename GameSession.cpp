#include "GameSession.hpp"
#include "SaveManager.hpp"
using namespace std;
GameSession::GameSession() {
    for (int i = 0; i < 28; i++) catalogue[i] = ElementFactory::createElement(i + 1);
    newGame("Explorer");
}
GameSession::~GameSession() {
    for (int i = 0; i < 28; i++) delete catalogue[i];
}
void GameSession::newGame(string name) {
    player = Player(name);
    inventory.reset();
    attempts = 0;
    successes = 0;
    hints = 0;
    for (int i = 0; i < 28; i++) {
        catalogue[i]->setDiscovered(inventory.hasElement(catalogue[i]->getName()));
    }
}
Element* GameSession::findElement(string name) const {
    for (int i = 0; i < 28; i++) {
        if (catalogue[i]->getName() == name) return catalogue[i];
    }
    return nullptr;
}
CombinationResult GameSession::combine(string first, string second) {
    CombinationResult answer = {"", false, false};
    if (!inventory.hasElement(first) || !inventory.hasElement(second)) return answer;
    attempts++;
    answer.element = recipes.findCombination(first, second);
    if (answer.element.empty()) return answer;
    answer.valid = true;
    successes++;
    answer.isNew = inventory.unlockElement(answer.element);
    Element* found = findElement(answer.element);
    if (found != nullptr) found->setDiscovered(true);
    player.setTotalDiscovered(inventory.getUnlockedCount());
    return answer;
}
bool GameSession::save(int slot) const {
    if (slot < 1 || slot > 3) return false;
    return SaveManager::saveGame("saves/slot" + to_string(slot) + ".txt",
                 player.getName(), inventory, attempts, successes, hints);
}
bool GameSession::load(int slot) {
    if (slot < 1 || slot > 3) return false;
    string loadedName;
    Inventory loadedInventory;
    int a = 0, s = 0, h = 0;
    if (!SaveManager::loadGame("saves/slot" + to_string(slot) + ".txt",
                              loadedName, loadedInventory, a, s, h)) return false;
    for (int i = 0; i < loadedInventory.getUnlockedCount(); i++) {
        if (findElement(loadedInventory.getElement(i)) == nullptr) return false;
    }
    newGame(loadedName);
    inventory = loadedInventory;
    attempts = a;
    successes = s;
    hints = h;
    player.setTotalDiscovered(inventory.getUnlockedCount());
    for (int i = 0; i < 28; i++) {
        catalogue[i]->setDiscovered(inventory.hasElement(catalogue[i]->getName()));
    }
    return true;
}
string GameSession::getElementName(int index) const {
    if (index < 0 || index >= 28) return "";
    return catalogue[index]->getName();
}
const Player& GameSession::getPlayer() const 
{ 
    return player; 
}
const Inventory& GameSession::getInventory() const 
{ 
    return inventory; 
}
const RecipeBook& GameSession::getRecipes() const 
{ 
    return recipes; }
int GameSession::getAttempts() const 
{ 
    return attempts; 
}
int GameSession::getSuccesses() const 
{ 
    return successes; 
}
int GameSession::getHintsUsed() const
{
    return hints; 
}
void GameSession::recordHint() 
{ 
    hints++; 
}
int GameSession::getCatalogueSize() const 
{ 
    return 28; 
}
