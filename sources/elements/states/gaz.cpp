#include "elements/states/gaz.h"
#include "elements/water.h"

Gaz::Gaz(sf::Color color, Vector2 position) : Element(color, position) {}

bool Gaz::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Gaz::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    Vector2 targetPosition { _position + Vector2(randInt(-3, 3), randInt(-1, -3)) };
    float x { targetPosition.getX() }, y { targetPosition.getY() };

    if (_isInBounds(targetPosition) && !map[x][y]->hasChanged() &&
        (map[x][y]->getName() == "void" || map[x][y]->getName() == "water")) {
        setNextElement(map[x][y]->getNew(_position));
        map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
    }
}

int Gaz::getWeight() const {
    return -1;
}
