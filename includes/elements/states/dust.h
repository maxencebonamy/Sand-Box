#ifndef SANDBOX_DUST_H
#define SANDBOX_DUST_H

#include "elements/element.h"

class Dust : public Element {

public:

    Dust(sf::Color color, Vector2 position={});

    virtual ~Dust() = default;

    virtual std::string getName() const override = 0;

    virtual int getWeight() const override;

    virtual bool canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) override;

    virtual void testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) override;

    virtual std::unique_ptr<Element> getNew(Vector2 position) override = 0;

};


#endif
