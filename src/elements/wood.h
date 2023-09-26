#ifndef SANDBOX_WOOD_H
#define SANDBOX_WOOD_H


#include "elements/states/solid.h"

class Wood final : public Solid {

public:

    Wood(Vector2 position={});

    virtual ~Wood() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};


#endif