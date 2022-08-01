#include "elements/acid.h"

Acid::Acid(Vector2 position) : Liquid({ 137, 255, 0 }, position) {}

std::unique_ptr<Element> Acid::getNew(Vector2 position) { return std::make_unique<Acid>(position); }

std::string Acid::getName() const { return "acid"; }