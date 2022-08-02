#include "elements/ash.h"

std::vector<sf::Color> ashColors {
        {208,198,198},
        {195,185,185},
        {180,168,168},
        {169,157,157},
        {159,147,147}
};

Ash::Ash(Vector2 position) : Dust(randVector(ashColors), position) {}

std::unique_ptr<Element> Ash::getNew(Vector2 position) { return std::make_unique<Ash>(position); }

std::string Ash::getName() const { return "ash"; }