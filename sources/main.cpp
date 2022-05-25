#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include <grid.h>


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE);
    window.setFramerateLimit(120);

    sf::Vector2i mouse_position;
    sf::Mouse mouse;

    Grid grid;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        mouse_position = mouse.getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            grid.setElement(mouse_position, SAND);
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            grid.setElement(mouse_position, WATER);
        }
        grid.update();

        window.clear(WINDOW_COLOR);

        grid.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}