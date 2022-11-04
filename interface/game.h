#include "header.h"
#include "menu.h"

void game() {
    sf::RenderWindow window(sf::VideoMode(1440, 900), "Checkers", sf::Style::Close);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        menu.draw(window, background);
        window.display();
    }
}