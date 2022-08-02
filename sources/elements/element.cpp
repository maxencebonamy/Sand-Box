#include "elements/element.h"


Element::Element(sf::Color color, Vector2 position) :
_color(color), _position(position) {}

sf::Color Element::getColor() const { return _color; }

Vector2 Element::getPosition() const { return _position; }

void Element::setNextPosition(Vector2 position) {
    _nextPosition = position;
}

void Element::update() {
    if (_hasMoved) {
        _position = _nextPosition;
        _hasMoved = false;
    }
}

bool Element::_isInBounds(Vector2 position) {
    return position.getX() >= 0 && position.getX() < GRID_SIZE.getX() &&
           position.getY() >= 0 && position.getY() < GRID_SIZE.getY();
}

bool Element::hasMoved() const { return _hasMoved; }

Vector2 Element::getNextPosition() const {
    return _nextPosition;
}

bool Element::hasChanged() const {
    return _hasChanged;
}

std::unique_ptr<Element> Element::getNextElement() {
    return std::move(_nextElement);
}

void Element::setNextElement(std::unique_ptr<Element> nextElement) {
    if (!_hasChanged) {
        _hasChanged = true;
        _nextElement = std::move(nextElement);
    }
}

std::vector<Vector2> Element::_getNeighbors(const Map& map, const std::string& name) const {
    float x { _position.getX() }, y { _position.getY() };
    std::vector<Vector2> result;

    for (int i { -1 }; i <= 1; ++i) {
        for (int j { -1 }; j <= 1; ++j) {
            if ((i != 0 || j != 0) && map[x + i][y + j]->getName() == name) result.push_back({ x + i, y + j });
        }
    }

    return result;
}

