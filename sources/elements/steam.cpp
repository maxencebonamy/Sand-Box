#include "elements/steam.h"

Steam::Steam(Vector2 position) : Gaz({ 22, 25, 20 }, position) {}

std::unique_ptr<Element> Steam::getNew(Vector2 position) { return std::make_unique<Steam>(position); }

std::string Steam::getName() const { return "steam"; }