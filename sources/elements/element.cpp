#include "elements/element.h"


Element::Element(sf::Color color, Vector2 position) :
_color(color), _position(position) {}

sf::Color Element::getColor() const { return _color; }

Vector2 Element::getPosition() const { return _position; }

void Element::setNextPosition(Vector2 position) {
    _nextPosition = position;
}

void Element::update() {
    if (_position != _nextPosition) _position = _nextPosition;
}

bool Element::_isInBounds(Vector2 position) {
    return position.getX() >= 0 && position.getX() < GRID_SIZE.getX() &&
           position.getY() >= 0 && position.getY() < GRID_SIZE.getY();
}

bool Element::hasMoved() const { return _hasMoved; }

