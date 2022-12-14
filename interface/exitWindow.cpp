#include "exitWindow.h"

void ExitWindow(sf::RenderWindow& window){
    window.setActive();
    sf::RenderWindow exitWindow(sf::VideoMode(695, 434), "Checkers", sf::Style::None);
    sf::Vector2i menuWindowPosition = window.getPosition();
    menuWindowPosition.x += 372;
    menuWindowPosition.y += 250;

    exitWindow.setPosition(menuWindowPosition);
    Exit exit;


    exitWindow.hasFocus();
    while (exitWindow.isOpen()) {
        sf::Event event;

        exit.ActivateButton(sf::Mouse::getPosition(exitWindow), exitWindow);

        while (exitWindow.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                exitWindow.close();
            }
        }

        switch (exit.PressButton(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
            case -1:{
                exit.deleteConfigCustomFiles();
                window.close();
                exitWindow.close();
                break;
            }
            case 1:{
                exitWindow.close();
                break;
            }
        }

        if (window.pollEvent(event)){}

        exitWindow.clear();
        exit.Draw(exitWindow);
        exitWindow.display();
    }

    window.setActive(false);
}

void Exit::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor) {
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void Exit::ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window){

    if ((is_mouse_on_accept_button || is_mouse_on_cancel_button) && !is_mouse_on_button){

        is_mouse_on_button = true;
        ChangeCursor(window, sf::Cursor::Hand);

        if (is_mouse_on_accept_button) {
            accept.setColorFigure(sf::Color::Red);
            accept.setColorText(sf::Color::Red);
        } else if (is_mouse_on_cancel_button) {
            cancel.setColorFigure(sf::Color::Red);
            cancel.setColorText(sf::Color::Red);
        }

    } else if (!(is_mouse_on_accept_button || is_mouse_on_cancel_button) && is_mouse_on_button){

        is_mouse_on_button = false;
        ChangeCursor(window, sf::Cursor::Arrow);

        accept.setColorFigure(sf::Color::Black);
        accept.setColorText(sf::Color::Black);

        cancel.setColorFigure(sf::Color::Black);
        cancel.setColorText(sf::Color::Black);
    }

    if (mousePosition.x >= POS_ACCEPT_X && mousePosition.x <= POS_ACCEPT_X + SIZE_X &&
        mousePosition.y >= POS_Y && mousePosition.y <= POS_Y + SIZE_Y){
        is_mouse_on_accept_button = true;
        return;
    }else {
        is_mouse_on_accept_button = false;
    }


    if (mousePosition.x >= POS_CANCEL_X && mousePosition.x <= POS_CANCEL_X + SIZE_X &&
        mousePosition.y >= POS_Y && mousePosition.y <= POS_Y + SIZE_Y) {
        is_mouse_on_cancel_button = true;
        return;
    } else {
        is_mouse_on_cancel_button = false;
    }

}

int Exit::PressButton(bool mouse_is_pressed) const{
    if (mouse_is_pressed){
        if (is_mouse_on_accept_button)
            return -1;

        if (is_mouse_on_cancel_button)
            return 1;
    }

    return 0;
}

Exit::Exit(): background(BACKGROUND_IMAGE),
              accept(SIZE_EXIT_BUTTONS, THICKNESS, POS_ACCEPT_X,
                     POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                     TEXT_SIZE, PATH_FONTS, POS_ACCEPT_TEXT_X,
                     POS_TEXT_Y, "ACCEPT"),
              cancel(SIZE_EXIT_BUTTONS, THICKNESS, POS_CANCEL_X,
                     POS_Y , COLOR_OUTLINE, COLOR_TEXT,
                     TEXT_SIZE, PATH_FONTS, POS_CANCEL_TEXT_X,
                     POS_TEXT_Y , "CANCEL")
{}

void Exit::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    accept.drawButton(window);
    cancel.drawButton(window);
}

void Exit::deleteConfigCustomFiles(){
    if (std::filesystem::exists("../config/custom_settings.txt")){
        std::system("rm -r ../config/custom_settings.txt");
    }
}