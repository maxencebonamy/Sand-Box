#include "cell.h"


Cell::Cell(sf::Vector2f position, Element element) {
    this->position = position;
    this->element = element;

    rectangle = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    rectangle.setPosition(position * CELL_SIZE);
    rectangle.setFillColor(element.getColor());
}


void Cell::display(sf::RenderWindow &window) {
    window.draw(rectangle);
}


void Cell::setElement(Element newElement) {
    element = newElement;
    rectangle.setFillColor(element.getColor());
}

Element Cell::getElement() {
    return element;
}
