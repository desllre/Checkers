#include "elements.h"

#include "SFML/Graphics.hpp"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/menu_exit.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 310
#define SIZE_Y 70
#define THICKNESS 3

#define POS_RESUME_X 25
#define POS_RESTART_X 360
#define POS_EXIT_X 192.5f

#define POS_RESUME_Y 235
#define POS_RESTART_Y 235
#define POS_EXIT_Y 325
const sf::Vector2<float> SIZE_GAME_EXIT_BUTTONS(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 30L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"

#define POS_RESUME_TEXT_X 61
#define POS_RESTART_TEXT_X 380
#define POS_EXIT_TEXT_X 267

#define POS_RESUME_TEXT_Y 252
#define POS_RESTART_TEXT_Y 252
#define POS_EXIT_TEXT_Y 342

#pragma once

void GameExitWindow(sf::RenderWindow& window, int& gameState); // gameState - данная переменная будет определять состояние борда после закрытия gameExitWindow
                                                              // 0 - продолжение, 1 - рестарт, 2 - выход в меню
class GameExit{
public:
    GameExit();
    ~GameExit() = default;

    void ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window); // проверка наведения на кнопки

    int PressButton(bool mouse_is_pressed) const; // функция проверки нажатия на кнопку. Возвращает -1 - если ничего не нажато, 0 - если нажата клавиша resume, 1 - restart, 2 - exit

    void Draw(sf::RenderWindow& window);

private:

    void ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor);

private:
    Background background;
    Button resume;
    Button restart;
    Button exit;

    sf::Cursor cursor;

    bool is_mouse_on_resume_button = false;
    bool is_mouse_on_restart_button = false;
    bool is_mouse_on_exit_button = false;

    bool is_mouse_on_button = false;
};