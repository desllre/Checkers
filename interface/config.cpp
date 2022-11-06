#include "config.h"

void ConfigGame::changeCursor(sf::RenderWindow& window) { //Change cursor
    cursor.loadFromSystem(sf::Cursor::Help);
    window.setMouseCursor(cursor);
}
void ConfigGame::activateButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_right,
                                      bool is_mouse_on_arrow_left, sf::RenderWindow &window) { //Activate buttons and arrows
    if (is_mouse_on_back_button) { //Activate play button
        back_button.setColorFigure(sf::Color::Red);
        back_button.setColorText(sf::Color::Red);
        changeCursor(window);
    }
    else {
        back_button.setColorFigure(sf::Color::Black);
        back_button.setColorText(sf::Color::Black);
    }

    if (is_mouse_on_begin_button) { //Activate play button
        begin_button.setColorFigure(sf::Color::Red);
        begin_button.setColorText(sf::Color::Red);
        changeCursor(window);
    }
    else {
        begin_button.setColorFigure(sf::Color::Black);
        begin_button.setColorText(sf::Color::Black);
    }

    if (is_mouse_on_arrow_left) { //Activate play button
        arrow_left.changeArrowLeftColor("");
        changeCursor(window);
    }
    else {
        back_button.setColorFigure(sf::Color::Black);
        back_button.setColorText(sf::Color::Black);
    }
}
void ConfigGame::pressButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_left,
                                   bool is_mouse_on_arrow_right,bool is_press_mouse_button,
                                   bool is_press_mouse, sf::RenderWindow &window) { //Press on button

}
void ConfigGame::drawConfigGame(sf::RenderWindow& window) { //Function for draw and activate buttons
    auto mouse_position = sf::Mouse::getPosition(window);
    bool is_mouse_on_back_button = (mouse_position.x >= POS_X && mouse_position.y >= POS_Y) &&
                                   (mouse_position.x <= POS_X + SIZE_X && mouse_position.y <= POS_Y + SIZE_Y);
    bool is_mouse_on_begin_button = (mouse_position.x >= POS_X && mouse_position.y >= (POS_Y + CONST_DISPLACEMENT)) &&
                                       (mouse_position.x <= POS_X + SIZE_X) &&
                                       (mouse_position.y <= (POS_Y + SIZE_Y + CONST_DISPLACEMENT));
    bool is_mouse_on_arrow_right;
    bool is_press_mouse = sf::Mouse::isButtonPressed(sf::Mouse::Left);


}

void config_game(sf::RenderWindow &window) {
    window.setActive(true);
    ConfigGame config;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        config.drawConfigGame(window);
        window.display();
    }

    window.setActive(false);
}

