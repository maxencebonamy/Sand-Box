#ifndef SANDBOX_FIRE_H
#define SANDBOX_FIRE_H

#include "element.h"

class Fire final : public Element {

public:
    Fire(Vector2 position={});

    bool canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) override;

    void testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) override;

    std::unique_ptr<Element> getNew(Vector2 position) override;

    std::string getName() const override;
    int getWeight() const override;


};


#endif //SANDBOX_FIRE_H
