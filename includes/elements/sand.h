#ifndef SANDBOX_SAND_H
#define SANDBOX_SAND_H

#include "states/dust.h"

class Sand final : public Dust {

public:

    Sand(Vector2 position={});

    virtual ~Sand() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};


#endif //SANDBOX_SAND_H
