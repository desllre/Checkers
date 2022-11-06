#pragma once
#include "header.h"
#include "elements.h"

/*Music*/
#define MUSIC_PRESS "../songs/pressbutton.wav"
#define MUSIC_TOUCH "../songs/pressbutton.wav"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/menu_bg.png"

/*Settings for button*/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 600.f
#define SIZE_Y 100.f
#define THICKNESS 7.f
#define POS_X 400.f
#define POS_Y 325.f
const sf::Vector2<float> SIZE_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 580.f
#define POS_TEXT_Y 345.f
#define CONST_DISPLACEMENT 150.f

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100.f

/*Settings for arrows*/
#define PATH_ARROW_LEFT "../textures/elements/arrow_left.png"
#define PATH_ARROW_RIGHT "../textures/elements/arrow_right.png"
#define PATH_ARROW_LEFT_ACTIVATE "../textures/elements/arrow_left_activate.png"
#define PATH_ARROW_RIGHT_ACTIVATE "../textures/elements/arrow_right_activate.png"
#define SIZE_ARROW_X 100.f
#define SIZE_ARROW_Y 100.f
#define POS_ARROW_LEFT_X 800.f
#define POS_ARROW_LEFT_Y 345.f
#define POS_ARROW_RIGHT_X 1200.f
#define POS_ARROW_RIGHT_Y 345.f
const sf::Vector2<float> SIZE_ARROW(SIZE_X, SIZE_Y);

/**************Main class to create config game**************/
class ConfigGame {
public:
    ConfigGame() :
            background(PATH_MENU_BACKGROUND),
            begin_button(SIZE_BUTTON, THICKNESS, POS_X,
                         POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                         TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                         POS_TEXT_Y, MUSIC_TOUCH, MUSIC_PRESS, "BEGIN"),
            back_button(SIZE_BUTTON, THICKNESS, POS_X,
                        POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                        POS_TEXT_Y, MUSIC_TOUCH, MUSIC_PRESS, "BACK"),
            arrow_left(SIZE_ARROW, POS_ARROW_LEFT_X, POS_ARROW_LEFT_Y,
                       PATH_ARROW_LEFT, MUSIC_TOUCH, MUSIC_PRESS),
            arrow_right(SIZE_ARROW, POS_ARROW_RIGHT_X, POS_ARROW_RIGHT_Y,
                        PATH_ARROW_RIGHT, MUSIC_TOUCH, MUSIC_PRESS) {} //Construction for config game

    ~ConfigGame() = default;

    void changeCursor(sf::RenderWindow &window); //Change cursor

    void activateButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_right,
                              bool is_mouse_on_arrow_left, sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_left,
                           bool is_mouse_on_arrow_right,bool is_press_mouse_button,
                           bool is_press_mouse, sf::RenderWindow &window); //Press on button and on arrows

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

private:
    Background background;
    Button begin_button;
    Button back_button;
    sf::Text round_text;
    sf::Text option_text;
    sf::Text color_text;
    Arrow arrow_left;
    Arrow arrow_right;
    sf::Cursor cursor;
};
