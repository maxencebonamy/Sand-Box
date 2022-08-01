#ifndef SANDBOX_SOLID_H
#define SANDBOX_SOLID_H

#include "elements/element.h"

class Solid : public Element {

public:
    Solid(sf::Color color, Vector2 position={});

    virtual ~Solid() = default;

    virtual std::string getName() const override = 0;

    virtual bool canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) override;

    virtual void testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) override;

    virtual std::unique_ptr<Element> getNew(Vector2 position) override = 0;

protected:

    static const int _weight { 0 };

};

#endif //SANDBOX_SOLID_H
