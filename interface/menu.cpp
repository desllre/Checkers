#include "menu.h"


void Menu::changeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor) {
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void Menu::activateButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button,
                          bool is_mouse_on_exit_button, sf::RenderWindow &window) {

    if ((is_mouse_on_play_button || is_mouse_on_exit_button || is_mouse_on_settings_button) && !is_mouse_on_button){
        is_mouse_on_button = true;
        changeCursor(window, sf::Cursor::Type::Hand);
    } else if (!(is_mouse_on_play_button || is_mouse_on_exit_button || is_mouse_on_settings_button) && is_mouse_on_button){
        is_mouse_on_button = false;
        changeCursor(window, sf::Cursor::Arrow);
    }

    if (is_mouse_on_play_button) { //Activate play button
        play_button.setColorFigure(sf::Color::Red);
        play_button.setColorText(sf::Color::Red);
    }
    else {
        play_button.setColorFigure(sf::Color::Black);
        play_button.setColorText(sf::Color::Black);
    }

    if (is_mouse_on_settings_button) { //Activate settings button
        settings_button.setColorFigure(sf::Color::Red);
        settings_button.setColorText(sf::Color::Red);
    }
    else {
        settings_button.setColorFigure(sf::Color::Black);
        settings_button.setColorText(sf::Color::Black);
    }

    if (is_mouse_on_exit_button) { //Activate exit button
        exit_button.setColorFigure(sf::Color::Red);
        exit_button.setColorText(sf::Color::Red);
    }
    else {
        exit_button.setColorFigure(sf::Color::Black);
        exit_button.setColorText(sf::Color::Black);
    }
}

void Menu::drawMenu(sf::RenderWindow &window) { //Function for draw and activate buttons
    auto mouse_position = sf::Mouse::getPosition(window);
    bool is_mouse_on_play_button = (mouse_position.x >= POS_X && mouse_position.y >= POS_Y) &&
                                   (mouse_position.x <= POS_X + SIZE_X && mouse_position.y <= POS_Y + SIZE_Y);
    bool is_mouse_on_settings_button = (mouse_position.x >= POS_X && mouse_position.y >= (POS_Y + CONST_DISPLACEMENT)) &&
                                       (mouse_position.x <= POS_X + SIZE_X) &&
                                       (mouse_position.y <= (POS_Y + SIZE_Y + CONST_DISPLACEMENT));
    bool is_mouse_on_exit_button = (mouse_position.x >= POS_X && mouse_position.y >= (POS_Y + 2 * CONST_DISPLACEMENT)) &&
                                   (mouse_position.x <= POS_X + SIZE_X) &&
                                   (mouse_position.y <= (POS_Y + SIZE_Y + 2 * CONST_DISPLACEMENT));
    bool is_press_mouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    activateButton(is_mouse_on_play_button, is_mouse_on_settings_button, is_mouse_on_exit_button, window);

    pressButton(is_mouse_on_play_button, is_mouse_on_settings_button, is_mouse_on_exit_button, is_press_mouse, window);

    background.drawBackground(window);
    play_button.drawButton(window);
    settings_button.drawButton(window);
    exit_button.drawButton(window);
}

void Menu::pressButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button, bool is_mouse_on_exit_button, bool is_press_mouse, sf::RenderWindow &window) {
    if (is_press_mouse){
        if (is_mouse_on_play_button) {
            window.setActive(false);
            sf::Thread configGameThread(config_game, std::ref(window));
            configGameThread.launch();
            configGameThread.wait();
            window.setActive(true);
        }

        if (is_mouse_on_settings_button) {
            window.setActive(false);
            sf::Thread configGameThread( SettingsWindow, std::ref(window));
            configGameThread.launch();
            configGameThread.wait();
            window.setActive(true);
        }

        if (is_mouse_on_exit_button) {

            exit_button.setColorFigure(sf::Color::Black);
            exit_button.setColorText(sf::Color::Black);

            window.clear();
            background.drawBackground(window);
            play_button.drawButton(window);
            settings_button.drawButton(window);
            exit_button.drawButton(window);
            window.display();

            changeCursor(window, sf::Cursor::Arrow);

            window.setActive(false);

            sf::Thread exitThread(ExitWindow, std::ref(window));
            exitThread.launch();
            exitThread.wait();
            window.setActive();
        }
    }

}
