#ifndef SANDBOX_HOTBAR_H
#define SANDBOX_HOTBAR_H

#include "image.h"
#include "config.h"
#include "elements/element.h"
#include "elements/acid.h"
#include "elements/ash.h"
#include "elements/fire.h"
#include "elements/ice.h"
#include "elements/sand.h"
#include "elements/snow.h"
#include "elements/steam.h"
#include "elements/stone.h"
#include "elements/void.h"
#include "elements/water.h"
#include "elements/wood.h"
#include <memory>

class HotBar {

public:
    HotBar();

    void display(sf::RenderWindow& window);

    void updateVisibily();

    void updateEvents(const sf::Event& event, const Vector2& mousePosition);

    std::shared_ptr<Element> getElement() const;

    bool hasBeenUpdated() const;

private:

    std::array<Image, 11> _images;

    bool _isVisible { true };

    std::shared_ptr<Element> _currentElement { std::make_shared<Sand>() };

    bool _hasBeenUpdated { false };

    static const int _nbElements { 11 };

};

#endif
