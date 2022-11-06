#pragma once
#include "menu.h"

/**********Main function to create game**********/
void game() {
    sf::RenderWindow window(sf::VideoMode(1440, 900), "Checkers", sf::Style::Close);
    Menu menu;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            sf::
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Cursor cursor;
                cursor.loadFromSystem(sf::Cursor::Hand);
                window.setMouseCursor(cursor);
            }
        }

        window.clear();
        menu.drawMenu(window);
        window.display();
    }
}

