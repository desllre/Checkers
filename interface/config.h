#include "header.h"
#include "elements.h"
#pragma once

/*Music*/
#define MUSIC_PRESS "../songs/pressbutton.wav"
#define MUSIC_TOUCH "../songs/pressbutton.wav"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/bg.png"

/*Settings for back button*/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_BUTTON_X 265.f
#define SIZE_BUTTON_Y 90.f
#define THICKNESS 7.f
#define POS_BUTTON_X 20.f
#define POS_BUTTON_Y 20.f
const sf::Vector2<float> SIZE_BUTTON(SIZE_BUTTON_X, SIZE_BUTTON_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 30.f
#define POS_TEXT_Y 35.f
#define CONST_DISPLACEMENT 150.f

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100.f

/*For arrows*/
#define POS_ARROW_ROUND_X 600.f
#define POS_ARROW_ROUND_Y 300.f
#define SIZE_ARROWS_X 100.f
#define SIZE_ARROWS_Y 100.f
const sf::Vector2<float> SIZE_ARROWS(SIZE_ARROWS_X, SIZE_ARROWS_Y);
#define ARROW_LEFT "../textures/elements/arrow_left.png"
#defineARROW_LEFT_ACTIVATED "../textures/elements/"
#define ARROW_RIGHT "../textures/elements/arrow_right.png"


/**************Main class to create config game**************/
class ConfigGame {
public:
    ConfigGame() :
        background(PATH_MENU_BACKGROUND),
        back_button(SIZE_BUTTON, THICKNESS, POS_BUTTON_X,
                        POS_BUTTON_Y, COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                        POS_TEXT_Y, MUSIC_TOUCH, MUSIC_PRESS, "BACK"),
        arrow_round_left(SIZE_ARROWS, POS_ARROW_ROUND_X, POS_ARROW_ROUND_Y,
                             ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH,
                             MUSIC_PRESS) {}

    ~ConfigGame() = default;

    void activateButtonArrows(bool is_mouse_on_back_button, sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button, bool is_press_mouse, sf::RenderWindow &window); //Press on button and on arrows

    void changeCursor(sf::RenderWindow& window, sf::Cursor::Type type_cursor); //Change cursor

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

    bool getIsBackButtonPressed(); //Get value end of function

private:
    Arrow arrow_round_left;
    Background background;
    Button back_button;
    bool is_cursor_set = true;
    bool is_back_button_pressed = false;
};
