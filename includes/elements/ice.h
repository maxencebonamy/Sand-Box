#ifndef SANDBOX_ICE_H
#define SANDBOX_ICE_H

#include "elements/states/solid.h"

class Ice final : public Solid {

public:

    Ice(Vector2 position={});

    virtual ~Ice() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};


#endif //SANDBOX_ICE_H
