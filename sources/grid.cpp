#include "grid.h"


Grid::Grid() {
    grid_size = window_size / CELL_SIZE;

    for (int y = 0; y < grid_size.y; y++) {
        world.push_back(std::vector<Cell>());
        previous_world.push_back(std::vector<Cell>());
        for (int x = 0; x < grid_size.x; x++) {
            world[y].push_back(Cell(sf::Vector2f(x, y), VOID));
            previous_world[y].push_back(Cell(sf::Vector2f(x, y), VOID));
        }
    }
}


void Grid::display(sf::RenderWindow &window) {
    for (int y = 0; y < grid_size.y; y++) {
        for (int x = 0; x < grid_size.x; x++) {
            world[y][x].display(window);
        }
    }
}

// todo: Problème de génération de vapeur avec le feu (same pour glace et neige)
// todo: Menu de choix d'élément (avec le clic droit par exemple)
// todo: Ajouter la possibilité de changer la taille du cercle de génération (avec le scroll par exemple)



void Grid::update() {
    for (int y = 0; y < grid_size.y; y++) {
        for (int x = 0; x < grid_size.x; x++) {
            Element element = previous_world[y][x].getElement();
            sf::Vector2i position(x, y);

            if (element == STEAM && rand() % 100 == 0) world[y][x].setElement(WATER);
            else if (element == FIRE && !hasNeighbor(position, WOOD)) world[y][x].setElement(VOID);
            else if (element == ICE) {
//                if (hasOtherNeighbor(position, ICE) && rand() % 500 == 0) world[y][x].setElement(WATER);
                if (hasNeighbor(position, FIRE) && rand() % 2 == 0) world[y][x].setElement(WATER);
            }
            else if (element == SNOW) {
//                if (hasOtherNeighbor(position, ICE) && rand() % 500 == 0) world[y][x].setElement(WATER);
                if (hasNeighbor(position, FIRE) && rand() % 2 == 0) world[y][x].setElement(WATER);
            }
            else if (element == WATER) {
                if (hasNeighbor(position, FIRE) && rand() % 2 == 0) world[y][x].setElement(STEAM);
            }
//            else if (element == ICE && hasOtherNeighbor(position, ICE) && rand() % 500 == 0) world[y][x].setElement(WATER);
//            else if (element == SNOW && hasOtherNeighbor(position, SNOW) && rand() % 500 == 0) world[y][x].setElement(WATER);

            if (element.getState() == LIQUID) {
                std::vector<sf::Vector2i> down = {{x-1, y+1}, {x, y+1}, {x+1, y+1}};
                for (sf::Vector2i pos: shufflePositions(down)) {
                    if (move(position, pos)) break;
                }
                std::vector<sf::Vector2i> center = {{x-1, y}, {x+1, y}};
                for (sf::Vector2i pos: shufflePositions(center)) {
                    if (move(position, pos)) break;
                }
            }
            else if (element.getState() == PLASMA) {
                int n = rand() % 20;
                if (n == 0) move(position, sf::Vector2i(x, y+1));
                else if (n == 1) move(position, sf::Vector2i(x, y-1));
                else if (n == 2) move(position, sf::Vector2i(x+1, y));
                else if (n == 3) move(position, sf::Vector2i(x-1, y));
            }
            else if (element.getState() == DUST) {
                int n = rand() % 3 - 1;
                move(position, sf::Vector2i(x + n, y+1));
            }
            else if (element.getState() == GAZ) {
                int n = rand() % 3 - 1;
                move(position, sf::Vector2i(x + n, y-1));
            }
        }
    }

    for (int y = 0; y < grid_size.y; y++) {
        for (int x = 0; x < grid_size.x; x++) {
            if (world[y][x].getElement() != previous_world[y][x].getElement())
                previous_world[y][x].setElement(world[y][x].getElement());
        }
    }
}


bool Grid::isInBounds(sf::Vector2i position) {
    return 0 <= position.x && position.x < grid_size.x && 0 <= position.y && position.y < grid_size.y;
}


