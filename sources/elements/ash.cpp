#include "elements/ash.h"

Ash::Ash(Vector2 position) : Dust({ 208, 198, 198 }, position) {}

std::unique_ptr<Element> Ash::getNew(Vector2 position) { return std::make_unique<Ash>(position); }

std::string Ash::getName() const { return "ash"; }