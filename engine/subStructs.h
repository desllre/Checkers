#include "cstdlib"
#include "list"
#include "string"
#pragma once

enum GameType{
    English,
    Russian,
    Giveaway, // поддавки шашки
    International // международные шашки
};

struct Figure{
    Figure(){ figureType = '0'; figureColor = '0';}
    Figure(uint16_t x, uint16_t y, char figureType): x(x), y(y), figureType(figureType), figureColor('0') {};
    Figure(uint16_t x, uint16_t y, char figureType, char figureColor): x(x), y(y), figureType(figureType), figureColor(figureColor) {};

    Figure(const Figure& other){
        figureType = other.figureType;
        figureColor = other.figureColor;
        x = other.x;
        y = other.y;
    }

    Figure& operator =(const Figure& other){
        figureType = other.figureType;
        figureColor = other.figureColor;
        x = other.x;
        y = other.y;
    }

    char figureType; // p - пешка(pawn), k - дамка(king) - для белых. P и K для чёрных
    char figureColor;
    uint16_t x = 0;
    uint16_t y = 0;
};

// структура - движение(движение может быть не полным ходом, в случае сбитиия не одной фигуры). Хранит конечную позиция и предыдущую позицию
struct Motion{
    Motion() = default;
    Motion(int currentX, int currentY, int oldX, int oldY): currentX(currentX), currentY(currentY), oldX(oldX), oldY(oldY){};
    Motion(int currentX, int currentY, int oldX, int oldY, const Figure& chargeFigure): currentX(currentX), currentY(currentY), oldX(oldX), oldY(oldY), chargeFigure(chargeFigure){};
    Motion(const Motion& other){
        oldFigureType = other.oldFigureType;
        newFigureType = other.newFigureType;
        chargeFigure = other.chargeFigure;
        currentX = other.currentX;
        currentY = other.currentY;
        oldX = other.oldX;
        oldY = other.oldY;
    }
    Motion& operator =(const Motion& other){
        oldFigureType = other.oldFigureType;
        newFigureType = other.newFigureType;
        chargeFigure = other.chargeFigure;
        currentX = other.currentX;
        currentY = other.currentY;
        oldX = other.oldX;
        oldY = other.oldY;
    }

    Figure chargeFigure; // фигура, которую бьёт(если не бьёт, то figureType = '0')
    int currentX = -1;
    int currentY = -1;
    int oldX = -1;
    int oldY = -1;
    char oldFigureType = '0';
    char newFigureType = '0';
};

// структура, содержащая полный ход
struct Moves{
    Moves() = default;
    ~Moves() = default;
    Moves(const Moves& other){ moves = other.moves; }
    Moves& operator=(const Moves& other){ moves = other.moves; }
    std::list<Motion> moves;
};