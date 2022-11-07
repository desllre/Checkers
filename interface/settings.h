#include "elements.h"

#include "SFML/Graphics.hpp"

#include "fstream"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/settings_bg.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_SETTINGS_BUTTON_X 450
#define SIZE_SETTINGS_BUTTON_Y 90

#define SIZE_CHANGE_NAME_X 500
#define SIZE_CHANGE_NAME_Y 90

#define THICKNESS 5

#define POS_SAVE_X 150
#define POS_BACK_X 790
#define POS_CHANGE_NAME_X 200

#define POS_SAVE_Y 720
#define POS_BACK_Y 720
#define POS_CHANGE_NAME_Y 300

const sf::Vector2<float> SIZE_CHANGE_NAME(SIZE_CHANGE_NAME_X, SIZE_CHANGE_NAME_Y);
const sf::Vector2<float> SIZE_SETTINGS_BUTTONS(SIZE_SETTINGS_BUTTON_X, SIZE_SETTINGS_BUTTON_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black

#define TEXT_CHANGE_NAME_SIZE 35L

#define TEXT_BUTTON_SIZE 40L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"

#define POS_SAVE_TEXT_X 270
#define POS_BACK_TEXT_X 910
#define POS_CHANGE_NAME_TEXT_X 235

#define POS_SAVE_TEXT_Y 740
#define POS_BACK_TEXT_Y 740
#define POS_CHANGE_NAME_TEXT_Y 323

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
    Background background;
    Button save;
    Button back;
    Button changeName;

    Arrow leftArrow;
    Arrow rightArrow;

    sf::Cursor cursor;

    bool is_mouse_on_accept_button = false;
    bool is_mouse_on_cancel_button = false;

    bool is_mouse_on_button = false;
};

