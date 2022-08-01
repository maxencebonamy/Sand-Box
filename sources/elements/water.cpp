#include "elements/water.h"

Water::Water(Vector2 position) : Liquid({ 23, 27, 65 }, position) {}

std::unique_ptr<Element> Water::getNew(Vector2 position) { return std::make_unique<Water>(position); }

std::string Water::getName() const { return "water"; }