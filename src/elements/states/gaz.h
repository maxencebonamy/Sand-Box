#ifndef SANDBOX_GAZ_H
#define SANDBOX_GAZ_H

#include "elements/element.h"

class Gaz : public Element {

public:

    Gaz(sf::Color color, Vector2 position={});

    virtual ~Gaz() = default;

    virtual std::string getName() const override = 0;

    virtual int getWeight() const override;

    virtual bool canMove(const Map& map, Vector2 position) override;

    virtual void testMoves(const Map& map) override;

    virtual std::unique_ptr<Element> getNew(Vector2 position) override = 0;

};

#endif
