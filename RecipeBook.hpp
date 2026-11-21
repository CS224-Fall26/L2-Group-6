#ifndef RECIPEBOOK_HPP
#define RECIPEBOOK_HPP
#include <string>
using namespace std;
struct Recipe {
    string first, second, result;
};
class RecipeBook {
    Recipe recipes[24];
    int count;
public:
    RecipeBook();
    void addRecipe(string first, string second, string result);
    string findCombination(string first, string second) const;
    Recipe getRecipe(int index) const;
    int getCount() const;
};
#endif
