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

void ConfigGame::setArrowCursor(sf::RenderWindow& window) { //Change cursor
    cursor.loadFromSystem(sf::Cursor::Arrow);
    window.setMouseCursor(cursor);
}

void ConfigGame::setHandCursor(sf::RenderWindow& window) { //Change cursor
    cursor.loadFromSystem(sf::Cursor::Hand);
    window.setMouseCursor(cursor);
}

void ConfigGame::activateButtonArrows(bool is_mouse_on_back_button,
                                      bool is_mouse_on_begin_button,
                                      bool is_mouse_on_left_round_arrows,
                                      bool is_mouse_on_right_round_arrows,
                                      bool is_mouse_on_left_text_arrows,
                                      bool is_mouse_on_right_text_arrows,
                                      bool is_mouse_on_left_color_arrows,
                                      bool is_mouse_on_right_color_arrows,
                                      bool is_mouse_on_left_multiplayer_arrows,
                                      bool is_mouse_on_right_multiplayer_arrows,
                                      sf::RenderWindow &window) { //Activate buttons and arrows
    if (is_mouse_on_back_button) { //Activate back button
        back_button.setColorFigure(sf::Color::Red);
        back_button.setColorText(sf::Color::Red);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_begin_button) {
        begin_button.setColorFigure(sf::Color::Red);
        begin_button.setColorText(sf::Color::Red);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_left_round_arrows) {
        arrow_round_left.setColor(is_mouse_on_left_round_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_right_round_arrows) {
        arrow_round_right.setColor(is_mouse_on_right_round_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_left_text_arrows) {
        arrow_type_left.setColor(is_mouse_on_left_text_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_right_text_arrows) {
        arrow_type_right.setColor(is_mouse_on_right_text_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_left_color_arrows) {
        arrow_color_left.setColor(is_mouse_on_left_color_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (is_mouse_on_right_color_arrows) {
        arrow_color_right.setColor(is_mouse_on_right_color_arrows);
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if(is_mouse_on_left_multiplayer_arrows){
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if(is_mouse_on_right_multiplayer_arrows){
        if (!is_set_cursor) {
            setHandCursor(window);
            is_set_cursor = true;
        }
    } else if (!is_mouse_on_back_button &&
               !is_mouse_on_left_round_arrows &&
               !is_mouse_on_begin_button &&
               !is_mouse_on_right_round_arrows &&
               !is_mouse_on_left_text_arrows &&
               !is_mouse_on_right_text_arrows &&
               !is_mouse_on_left_color_arrows &&
               !is_mouse_on_right_color_arrows) {
        back_button.setColorFigure(sf::Color::Black);
        back_button.setColorText(sf::Color::Black);
        begin_button.setColorFigure(sf::Color::Black);
        begin_button.setColorText(sf::Color::Black);
        arrow_round_left.setColor(is_mouse_on_left_round_arrows);
        arrow_round_right.setColor(is_mouse_on_right_round_arrows);
        arrow_type_left.setColor(is_mouse_on_left_round_arrows);
        arrow_type_right.setColor(is_mouse_on_right_round_arrows);
        arrow_color_right.setColor(is_mouse_on_left_round_arrows);
        arrow_color_left.setColor(is_mouse_on_right_round_arrows);
        if (is_set_cursor) {
            setArrowCursor(window);
            is_set_cursor = false;
        }
    }
}

void ConfigGame::pressButtonArrows(bool is_mouse_on_back_button,
                                   bool is_mouse_on_begin_button,
                                   bool is_mouse_on_left_round_arrows,
                                   bool is_mouse_on_right_round_arrows,
                                   bool is_mouse_on_left_type_arrows,
                                   bool is_mouse_on_right_type_arrows,
                                   bool is_mouse_on_left_color_arrows,
                                   bool is_mouse_on_right_color_arrows,
                                   bool is_mouse_on_left_multiplayer_arrows,
                                   bool is_mouse_on_right_multiplayer_arrows,
                                   bool is_press_mouse,
                                   sf::RenderWindow &window) { //Press on button
    if (is_mouse_on_back_button && is_press_mouse) {
        back_button.playSongsPress();
        is_back_button_pressed = true;
    } else if (is_mouse_on_left_round_arrows && is_press_mouse) {
        rounds.setValue(is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows);
        arrow_round_left.playSongsPress();
    } else if (is_mouse_on_right_round_arrows && is_press_mouse) {
        rounds.setValue(is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows);
        arrow_round_right.playSongsPress();
    } else if (is_mouse_on_left_type_arrows && is_press_mouse) {
        rules.setValue(is_mouse_on_left_type_arrows, is_mouse_on_right_type_arrows);
        arrow_type_left.playSongsPress();
    } else if (is_mouse_on_right_type_arrows && is_press_mouse) {
        rules.setValue(is_mouse_on_left_type_arrows, is_mouse_on_right_type_arrows);
        arrow_type_right.playSongsPress();
    } else if (is_mouse_on_right_color_arrows && is_press_mouse) {
        color.setValue(is_mouse_on_left_color_arrows, is_mouse_on_right_color_arrows);
        arrow_color_right.playSongsPress();
    } else if (is_mouse_on_left_color_arrows && is_press_mouse) {
        color.setValue(is_mouse_on_left_color_arrows, is_mouse_on_right_color_arrows);
        arrow_color_left.playSongsPress();
    } else if (is_mouse_on_begin_button && is_press_mouse) {
        begin_button.playSongsPress();
    } else if((is_mouse_on_left_multiplayer_arrows || is_mouse_on_right_multiplayer_arrows) && is_press_mouse){
        multiplayer.setValue(is_mouse_on_left_multiplayer_arrows, is_mouse_on_right_multiplayer_arrows);
        arrow_multiplayer_left.playSongsPress();
    }
}

void ConfigGame::drawConfigGame(sf::RenderWindow& window) { //Function for draw and activate buttons
    auto mouse_position = sf::Mouse::getPosition(window);
    bool is_mouse_on_back_button = (mouse_position.x >= POS_BUTTON_X && mouse_position.y >= POS_BUTTON_Y) &&
                                   (mouse_position.x <= POS_BUTTON_X + SIZE_BUTTON_X && mouse_position.y <= POS_BUTTON_Y + SIZE_BUTTON_Y);
    bool is_mouse_on_left_round_arrows = (mouse_position.x >= POS_ARROW_LEFT_ROUND_X + 40 && mouse_position.y >= POS_ARROW_LEFT_ROUND_Y + FIX_ARROW_Y ) &&
                                         (mouse_position.x <= POS_ARROW_LEFT_ROUND_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_LEFT_ROUND_Y + FIX_ARROW_SIZE_Y);
    bool is_mouse_on_right_round_arrows = (mouse_position.x >= POS_ARROW_RIGHT_ROUND_X + 40 && mouse_position.y >= POS_ARROW_RIGHT_ROUND_Y + FIX_ARROW_Y + 10) &&
                                         (mouse_position.x <= POS_ARROW_RIGHT_ROUND_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_RIGHT_ROUND_Y + FIX_ARROW_SIZE_Y + 10);
    bool is_mouse_on_begin_button = (mouse_position.x >= POS_BUTTON_BEGIN_X && mouse_position.y >= POS_BUTTON_BEGIN_Y) &&
                                     (mouse_position.x <= POS_BUTTON_BEGIN_X + SIZE_BUTTON_BEGIN_X && mouse_position.y <= POS_BUTTON_BEGIN_Y + SIZE_BUTTON_BEGIN_Y);
    bool is_mouse_on_left_type_arrows = (mouse_position.x >= POS_ARROW_LEFT_TYPE_X + 40 && mouse_position.y >= POS_ARROW_LEFT_TYPE_Y + FIX_ARROW_Y) &&
                                         (mouse_position.x <= POS_ARROW_LEFT_TYPE_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_LEFT_TYPE_Y + FIX_ARROW_SIZE_Y);
    bool is_mouse_on_right_type_arrows = (mouse_position.x >= POS_ARROW_RIGHT_TYPE_X + 40 && mouse_position.y >= POS_ARROW_RIGHT_TYPE_Y + FIX_ARROW_Y + 10) &&
                                          (mouse_position.x <= POS_ARROW_RIGHT_TYPE_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_RIGHT_TYPE_Y + FIX_ARROW_SIZE_Y + 10);
    bool is_mouse_on_left_color_arrows = (mouse_position.x >= POS_ARROW_LEFT_COLOR_X + 40 && mouse_position.y >= POS_ARROW_LEFT_COLOR_Y + FIX_ARROW_Y) &&
                                         (mouse_position.x <= POS_ARROW_LEFT_COLOR_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_LEFT_COLOR_Y + FIX_ARROW_SIZE_Y);
    bool is_mouse_on_right_color_arrows = (mouse_position.x >= POS_ARROW_RIGHT_COLOR_X + 40 && mouse_position.y >= POS_ARROW_RIGHT_COLOR_Y + FIX_ARROW_Y + 10) &&
                                          (mouse_position.x <= POS_ARROW_RIGHT_COLOR_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_RIGHT_COLOR_Y + FIX_ARROW_SIZE_Y + 10);
    bool is_mouse_on_left_multiplayer_arrows = (mouse_position.x >= POS_ARROW_LEFT_MULTIPLAYER_X + 40 && mouse_position.y >= POS_ARROW_LEFT_MULTIPLAYER_Y + FIX_ARROW_Y) &&
                                         (mouse_position.x <= POS_ARROW_LEFT_MULTIPLAYER_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_LEFT_MULTIPLAYER_Y + FIX_ARROW_SIZE_Y);
    bool is_mouse_on_right_multiplayer_arrows = (mouse_position.x >= POS_ARROW_RIGHT_MULTIPLAYER_X + 40 && mouse_position.y >= POS_ARROW_RIGHT_COLOR_Y + FIX_ARROW_Y + 10) &&
                                          (mouse_position.x <= POS_ARROW_RIGHT_MULTIPLAYER_X + FIX_ARROW_SIZE_X && mouse_position.y <= POS_ARROW_RIGHT_MULTIPLAYER_Y + FIX_ARROW_SIZE_Y + 10);

    bool is_press_mouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    activateButtonArrows(is_mouse_on_back_button, is_mouse_on_begin_button,
                         is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows,
                         is_mouse_on_left_type_arrows, is_mouse_on_right_type_arrows,
                         is_mouse_on_left_color_arrows, is_mouse_on_right_color_arrows,
                         is_mouse_on_left_multiplayer_arrows, is_mouse_on_right_multiplayer_arrows, window);

    pressButtonArrows(is_mouse_on_back_button, is_mouse_on_begin_button,
                      is_mouse_on_left_round_arrows, is_mouse_on_right_round_arrows,
                      is_mouse_on_left_type_arrows, is_mouse_on_right_type_arrows,
                      is_mouse_on_left_color_arrows, is_mouse_on_right_color_arrows,
                      is_mouse_on_left_multiplayer_arrows, is_mouse_on_right_multiplayer_arrows,
                      is_press_mouse, window);

    background.drawBackground(window);
    back_button.drawButton(window);
    begin_button.drawButton(window);
    arrow_round_left.drawArrow(window);
    arrow_round_right.drawArrow(window);
    text_round.drawText(window);
    text_game_type.drawText(window);
    rounds.drawText(window);
    rules.drawText(window);
    arrow_type_right.drawArrow(window);
    arrow_type_left.drawArrow(window);
    text_color.drawText(window);
    arrow_color_left.drawArrow(window);
    arrow_color_right.drawArrow(window);
    color.drawText(window);

    text_multiplayer.drawText(window);
    multiplayer.drawText(window);
    arrow_multiplayer_left.drawArrow(window);
    arrow_multiplayer_right.drawArrow(window);
}