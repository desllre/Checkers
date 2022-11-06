#include "exitWindow.h"
#include "config.h"

void exit_window(sf::RenderWindow& window) {
    window.setActive();
    sf::RenderWindow exitWindow(sf::VideoMode(1440, 900), "Checkers", sf::Style::Close);
    Exit exit;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();
        exit.Draw(window);
        window.display();
    }

    window.setActive(false);
}

Exit::Exit(): background(BACKGROUND_IMAGE),
              accept(SIZE_EXIT_BUTTON, THICKNESS, POS_X,
                              (POS_Y + CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                              TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                              (POS_TEXT_Y + CONST_DISPLACEMENT), "ACCEPT"),
              cancel(SIZE_EXIT_BUTTON, THICKNESS, POS_X,
                          (POS_Y + 2 * CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                          TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                          (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), "CANCEL") {}

void Exit::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    accept.drawButton(window);
    cancel.drawButton(window);
}