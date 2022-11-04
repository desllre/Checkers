#include "header.h"
#include "elements.h"

/**Settings for background**/
#define PATH_IMAGE "../textures/backgrounds/menu_bg.png"

/**Settings for button**/
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 600.f
#define SIZE_Y 100.f
#define THICKNESS 7.f
#define POS_X 400.f
#define POS_Y 325.f
const sf::Vector2<float> SIZE_BUTTON(SIZE_X, SIZE_Y);

/**Settings for text**/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 580.f
#define POS_TEXT_Y 345.f
#define CONST_DISPLACEMENT 150.f

/**Fixed value for buttons and texts**/
#define FIX_SETTINGS_TEXT_X 100.f

class Menu {
public:
    Menu() : background(PATH_IMAGE),
        play_button(SIZE_BUTTON, THICKNESS, POS_X,
                    POS_Y, COLOR_OUTLINE, COLOR_TEXT,
                    TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                    POS_TEXT_Y, "PLAY"),
        settings_button(SIZE_BUTTON, THICKNESS, POS_X,
                        (POS_Y + CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                         TEXT_SIZE, PATH_FONTS, POS_TEXT_X - FIX_SETTINGS_TEXT_X,
                        (POS_TEXT_Y + CONST_DISPLACEMENT), "SETTINGS"),
        exit_button(SIZE_BUTTON, THICKNESS, POS_X,
                    (POS_Y + 2 * CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                    TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                    (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), "EXIT") {}

    void drawMenu(sf::RenderWindow& window) {
        sf::Vector2<int> mouse_position = sf::Mouse::getPosition(window);

        if ((mouse_position.x >= POS_X && mouse_position.y >= POS_Y) &&
            (mouse_position.x <= POS_X + SIZE_X && mouse_position.y <= POS_Y + SIZE_Y)) {
            play_button.setColorFigure(sf::Color::Red);
            play_button.setColorText(sf::Color::Red);
        }
        else {
            play_button.setColorFigure(sf::Color::Black);
            play_button.setColorText(sf::Color::Black);
        }

        if ((mouse_position.x >= POS_X && mouse_position.y >= (POS_Y + CONST_DISPLACEMENT)) &&
            (mouse_position.x <= POS_X + SIZE_X) &&
            (mouse_position.y <= (POS_Y + SIZE_Y + CONST_DISPLACEMENT))) {
            settings_button.setColorFigure(sf::Color::Red);
            settings_button.setColorText(sf::Color::Red);
        }
        else {
            settings_button.setColorFigure(sf::Color::Black);
            settings_button.setColorText(sf::Color::Black);
        }

        if ((mouse_position.x >= POS_X && mouse_position.y >= (POS_Y + 2 * CONST_DISPLACEMENT)) &&
            (mouse_position.x <= POS_X + SIZE_X) &&
            (mouse_position.y <= (POS_Y + SIZE_Y + 2 * CONST_DISPLACEMENT))) {
            exit_button.setColorFigure(sf::Color::Red);
            exit_button.setColorText(sf::Color::Red);
        }
        else {
            exit_button.setColorFigure(sf::Color::Black);
            exit_button.setColorText(sf::Color::Black);
        }


        background.drawBackground(window);
        play_button.drawButton(window);
        settings_button.drawButton(window);
        exit_button.drawButton(window);
    }



    ~Menu() = default;

private:
    Background background;
    Button play_button;
    Button settings_button;
    Button exit_button;
};

