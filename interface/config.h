#include "header.h"
#include "elements.h"
#include "../engine/board.h"
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

/*For arrows round*/
#define POS_ARROW_RIGHT_ROUND_X 1300.f
#define POS_ARROW_RIGHT_ROUND_Y 220.f
#define POS_ARROW_LEFT_ROUND_X 880.f
#define POS_ARROW_LEFT_ROUND_Y 220.f
#define SIZE_ARROWS_X 1.f
#define SIZE_ARROWS_Y 1.f
const sf::Vector2<float> SIZE_ARROWS(SIZE_ARROWS_X, SIZE_ARROWS_Y);
#define ARROW_LEFT "../textures/elements/arrow_left.png"
#define ARROW_LEFT_ACTIVATED "../textures/elements/arrow_left_activated.png"
#define ARROW_RIGHT "../textures/elements/arrow_right.png"
#define ARROW_RIGHT_ACTIVATED "../textures/elements/arrow_right_activated.png"

/*Fixed value for arrows*/
#define FIX_ARROW_Y 15.f
#define FIX_ARROW_SIZE_X 80.f
#define FIX_ARROW_SIZE_Y 40.f

/*For round text*/
#define SIZE_FIGURE_X 650.f
#define SIZE_FIGURE_Y 120.f
#define POS_FIGURE_X 75.f
#define POS_FIGURE_Y 190.f
const sf::Vector2<float> SIZE_FIGURE(SIZE_FIGURE_X, SIZE_FIGURE_Y);
#define COLOR_CONFIG_TEXT sf::Color::Black
#define TEXT_CONFIGS_SIZE 40L
#define POS_TEXT_ROUND_X 90.f
#define POS_TEXT_ROUND_Y 200.f

/*For input number of rounds*/
#define SIZE_INPUT_X 270.f
#define SIZE_INPUT_Y 120.f
#define POS_INPUT_ROUNDS_X 1000.f
#define POS_INPUT_ROUNDS_Y 190.f
const sf::Vector2<float> SIZE_INPUT_ROUND(SIZE_INPUT_X, SIZE_INPUT_Y);
#define POS_INPUT_TEXT_ROUND_X 1105.f
#define POS_INPUT_TEXT_ROUNDS_Y 205.f
#define TEXT_INPUT_ROUND_SIZE 70L

/*For begin button*/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_BUTTON_BEGIN_X 265.f
#define SIZE_BUTTON_BEGIN_Y 90.f
#define POS_BUTTON_BEGIN_X 580.f
#define POS_BUTTON_BEGIN_Y 790.f
const sf::Vector2<float> SIZE_BUTTON_BEGIN(SIZE_BUTTON_BEGIN_X, SIZE_BUTTON_BEGIN_Y);
#define COLOR_BEGIN_TEXT sf::Color::Black
#define TEXT_BEGIN_SIZE 40L
#define POS_TEXT_BEGIN_X 595.f
#define POS_TEXT_BEGIN_Y 810.f

/*For game type text*/
#define SIZE_GAME_TYPE_X 650.f
#define SIZE_GAME_TYPE_Y 120.f
#define POS_GAME_TYPE_X 75.f
#define POS_GAME_TYPE_Y 380.f
const sf::Vector2<float> SIZE_GAME_TYPE(SIZE_GAME_TYPE_X, SIZE_GAME_TYPE_Y);
#define COLOR_GAME_TYPE_TEXT sf::Color::Black
#define TEXT_GAME_TYPE_SIZE 40L
#define POS_GAME_TYPE_TEXT_ROUND_X 90.f
#define POS_GAME_TYPE_TEXT_ROUND_Y 390.f

/**************Main class to create config game**************/
class ConfigGame {
public:
    ConfigGame() :
        background(PATH_MENU_BACKGROUND),
        back_button(SIZE_BUTTON, THICKNESS, POS_BUTTON_X,
                        POS_BUTTON_Y, COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                        POS_TEXT_Y, MUSIC_TOUCH, MUSIC_PRESS, "BACK"),
        arrow_round_left(SIZE_ARROWS, POS_ARROW_LEFT_ROUND_X, POS_ARROW_LEFT_ROUND_Y,
                             ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH,
                             MUSIC_PRESS),
        arrow_round_right(SIZE_ARROWS, POS_ARROW_RIGHT_ROUND_X, POS_ARROW_RIGHT_ROUND_Y,
                          ARROW_RIGHT, ARROW_RIGHT_ACTIVATED, MUSIC_TOUCH,
                          MUSIC_PRESS),
        text_round(SIZE_FIGURE, THICKNESS, POS_FIGURE_X,
                   POS_FIGURE_Y, COLOR_OUTLINE, COLOR_CONFIG_TEXT,
                   TEXT_CONFIGS_SIZE, PATH_FONTS,
                   "NUMBER\nOF ROUNDS",
                    POS_TEXT_ROUND_X, POS_TEXT_ROUND_Y),
        begin_button(SIZE_BUTTON_BEGIN, THICKNESS, POS_BUTTON_BEGIN_X,
                     POS_BUTTON_BEGIN_Y, COLOR_OUTLINE, COLOR_BEGIN_TEXT,
                     TEXT_BEGIN_SIZE, PATH_FONTS, POS_TEXT_BEGIN_X,
                     POS_TEXT_BEGIN_Y, MUSIC_TOUCH, MUSIC_PRESS, "BEGIN"),
        rounds(SIZE_INPUT_ROUND, THICKNESS, POS_INPUT_ROUNDS_X,
               POS_INPUT_ROUNDS_Y, COLOR_OUTLINE, COLOR_CONFIG_TEXT,
               TEXT_INPUT_ROUND_SIZE, PATH_FONTS,
               "1", POS_INPUT_TEXT_ROUND_X, POS_INPUT_TEXT_ROUNDS_Y, roundsNum),
        text_game_type(SIZE_GAME_TYPE, THICKNESS, POS_GAME_TYPE_X,
                       POS_GAME_TYPE_Y, COLOR_OUTLINE, COLOR_GAME_TYPE_TEXT,
                       TEXT_GAME_TYPE_SIZE, PATH_FONTS,
                       "TYPE OF\nRULES GAME", POS_GAME_TYPE_TEXT_ROUND_X, POS_GAME_TYPE_TEXT_ROUND_Y) {};

    ~ConfigGame() = default;

    void activateButtonArrows(bool is_mouse_on_back_button,
                              bool is_mouse_on_begin_button,
                              bool is_mouse_on_left_round_arrows,
                              bool is_mouse_on_right_round_arrows,
                              sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button,
                           bool is_mouse_on_begin_button,
                           bool is_mouse_on_left_round_arrows,
                           bool is_mouse_on_right_round_arrows,
                           bool is_press_mouse,
                           sf::RenderWindow &window); //Press on button and on arrows

    void setArrowCursor(sf::RenderWindow& window); //Change arrow cursor

    void setHandCursor(sf::RenderWindow& window); //Change hand cursor

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

    bool getIsBackButtonPressed(); //Get value end of function

    void saveSettings(); // Saving the settings

private:
    Background background;
    Button back_button;
    Button begin_button;
    sf::Cursor cursor;

    /*Config round*/
    Arrow arrow_round_left;
    Arrow arrow_round_right;
    Text text_round;
    Text text_game_type;
    InputFieldRounds rounds;

    /*Configs game*/
    uint32_t roundsNum = 1;
    GameType gameType = Russian;
    char figureColor = 'w';
    bool isSingleGame = true;

    /*For working window*/
    bool is_set_cursor = true;
    bool is_back_button_pressed = false;
};
