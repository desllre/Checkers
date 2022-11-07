#include "settings.h"

void SettingsWindow(sf::RenderWindow& window){
    window.setActive();

    Settings settings;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.setActive(false);
                return;
            }
        }

        if (window.pollEvent(event)){}

        window.clear();
        settings.Draw(window);
        window.display();
    }

    window.setActive(false);
}

Settings::Settings(): background(BACKGROUND_IMAGE),
                      save(SIZE_SETTINGS_BUTTONS, THICKNESS, POS_SAVE_X,
                           POS_SAVE_Y, COLOR_OUTLINE, COLOR_TEXT,
                           TEXT_BUTTON_SIZE, PATH_FONTS, POS_SAVE_TEXT_X,
                           POS_SAVE_TEXT_Y, "SAVE"),
                      back(SIZE_SETTINGS_BUTTONS, THICKNESS, POS_BACK_X,
                           POS_BACK_Y , COLOR_OUTLINE, COLOR_TEXT,
                           TEXT_BUTTON_SIZE, PATH_FONTS, POS_BACK_TEXT_X,
                           POS_BACK_TEXT_Y , "BACK"),
                      changeName(SIZE_CHANGE_NAME, THICKNESS, POS_CHANGE_NAME_X,
                                 POS_CHANGE_NAME_Y, COLOR_OUTLINE, COLOR_TEXT,
                                 TEXT_CHANGE_NAME_SIZE, PATH_FONTS, POS_CHANGE_NAME_TEXT_X,
                                 POS_CHANGE_NAME_TEXT_Y, "ENTER NAME"),
                      leftArrow(),
                      rightArrow()
                             {}

void Settings::ActivateButton(const sf::Vector2i& mousePosition){

}
int Settings::PressButton(bool mouse_is_pressed) const{

}

void Settings::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    changeName.drawButton(window);
    save.drawButton(window);
    back.drawButton(window);
}


void Settings::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor){
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}
