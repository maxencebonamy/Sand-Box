#ifndef SANDBOX_VOID_H
#define SANDBOX_VOID_H

#include "states/solid.h"

class Void final : public Solid {

public:

    Void(Vector2 position={});

    virtual ~Void() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};

#endif //SANDBOX_VOID_H
