#ifndef SANDBOX_GRID_H
#define SANDBOX_GRID_H

#include "cell.h"
#include "vector"
#include "element.h"
#include "config.h"
#include "iostream"
#include "assert.h"
#include "algorithm"


class Grid {

public:
    Grid();
    void display(sf::RenderWindow &window);
    void update();

    bool isInBounds(sf::Vector2i position);
    void setElement(sf::Vector2i position, Element newElement);

    bool hasNeighbor(sf::Vector2i position, Element element);
    bool hasOtherNeighbor(sf::Vector2i position, Element element);

    bool canMove(sf::Vector2i from, sf::Vector2i to);
    bool move(sf::Vector2i from, sf::Vector2i to);

    std::vector<sf::Vector2i> shufflePositions(std::vector<sf::Vector2i> positions);

private:
    sf::Vector2f window_size = WINDOW_SIZE;
    sf::Vector2f grid_size;

    std::vector<std::vector<Cell>> world;
    std::vector<std::vector<Cell>> previous_world;

    std::array<sf::Vector2i, 4> directions = {
            sf::Vector2i(-1, 0),
            sf::Vector2i(1, 0),
            sf::Vector2i(0, -1),
            sf::Vector2i(0, 1)
    };

};

#endif
