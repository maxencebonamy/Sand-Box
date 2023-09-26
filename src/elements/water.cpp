#include "elements/water.h"

std::vector<sf::Color> waterColors {
    { 23, 27, 65 },
    { 0, 31, 60 }
};

Water::Water(Vector2 position) : Liquid(randVector(waterColors), position) {}

std::unique_ptr<Element> Water::getNew(Vector2 position) { return std::make_unique<Water>(position); }

std::string Water::getName() const { return "water"; }

void Water::testMoves(const Element::Map& map) {
    for (auto& position : _getNeighbors(map, "acid")) {
        float x { position.getX() }, y { position.getY() };
        map[x][y]->setNextElement(std::make_unique<Water>(position));
    }

    Liquid::testMoves(map);
}
