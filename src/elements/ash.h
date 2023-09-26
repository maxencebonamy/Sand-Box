#ifndef SANDBOX_ASH_H
#define SANDBOX_ASH_H

#include "states/dust.h"

class Ash final : public Dust {

public:

    Ash(Vector2 position={});

    virtual ~Ash() = default;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;

};


#endif //SANDBOX_ASH_H
