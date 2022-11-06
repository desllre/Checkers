#include "header.h"
#include "elements.h"

/*Music*/
#define MUSIC_PRESS "../songs/pressbutton.wav"
#define MUSIC_TOUCH "../songs/pressbutton.wav"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/bg.png"

/*Settings for back button*/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 265.f
#define SIZE_Y 90.f
#define THICKNESS 7.f
#define POS_X 20.f
#define POS_Y 20.f
const sf::Vector2<float> SIZE_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 30.f
#define POS_TEXT_Y 35.f
#define CONST_DISPLACEMENT 150.f

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100.f

#pragma once

/**************Main class to create config game**************/
class ConfigGame {
public:
    ConfigGame() :
            background(PATH_MENU_BACKGROUND),
            back_button(SIZE_BUTTON, THICKNESS, POS_X,
                        POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                        POS_TEXT_Y, MUSIC_TOUCH, MUSIC_PRESS, "BACK") {}

    ~ConfigGame() = default;

    void changeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor); //Change cursor

    void activateButtonArrows(bool is_mouse_on_back_button, sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button, bool is_press_mouse, sf::RenderWindow &window); //Press on button and on arrows

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

    bool getValueEndFunction(); //Get value end of function

private:
    bool end_function = false;
    Background background;
    Button back_button;
    sf::Cursor cursor;
};
