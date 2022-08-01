#include "elements/void.h"

Void::Void(Vector2 position) : Solid({ 12, 15, 10 }, position) {}

std::unique_ptr<Element> Void::getNew(Vector2 position) {
    return std::make_unique<Void>(position);
}

std::string Void::getName() const { return "void"; }