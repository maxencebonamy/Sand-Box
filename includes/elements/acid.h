#ifndef SANDBOX_ACID_H
#define SANDBOX_ACID_H

#include "states/liquid.h"

class Acid final : public Liquid {

public:

    Acid(Vector2 position={});

    virtual ~Acid() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};

#endif
