#include "elements/sand.h"

std::vector<sf::Color> sandColors {
    { 246, 215, 176 },
    { 242, 210, 169 },
    { 236, 204, 162 },
    { 231, 196, 150 },
    { 225, 191, 146 }
};

Sand::Sand(Vector2 position) : Dust(randVector(sandColors), position) {}

std::unique_ptr<Element> Sand::getNew(Vector2 position) { return std::make_unique<Sand>(position); }

std::string Sand::getName() const { return "sand"; }