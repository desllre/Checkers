#include "../engine/board.h"
#include "elements.h"

#include "SFML/Graphics.hpp"

#include "string"
#include "vector"
#include "filesystem"
#include "fstream"



#define BOARD_WIDTH 800
#define BOARD_HEIGHT 800

// константы для большого поля (междуанродные шашки)
#define BIG_FIRST_FIGURE_POSITION_X 42
#define BIG_FIRST_FIGURE_POSITION_Y 56
#define BIG_FIGURE_DISPLACEMENT_X 80
#define BIG_FIGURE_DISPLACEMENT_Y 80

// константы для малого поля (любые шашки, кроме международных)
#define SMALL_FIRST_FIGURE_POSITION_X 42
#define SMALL_FIRST_FIGURE_POSITION_Y 56
#define SMALL_FIGURE_DISPLACEMENT_X 100
#define SMALL_FIGURE_DISPLACEMENT_Y 100

#pragma once


void Game_design(sf::RenderWindow& window, const uint32_t& roundsNum, bool isSingleGame, GameType gameType, const char& figureColor);

class Game{
public:

    Game(const uint32_t& roundsNum, bool isSingleGame, GameType gameType, bool playerHasWhiteBoard,
         const uint16_t& boardSize);

    void Draw(sf::RenderWindow& window);

    void FigureSelection(sf::Vector2i mousePos); // выделение фигуры и её возможных ходов при нажатии

private:
    struct Object{
        void SetPosition(int x, int y); // установка позиции объекта
        void Draw(sf::RenderWindow& window);

        sf::Texture texture;
        sf::Sprite sprite;
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t width = 0;
        uint32_t height = 0;
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

    Object moveSelector; // для выделения возможных ходов фигур
    std::vector<int> movePos; // хранит номера позиций возможных ходов фигуры, на которую нажали

    Object figureSelector; // для выделения фигуры

    int FIRST_FIGURE_POSITION_X;
    int FIRST_FIGURE_POSITION_Y;

    int FIGURE_DISPLACEMENT_X;
    int FIGURE_DISPLACEMENT_Y;

    bool isSelected = false; // выделена ли на данный момент фигура

};

