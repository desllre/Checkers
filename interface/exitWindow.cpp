#include "exitWindow.h"


void ExitWindow(sf::RenderWindow& window){
   window.setActive();
    sf::RenderWindow exitWindow(sf::VideoMode(695, 434), "Checkers", sf::Style::None);
    sf::Vector2i menuWindowPosition = window.getPosition();
    menuWindowPosition.x += 372;
    menuWindowPosition.y += 233;

    exitWindow.setPosition(menuWindowPosition);
    Exit exit;

    while (exitWindow.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        exitWindow.clear();
        exit.Draw(exitWindow);
        exitWindow.display();
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
                          (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), "CANCEL")
                          {}

void Exit::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    accept.drawButton(window);
    cancel.drawButton(window);
}