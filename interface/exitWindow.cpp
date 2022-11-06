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
              accept(SIZE_EXIT_BUTTON, THICKNESS, POS_ACCEPT_X,
                              POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                              TEXT_SIZE, PATH_FONTS, POS_ACCEPT_TEXT_X,
                              POS_TEXT_Y, "ACCEPT"),
              cancel(SIZE_EXIT_BUTTON, THICKNESS, POS_CANCEL_X,
                          POS_Y , COLOR_OUTLINE, COLOR_TEXT,
                          TEXT_SIZE, PATH_FONTS, POS_CANCEL_TEXT_X,
                          POS_TEXT_Y , "CANCEL")
                          {}

void Exit::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    accept.drawButton(window);
    cancel.drawButton(window);
}