#include "menu.h"

void Menu::setArrowCursor(sf::RenderWindow& window) { //Change cursor
    cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void Menu::setHandCursor(sf::RenderWindow& window) { //Change cursor
    cursor.loadFromSystem(sf::Cursor::Hand);
    window.setMouseCursor(cursor);
}

void Menu::activateButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button,
                          bool is_mouse_on_exit_button, sf::RenderWindow &window) {

    if (is_mouse_on_play_button) { //Activate play button
        play_button.setColorFigure(sf::Color::Red);
        play_button.setColorText(sf::Color::Red);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    }
    if (is_mouse_on_settings_button) { //Activate settings button
        settings_button.setColorFigure(sf::Color::Red);
        settings_button.setColorText(sf::Color::Red);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    }
    if (is_mouse_on_exit_button) { //Activate exit button
        exit_button.setColorFigure(sf::Color::Red);
        exit_button.setColorText(sf::Color::Red);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    }
    else if (!is_mouse_on_play_button &&
             !is_mouse_on_settings_button &&
             !is_mouse_on_exit_button) {
        play_button.setColorFigure(sf::Color::Black);
        play_button.setColorText(sf::Color::Black);
        settings_button.setColorFigure(sf::Color::Black);
        settings_button.setColorText(sf::Color::Black);
        exit_button.setColorFigure(sf::Color::Black);
        exit_button.setColorText(sf::Color::Black);
        if (is_set_cursor) {
            setArrowCursor(window);
            is_set_cursor = false;
        }
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
    if (is_mouse_on_play_button && is_press_mouse) {
        play_button.playSongsPress();
        window.setActive(false);
        sf::Thread configGameThread(config_game, std::ref(window));
        configGameThread.launch();
        configGameThread.wait();
        window.setActive(true);
    }

    if (is_mouse_on_exit_button && is_press_mouse) {
        exit_button.playSongsPress();
        window.setActive(false);
        sf::Thread exitThread(exit_window, std::ref(window));
        exitThread.launch();
        exitThread.wait();
        window.setActive();
    }
}
