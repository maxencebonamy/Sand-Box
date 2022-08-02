#include "elements/ice.h"
#include "elements/water.h"

std::vector<sf::Color> iceColors {
    {192, 247, 255},
    {148, 247, 255}
};

Ice::Ice(Vector2 position) : Solid(randVector(iceColors), position) {}

std::unique_ptr<Element> Ice::getNew(Vector2 position) { return std::make_unique<Ice>(position); }

std::string Ice::getName() const { return "ice"; }

void Ice::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    if (randInt(0, 1000) == 0) setNextElement(std::make_unique<Water>(_position));

    Solid::testMoves(map);
}
