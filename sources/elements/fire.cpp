#include "elements/fire.h"

std::vector<sf::Color> fireColors {
        {255,0,0},
        {255,90,0},
        {255,154,0},
        {255,206,0},
        {255,232,8}
};

Fire::Fire(Vector2 position) : Element(randVector(fireColors), position) {}

bool Fire::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Fire::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {

}

std::unique_ptr<Element> Fire::getNew(Vector2 position) { return std::make_unique<Fire>(position); }

std::string Fire::getName() const { return "fire"; }

int Fire::getWeight() const {
    return 0;
}
