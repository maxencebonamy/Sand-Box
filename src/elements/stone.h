#ifndef SANDBOX_STONE_H
#define SANDBOX_STONE_H

#include "elements/states/solid.h"

class Stone final : public Solid {

public:

    Stone(Vector2 position={});

    virtual ~Stone() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};


#endif //SANDBOX_STONE_H
