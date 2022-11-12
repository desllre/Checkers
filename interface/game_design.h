#include "../engine/board.h"
#include "elements.h"

#include "SFML/Graphics.hpp"

#include "string"
#include "vector"
#include "filesystem"
#include "fstream"

#include "iostream"

// параметры поля игры
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

    void FigureSelection(const sf::Vector2i& mousePos); // выделение фигуры и её возможных ходов при нажатии

    void Move(const sf::Vector2i& mousePos); // движение фигуры

    void SetCurrentTIme(); // устанавливает текущее время продолжительности игры

private:
    struct Object{
        void SetPosition(int x, int y); // установка позиции объекта
        void Draw(sf::RenderWindow& window) const;

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

    GameType gameType;

    bool isSingleGame;
    bool playerHasWhiteBoard; // определяет цвет фигур игрока. Если игра на двоих, то первого игрока

    Background background;

    Object black_pawn;
    Object black_king;

    Object white_pawn;
    Object white_king;

    Object moveSelector; // для выделения возможных ходов фигур
    std::pair<uint16_t, uint16_t> selectedPos; // координаты выделеннной фигуры в массиве
    std::vector<int> movePos; // хранит номера позиций возможных ходов фигуры, на которую нажали

    Object figureSelector; // для выделения фигуры

    int FIRST_FIGURE_POSITION_X;
    int FIRST_FIGURE_POSITION_Y;

    int FIGURE_DISPLACEMENT_X;
    int FIGURE_DISPLACEMENT_Y;

    bool isSelected = false; // выделена ли на данный момент фигура

    sf::Font textFont;

    uint32_t roundsNum;
    uint32_t currentRound = 1;
    sf::Text roundsText;
    sf::RectangleShape roundsRect;

    std::pair<uint16_t, uint16_t> score; // счёт игры. Первая цифра - кол-во побед player_1, вторая - player_2
    sf::Text scoreText;
    sf::RectangleShape scoreRect;

    sf::Clock gameTime; // время игры
    std::string gameTimeString;
    sf::Text gameTimeText;
    sf::RectangleShape gameTimeRect;

    std::string player1Name;
    sf::Text player1TextName;
    sf::RectangleShape player1Rect;

    std::string player2Name;
    sf::Text player2TextName; // строка с указанием противников
    sf::RectangleShape player2Rect;
};

