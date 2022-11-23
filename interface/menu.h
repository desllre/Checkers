#include "header.h"
#include "elements.h"
#include "config.h"
#include "exitWindow.h"
#include "settings.h"
#include "game_design.h"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/menu_bg.png"

/*Settings for button*/
#define PATH_PRESS_BUTTON "../songs/pressbutton.wav"
#define PATH_TOUCH_BUTTON "../songs/pressbutton.wav"
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 600
#define SIZE_Y 100
#define THICKNESS 7
#define POS_X 420
#define POS_Y 325
const sf::Vector2<float> SIZE_MENU_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 600
#define POS_TEXT_Y 345
#define CONST_DISPLACEMENT 150

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100

#pragma once

/**************Main class to create menu**************/
class Menu {
public:
    Menu();//Construction for menu

    ~Menu() = default;

    void changeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor); //Change cursor

    void activateButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button, bool is_mouse_on_exit_button, sf::RenderWindow &window); //Activate buttons

    void pressButton(bool is_mouse_on_play_button, bool is_mouse_on_settings_button, bool is_mouse_on_exit_button, bool is_press_mouse, sf::RenderWindow &window); //Press on button

    void drawMenu(sf::RenderWindow &window); //Function for draw

private:
    Background background;
    Button play_button;
    Button settings_button;
    Button exit_button;
    sf::Cursor cursor;

    bool is_mouse_on_button = false;

    sf::Clock press_delay_timer; // a delay on pressing so that the buttons are not pressed again when leaving the selected item

};

