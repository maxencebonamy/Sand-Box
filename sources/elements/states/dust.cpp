#include "elements/states/dust.h"


Dust::Dust(sf::Color color, Vector2 position) : Element(color, position) {}

bool Dust::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Dust::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    Vector2 targetPosition { _position + Vector2(randInt(-1, 1), randInt(1, 3)) };
    float x { targetPosition.getX() }, y { targetPosition.getY() };

    if (_isInBounds(targetPosition) && (map[x][y]->getName() == "void" || map[x][y]->getName() == "water")) {
        setNextElement(map[x][y]->getNew(_position));
        map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
    }
}

int Dust::getWeight() const {
    return 2;
}
