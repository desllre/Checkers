#include "config.h"

void config_game(sf::RenderWindow &window) {
    window.setActive(true);
    ConfigGame config;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (config.getIsBackButtonPressed()) {
                return;
            }
        }

        window.clear();
        config.drawConfigGame(window);
        window.display();
    }

    window.setActive(false);
}

bool ConfigGame::getIsBackButtonPressed() {
    return is_back_button_pressed;
}

void ConfigGame::changeCursor(sf::RenderWindow& window, sf::Cursor::Type type_cursor) { //Change cursor
    sf::Cursor cursor;
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void ConfigGame::activateButtonArrows(bool is_mouse_on_back_button,
                                      bool is_mouse_on_left_round_arrows,
                                      bool is_mouse_on_right_round_arrows,
                                      sf::RenderWindow &window) { //Activate buttons and arrows
    sf::Cursor::Type cursor_hand = sf::Cursor::Hand;
    sf::Cursor::Type cursor_arrow = sf::Cursor::Arrow;

    if (is_mouse_on_back_button) { //Activate back button
        back_button.setColorFigure(sf::Color::Red);
        back_button.setColorText(sf::Color::Red);
        if (!is_cursor_set) {
            changeCursor(window, cursor_hand);
            is_cursor_set = true;
        }
    }
    if (is_mouse_on_left_round_arrows) {
        arrow_round_left.setColor(is_mouse_on_left_round_arrows);
        if (!is_cursor_set) {
            changeCursor(window, cursor_hand);
            is_cursor_set = true;
        }
    }
    if (is_mouse_on_right_round_arrows) {
        arrow_round_right.setColor(is_mouse_on_right_round_arrows);
        if (!is_cursor_set) {
            changeCursor(window, cursor_hand);
            is_cursor_set = true;
        }
    }
    else if (!is_mouse_on_back_button &&
             !is_mouse_on_left_round_arrows &&
             !is_mouse_on_right_round_arrows) {
        back_button.setColorFigure(sf::Color::Black);
        back_button.setColorText(sf::Color::Black);
        arrow_round_left.setColor(is_mouse_on_left_round_arrows);
        arrow_round_right.setColor(is_mouse_on_right_round_arrows);
        if (is_cursor_set) {
            changeCursor(window, cursor_arrow);
            is_cursor_set = false;
        }
    }
}

void ConfigGame::pressButtonArrows(bool is_mouse_on_back_button,
                                   bool is_mouse_on_left_round_arrows,
                                   bool is_mouse_on_right_round_arrows,
                                   bool is_press_mouse,
                                   sf::RenderWindow &window) { //Press on button
    if (is_mouse_on_back_button && is_press_mouse) {
        back_button.playSongsPress();
        is_back_button_pressed = true;
    }
    if (is_mouse_on_left_round_arrows && is_press_mouse) {
        arrow_round_left.playSongsPress();
    }
    if (is_mouse_on_right_round_arrows && is_press_mouse) {
        arrow_round_right.playSongsPress();
    }
}

void ConfigGame::saveSettings(){
    if (!rounds.empty()){
        std::ofstream fout("../config/custom_settings.txt");

        if (!fout.is_open()) {
            throw std::exception();
        }

        fout << "Player_1 ";
    }
}

void ConfigGame::drawConfigGame(sf::RenderWindow& window) { //Function for draw and activate buttons
    auto mouse_position = sf::Mouse::getPosition(window);
    bool is_mouse_on_back_button = (mouse_position.x >= POS_BUTTON_X && mouse_position.y >= POS_BUTTON_Y) &&
                                   (mouse_position.x <= POS_BUTTON_X + SIZE_BUTTON_X && mouse_position.y <= POS_BUTTON_Y + SIZE_BUTTON_Y);
    bool is_mouse_on_left_round_arrows = (mouse_position.x >= POS_ARROW_LEFT_ROUND_X && mouse_position.y >= POS_ARROW_LEFT_ROUND_Y + FIX_ARROW_Y) &&
                                         (mouse_position.x <= POS_ARROW_LEFT_ROUND_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_LEFT_ROUND_Y + FIX_ARROW_SIZE_Y);
    bool is_mouse_on_right_round_arrows = (mouse_position.x >= POS_ARROW_RIGHT_ROUND_X && mouse_position.y >= POS_ARROW_RIGHT_ROUND_Y + FIX_ARROW_Y) &&
                                         (mouse_position.x <= POS_ARROW_RIGHT_ROUND_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_RIGHT_ROUND_Y + FIX_ARROW_SIZE_Y);
    bool is_press_mouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    activateButtonArrows(is_mouse_on_back_button, is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows, window);

    pressButtonArrows(is_mouse_on_back_button,is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows, is_press_mouse, window);

    background.drawBackground(window);
    back_button.drawButton(window);
    arrow_round_left.drawArrow(window);
    arrow_round_right.drawArrow(window);
    text_round.drawText(window);
}