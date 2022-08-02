#include "elements/states/liquid.h"

Liquid::Liquid(sf::Color color, Vector2 position) : Element(color, position) {}

bool Liquid::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Liquid::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    auto testMove { [this, &map](Vector2 targetPosition) -> bool {
        float x { targetPosition.getX() }, y { targetPosition.getY() };

        if (_isInBounds(targetPosition) && map[x][y]->getName() == "void" && !map[x][y]->hasChanged()) {
            setNextElement(map[x][y]->getNew(_position));
            map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
            return true;
        }

        return false;
    } };

    if (testMove(_position + Vector2(0, 1))) {}
    else if (testMove(_position + Vector2(randInt(-2, 2), 1))) {}
    else if (testMove(_position + Vector2(randInt(-5, 5), 0))) {}

//    Vector2 targetPosition { _position + Vector2(randInt(-5, 5), randInt(0, 1)) };

}

int Liquid::getWeight() const {
    return 1;
}
