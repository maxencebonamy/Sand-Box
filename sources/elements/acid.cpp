#include "elements/acid.h"
#include "elements/void.h"

std::vector<sf::Color> acidColors {
    {137,255,0},
    {253,255,0}
};

Acid::Acid(Vector2 position) : Liquid(randVector(acidColors), position) {}

std::unique_ptr<Element> Acid::getNew(Vector2 position) { return std::make_unique<Acid>(position); }

std::string Acid::getName() const { return "acid"; }

void Acid::testMoves(const Map& map) {
    auto testMove { [this, &map](Vector2 targetPosition) -> bool {
        float x { targetPosition.getX() }, y { targetPosition.getY() };

        if (_isInBounds(targetPosition) && map[x][y]->getName() != "acid" && !map[x][y]->hasChanged()) {
            if (map[x][y]->getName() == "void" || !randInt(0, 99)) {
                setNextElement(std::make_unique<Void>(_position));
                map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
                return true;
            }
        }

        return false;
    } };

    if (testMove(_position + Vector2(0, 1))) {}
    else if (testMove(_position + Vector2(randInt(-2, 2), 1))) {}
    else if (testMove(_position + Vector2(randInt(-5, 5), 0))) {}
}
