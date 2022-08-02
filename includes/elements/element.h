#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics.hpp>
#include "utils/vector2.h"
#include "config.h"
#include "utils/utils.h"

class Element {

public:

    typedef std::vector<std::vector<std::unique_ptr<Element>>> Map;

    Element(sf::Color color, Vector2 position={});

    virtual ~Element() = default;

    virtual sf::Color getColor() const;

    virtual Vector2 getPosition() const;

    virtual std::string getName() const = 0;
    virtual int getWeight() const = 0;

    virtual void setNextPosition(Vector2 position);
    virtual Vector2 getNextPosition() const;

    virtual bool canMove(const Map& map, Vector2 position) = 0;

    virtual void update();

    virtual void testMoves(const Map& map) = 0;

    bool hasMoved() const;
    bool hasChanged() const;

    void setNextElement(std::unique_ptr<Element> nextElement);

    virtual std::unique_ptr<Element> getNew(Vector2 position) = 0;

    virtual std::unique_ptr<Element> getNextElement();

protected:

    bool _isInBounds(Vector2 position) const;

    std::vector<Vector2> _getNeighbors(const Map& map, const std::string& name) const;

    bool _hasMoved { false };
    bool _hasChanged { false };

    std::unique_ptr<Element> _nextElement;

    sf::Color _color;
    Vector2 _position;
    Vector2 _nextPosition;

};


#endif
