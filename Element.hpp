#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <string>
#include <iostream>

using namespace std;

class Element {
protected:
    int elementId;
    string elementName;
    string category;
    string description;
    bool discoveryStatus;

public:
    Element(int id, string name, string cat, string desc, bool discovered = false);
    virtual ~Element() {}

    int getId() const;
    string getName() const;
    string getCategory() const;
    string getDescription() const;
    bool isDiscovered() const;
    void setDiscovered(bool status);

    virtual void displayInfo() const = 0; // Pure virtual function for polymorphism
};

class BasicElement : public Element {
private:
    bool startingAvailability;

public:
    BasicElement(int id, string name, string cat, string desc, bool available);
    void displayInfo() const override;
    bool isStarting() const;
};

class CraftedElement : public Element {
private:
    string discoveryRequirement;

public:
    CraftedElement(int id, string name, string cat, string desc, string requirement);
    void displayInfo() const override;
    string getRequirement() const;
};

#endif
