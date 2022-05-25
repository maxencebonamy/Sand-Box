#ifndef SANDBOX_ELEMENT_H
#define SANDBOX_ELEMENT_H

#include <SFML/Graphics.hpp>


class Element {

public:
    Element(std::string name, sf::Color color);
    sf::Color getColor();

    bool operator==(Element other);
    bool operator!=(Element other);

private:
    std::string name;
    sf::Color color;

};

const Element VOID = Element("Void", sf::Color(13, 22, 11));
const Element WATER = Element("Water", sf::Color(34, 116, 165));
const Element SAND = Element("Sand", sf::Color(252, 158, 79));


#endif
