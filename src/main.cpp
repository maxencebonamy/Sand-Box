#include "display/grid.h"
#include "display/hotBar.h"


int main() {

    sf::VideoMode videoMode { (unsigned int)WINDOW_SIZE.getX(), (unsigned int)WINDOW_SIZE.getY() };
    auto flags = WINDOW_FULLSCREEN ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close;
    sf::RenderWindow window(videoMode, WINDOW_TITLE, flags);
    window.setFramerateLimit(WINDOW_FPS);

    sf::Image icon;
    icon.loadFromFile("assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    HotBar hotBar;
    Grid grid { hotBar.getElement() };
    sf::Mouse mouse;

    Vector2 mousePosition;

    window.display();

    while (window.isOpen()) {
        mousePosition = { (float)mouse.getPosition(window).x, (float)mouse.getPosition(window).y };

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            else {
                hotBar.updateEvents(event, mousePosition);
                if (hotBar.hasBeenUpdated()) grid.setElement(hotBar.getElement());
                else grid.updateEvents(event, mousePosition);
            }
        }

        grid.updateSimulation();

        window.clear();

        grid.display(window);
        hotBar.display(window);

        window.display();
    }

    return EXIT_SUCCESS;
}