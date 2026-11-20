#include "Element.hpp"
#include <iostream>

using namespace std;

// Element class

Element::Element(int id, string name, string cat, string desc, bool discovered) {
    elementId = id;
    elementName = name;
    category = cat;
    description = desc;
    discoveryStatus = discovered;
}

int Element::getId() const {
    return elementId;
}

string Element::getName() const {
    return elementName;
}

string Element::getCategory() const {
    return category;
}

string Element::getDescription() const {
    return description;
}

bool Element::isDiscovered() const {
    return discoveryStatus;
}

void Element::setDiscovered(bool status) {
    discoveryStatus = status;
}

// BasicElement class

BasicElement::BasicElement(int id, string name, string cat, string desc, bool available)
    : Element(id, name, cat, desc, available) {
    startingAvailability = available;
}

void BasicElement::displayInfo() const {
    cout << "Basic Element: " << elementName << endl;
    cout << "Category: " << category << endl;
    cout << "Description: " << description << endl;
}

bool BasicElement::isStarting() const {
    return startingAvailability;
}

// CraftedElement class

CraftedElement::CraftedElement(int id, string name, string cat, string desc, string requirement)
    : Element(id, name, cat, desc, false) {
    discoveryRequirement = requirement;
}

void CraftedElement::displayInfo() const {
    cout << "Crafted Element: " << elementName << endl;
    cout << "Category: " << category << endl;
    cout << "Description: " << description << endl;
    cout << "Requirement: " << discoveryRequirement << endl;
}

string CraftedElement::getRequirement() const {
    return discoveryRequirement;
}