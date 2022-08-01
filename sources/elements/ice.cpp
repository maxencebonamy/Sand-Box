#include "elements/ice.h"

Ice::Ice(Vector2 position) : Solid({ 148, 247, 255 }, position) {}

std::unique_ptr<Element> Ice::getNew(Vector2 position) { return std::make_unique<Ice>(position); }

std::string Ice::getName() const { return "ice"; }