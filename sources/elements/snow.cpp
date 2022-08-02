#include "elements/snow.h"
#include "elements/water.h"

std::vector<sf::Color> snowColors {
    { 255, 255, 255 },
    { 236, 255, 253 },
    { 208, 236, 235 }
};

Snow::Snow(Vector2 position) : Dust(randVector(snowColors), position) {}

std::unique_ptr<Element> Snow::getNew(Vector2 position) { return std::make_unique<Snow>(position); }

std::string Snow::getName() const { return "snow"; }

void Snow::testMoves(const Map& map) {
    if (!randInt(0, 9999)) setNextElement(std::make_unique<Water>(_position));

    Dust::testMoves(map);
}