void Grid::setElement(sf::Vector2i position, Element newElement) {
    if (0 <= position.x && position.x < WINDOW_SIZE.x && 0 <= position.y && position.y < WINDOW_SIZE.y) {
        for (int i = -BRUSH_RADIUS; i <= BRUSH_RADIUS; i++) {
            for (int j = -BRUSH_RADIUS; j <= BRUSH_RADIUS; j++) {
                if (i*i + j*j < BRUSH_RADIUS*BRUSH_RADIUS && (newElement.getState() == SOLID || rand() % 3 == 0)) {
                    sf::Vector2i coords(position.x / CELL_SIZE + i, position.y / CELL_SIZE + j);
                    if (isInBounds(coords) && (world[coords.y][coords.x].getElement() == VOID || newElement == VOID)) {
                        world[coords.y][coords.x].setElement(newElement);
                        previous_world[coords.y][coords.x].setElement(newElement);
                    }
                }
            }
        }
    }
}


bool Grid::hasNeighbor(sf::Vector2i position, Element element) {
    int x = position.x, y = position.y;

    for (sf::Vector2i dir: directions) {
        if (isInBounds(position + dir) && world[y + dir.y][x + dir.x].getElement() == element) return true;
    }
    return false;
}

bool Grid::hasOtherNeighbor(sf::Vector2i position, Element element) {
    int x = position.x, y = position.y;

    for (sf::Vector2i dir: directions) {
        if (isInBounds(position + dir) && world[y + dir.y][x + dir.x].getElement() != element) return true;
    }
    return false;
}


bool Grid::canMove(sf::Vector2i from, sf::Vector2i to) {
    if (isInBounds(to)) {
        Element fromElement = world[from.y][from.x].getElement();
        Element toElement = world[to.y][to.x].getElement();

        if (toElement == VOID) return true;
        if (fromElement == SAND && toElement == WATER) return true;
        if (fromElement == ASH && toElement == WATER) return true;
        if (fromElement == ACID && toElement != ACID) return true;
        if (fromElement == FIRE && (toElement == WATER || toElement == ICE || toElement == SNOW || toElement == WOOD)) return true;

        return false;
    }
    return false;
}

bool Grid::move(sf::Vector2i from, sf::Vector2i to) {
    if (canMove(from, to)) {
        Element fromElement = world[from.y][from.x].getElement();
        Element toElement = world[to.y][to.x].getElement();

        if (fromElement == WATER && hasNeighbor(from, FIRE)) fromElement = STEAM;
        if (fromElement == ICE && hasNeighbor(from, FIRE)) fromElement = WATER;
        if (fromElement == SNOW && hasNeighbor(from, FIRE)) fromElement = WATER;

        if (fromElement == ACID) {
            if (toElement == WATER) fromElement = WATER;
            else if (toElement != VOID) {
                toElement = VOID;
                if (rand() % 2 == 0) fromElement = VOID;
            }
        }

        if (fromElement == FIRE) {
            if (hasNeighbor(from, WATER)) fromElement = VOID;
            if (hasNeighbor(from, ICE)) fromElement = WATER;
            if (toElement == VOID && !hasNeighbor(from, WOOD)) fromElement = VOID;
            else {
                int n = rand() % 10;
                if (n == 0) toElement = ASH;
                else if (n < 9) toElement = FIRE;
                else toElement = VOID;
            }
        }

        world[from.y][from.x].setElement(toElement);
        world[to.y][to.x].setElement(fromElement);
        return true;
    }
    return false;
}


std::vector<sf::Vector2i> Grid::shufflePositions(std::vector<sf::Vector2i> positions) {
    std::vector<sf::Vector2i> result;
    int n;

    while (!positions.empty()) {
        n = rand() % positions.size();
        sf::Vector2i element = positions[n];
        result.push_back(element);
        positions.erase(std::remove(positions.begin(), positions.end(), element), positions.end());
    }

    return result;
}
