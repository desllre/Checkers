#include "elements.h"

#include "SFML/Graphics.hpp"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/menu_exit.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 290.f
#define SIZE_Y 80.f
#define THICKNESS 3.f
#define POS_ACCEPT_X 10.f
#define POS_CANCEL_X 395.f
#define POS_Y 280.f
const sf::Vector2<float> SIZE_EXIT_BUTTON(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 35L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"
#define POS_ACCEPT_TEXT_X 28.f
#define POS_CANCEL_TEXT_X 420.f
#define POS_TEXT_Y 300.f

#pragma once

void ExitWindow(sf::RenderWindow& window);

class Exit {
private:

public:
    Exit();
    ~Exit() = default;

    void Draw(sf::RenderWindow&);
private:
    Background background;
    Button accept;
    Button cancel;
};