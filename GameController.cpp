#include "GameController.hpp"
#include "HintSystem.hpp"
#include "Achievement.hpp"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace {
int readNumber(const string& prompt) {
    string input;
    cout << prompt;
    if (!getline(cin, input)) return -1;
    try {
        size_t used = 0;
        int value = stoi(input, &used);
        if (used == input.size()) return value;
    } catch (...) {}
    return -1;
}
}

void GameController::showElements() const {
    const Inventory& items = game.getInventory();
    cout << "\n Discovered elements (" << items.getUnlockedCount() << "/28) ---\n";
    for (int i = 0; i < items.getUnlockedCount(); ++i)
        cout << i + 1 << ". " << items.getElement(i) << '\n';
}

void GameController::combineElements() {
    showElements();
    const Inventory& items = game.getInventory();
    cout << "\nEnter the numbers of two discovered elements.\n";
    int first = readNumber("First number: ");
    int second = readNumber("Second number: ");
    if (first < 1 || first > items.getUnlockedCount() ||
        second < 1 || second > items.getUnlockedCount()) {
        cout << "Invalid selection. Choose numbers from the list.\n";
        return;
    }
    const string a = items.getElement(first - 1);
    const string b = items.getElement(second - 1);
    CombinationResult result = game.combine(a, b);
    if (!result.valid) cout << "No recipe found for " << a << " + " << b << ".\n";
    else if (result.isNew) cout << "New discovery! " << a << " + " << b << " = " << result.element << "\n";
    else cout << "You already discovered " << result.element << ".\n";
    if (game.getPlayer().isCompleted())
        cout << "Congratulations! You have discovered all 28 elements!\n";
}

void GameController::showHint() {
    string hint = HintSystem::getHint(game.getRecipes(), game.getInventory());
    cout << "\nHint: " << hint << '\n';
    if (hint != "No more hints available") game.recordHint();
}

void GameController::showAchievements() const {
    int discoveries = game.getInventory().getUnlockedCount();
    int attempts = game.getAttempts();
    int successes = game.getSuccesses();
    int hints = game.getHintsUsed();
    cout << "\n...Achievements...\n";
    int count = Achievement::getCount(discoveries, attempts, successes, hints);
    if (count == 0) cout << "No achievements unlocked yet.\n";
    for (int i = 0; i < count; ++i)
        cout << "- " << Achievement::getName(i, discoveries, attempts, successes, hints) << '\n';
}

void GameController::showElementInfo() const {
    showElements();
    int choice = readNumber("Element number for details: ");
    const Inventory& items = game.getInventory();
    if (choice < 1 || choice > items.getUnlockedCount()) {
        cout << "Invalid element number.\n";
        return;
    }
    Element* element = game.findElement(items.getElement(choice - 1));
    if (element) {
        // Runtime polymorphism: calls the BasicElement or CraftedElement override.
        element->displayInfo();
        cout << "Category: " << element->getCategory() << '\n';
        cout << "Description: " << element->getDescription() << '\n';
    }
}

void GameController::startNewGame() {
    string name;
    cout << "Player name: ";
    if (!getline(cin, name)) return;
    if (name.empty()) name = "Explorer";
    game.newGame(name);
    cout << "New game started for " << game.getPlayer().getName() << ".\n";
}

void GameController::saveGame() const {
    int slot = readNumber("Save slot (1-3): ");
    cout << (game.save(slot) ? "Game saved successfully.\n" : "Could not save. Use slot 1, 2, or 3.\n");
}

void GameController::loadGame() {
    int slot = readNumber("Load slot (1-3): ");
    cout << (game.load(slot) ? "Game loaded successfully.\n" : "Save not found or invalid slot.\n");
}

void GameController::run() {
    cout << "       ELEMENTORIA\n";
    while (cin.good()) {
        cout << "\nPlayer: " << game.getPlayer().getName()
             << " | Elements: " << game.getInventory().getUnlockedCount()
             << "/28 | Completion: " << game.getPlayer().getCompletionPercentage() << "%\n";
        cout << "1. New game\n"
             << "2. Show discovered elements\n"
             << "3. Combine elements\n"
             << "4. Get hint\n"
             << "5. Element details\n"
             << "6. Achievements\n"
             << "7. Save game\n"
             << "8. Load game\n"
             << "9. Game statistics\n"
             << "0. Exit\n";
        int choice = readNumber("Choose an option: ");
        if (!cin.good()) break;
        switch (choice) {
            case 0: 
            cout << "Thanks for playing Elementoria!\n"; return;
            case 1: 
            startNewGame(); break;
            case 2: 
            showElements(); break;
            case 3: 
            combineElements(); break;
            case 4: 
            showHint(); break;
            case 5: 
            showElementInfo(); break;
            case 6: 
            showAchievements(); break;
            case 7: 
            saveGame(); break;
            case 8: loadGame(); break;
            case 9:
                cout << "Attempts: " << game.getAttempts()
                     << " | Successful combinations: " << game.getSuccesses()
                     << " | Hints used: " << game.getHintsUsed() << '\n';
                break;
            default: cout << "Invalid option. Try again.\n";
        }
    }
}