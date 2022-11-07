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
                      changeNamePlayer_1(SIZE_CHANGE_NAME, THICKNESS, POS_CHANGE_NAME_PLAYER_1_NOTATION_X,
                                         POS_CHANGE_NAME_PLAYER_1_NOTATION_Y, COLOR_OUTLINE, COLOR_TEXT,
                                         TEXT_CHANGE_NAME_NOTATION_SIZE, PATH_FONTS, POS_CHANGE_NAME_PLAYER_1_TEXT_NOTATION_X,
                                         POS_CHANGE_NAME_PLAYER_1_TEXT_NOTATION_Y, "PLAYER 1"),
                      changeNamePlayer_2(SIZE_CHANGE_NAME, THICKNESS, POS_CHANGE_NAME_PLAYER_2_NOTATION_X,
                                         POS_CHANGE_NAME_PLAYER_2_NOTATION_Y, COLOR_OUTLINE, COLOR_TEXT,
                                         TEXT_CHANGE_NAME_NOTATION_SIZE, PATH_FONTS, POS_CHANGE_NAME_PLAYER_2_TEXT_NOTATION_X,
                                         POS_CHANGE_NAME_PLAYER_2_TEXT_NOTATION_Y, "PLAYER 2"),
                      changeNamePlayer_1_Text_Button(SIZE_CHANGE_NAME, THICKNESS, POS_CHANGE_NAME_PLAYER_1_X,
                                         POS_CHANGE_NAME_PLAYER_1_Y, COLOR_OUTLINE, COLOR_TEXT,
                                         TEXT_CHANGE_NAME_SIZE, PATH_FONTS, POS_CHANGE_NAME_PLAYER_1_TEXT_X,
                                         POS_CHANGE_NAME_PLAYER_1_TEXT_Y, "ENTER_NAME"),
                      changeNamePlayer_2_Text_Button(SIZE_CHANGE_NAME, THICKNESS, POS_CHANGE_NAME_PLAYER_2_X,
                                         POS_CHANGE_NAME_PLAYER_2_Y, COLOR_OUTLINE, COLOR_TEXT,
                                         TEXT_CHANGE_NAME_SIZE, PATH_FONTS, POS_CHANGE_NAME_PLAYER_2_TEXT_X,
                                         POS_CHANGE_NAME_PLAYER_2_TEXT_Y, "ENTER_NAME"),
                      leftArrow(POS_LEFT_ARROW_X, POS_LEFT_ARROW_Y, LEFT_ARROW_IMAGE),
                      rightArrow(POS_RIGHT_ARROW_X, POS_RIGHT_ARROW_Y, RIGHT_ARROW_IMAGE),
                      game_styles(STANDART_STYLE_IMAGE, BLACK_AND_WHITE_STYLE_IMAGE, POS_STYLE_IMAGE_X, POS_STYLE_IMAGE_Y)
                             {}


void Settings::ActivateButton(const sf::Vector2i& mousePosition){

}
int Settings::PressButton(bool mouse_is_pressed) const{

}

void Settings::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    changeNamePlayer_1.drawButton(window);
    changeNamePlayer_2.drawButton(window);
    changeNamePlayer_1_Text_Button.drawButton(window);
    changeNamePlayer_2_Text_Button.drawButton(window);
    window.draw(game_styles.sprite);
    leftArrow.drawArrow(window);
    rightArrow.drawArrow(window);
    save.drawButton(window);
    back.drawButton(window);
}


void Settings::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor){
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

Settings::Game_Styles::Game_Styles(const std::string& textureImg_1, const std::string& textureImg_2, uint32_t x, uint32_t y): x(x), y(y){
    textures[0].loadFromFile(textureImg_1);
    textures[1].loadFromFile(textureImg_2);

    sprite.setTexture(textures[0]);
    sprite.setPosition(x, y);
}