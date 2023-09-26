#ifndef SANDBOX_GRID_H
#define SANDBOX_GRID_H

#include "config.h"
#include "elements/element.h"
#include "elements/void.h"
#include "elements/sand.h"
#include <memory>

class Grid {

public:
    Grid(std::shared_ptr<Element> element);

    void updateSimulation();

    void display(sf::RenderWindow& window);

    void updateEvents(const sf::Event& event, const Vector2& mousePosition);

    void setElement(std::shared_ptr<Element> element);

private:
    void _updateElements();

    bool _isInBounds(Vector2 position);

    void _swap(Vector2 positionA, Vector2 positionB);

    sf::Texture _texture;
    std::vector<sf::Uint8> _pixels;
    sf::Sprite _sprite;

    const int RADIUS { 5 };

    bool _isMouseClicking { false };

    std::shared_ptr<Element> _currentElement;

    Element::Map _map;
};

#endif
