#include "elements/states/liquid.h"

Liquid::Liquid(sf::Color color, Vector2 position) : Element(color, position) {}

bool Liquid::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Liquid::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {

}
