#include "element.h"


Element::Element(std::string name, sf::Keyboard::Key key, std::vector<sf::Color> colors, State state) {
    this->name = name;
    this->key = key;
    this->colors = colors;
    this->state = state;
}


std::string Element::getName() {
    return name;
}

sf::Color Element::getColor() {
    int n = rand() % colors.size();
    return colors[n];
}

sf::Keyboard::Key Element::getKey() {
    return key;
}

State Element::getState() {
    return state;
}


bool Element::operator==(Element other) {
    return name == other.name;
}

bool Element::operator!=(Element other) {
    return !(*this == other);
}
