#include "elements/ice.h"

std::vector<sf::Color> iceColors {
    {192, 247, 255},
    {148, 247, 255}
};

Ice::Ice(Vector2 position) : Solid(randVector(iceColors), position) {}

std::unique_ptr<Element> Ice::getNew(Vector2 position) { return std::make_unique<Ice>(position); }

std::string Ice::getName() const { return "ice"; }