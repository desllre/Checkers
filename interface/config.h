#include "header.h"
#include "elements.h"
#include "../engine/board.h"
#include "filesystem"
#pragma once

/*Music*/
#define MUSIC_PRESS "../songs/pressbutton.wav"
#define MUSIC_TOUCH "../songs/pressbutton.wav"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/bg.png"

/*Settings for back button*/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_BUTTON_X 250.f
#define SIZE_BUTTON_Y 85.f
#define THICKNESS 5.f
#define POS_BUTTON_X 20.f
#define POS_BUTTON_Y 20.f
const sf::Vector2<float> SIZE_BUTTON(SIZE_BUTTON_X, SIZE_BUTTON_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 40L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 43.f
#define POS_TEXT_Y 37.f
#define CONST_DISPLACEMENT 150.f

/*Fixed value for buttons and texts*/
#define FIX_SETTINGS_TEXT_X 100.f

/*For arrows round*/
#define POS_ARROW_RIGHT_ROUND_X 1170.f
#define POS_ARROW_RIGHT_ROUND_Y 150.f
#define POS_ARROW_LEFT_ROUND_X 780.f
#define POS_ARROW_LEFT_ROUND_Y 145.f
#define SIZE_ARROWS_X 1.f
#define SIZE_ARROWS_Y 1.f
const sf::Vector2<float> SIZE_ARROWS(SIZE_ARROWS_X, SIZE_ARROWS_Y);
#define ARROW_LEFT "../textures/elements/arrow_left.png"
#define ARROW_LEFT_ACTIVATED "../textures/elements/arrow_left.png"
#define ARROW_RIGHT "../textures/elements/arrow_right.png"
#define ARROW_RIGHT_ACTIVATED "../textures/elements/arrow_right.png"

/*Fixed value for arrows*/
#define FIX_ARROW_Y 20.f
#define FIX_ARROW_SIZE_X 80.f
#define FIX_ARROW_SIZE_Y 90.f

/*For round text*/
#define SIZE_FIGURE_X 500.f
#define SIZE_FIGURE_Y 100.f
#define POS_FIGURE_X 75.f
#define POS_FIGURE_Y 150.f
const sf::Vector2<float> SIZE_FIGURE(SIZE_FIGURE_X, SIZE_FIGURE_Y);
#define TEXT_CONFIGS_SIZE 35L
#define POS_TEXT_ROUND_X 90.f
#define POS_TEXT_ROUND_Y 155.f

/*For input number of rounds*/
#define SIZE_INPUT_X 270.f
#define SIZE_INPUT_Y 100.f
#define POS_INPUT_ROUNDS_X 900.f
#define POS_INPUT_ROUNDS_Y 150.f
const sf::Vector2<float> SIZE_INPUT_ROUND(SIZE_INPUT_X, SIZE_INPUT_Y);
#define POS_INPUT_TEXT_ROUND_X 1005.f
#define POS_INPUT_TEXT_ROUNDS_Y 160.f
#define TEXT_INPUT_ROUND_SIZE 60L

/*For begin button*/
#define SIZE_BUTTON_BEGIN_X 265.f
#define SIZE_BUTTON_BEGIN_Y 90.f
#define POS_BUTTON_BEGIN_X 580.f
#define POS_BUTTON_BEGIN_Y 790.f
const sf::Vector2<float> SIZE_BUTTON_BEGIN(SIZE_BUTTON_BEGIN_X, SIZE_BUTTON_BEGIN_Y);
#define TEXT_BEGIN_SIZE 40L
#define POS_TEXT_BEGIN_X 595.f
#define POS_TEXT_BEGIN_Y 810.f

/*For game type text*/
#define SIZE_GAME_TYPE_X 500.f
#define SIZE_GAME_TYPE_Y 100.f
#define POS_GAME_TYPE_X 75.f
#define POS_GAME_TYPE_Y 310.f
const sf::Vector2<float> SIZE_GAME_TYPE(SIZE_GAME_TYPE_X, SIZE_GAME_TYPE_Y);
#define TEXT_GAME_TYPE_SIZE 35L
#define POS_GAME_TYPE_TEXT_ROUND_X 90.f
#define POS_GAME_TYPE_TEXT_ROUND_Y 315.f

/*For input type of game*/
#define SIZE_INPUT_TYPE_X 600.f
#define SIZE_INPUT_TYPE_Y 100.f
#define POS_INPUT_TYPE_ROUNDS_X 740.f
#define POS_INPUT_TYPE_ROUNDS_Y 310.f
const sf::Vector2<float> SIZE_INPUT_TYPE_ROUND(SIZE_INPUT_TYPE_X, SIZE_INPUT_TYPE_Y);
#define POS_INPUT_TYPE_TEXT_ROUND_X 755.f
#define POS_INPUT_TYPE_TEXT_ROUNDS_Y 340.f
#define TEXT_INPUT_TYPE_SIZE 35L

/*For arrows type game*/
#define POS_ARROW_RIGHT_TYPE_X 1335.f
#define POS_ARROW_RIGHT_TYPE_Y 295.f
#define POS_ARROW_LEFT_TYPE_X 620.f
#define POS_ARROW_LEFT_TYPE_Y 305.f

/*For color checkers text*/
#define SIZE_COLOR_X 500.f
#define SIZE_COLOR_Y 100.f
#define POS_COLOR_X 75.f
#define POS_COLOR_Y 475.f
const sf::Vector2<float> SIZE_COLOR_TYPE(SIZE_COLOR_X, SIZE_COLOR_Y);
#define TEXT_COLOR_SIZE 35L
#define POS_GAME_COLOR_ROUND_X 90.f
#define POS_GAME_COLOR_ROUND_Y 480.f

/*For input color of checkers*/
#define SIZE_INPUT_COLOR_X 270.f
#define SIZE_INPUT_COLOR_Y 100.f
#define POS_INPUT_COLOR_X 900.f
#define POS_INPUT_COLOR_Y 475.f
const sf::Vector2<float> SIZE_INPUT_COLOR_ROUND(SIZE_INPUT_COLOR_X, SIZE_INPUT_COLOR_Y);
#define POS_INPUT_COLOR_TEXT_X 910.f
#define POS_INPUT_COLOR_TEXT_Y 505.f
#define TEXT_INPUT_COLOR_SIZE 35L

/*For arrows type game*/
#define POS_ARROW_RIGHT_COLOR_X 1175.f
#define POS_ARROW_RIGHT_COLOR_Y 460.f
#define POS_ARROW_LEFT_COLOR_X 780.f
#define POS_ARROW_LEFT_COLOR_Y 470.f


/*For multiplayer checkers text*/
#define SIZE_MULTIPLAYER_X 500.f
#define SIZE_MULTIPLAYER_Y 100.f
#define POS_MULTIPLAYER_X 75.f
#define POS_MULTIPLAYER_Y 640.f
const sf::Vector2<float> SIZE_MULTIPLAYER_TYPE(SIZE_MULTIPLAYER_X, SIZE_MULTIPLAYER_Y);
#define TEXT_MULTIPLAYER_SIZE 32L
#define POS_GAME_MULTIPLAYER_X 90.f
#define POS_GAME_MULTIPLAYER_Y 670.f

/*For input multiplayer of checkers*/
#define SIZE_INPUT_MULTIPLAYER_X 600.f
#define SIZE_INPUT_MULTIPLAYER_Y 100.f
#define POS_INPUT_MULTIPLAYER_X 740.f
#define POS_INPUT_MULTIPLAYER_Y 640.f
const sf::Vector2<float> SIZE_INPUT_MULTIPLAYER_ROUND(SIZE_INPUT_MULTIPLAYER_X, SIZE_INPUT_MULTIPLAYER_Y);
#define POS_INPUT_MULTIPLAYER_TEXT_X 750.f
#define POS_INPUT_MULTIPLAYER_TEXT_Y 670.f
#define TEXT_INPUT_MULTIPLAYER_SIZE 35L

/*For multiplayer arrows*/
#define POS_ARROW_RIGHT_MULTIPLAYER_X 1335.f
#define POS_ARROW_RIGHT_MULTIPLAYER_Y 625.f
#define POS_ARROW_LEFT_MULTIPLAYER_X 620.f
#define POS_ARROW_LEFT_MULTIPLAYER_Y 635.f

#pragma once

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
                             ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH, MUSIC_PRESS),
            arrow_round_right(SIZE_ARROWS, POS_ARROW_RIGHT_ROUND_X, POS_ARROW_RIGHT_ROUND_Y,
                              ARROW_RIGHT, ARROW_RIGHT_ACTIVATED, MUSIC_TOUCH, MUSIC_PRESS),
            text_round(SIZE_FIGURE, THICKNESS, POS_FIGURE_X,
                       POS_FIGURE_Y, COLOR_OUTLINE, COLOR_TEXT,
                       TEXT_CONFIGS_SIZE, PATH_FONTS,
                       "NUMBER\nOF ROUNDS", POS_TEXT_ROUND_X, POS_TEXT_ROUND_Y),
            begin_button(SIZE_BUTTON_BEGIN, THICKNESS, POS_BUTTON_BEGIN_X,
                         POS_BUTTON_BEGIN_Y, COLOR_OUTLINE, COLOR_TEXT,
                         TEXT_BEGIN_SIZE, PATH_FONTS, POS_TEXT_BEGIN_X,
                         POS_TEXT_BEGIN_Y, MUSIC_TOUCH, MUSIC_PRESS, "BEGIN"),
            rounds(SIZE_INPUT_ROUND, THICKNESS, POS_INPUT_ROUNDS_X,
                   POS_INPUT_ROUNDS_Y, COLOR_OUTLINE, COLOR_TEXT,
                   TEXT_INPUT_ROUND_SIZE, PATH_FONTS,
                   "1", POS_INPUT_TEXT_ROUND_X, POS_INPUT_TEXT_ROUNDS_Y, roundsNum),
            arrow_type_left(SIZE_ARROWS, POS_ARROW_LEFT_TYPE_X, POS_ARROW_LEFT_TYPE_Y,
                            ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH,
                            MUSIC_PRESS),
            arrow_type_right(SIZE_ARROWS, POS_ARROW_RIGHT_TYPE_X, POS_ARROW_RIGHT_TYPE_Y,
                             ARROW_RIGHT, ARROW_RIGHT_ACTIVATED, MUSIC_TOUCH,
                             MUSIC_PRESS),
            text_game_type(SIZE_GAME_TYPE, THICKNESS, POS_GAME_TYPE_X,
                           POS_GAME_TYPE_Y, COLOR_OUTLINE, COLOR_TEXT,
                           TEXT_GAME_TYPE_SIZE, PATH_FONTS,
                           "TYPE OF\nRULES GAME", POS_GAME_TYPE_TEXT_ROUND_X, POS_GAME_TYPE_TEXT_ROUND_Y),
            rules(SIZE_INPUT_TYPE_ROUND, THICKNESS, POS_INPUT_TYPE_ROUNDS_X,
                  POS_INPUT_TYPE_ROUNDS_Y, COLOR_OUTLINE, COLOR_TEXT,
                  TEXT_INPUT_TYPE_SIZE, PATH_FONTS,
                  "Russian", POS_INPUT_TYPE_TEXT_ROUND_X, POS_INPUT_TYPE_TEXT_ROUNDS_Y, game_type),
            text_color(SIZE_COLOR_TYPE, THICKNESS, POS_COLOR_X, POS_COLOR_Y,
                       COLOR_OUTLINE, COLOR_TEXT, TEXT_COLOR_SIZE, PATH_FONTS,
                       "COLOR OF\nCHECKERS", POS_GAME_COLOR_ROUND_X, POS_GAME_COLOR_ROUND_Y),
            color(SIZE_INPUT_COLOR_ROUND, THICKNESS, POS_INPUT_COLOR_X,
                  POS_INPUT_COLOR_Y, COLOR_OUTLINE, COLOR_TEXT,
                  TEXT_INPUT_COLOR_SIZE, PATH_FONTS,
                  "White", POS_INPUT_COLOR_TEXT_X, POS_INPUT_COLOR_TEXT_Y, color_of_checkers),
            arrow_color_left(SIZE_ARROWS, POS_ARROW_LEFT_COLOR_X, POS_ARROW_LEFT_COLOR_Y,
                             ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH,
                             MUSIC_PRESS),
            arrow_color_right(SIZE_ARROWS, POS_ARROW_RIGHT_COLOR_X, POS_ARROW_RIGHT_COLOR_Y,
                              ARROW_RIGHT, ARROW_RIGHT_ACTIVATED, MUSIC_TOUCH, MUSIC_PRESS),
            text_multiplayer(SIZE_MULTIPLAYER_TYPE, THICKNESS, POS_MULTIPLAYER_X, POS_MULTIPLAYER_Y,
                             COLOR_OUTLINE, COLOR_TEXT, TEXT_MULTIPLAYER_SIZE, PATH_FONTS,
                             "MULTIPLAYER?", POS_GAME_MULTIPLAYER_X, POS_GAME_MULTIPLAYER_Y),
            multiplayer(SIZE_INPUT_MULTIPLAYER_ROUND, THICKNESS, POS_INPUT_MULTIPLAYER_X,
                        POS_INPUT_MULTIPLAYER_Y, COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_INPUT_MULTIPLAYER_SIZE, PATH_FONTS,
                        "Single Player", POS_INPUT_MULTIPLAYER_TEXT_X, POS_INPUT_MULTIPLAYER_TEXT_Y),
            arrow_multiplayer_left(SIZE_ARROWS, POS_ARROW_LEFT_MULTIPLAYER_X, POS_ARROW_LEFT_MULTIPLAYER_Y,
                                   ARROW_LEFT, ARROW_LEFT_ACTIVATED, MUSIC_TOUCH,
                                   MUSIC_PRESS),
            arrow_multiplayer_right(SIZE_ARROWS, POS_ARROW_RIGHT_MULTIPLAYER_X, POS_ARROW_RIGHT_MULTIPLAYER_Y,
                                    ARROW_RIGHT, ARROW_RIGHT_ACTIVATED, MUSIC_TOUCH, MUSIC_PRESS)
    {};

    ~ConfigGame() = default;

    void activateButtonArrows(bool is_mouse_on_back_button,
                              bool is_mouse_on_begin_button,
                              bool is_mouse_on_left_round_arrows,
                              bool is_mouse_on_right_round_arrows,
                              bool is_mouse_on_left_text_arrows,
                              bool is_mouse_on_right_text_arrows,
                              bool is_mouse_on_left_color_arrows,
                              bool is_mouse_on_right_color_arrows,
                              bool is_mouse_on_left_multiplayer_arrows,
                              bool is_mouse_on_right_multiplayer_arrows,
                              sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button,
                           bool is_mouse_on_begin_button,
                           bool is_mouse_on_left_round_arrows,
                           bool is_mouse_on_right_round_arrows,
                           bool is_mouse_on_left_type_arrows,
                           bool is_mouse_on_right_type_arrows,
                           bool is_mouse_on_left_color_arrows,
                           bool is_mouse_on_right_color_arrows,
                           bool is_mouse_on_left_multiplayer_arrows,
                           bool is_mouse_on_right_multiplayer_arrows,
                           bool is_press_mouse,
                           sf::RenderWindow &window); //Press on button and on arrows

    void setArrowCursor(sf::RenderWindow& window); //Change arrow cursor

    void setHandCursor(sf::RenderWindow& window); //Change hand cursor

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

    bool getIsBackButtonPressed(); //Get value end of function

private:
    Background background;
    Button back_button;
    Button begin_button;
    sf::Cursor cursor;

    /*Config round*/
    Arrow arrow_round_left;
    Arrow arrow_round_right;
    Arrow arrow_type_left;
    Arrow arrow_type_right;
    Text text_round;
    Text text_game_type;
    Text text_color;
    Text text_multiplayer;
    InputFieldRounds rounds;
    InputFieldTypeRules rules;
    InputFieldColor color;
    Arrow arrow_color_left;
    Arrow arrow_color_right;

    InputFieldMultiplayer multiplayer;
    Arrow arrow_multiplayer_left;
    Arrow arrow_multiplayer_right;

    /*Configs game*/
    uint32_t roundsNum = 1;
    GameType game_type = Russian;
    char color_of_checkers = 'w';
    bool is_single_game = true;

    /*For working window*/
    bool is_set_cursor = true;
    bool is_back_button_pressed = false;
};