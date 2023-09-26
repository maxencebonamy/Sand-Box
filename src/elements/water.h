#ifndef SANDBOX_WATER_H
#define SANDBOX_WATER_H

#include "elements/states/liquid.h"

class Water final : public Liquid {

public:

    Water(Vector2 position={});

    virtual ~Water() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

    void testMoves(const Map& map) override;

};


#endif //SANDBOX_WATER_H
