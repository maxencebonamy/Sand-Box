#include "elements/acid.h"

std::vector<sf::Color> acidColors {
    {137,255,0},
    {253,255,0}
};

Acid::Acid(Vector2 position) : Liquid(randVector(acidColors), position) {}

std::unique_ptr<Element> Acid::getNew(Vector2 position) { return std::make_unique<Acid>(position); }

std::string Acid::getName() const { return "acid"; }