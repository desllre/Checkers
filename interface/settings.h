#include "elements.h"

#include "SFML/Graphics.hpp"

#include "fstream"
#include "string"
#include "array"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/settings_bg.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_SETTINGS_BUTTON_X 450
#define SIZE_SETTINGS_BUTTON_Y 90

const sf::Vector2<float> SIZE_SETTINGS_BUTTONS(SIZE_SETTINGS_BUTTON_X, SIZE_SETTINGS_BUTTON_Y);


// PLAYER 1 SETTINGS
#define SIZE_NAME_FIELD_PLAYER_1_X 430
#define SIZE_NAME_FIELD_PLAYER_1_Y 90

#define SIZE_ENTER_FIELD_PLAYER_1_X 570
#define SIZE_ENTER_FIELD_PLAYER_1_Y 90

#define POS_NAME_FIELD_PLAYER_1_X 185
#define POS_NAME_FIELD_PLAYER_1_Y 230

#define POS_ENTER_FIELD_PLAYER_1_X 665
#define POS_ENTER_FIELD_PLAYER_1_Y 230


#define TEXT_NAME_FIELD_PLAYER_1_SIZE 35L
#define TEXT_ENTER_FIELD_PLAYER_1_SIZE 28L


#define TEXT_POS_NAME_FIELD_PLAYER_1_X 240
#define TEXT_POS_NAME_FIELD_PLAYER_1_Y 255

#define TEXT_POS_ENTER_FIELD_PLAYER_1_X 700
#define TEXT_POS_ENTER_FIELD_PLAYER_1_Y 258

const sf::Vector2<float> SIZE_NAME_FIELD_PLAYER_1(SIZE_NAME_FIELD_PLAYER_1_X, SIZE_NAME_FIELD_PLAYER_1_Y);
const sf::Vector2<float> SIZE_ENTER_FIELD_PLAYER_1(SIZE_ENTER_FIELD_PLAYER_1_X, SIZE_ENTER_FIELD_PLAYER_1_Y);

// PLAYER 2 SETTINGS

#define SIZE_NAME_FIELD_PLAYER_2_X 430
#define SIZE_NAME_FIELD_PLAYER_2_Y 90

#define SIZE_ENTER_FIELD_PLAYER_2_X 570
#define SIZE_ENTER_FIELD_PLAYER_2_Y 90

#define POS_NAME_FIELD_PLAYER_2_X 185
#define POS_NAME_FIELD_PLAYER_2_Y 360

#define POS_ENTER_FIELD_PLAYER_2_X 665
#define POS_ENTER_FIELD_PLAYER_2_Y 360


#define TEXT_NAME_FIELD_PLAYER_2_SIZE 35L
#define TEXT_ENTER_FIELD_PLAYER_2_SIZE 28L


#define TEXT_POS_NAME_FIELD_PLAYER_2_X 240
#define TEXT_POS_NAME_FIELD_PLAYER_2_Y 385

#define TEXT_POS_ENTER_FIELD_PLAYER_2_X 700
#define TEXT_POS_ENTER_FIELD_PLAYER_2_Y 388

const sf::Vector2<float> SIZE_NAME_FIELD_PLAYER_2(SIZE_NAME_FIELD_PLAYER_2_X, SIZE_NAME_FIELD_PLAYER_2_Y);
const sf::Vector2<float> SIZE_ENTER_FIELD_PLAYER_2(SIZE_ENTER_FIELD_PLAYER_2_X, SIZE_ENTER_FIELD_PLAYER_2_Y);

// SAVE BUTTON SETTINGS
#define POS_SAVE_X 170
#define POS_SAVE_Y 720

#define POS_SAVE_TEXT_X 290
#define POS_SAVE_TEXT_Y 740

// BACK BUTTON SETTINGS
#define POS_BACK_X 790
#define POS_BACK_Y 720

#define POS_BACK_TEXT_X 910
#define POS_BACK_TEXT_Y 740

// STYLE IMAGE SETTINGS
#define STANDART_STYLE_IMAGE "../textures/elements/standart_style.png"
#define BLACK_AND_WHITE_STYLE_IMAGE "../textures/elements/black_and_white_style.png"

#define POS_STYLE_IMAGE_X 615
#define POS_STYLE_IMAGE_Y 500

// ARROW SETTINGS
#define LEFT_ARROW_IMAGE "../textures/elements/arrow_left.png"
#define RIGHT_ARROW_IMAGE "../textures/elements/arrow_right.png"

#define POS_LEFT_ARROW_X 495
#define POS_LEFT_ARROW_Y 530

#define POS_RIGHT_ARROW_X 795
#define POS_RIGHT_ARROW_Y 520


#define THICKNESS 5


/*Settings for text*/
#define COLOR_TEXT sf::Color::Black

#define TEXT_BUTTON_SIZE 40L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"

#pragma once

void SettingsWindow(sf::RenderWindow& window);

class Settings {
private:

public:
    Settings();
    ~Settings() = default;

    void ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window); // проверка наведения на кнопки

    int PressButton(bool mouse_is_pressed); // функция проверки нажатия на кнопку. Возвращает -1 - если нажата клавиша accept, 1 - если close, 0 - ничего

    void Draw(sf::RenderWindow& window);

    void setStyleBoardStyle(const std::string& styleName);

    void setTextInput();

    void inputText(const uint32_t& inputSymbol);

private:

    void ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor);

private:

    struct Game_Styles{
        Game_Styles(const std::string&, const std::string&, float x, float y);

        std::array<sf::Texture, 2> textures;

        sf::Sprite sprite;
        float x;
        float y;

        bool isStandartStyle = true;
    };

    struct InputNameField{
        InputNameField(sf::Vector2<float> nameFieldSize, sf::Vector2<float> enterFieldSize,
                       float nameField_posX, float nameField_posY,
                       float enterField_posX, float enterField_posY,
                       int nameField_textSize, int enterField_textSize,
                       float nameField_text_posX, float nameField_text_posY,
                       float enterField_text_posX, float enterField_text_posY,
                       const std::string& path_font,
                       const std::string& nameFieldString, const std::string& enterFieldString);

        void Draw(sf::RenderWindow& window) const;

        sf::RectangleShape nameField;
        sf::RectangleShape enterField;

        sf::Font font;

        sf::Text nameFieldText;
        sf::Text enterFieldText;

        bool isTextEntered = false;
    };

    InputNameField player1Field;
    InputNameField player2Field;

    Game_Styles game_styles;

    Background background;
    Button save;
    Button back;

    std::string player_1_Name = "";
    std::string player_2_Name = "";

    Arrow leftArrow;
    Arrow rightArrow;

    sf::Cursor cursor;

    bool is_mouse_on_save_button = false;
    bool is_mouse_on_back_button = false;
    bool is_mouse_on_button = false;

    bool is_mouse_on_enter_player_1_field = false;
    bool is_mouse_on_enter_player_2_field = false;
    bool is_mouse_on_enter_field = false;

    bool is_mouse_on_left_arrow = false;
    bool is_mouse_on_right_arrow = false;
    bool is_mouse_on_arrow = false;

    bool is_player_1_name_input = false;
    bool is_player_2_name_input = false;
};