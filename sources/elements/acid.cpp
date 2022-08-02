#include "elements/acid.h"
#include "elements/void.h"

std::vector<sf::Color> acidColors {
    {137,255,0},
    {253,255,0}
};

Acid::Acid(Vector2 position) : Liquid(randVector(acidColors), position) {}

std::unique_ptr<Element> Acid::getNew(Vector2 position) { return std::make_unique<Acid>(position); }

std::string Acid::getName() const { return "acid"; }

void Acid::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {
    Vector2 targetPosition { _position + Vector2(randInt(-3, 3), randInt(0, 1)) };
    float x { targetPosition.getX() }, y { targetPosition.getY() };

    if (_isInBounds(targetPosition) && map[x][y]->getName() != "acid" && !map[x][y]->hasChanged()) {
        setNextElement(std::make_unique<Void>(_position));
        map[x][y]->setNextElement(getNew(map[x][y]->getPosition()));
    }
}
