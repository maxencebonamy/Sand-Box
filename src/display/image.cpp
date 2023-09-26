#include "display/image.h"


// Getters

Vector2 Image::getPosition() const { return _position; }

std::shared_ptr<Element> Image::getElement() const { return _currentElement; }


// Setters

void Image::setPosition(Vector2 position) {
    _position = position;
    _sprite.setPosition(position.toSFML());
}

void Image::setElement(std::shared_ptr<Element> element) {
    _texture.loadFromFile("assets/" + element->getName() + ".png");
    _sprite = sf::Sprite(_texture);

    _currentElement = std::move(element);
}


// Methods

bool Image::isSelected(Vector2 mousePosition) const {
    float x { _position.getX() }, y { _position.getY() };

    return x <= mousePosition.getX() && mousePosition.getX() <= x + Image::SIZE &&
           y <= mousePosition.getY() && mousePosition.getY() <= y + Image::SIZE;
}

void Image::display(sf::RenderWindow& window) {
    window.draw(_sprite);
}

