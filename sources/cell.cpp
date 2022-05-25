#include "cell.h"


Cell::Cell(sf::Vector2f position, Element element) {
    this->position = position;
    this->element = element;

    this->rectangle = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    this->rectangle.setPosition(position * CELL_SIZE);
    this->rectangle.setFillColor(element.getColor());
}


void Cell::display(sf::RenderWindow &window) {
    window.draw(rectangle);
}


void Cell::setElement(Element newElement) {
    this->element = newElement;
    this->rectangle.setFillColor(element.getColor());
}

Element Cell::getElement() {
    return this->element;
}
