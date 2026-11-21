#include "ElementFactory.hpp"
using namespace std;

Element* ElementFactory::createElement(int id) {
    if (id == 1){
        return new BasicElement(1, "Fire", "Basic Elements", "Produces heat and light",true);
    }
    else if (id == 2){
        return new BasicElement(2, "Water", "Basic Elements", "Essential for life",true);
    }
    else if (id == 3){
        return new BasicElement(3, "Earth", "Basic Elements", "Soil and ground",true);
    }
    else if (id == 4){
        return new BasicElement(4, "Air", "Basic Elements", "Air around us",true);
    }
    else if (id == 5){
        return new CraftedElement(5, "Steam", "Natural Phenomena", "Water vapor", "Recipe");
    }
    else if (id == 6){
        return new CraftedElement(6, "Mud", "Natural Materials", "Wet soil", "Recipe");
    }
    else if (id == 7){
        return new CraftedElement(7, "Lava", "Natural Materials", "Molten rock", "Recipe");
    }
    else if (id == 8){
        return new CraftedElement(8, "Dust", "Natural Materials", "Small particles", "Recipe");
    }
    else if (id == 9){
        return new CraftedElement(9, "Energy", "Natural Phenomena", "Power", "Recipe");
    }
    else if (id == 10){
        return new CraftedElement(10, "Rain", "Natural Phenomena", "Falling water", "Recipe");
    }
    else if (id == 11){
        return new CraftedElement(11, "Stone", "Natural Materials", "Solid rock", "Recipe");
    }
    else if (id == 12){
        return new CraftedElement(12, "Clay", "Natural Materials", "Soft earth", "Recipe");
    }
    else if (id == 13){
        return new CraftedElement(13, "Plant", "Living Things", "A growing organism", "Recipe");
    }
    else if (id == 14){
        return new CraftedElement(14, "Brick", "Human-Made Objects", "Building material", "Recipe");
    }
    else if (id == 15){
        return new CraftedElement(15, "Metal", "Natural Materials", "Strong material", "Recipe");
    }
    else if (id == 16){
        return new CraftedElement(16, "Sand", "Natural Materials", "Tiny rock particles", "Recipe");
    }
    else if (id == 17){
        return new CraftedElement(17, "Glass", "Human-Made Objects", "Transparent material", "Recipe");
    }
    else if (id == 18){
        return new CraftedElement(18, "Cloud", "Natural Phenomena", "Water droplets in the sky", "Recipe");
    }
    else if (id == 19){
        return new CraftedElement(19, "Storm", "Natural Phenomena", "Strong weather", "Recipe");
    }
    else if (id == 20){
        return new CraftedElement(20, "Lightning", "Natural Phenomena", "Electrical discharge", "Recipe");
    }
    else if (id == 21){
        return new CraftedElement(21, "Tree", "Living Things", "A large plant", "Recipe");
    }
    else if (id == 22){
        return new CraftedElement(22, "Forest", "Living Things", "Group of trees", "Recipe");
    }
    else if (id == 23){
        return new CraftedElement(23, "House", "Human-Made Objects", "Place to live", "Recipe");
    }
    else if (id == 24){
        return new CraftedElement(24, "City", "Human-Made Objects", "Large settlement", "Recipe");
    }
    else if (id == 25){
        return new CraftedElement(25, "Life", "Living Things", "Living existence", "Recipe");
    }
    else if (id == 26){
        return new CraftedElement(26, "Human", "Living Things", "A person", "Recipe");
    }
    else if (id == 27){
        return new CraftedElement(27, "Tool", "Human-Made Objects", "Used to perform work", "Recipe");
    }
    else if (id == 28){
        return new CraftedElement(28, "Village", "Human-Made Objects", "Small settlement", "Recipe");
    }
    return nullptr;
}