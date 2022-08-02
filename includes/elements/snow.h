#ifndef SANDBOX_SNOW_H
#define SANDBOX_SNOW_H

#include "elements/states/dust.h"

class Snow final : public Dust {

public:

    Snow(Vector2 position={});

    virtual ~Snow() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

    void testMoves(const Map& map) override;

};


#endif //SANDBOX_SNOW_H
