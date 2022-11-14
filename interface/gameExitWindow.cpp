#include "gameExitWindow.h"

void GameExitWindow(sf::RenderWindow& window, int& gameState){
    window.setActive();
    sf::RenderWindow exitWindow(sf::VideoMode(695, 434), "Checkers", sf::Style::None);
    sf::Vector2i menuWindowPosition = window.getPosition();
    menuWindowPosition.x += 372;
    menuWindowPosition.y += 250;

    exitWindow.setPosition(menuWindowPosition);
    GameExit gameExit;

    exitWindow.hasFocus();
    while (exitWindow.isOpen()) {
        sf::Event event;

        gameExit.ActivateButton(sf::Mouse::getPosition(exitWindow), exitWindow);

        while (exitWindow.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                exitWindow.close();
            }

            switch (gameExit.PressButton(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
                case -1:{ // 0 - resume, 1 - restart, 2 - exit
                    break;
                }
                case 0:{
                    exitWindow.close();
                    gameState = 0;
                    break;
                }
                case 1:{
                    exitWindow.close();
                    gameState = 1;
                    break;
                }
                case 2:{
                    exitWindow.close();
                    gameState = 2;
                    break;
                }
            }

        }

        if (window.pollEvent(event)){}

        exitWindow.clear();
        gameExit.Draw(exitWindow);
        exitWindow.display();
    }
    window.setActive(false);

}

GameExit::GameExit(): background(BACKGROUND_IMAGE),
                      resume(SIZE_GAME_EXIT_BUTTONS, THICKNESS, POS_RESUME_X,
                             POS_RESUME_Y, COLOR_OUTLINE, COLOR_TEXT,
                             TEXT_SIZE, PATH_FONTS, POS_RESUME_TEXT_X,
                             POS_RESUME_TEXT_Y, "RESUME"),
                      restart(SIZE_GAME_EXIT_BUTTONS, THICKNESS, POS_RESTART_X,
                              POS_RESTART_Y, COLOR_OUTLINE, COLOR_TEXT,
                             TEXT_SIZE, PATH_FONTS, POS_RESTART_TEXT_X,
                              POS_RESTART_TEXT_Y, "RESTART"),
                      exit(SIZE_GAME_EXIT_BUTTONS, THICKNESS, POS_EXIT_X,
                           POS_EXIT_Y, COLOR_OUTLINE, COLOR_TEXT,
                              TEXT_SIZE, PATH_FONTS, POS_EXIT_TEXT_X,
                           POS_EXIT_TEXT_Y, "EXIT"){}

void GameExit::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor) {
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void GameExit::ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window){

    if ((is_mouse_on_resume_button || is_mouse_on_restart_button || is_mouse_on_exit_button) && !is_mouse_on_button){

        is_mouse_on_button = true;
        ChangeCursor(window, sf::Cursor::Hand);

        if (is_mouse_on_resume_button) {
            resume.setColorFigure(sf::Color::Red);
            resume.setColorText(sf::Color::Red);
        } else if (is_mouse_on_restart_button) {
            restart.setColorFigure(sf::Color::Red);
            restart.setColorText(sf::Color::Red);
        } else if (is_mouse_on_exit_button) {
            exit.setColorFigure(sf::Color::Red);
            exit.setColorText(sf::Color::Red);
        }

    } else if (!(is_mouse_on_resume_button || is_mouse_on_restart_button || is_mouse_on_exit_button) && is_mouse_on_button){

        is_mouse_on_button = false;
        ChangeCursor(window, sf::Cursor::Arrow);

        resume.setColorFigure(sf::Color::Black);
        resume.setColorText(sf::Color::Black);

        restart.setColorFigure(sf::Color::Black);
        restart.setColorText(sf::Color::Black);

        exit.setColorFigure(sf::Color::Black);
        exit.setColorText(sf::Color::Black);
    }

    if (mousePosition.x >= POS_RESUME_X && mousePosition.x <= POS_RESUME_X + SIZE_X &&
        mousePosition.y >= POS_RESUME_Y && mousePosition.y <= POS_RESUME_Y + SIZE_Y){
        is_mouse_on_resume_button = true;
        return;
    }else {
        is_mouse_on_resume_button = false;
    }


    if (mousePosition.x >= POS_RESTART_X && mousePosition.x <= POS_RESTART_X + SIZE_X &&
        mousePosition.y >= POS_RESTART_Y && mousePosition.y <= POS_RESTART_Y + SIZE_Y) {
        is_mouse_on_restart_button = true;
        return;
    } else {
        is_mouse_on_restart_button = false;
    }

    if (mousePosition.x >= POS_EXIT_X && mousePosition.x <= POS_EXIT_X + SIZE_X &&
        mousePosition.y >= POS_EXIT_Y && mousePosition.y <= POS_EXIT_Y + SIZE_Y){
        is_mouse_on_exit_button = true;
        return;
    }else {
        is_mouse_on_exit_button = false;
    }

}

int GameExit::PressButton(bool mouse_is_pressed) const{
    if (mouse_is_pressed){
        if (is_mouse_on_resume_button)
            return 0;

        if (is_mouse_on_restart_button)
            return 1;

        if (is_mouse_on_exit_button)
            return 2;
    }

    return -1;
}

void GameExit::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    resume.drawButton(window);
    restart.drawButton(window);
    exit.drawButton(window);
}