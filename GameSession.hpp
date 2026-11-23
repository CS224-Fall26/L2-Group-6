#ifndef GAMESESSION_HPP
#define GAMESESSION_HPP
#include "Player.hpp"
#include "Inventory.hpp"
#include "RecipeBook.hpp"
#include "ElementFactory.hpp"
#include <string>
using namespace std;
struct CombinationResult {
    string element;
    bool valid;
    bool isNew;
};
class GameSession {
    Player player;
    Inventory inventory;
    RecipeBook recipes;
    Element* catalogue[28];
    int attempts, successes, hints;
public:
    GameSession();
    ~GameSession();
    GameSession(const GameSession&) = delete;
    GameSession& operator=(const GameSession&) = delete;
    void newGame(string name);
    CombinationResult combine(string first, string second);
    Element* findElement(string name) const;
    bool save(int slot) const;
    bool load(int slot);
    string getElementName(int index) const;
    const Player& getPlayer() const;
    const Inventory& getInventory() const;
    const RecipeBook& getRecipes() const;
    int getAttempts() const;
    int getSuccesses() const;
    int getHintsUsed() const;
    void recordHint();
    int getCatalogueSize() const;
};
#endif
