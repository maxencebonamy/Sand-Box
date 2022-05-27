#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include <grid.h>


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), WINDOW_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Vector2i mouse_position;
    sf::Mouse mouse;

    Grid grid;
    Element current_element = SAND;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        grid.update();

        mouse_position = mouse.getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            grid.setElement(mouse_position, current_element);
        }
        else {
            for (Element element: ELEMENTS) {
                if (sf::Keyboard::isKeyPressed(element.getKey()) && current_element != element) {
                    current_element = element;
                    std::cout << element.getName() << std::endl;
                    break;
                }
            }
        }

        window.clear(WINDOW_COLOR);

        grid.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}