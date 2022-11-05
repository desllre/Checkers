#include "header.h"
#include "elements.h"

/*Settings for background*/
#define PATH_MENU_BACKGROUND "../textures/backgrounds/menu_bg.png"

/*Settings for button*/
#define PATH_PRESS_BUTTON "../songs/pressbutton.wav"
#define PATH_TOUCH_BUTTON "../songs/pressbutton.wav"
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

/**************Main class to create config game**************/
class ConfigGame {
public:
    ConfigGame() :
            background(PATH_MENU_BACKGROUND),

            back_button(SIZE_BUTTON, THICKNESS, POS_X,
                        (POS_Y + 2 * CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                        TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                        (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), PATH_TOUCH_BUTTON, PATH_PRESS_BUTTON, "BACK"),
            arrow_left(),
            arrow_right() {} //Construction for config game

    void changeCursor(sf::RenderWindow &window); //Change cursor

    void activateButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_right,
                        bool is_mouse_on_arrow_left, sf::RenderWindow &window); //Activate buttons and arrows

    void pressButtonArrows(bool is_mouse_on_back_button, bool is_mouse_on_begin_button, bool is_mouse_on_arrow_left,
                           bool is_mouse_on_arrow_right,bool is_press_mouse_button,
                           bool is_press_mouse, sf::RenderWindow &window); //Press on button and on arrows

    void drawConfigGame(sf::RenderWindow& window); //Function for draw

    ~ConfigGame() = default;

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

