#include "elements.h"

#include "SFML/Graphics.hpp"

#include "string"

// BACKGROUND VARIABLESS
#define BACKGROUND_IMAGE "../textures/backgrounds/end_of_game.png"

// BUTTON VARIABLESS
#define COLOR_OUTLINE sf::Color::Black
#define SIZE_X 290
#define SIZE_Y 70
#define THICKNESS 3

#define POS_RESTART_X 38.3
#define POS_EXIT_X 366.6

#define POS_RESTART_Y 320
#define POS_EXIT_Y 320
const sf::Vector2<float> SIZE_END_OF_GAME_BUTTONS(SIZE_X, SIZE_Y);

/*Settings for text*/
#define COLOR_TEXT sf::Color::Black
#define TEXT_SIZE 30L
#define PATH_FONTS "../fonts/GOUDYSTO.TTF"

#define POS_RESTART_TEXT_X 45
#define POS_EXIT_TEXT_X 436

#define POS_RESTART_TEXT_Y 336
#define POS_EXIT_TEXT_Y 336

#pragma once

// возвращаемые значения: 0 - продолжение игры, 1 - рестарт игры, 2 - выход из игры
void EndOfGameWindow(sf::RenderWindow& window, uint32_t roundsNum, uint32_t currentRound, std::pair<uint16_t, uint16_t> score, const std::string& winnerName, int &returnValue);

class EndOfGame{
public:
    EndOfGame(uint32_t roundsNum, uint32_t currentRound, std::pair<uint16_t, uint16_t> score, const std::string& winnerName);
    ~EndOfGame() = default;

    void ActivateButton(const sf::Vector2i& mousePos, sf::RenderWindow& window);

    void Draw(sf::RenderWindow& window);

    int PressButton(bool mouse_is_pressed) const; // возвращает 0, если нажата кнопка рестарт, 1 - если выход, -1 - ничего

    bool IsLastRound(); // возвращает isLastRound
private:

    void ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor);

private:
    Background background;

    sf::Cursor cursor;

    sf::Font font;

    std::pair<uint16_t, uint16_t> score;
    sf::Text scoreText;
    sf::RectangleShape scoreRect;

    std::string winnerName;
    sf::Text winnerNameText;
    sf::RectangleShape winnerNameRect;

    Button restart;
    Button exit;

    bool isExitActive = false;
    bool isRestartActive = false;
    bool isMouseOnButton = false;

    uint32_t currentRound;
    uint32_t roundsNum;

    bool isLastRound = false;
};

