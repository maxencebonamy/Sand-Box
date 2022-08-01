#include "elements/snow.h"

Snow::Snow(Vector2 position) : Dust({ 236, 255, 253 }, position) {}

std::unique_ptr<Element> Snow::getNew(Vector2 position) { return std::make_unique<Snow>(position); }

std::string Snow::getName() const { return "snow"; }