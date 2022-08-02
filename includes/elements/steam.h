#ifndef SANDBOX_STEAM_H
#define SANDBOX_STEAM_H

#include "elements/states/gaz.h"

class Steam final : public Gaz {

public:

    Steam(Vector2 position={});

    virtual ~Steam() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

    void testMoves(const Map& map) override;

};

#endif