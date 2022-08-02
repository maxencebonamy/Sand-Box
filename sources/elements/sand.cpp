#include "elements/sand.h"

std::vector<sf::Color> sandColors {
    { 242, 210, 169 }
};

Sand::Sand(Vector2 position) : Dust(randVector(sandColors), position) {}

std::unique_ptr<Element> Sand::getNew(Vector2 position) { return std::make_unique<Sand>(position); }

std::string Sand::getName() const { return "sand"; }