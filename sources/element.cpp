#include "element.h"


Element::Element(std::string name, sf::Color color) {
    this->name = name;
    this->color = color;
}


sf::Color Element::getColor() {
    return this->color;
}


bool Element::operator==(Element other) {
    return this->name == other.name;
}

bool Element::operator!=(Element other) {
    return !(*this == other);
}
