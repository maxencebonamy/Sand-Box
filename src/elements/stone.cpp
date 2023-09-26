#include "elements/stone.h"

std::vector<sf::Color> stoneColors {
    { 112, 121, 126 },
    { 133, 140, 144 }
};

Stone::Stone(Vector2 position) : Solid(randVector(stoneColors), position) {}

std::unique_ptr<Element> Stone::getNew(Vector2 position) { return std::make_unique<Stone>(position); }

std::string Stone::getName() const { return "stone"; }