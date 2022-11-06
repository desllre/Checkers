#include "header.h"
#include "elements.h"

// BACKGROUND VARIABLES
#define BACKGROUND_IMAGE "../textures/menu_exit.png"

// BUTTON VARIABLES
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 600.f
#define SIZE_Y 100.f
#define THICKNESS 7.f
#define POS_X 400.f
#define POS_Y 325.f
const sf::Vector2<float> SIZE_EXIT_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 48L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_TEXT_X 580.f
#define POS_TEXT_Y 345.f
#define CONST_DISPLACEMENT 150.f

class Exit {
public:

Exit();

~Exit() = default;

void Draw(sf::RenderWindow&);


private:
Background background;
Button accept;
Button cancel;
};