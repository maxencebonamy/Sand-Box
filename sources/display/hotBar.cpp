#include "display/hotBar.h"

HotBar::HotBar() {

    float x { (WINDOW_SIZE.getX() - (Image::SIZE + 2 * Image::PADDING) * _nbElements) / 2 },
          y { WINDOW_SIZE.getY() - Image::SIZE - 2 * Image::PADDING };

    std::array<std::shared_ptr<Element>, _nbElements> elements {
        std::make_shared<Void>(),
        std::make_shared<Sand>(),
        std::make_shared<Water>(),
        std::make_shared<Steam>(),
        std::make_shared<Wood>(),
        std::make_shared<Fire>(),
        std::make_shared<Ash>(),
        std::make_shared<Stone>(),
        std::make_shared<Acid>(),
        std::make_shared<Snow>(),
        std::make_shared<Ice>()
    };

    for (int i { 0 }; i < _nbElements; ++i) {
        _images[i].setElement(elements[i]);
        _images[i].setPosition({ x + i * (Image::SIZE + 2 * Image::PADDING), y });
    }
}

void HotBar::display(sf::RenderWindow& window) {
    if (_isVisible) {
        for (auto& image: _images)
            image.display(window);
    }
}

void HotBar::updateVisibily() {
    _isVisible = !_isVisible;
}

void HotBar::updateEvents(const sf::Event& event, const Vector2& mousePosition) {
    if (_hasBeenUpdated) _hasBeenUpdated = false;

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) updateVisibily();

        else if (_isVisible && event.mouseButton.button == sf::Mouse::Left) {
            for (int i { 0 }; i < _nbElements; ++i) {
                Vector2 pos { mousePosition };
                if (_images[i].isSelected(pos)) {
                    _hasBeenUpdated = true;
                    _currentElement = _images[i].getElement();
                }
            }
        }
    }
}

std::shared_ptr<Element> HotBar::getElement() const {
    return _currentElement;
}

bool HotBar::hasBeenUpdated() const {
    return _hasBeenUpdated;
}

