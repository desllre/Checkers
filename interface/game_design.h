#include "../engine/board.h"
#include "elements.h"

#include "SFML/Graphics.hpp"

#include "string"
#include "filesystem"
#include "fstream"


#define FIRST_FIGURE_POSITION_X 42
#define FIRST_FIGURE_POSITION_Y 56
#define FIGURE_DISPLACEMENT_X 100
#define FIGURE_DISPLACEMENT_Y 100


#pragma once


void Game_design(sf::RenderWindow& window, const uint32_t& roundsNum, bool isSingleGame, GameType gameType, const char& figureColor);

class Game{
public:

    Game(const uint32_t& roundsNum, bool isSingleGame, GameType gameType, bool playerHasWhiteBoard,
         const uint16_t& boardSize);

    void Draw(sf::RenderWindow& window);

private:
    struct Object{
        void SetPosition(int x, int y); // установка позиции объекта
        void Draw(sf::RenderWindow& window);

        sf::Texture texture;
        sf::Sprite sprite;
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;
    };



private:
    Board board;
    Object boardStyle;

    uint32_t roundsNum;
    uint32_t currentRound = 1;

    GameType gameType;

    bool isSingleGame;
    bool playerHasWhiteBoard; // определяет цвет фигур игрока. Если игра на двоих, то первого игрока

    std::string player1Name;
    std::string player2Name;

    Background background;

    Object black_pawn;
    Object black_king;

    Object white_pawn;
    Object white_king;
};

