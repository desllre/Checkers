#include "elements.h"

#include "SFML/Graphics.hpp"

#include "fstream"
#include "string"
#include "array"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/settings_bg.png"

// BUTTON VARIABLESS
#define LEFT_ARROW_IMAGE "../textures/elements/arrow_left.png"
#define RIGHT_ARROW_IMAGE "../textures/elements/arrow_right.png"

#define STANDART_STYLE_IMAGE "../textures/elements/standart_style.png"
#define BLACK_AND_WHITE_STYLE_IMAGE "../textures/elements/black_and_white_style.png"

#define COLOR_OUTLINE sf::Color::Black
#define SIZE_SETTINGS_BUTTON_X 450
#define SIZE_SETTINGS_BUTTON_Y 90

#define SIZE_CHANGE_NAME_X 500
#define SIZE_CHANGE_NAME_Y 90

#define THICKNESS 5

#define POS_SAVE_X 170
#define POS_BACK_X 790

#define POS_CHANGE_NAME_PLAYER_1_NOTATION_X 185
#define POS_CHANGE_NAME_PLAYER_2_NOTATION_X 185
#define POS_CHANGE_NAME_PLAYER_1_X 735
#define POS_CHANGE_NAME_PLAYER_2_X 735

#define POS_SAVE_Y 720
#define POS_BACK_Y 720

#define POS_CHANGE_NAME_PLAYER_1_NOTATION_Y 230
#define POS_CHANGE_NAME_PLAYER_2_NOTATION_Y 360
#define POS_CHANGE_NAME_PLAYER_1_Y 230
#define POS_CHANGE_NAME_PLAYER_2_Y 360

#define POS_STYLE_IMAGE_X 615
#define POS_STYLE_IMAGE_Y 500

#define POS_LEFT_ARROW_X 495
#define POS_RIGHT_ARROW_X 795

#define POS_LEFT_ARROW_Y 530
#define POS_RIGHT_ARROW_Y 520

const sf::Vector2<float> SIZE_CHANGE_NAME(SIZE_CHANGE_NAME_X, SIZE_CHANGE_NAME_Y);
const sf::Vector2<float> SIZE_SETTINGS_BUTTONS(SIZE_SETTINGS_BUTTON_X, SIZE_SETTINGS_BUTTON_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black

#define TEXT_CHANGE_NAME_SIZE 28L

#define TEXT_CHANGE_NAME_NOTATION_SIZE 35L

#define TEXT_BUTTON_SIZE 40L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"

#define POS_SAVE_TEXT_X 290
#define POS_BACK_TEXT_X 910

#define POS_CHANGE_NAME_PLAYER_1_TEXT_NOTATION_X 275
#define POS_CHANGE_NAME_PLAYER_2_TEXT_NOTATION_X 275

#define POS_CHANGE_NAME_PLAYER_1_TEXT_X 745
#define POS_CHANGE_NAME_PLAYER_2_TEXT_X 745

#define POS_SAVE_TEXT_Y 740
#define POS_BACK_TEXT_Y 740

#define POS_CHANGE_NAME_PLAYER_1_TEXT_NOTATION_Y 253
#define POS_CHANGE_NAME_PLAYER_2_TEXT_NOTATION_Y 385

#define POS_CHANGE_NAME_PLAYER_1_TEXT_Y 258
#define POS_CHANGE_NAME_PLAYER_2_TEXT_Y 388

#pragma once

void SettingsWindow(sf::RenderWindow& window);

class Settings {
private:

public:
    Settings();
    ~Settings() = default;

    void ActivateButton(const sf::Vector2i& mousePosition); // проверка наведения на кнопки

    int PressButton(bool mouse_is_pressed) const; // функция проверки нажатия на кнопку. Возвращает -1 - если нажата клавиша accept, 1 - если close, 0 - ничего

    void Draw(sf::RenderWindow& window);

private:

    void ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor);

private:

    struct Game_Styles{
        Game_Styles(const std::string&, const std::string&, uint32_t x, uint32_t y);

        std::array<sf::Texture, 2> textures;

        sf::Sprite sprite;
        uint32_t x;
        uint32_t y;

        bool isStandartStyle = true;
    };

    Game_Styles game_styles;

    Background background;
    Button save;
    Button back;

    Button changeNamePlayer_1;
    Button changeNamePlayer_2;

    Button changeNamePlayer_1_Text_Button;
    Button changeNamePlayer_2_Text_Button;

    std::string player_1_Name = "";
    std::string player_2_Name = "";

    Arrow leftArrow;
    Arrow rightArrow;

    sf::Cursor cursor;

    bool is_mouse_on_accept_button = false;
    bool is_mouse_on_cancel_button = false;

    bool is_mouse_on_button = false;
};

