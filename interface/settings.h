#include "elements.h"

#include "SFML/Graphics.hpp"

#include "fstream"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/menu_exit.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 290
#define SIZE_Y 80
#define THICKNESS 3
#define POS_ACCEPT_X 20
#define POS_CANCEL_X 385
#define POS_Y 280
const sf::Vector2<float> SIZE_SETTINGS_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 35L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_ACCEPT_TEXT_X 38
#define POS_CANCEL_TEXT_X 410
#define POS_TEXT_Y 300

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

