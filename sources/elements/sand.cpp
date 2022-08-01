#include "elements/sand.h"

Sand::Sand(Vector2 position) : Dust({ 242, 210, 169 }, position) {}

std::unique_ptr<Element> Sand::getNew(Vector2 position) { return std::make_unique<Sand>(position); }

std::string Sand::getName() const { return "sand"; }