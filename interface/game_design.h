#include "../engine/board.h"
#include "elements.h"

#include "SFML/Graphics.hpp"


// IMAGES
#define GAME_BACKGROUND "../textures/backgrounds/game_bg.png"


#define BLACK_AND_WHITE_SMALL_BOARD "../textures/boards/bw.png"
#define BLACK_AND_WHITE_BIG_BOARD "../textures/boards/big_bw.png"

#define STANDART_SMALL_BOARD "../textures/boards/yellow.png"
#define STANDART_BIG_BOARD "../textures/boards/big_yellow.png"


#define BLACK_AND_WHITE_PAWN_BLACK "../textures/figures/black_and_white/black_pawn.png"
#define BLACK_AND_WHITE_KING_BLACK "../textures/figures/black_and_white/black_king.png"

#define BLACK_AND_WHITE_PAWN_WHITE "../textures/figures/black_and_white/white_pawn.png"
#define BLACK_AND_WHITE_KING_WHITE "../textures/figures/black_and_white/white_king.png"

#define STANDART_PAWN_BLACK "../textures/figures/Standart/black_pawn.png"
#define STANDART_KING_BLACK "../textures/figures/Standart/black_king.png"

#define STANDART_PAWN_WHITE "../textures/figures/Standart/white_pawn.png"
#define STANDART_KING_WHITE "../textures/figures/Standart/white_king.png"




#pragma once


void Game_design(sf::RenderWindow& window, const uint32_t& roundsNum, bool isSingleGame, GameType gameType, const char& figureColor);

class Game{
public:

    Game(const uint32_t& roundsNum, bool isSingleGame, GameType gameType, bool playerHasWhiteBoard, const uint16_t& boardSize, bool isWhiteBoard);

private:
    struct Object{
        sf::Texture texture;
        sf::Sprite sprite;
        uint32_t x;
        uint32_t y;
        uint32_t width;
        uint32_t height;
    };

private:
    Board board;

    uint32_t roundsNum;
    uint32_t currentRound = 1;

    GameType gameType;

    bool isSingleGame;
    bool playerHasWhiteBoard; // определяет цвет фигур игрока. Если игра на двоих, то первого игрока

    Background background;

    Object black_pawn;
    Object black_king;

    Object white_pawn;
    Object white_king;
};