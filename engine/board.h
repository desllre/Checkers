#include "cstdlib"
#include "string"
#include "vector"
#include "list"

#pragma once

// обозначение фигур: 'P' - чёрная пешка, 'p' - белая пешка, 'K' - чёрная дамка,
// 'k' - белая дамка, отсутствие фигуры - '0'

enum GameType{
    English,
    Russian,
    Giveaway, // поддавки шашки
    International // международные шашки
};

class Board{
private:

public:
    Board(uint16_t size, bool isWhiteBoard, GameType typeOfGame);
    ~Board();

    bool isHere(uint16_t posX, uint16_t posY); // проверка на наличие фигуры в данной точке

    bool move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY); // движение фигуры. Возвращает true, если фигура успешно перемещена

    std::vector<int> possibles(uint16_t posX, uint16_t posY); // проверка на возмножность походить

    std::pair<uint16_t, uint16_t> convertPos(uint16_t pos) const; // конвертирует номер позиции в координаты

    char checkSide(uint16_t posX, uint16_t posY); // w - white, b - black, 0 - ничего

    bool getIsWhiteBoard();

    int endOfGame(); // проверка на конец игры. Возвращает 1 если выиграли белые, -1 - чёрные, 0 - игра ещё не окончена

    uint16_t getSize();

    void setFigure(uint16_t x, uint16_t y, char figure);

    void restart();

private:
    // функция инициализации борда
    void init();

    // проверка хода в конкретном направлении на 1 шаг вперёд для пешек
    // Возвращает -1 если не возможно походить в заданном направлении или если под указанными координатами не находится фигура
    // если возможно походить, возваращает номер позиции возможного хода (след клетка или через 1, если бьём)
    std::vector<int> checkPawnStep_Ang(uint16_t posX, uint16_t posY);

    std::vector<int>  checkPawnStep_Rus(uint16_t posX, uint16_t posY);


    // проверка хода для дамок в заданном направлении
    // возваращает вектор номеров возможных позиций хождения дамки
    // если нет места для ходов вернёт - -1
    std::vector<int> checkKingStep_Ang(uint16_t posX, uint16_t posY);

    std::vector<int> checkKingStep_Rus(uint16_t posX, uint16_t posY);

private:
    struct Figure{
        Figure() = default;
        Figure(uint16_t x, uint16_t y, char figureType): x(x), y(y), figureType(figureType) {};

        char figureType; // p - пешка(pawn), k - дамка(king)
        uint16_t x = 0;
        uint16_t y = 0;
    };

private:
    char** board;
    uint16_t size;
    bool isWhiteBoard; // хранит информацию о том, какой стороне принадлежит борд
    GameType typeOfGame;

public:
    std::list<Figure> whiteFigures;
    std::list<Figure> blackFigures;
};