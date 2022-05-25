#include "grid.h"


Grid::Grid() {
    this->grid_size = window_size / CELL_SIZE;

    for (int y = 0; y < this->grid_size.y; y++) {
        world.push_back(std::vector<Cell>());
        previous_world.push_back(std::vector<Cell>());
        for (int x = 0; x < this->grid_size.x; x++) {
            world[y].push_back(Cell(sf::Vector2f(x, y), VOID));
            previous_world[y].push_back(Cell(sf::Vector2f(x, y), VOID));
        }
    }
}


void Grid::display(sf::RenderWindow &window) {
    for (int y = 0; y < this->grid_size.y; y++) {
        for (int x = 0; x < this->grid_size.x; x++) {
            world[y][x].display(window);
        }
    }
}


void Grid::update() {
    for (int y = 0; y < grid_size.y; y++) {
        for (int x = 0; x < grid_size.x; x++) {
            Element element = previous_world[y][x].getElement();
            if (element == SAND) {
                if (move(sf::Vector2i(x, y), sf::Vector2i(x, y+1))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x+1, y+1))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x-1, y+1))) {}
            }
            else if (element == WATER) {
                if (move(sf::Vector2i(x, y), sf::Vector2i(x, y+1))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x+1, y+1))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x-1, y+1))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x+1, y))) {}
                else if (move(sf::Vector2i(x, y), sf::Vector2i(x-1, y))) {}
            }
        }
    }

    for (int y = 0; y < this->grid_size.y; y++) {
        for (int x = 0; x < this->grid_size.x; x++) {
            if (world[y][x].getElement() != previous_world[y][x].getElement())
                previous_world[y][x].setElement(world[y][x].getElement());
        }
    }
}


bool Grid::isInBounds(sf::Vector2i position) {
    return 0 <= position.x && position.x < grid_size.x && 0 <= position.y && position.y < grid_size.y;
}


void Grid::setElement(sf::Vector2i position, Element newElement) {
    for (int i = -BRUSH_RADIUS; i <= BRUSH_RADIUS; i++) {
        for (int j = -BRUSH_RADIUS; j <= BRUSH_RADIUS; j++) {
            if (i*i + j*j < BRUSH_RADIUS*BRUSH_RADIUS) {
                sf::Vector2i coords(position.x / CELL_SIZE + i, position.y / CELL_SIZE + j);
                if (this->isInBounds(coords)) {
                    world[coords.y][coords.x].setElement(newElement);
                    previous_world[coords.y][coords.x].setElement(newElement);
                }
            }
        }
    }
}


bool Grid::canMove(sf::Vector2i from, sf::Vector2i to) {
    if (isInBounds(to)) {
        Element fromElement = world[from.y][from.x].getElement();
        Element toElement = world[to.y][to.x].getElement();
        if (fromElement == SAND && toElement == WATER) return true;
        else if (fromElement == SAND && toElement == VOID) return true;
        else if (fromElement == WATER && toElement == VOID) return true;
        return false;
    }
    return false;
}

bool Grid::move(sf::Vector2i from, sf::Vector2i to) {
    if (canMove(from, to)) {
        Element fromElement = world[from.y][from.x].getElement();
        Element toElement = world[to.y][to.x].getElement();
        world[from.y][from.x].setElement(toElement);
        world[to.y][to.x].setElement(fromElement);
        return true;
    }
    return false;
}
