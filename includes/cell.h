#ifndef SANDBOX_CELL_H
#define SANDBOX_CELL_H

#include "element.h"
#include "config.h"


class Cell {

public:
    Cell(sf::Vector2f position, Element element);
    void display(sf::RenderWindow &window);

    void setElement(Element newElement);
    Element getElement();

private:
    sf::Vector2f position;
    Element element = VOID;

    sf::RectangleShape rectangle;
};


#endif
