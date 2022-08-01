#include "elements/fire.h"

Fire::Fire(Vector2 position) : Element({ 255, 154, 0 }, position) {}

bool Fire::canMove(const std::vector<std::vector<std::unique_ptr<Element>>>& map, Vector2 position) {
    return false;
}

void Fire::testMoves(const std::vector<std::vector<std::unique_ptr<Element>>>& map) {

}

std::unique_ptr<Element> Fire::getNew(Vector2 position) { return std::make_unique<Fire>(position); }

std::string Fire::getName() const { return "fire"; }