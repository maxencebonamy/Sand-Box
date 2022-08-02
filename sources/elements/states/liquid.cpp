#include "elements/states/liquid.h"

Liquid::Liquid(sf::Color color, Vector2 position) : Element(color, position) {}

bool Liquid::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Liquid::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    Vector2 targetPosition { _position + Vector2(randInt(-5, 5), randInt(0, 2)) };
    float x { targetPosition.getX() }, y { targetPosition.getY() };

    if (_isInBounds(targetPosition) && map[x][y]->getName() == "void") {
        setNextElement(map[x][y]->getNew(_position));
        map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
    }
}

int Liquid::getWeight() const {
    return 1;
}
