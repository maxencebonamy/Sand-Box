#include "elements/wood.h"

Wood::Wood(Vector2 position) : Solid({ 49, 18, 4 }, position) {}

std::unique_ptr<Element> Wood::getNew(Vector2 position) { return std::make_unique<Wood>(position); }

std::string Wood::getName() const { return "wood"; }