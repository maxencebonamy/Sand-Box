#include "elements/steam.h"
#include "elements/water.h"

std::vector<sf::Color> steamColors {
    { 22, 25, 20 }
};

Steam::Steam(Vector2 position) : Gaz(randVector(steamColors), position) {}

std::unique_ptr<Element> Steam::getNew(Vector2 position) { return std::make_unique<Steam>(position); }

std::string Steam::getName() const { return "steam"; }

void Steam::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    if (randInt(0, 1000) == 0) setNextElement(std::make_unique<Water>(_position));
    else Gaz::testMoves(map);
}
