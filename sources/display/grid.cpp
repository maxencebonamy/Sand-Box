#include "display/grid.h"


Grid::Grid(std::shared_ptr<Element> element) {
    _currentElement = std::move(element);

    _texture.create(GRID_SIZE.getX(), GRID_SIZE.getY());
    for (int i { 0 }; i < GRID_SIZE.getX() * GRID_SIZE.getY() * 4; ++i) _pixels.push_back(255);
    _texture.update(_pixels.data());

    _sprite.setTexture(_texture);
    _sprite.setScale(CELL_SIZE, CELL_SIZE);

    for (int i { 0 }; i < GRID_SIZE.getX(); ++i) {
        _map.push_back({ });
        for (int j { 0 }; j < GRID_SIZE.getY(); ++j)
            _map[i].push_back(std::make_unique<Void>(Vector2(i, j)));
    }
}

void Grid::updateSimulation() {
    _updateElements();

    sf::Uint8* ptr { _pixels.data() };
    for (int j { 0 }; j < GRID_SIZE.getY(); ++j) {
        for (int i { 0 }; i < GRID_SIZE.getX(); ++i) {
            sf::Color color { _map[i][j]->getColor() };

            if (color != sf::Color(*ptr, *(ptr+1), *(ptr+2))) {
                *ptr++ = color.r;
                *ptr++ = color.g;
                *ptr++ = color.b;
                ptr++;
            }
            else {
                ptr += 4;
            }
        }
    }

    _texture.update(_pixels.data());
    _sprite.setTexture(_texture);
}

void Grid::_updateElements() {
    for (int j { 0 }; j < GRID_SIZE.getY(); ++j) {
        for (int i { 0 }; i < GRID_SIZE.getX(); ++i) {
            _map[i][j]->testMoves(_map);
        }
    }
    for (int j { 0 }; j < GRID_SIZE.getY(); ++j) {
        for (int i { 0 }; i < GRID_SIZE.getX(); ++i) {
            if (_map[i][j]->hasChanged()) {
                _map[i][j] = _map[i][j]->getNextElement();
            }
        }
    }
}

void Grid::display(sf::RenderWindow& window) {
    window.draw(_sprite);
}

void Grid::updateEvents(const sf::Event& event, const Vector2& mousePosition) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) _isMouseClicking = true;
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) _isMouseClicking = false;

    if (_isMouseClicking) {
        Vector2 mousePos { mousePosition / CELL_SIZE };

        if (!_isInBounds(mousePos)) return;

        for (int i { -RADIUS }; i <= RADIUS; ++i ) {
            for (int j { -RADIUS }; j <= RADIUS; ++j) {
                Vector2 dPos { static_cast<float>(i), static_cast<float>(j) };
                Vector2 newPos { mousePos.getX() + i, mousePos.getY() + j };
                if (_isInBounds(mousePos + dPos) && dPos.getNorm() <= RADIUS &&
                    (_map[newPos.getX()][newPos.getY()]->getName() == "void" || _currentElement->getName() == "void")) {
                    _map[newPos.getX()][newPos.getY()] = _currentElement->getNew(newPos);
                }
            }
        }
    }
}

void Grid::setElement(std::shared_ptr<Element> element) {
    _currentElement = std::move(element);
}

bool Grid::_isInBounds(Vector2 position) {
    return position.getX() >= 0 && position.getX() < GRID_SIZE.getX() &&
           position.getY() >= 0 && position.getY() < GRID_SIZE.getY();
}

void Grid::_swap(Vector2 positionA, Vector2 positionB) {
    float xA { positionA.getX() }, yA { positionA.getY() },
          xB { positionB.getX() }, yB { positionB.getY() };

    std::swap(_map[xA][yA], _map[xB][yB]);

    _map[xA][yA]->update();
    _map[xB][yB]->update();
}
