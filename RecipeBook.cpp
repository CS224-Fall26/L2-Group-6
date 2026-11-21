#include "RecipeBook.hpp"
using namespace std;
RecipeBook::RecipeBook() {
    count = 0;
    addRecipe("Water", "Fire", "Steam");
    addRecipe("Earth", "Water", "Mud");
    addRecipe("Earth", "Fire", "Lava");
    addRecipe("Earth", "Air", "Dust");
    addRecipe("Fire", "Air", "Energy");
    addRecipe("Air", "Water", "Rain");
    addRecipe("Lava", "Water", "Stone");
    addRecipe("Mud", "Fire", "Clay");
    addRecipe("Rain", "Earth", "Plant");
    addRecipe("Clay", "Fire", "Brick");
    addRecipe("Stone", "Fire", "Metal");
    addRecipe("Dust", "Stone", "Sand");
    addRecipe("Sand", "Fire", "Glass");
    addRecipe("Steam", "Air", "Cloud");
    addRecipe("Cloud", "Energy", "Storm");
    addRecipe("Storm", "Energy", "Lightning");
    addRecipe("Plant", "Earth", "Tree");
    addRecipe("Tree", "Tree", "Forest");
    addRecipe("Brick", "Brick", "House");
    addRecipe("House", "House", "City");
    addRecipe("Energy", "Mud", "Life");
    addRecipe("Life", "Earth", "Human");
    addRecipe("Metal", "Human", "Tool");
    addRecipe("House", "Human", "Village");
}
void RecipeBook::addRecipe(string a, string b, string result) {
    if (count >= 24) return;
    recipes[count].first = a;
    recipes[count].second = b;
    recipes[count].result = result;
    count++;
}
string RecipeBook::findCombination(string a, string b) const {
    for (int i = 0; i < count; i++) {
        if ((recipes[i].first == a && recipes[i].second == b) ||
            (recipes[i].first == b && recipes[i].second == a)) {
            return recipes[i].result;
        }
    }
    return "";
}
Recipe RecipeBook::getRecipe(int index) const {
    if (index >= 0 && index < count) return recipes[index];
    Recipe empty = {"", "", ""};
    return empty;
}
int RecipeBook::getCount() const { return count; }
