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
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Cursor cursor;
                cursor.loadFromSystem(sf::Cursor::Hand);
                window.setMouseCursor(cursor);
            }
        }
        if (config.getValueEndFunction()) {
            return;
        }

        window.clear();
        config.drawConfigGame(window);
        window.display();
    }

    window.setActive(false);
}

void ConfigGame::activateButtonArrows(bool is_mouse_on_back_button, sf::RenderWindow &window) { //Activate buttons and arrows
    sf::Cursor::Type cursor_hand = sf::Cursor::Hand;
    sf::Cursor::Type cursor_arrow = sf::Cursor::Arrow;

    if (is_mouse_on_back_button) { //Activate back button
        back_button.setColorFigure(sf::Color::Red);
        back_button.setColorText(sf::Color::Red);
        is_mouse_on_button = true;
    }
    else {
        back_button.setColorFigure(sf::Color::Black);
        back_button.setColorText(sf::Color::Black);
        is_mouse_on_button = true;
    }
}

bool ConfigGame::getValueEndFunction() {
    return end_function;
}

void ConfigGame::pressButtonArrows(bool is_mouse_on_back_button, bool is_press_mouse, sf::RenderWindow &window) { //Press on button
    if (is_mouse_on_back_button && is_press_mouse) { //Activate back button
        end_function = true;
    }
}

void ConfigGame::drawConfigGame(sf::RenderWindow& window) { //Function for draw and activate buttons
    auto mouse_position = sf::Mouse::getPosition(window);
    bool is_mouse_on_back_button = (mouse_position.x >= POS_X && mouse_position.y >= POS_Y) &&
                                   (mouse_position.x <= POS_X + SIZE_X && mouse_position.y <= POS_Y + SIZE_Y);

    bool is_press_mouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    activateButtonArrows(is_mouse_on_back_button, window);
    pressButtonArrows(is_mouse_on_back_button, is_press_mouse, window);

    background.drawBackground(window);
    back_button.drawButton(window);
}
