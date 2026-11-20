#ifndef ELEMENTFACTORY_HPP
#define ELEMENTFACTORY_HPP

#include "Element.hpp"
using namespace std;

class ElementFactory {
public:
    static Element* createElement(int id);
};

#endif