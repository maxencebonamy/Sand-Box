#include "elements/void.h"

std::vector<sf::Color> voidColors {
    { 12, 15, 10 }
};

Void::Void(Vector2 position) : Solid(randVector(voidColors), position) {}

std::unique_ptr<Element> Void::getNew(Vector2 position) {
    return std::make_unique<Void>(position);
}

std::string Void::getName() const { return "void"; }