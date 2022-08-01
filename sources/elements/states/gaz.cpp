#include "elements/states/gaz.h"

Gaz::Gaz(sf::Color color, Vector2 position) : Element(color, position) {}

bool Gaz::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Gaz::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
//    _hasMoved = false;
//
//    Vector2 testPosition { _position + Vector2(randInt(-1, 1), -1) };
//    float x { testPosition.getX() }, y { testPosition.getY() };
//
//    if (_isInBounds(testPosition) && _weight > map[x][y]->getWeight()) {
//        _hasMoved = true;
//        setNextPosition(testPosition);
//    }
}