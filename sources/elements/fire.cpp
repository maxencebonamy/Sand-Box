#include "elements/fire.h"
#include "elements/void.h"
#include "elements/steam.h"
#include "elements/ash.h"
#include "elements/water.h"

std::vector<sf::Color> fireColors {
        {255,0,0},
        {255,90,0},
        {255,154,0},
        {255,206,0},
        {255,232,8}
};

Fire::Fire(Vector2 position) : Element(randVector(fireColors), position) {}

bool Fire::canMove(const Map& map, Vector2 position) {
    return false;
}

void Fire::testMoves(const Map& map) {
    for (auto& neighbors : { _getNeighbors(map, "ice"), _getNeighbors(map, "snow") }) {
        for (auto& position : neighbors) {
            if (!randInt(0, 14)) {
                float x { position.getX() }, y { position.getY() };
                map[x][y]->setNextElement(std::make_unique<Water>(map[x][y]->getPosition()));
            }
        }
    }

    for (auto& position : _getNeighbors(map, "water")) {
        if (!randInt(0, 14)) {
            float x { position.getX() }, y { position.getY() };
            map[x][y]->setNextElement(std::make_unique<Steam>(map[x][y]->getPosition()));
        }
    }

    std::vector<Vector2> woodNeighbors { _getNeighbors(map, "wood") };

    if (woodNeighbors.empty() && !randInt(0, 4)) setNextElement(std::make_unique<Void>(_position));

    for (auto& position : woodNeighbors) {
        if (!randInt(0, 14)) {
            float x { position.getX() }, y { position.getY() };
            if (randInt(0, 9)) setNextElement(std::make_unique<Void>(_position));
            else setNextElement(std::make_unique<Ash>(_position));
            map[x][y]->setNextElement(std::make_unique<Fire>(map[x][y]->getPosition()));
        }
    }
}

std::unique_ptr<Element> Fire::getNew(Vector2 position) { return std::make_unique<Fire>(position); }

std::string Fire::getName() const { return "fire"; }

int Fire::getWeight() const {
    return 0;
}
