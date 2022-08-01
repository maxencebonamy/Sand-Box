#ifndef SANDBOX_IMAGE_H
#define SANDBOX_IMAGE_H

#include "elements/element.h"
#include "config.h"
#include <memory>
#include "elements/void.h"

class Image {

public:
    // Constructor
    Image() = default;

    // Getters
    Vector2 getPosition() const;
    std::shared_ptr<Element> getElement() const;

    // Setters
    void setPosition(Vector2 position);
    void setElement(std::shared_ptr<Element> element);

    // Methods
    bool isSelected(Vector2 mousePosition) const;
    void display(sf::RenderWindow& window);

    // Consts
    static const int SIZE { 80 };
    static const int PADDING { 10 };

private:
    // Attributes
    sf::Texture _texture;
    sf::Sprite _sprite;

    std::shared_ptr<Element> _currentElement { std::make_shared<Void>(Vector2()) };
    Vector2 _position;
};

#endif
