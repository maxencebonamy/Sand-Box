#ifndef SANDBOX_LIQUID_H
#define SANDBOX_LIQUID_H

#include "elements/element.h"

class Liquid : public Element {

public:

    Liquid(sf::Color color, Vector2 position={});

    virtual ~Liquid() = default;

    virtual std::string getName() const override = 0;

    virtual bool canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) override;

    virtual void testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) override;

    virtual std::unique_ptr<Element> getNew(Vector2 position) override = 0;

};

#endif
