#include "header.h"
#include "elements.h"

/*Settings for background*/
#define PATH_IMAGE "../textures/backgrounds/menu_bg.png"

/*Settings for button*/
#define PATH_PRESS_BUTTON "../songs/pressbutton.wav"
#define PATH_TOUCH_BUTTON "../songs/pressbutton.wav"
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 600.f
#define SIZE_Y 100.f
#define THICKNESS 7.f
#define POS_X 400.f
#define POS_Y 325.f
const sf::Vector2<float> SIZE_MENU_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 580.f
#define POS_TEXT_Y 345.f
#define CONST_DISPLACEMENT 150.f

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100.f

#pragma once

/**************Main class to create menu**************/
class Menu {
public:
    Menu() :
        background(PATH_IMAGE),
        play_button(SIZE_MENU_BUTTON, THICKNESS, POS_X,
                    POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                    TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                    POS_TEXT_Y, PATH_TOUCH_BUTTON, PATH_PRESS_BUTTON , "PLAY"),
        settings_button(SIZE_MENU_BUTTON, THICKNESS, POS_X,
                        (POS_Y + CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                         TEXT_SIZE, PATH_FONTS, POS_TEXT_X - FIX_SETTINGS_TEXT_X,
                        (POS_TEXT_Y + CONST_DISPLACEMENT), PATH_TOUCH_BUTTON, PATH_PRESS_BUTTON, "SETTINGS"),
        exit_button(SIZE_MENU_BUTTON, THICKNESS, POS_X,
                    (POS_Y + 2 * CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                    TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                    (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), PATH_TOUCH_BUTTON, PATH_PRESS_BUTTON, "EXIT") {} //Construction for menu

    ~Menu() = default;

    void changeCursor(sf::RenderWindow &window); //Change cursor

    void activateButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button, bool is_mouse_on_exit_button, sf::RenderWindow &window); //Activate buttons

    void pressButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button, bool is_mouse_on_exit_button, bool is_press_mouse, sf::RenderWindow &window); //Press on button

    void drawMenu(sf::RenderWindow &window); //Function for draw

private:
    Background background;
    Button play_button;
    Button settings_button;
    Button exit_button;
    sf::Cursor cursor;
};

