#include "elements/wood.h"

std::vector<sf::Color> woodColors {
//    { 49, 18, 4 },
    { 65, 42, 30 }
};

Wood::Wood(Vector2 position) : Solid(randVector(woodColors), position) {}

std::unique_ptr<Element> Wood::getNew(Vector2 position) { return std::make_unique<Wood>(position); }

std::string Wood::getName() const { return "wood"; }