#ifndef HINTSYSTEM_HPP
#define HINTSYSTEM_HPP
#include "Inventory.hpp"
#include "RecipeBook.hpp"
#include <string>
using namespace std;
class HintSystem {
public:
    static string getHint(const RecipeBook& book, const Inventory& inventory);
};
#endif
