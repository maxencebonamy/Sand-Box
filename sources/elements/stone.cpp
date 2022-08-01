#include "elements/stone.h"

Stone::Stone(Vector2 position) : Solid({ 92, 73, 73 }, position) {}

std::unique_ptr<Element> Stone::getNew(Vector2 position) { return std::make_unique<Stone>(position); }

std::string Stone::getName() const { return "stone"; }