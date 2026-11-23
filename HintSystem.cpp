#include "HintSystem.hpp"
using namespace std;
string HintSystem::getHint(const RecipeBook& book, const Inventory& inventory) {
    for (int i = 0; i < book.getCount(); i++) {
        Recipe recipe = book.getRecipe(i);
        if (inventory.hasElement(recipe.first) &&
            inventory.hasElement(recipe.second) &&
            !inventory.hasElement(recipe.result)) {
            return recipe.first + " + " + recipe.second;
        }
    }
    return "No more hints available";
}
