#include "cstdlib"
#include "string"
#include "array"

#pragma once

// Здесь -1 означает чёрную фигуру, а 1 - белую

// обозначение фигур: 'P' - чёрная пешка, 'p' - малая пешка, 'K' - чёрная дамка, 'k' - белая дамка

#include "cstdlib"
#include "string"
#include "vector"

#pragma once

// Здесь -1 означает чёрную фигуру, а 1 - белую

// обозначение фигур: 'P' - чёрная пешка, 'p' - белая пешка, 'K' - чёрная дамка,
// 'k' - белая дамка, отсутствие фигуры - '0'

class Board{
private:

public:
    Board(uint16_t size, bool isWhiteBoard);
    ~Board();

    bool isHere(uint16_t posX, uint16_t posY); // проверка на наличие фигуры в данной точке

    bool move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY); // движение фигуры. Возвращает true, если фигура успешно перемещена

    std::vector<uint16_t> possibles(uint16_t posX, uint16_t posY); // проверка на возмножность походить

    std::pair<uint16_t, uint16_t> convertPos(uint16_t pos); // конвертирует номер позиции в координаты

    char checkSide(uint16_t posX, uint16_t posY); // w - white, b - black

private:
    // проверка хода в конкретном направлении на 1 шаг вперёд
    // Возвращает 999 если не возможно походить в заданном направлении или если под указанными координатами не находится фигура
    // если возможно походить, возваращает номер позиции возможного хода (след клетка или через 1, если бьём)
    uint16_t checkStep(uint16_t posX, uint16_t posY, char direct);

private:
    char** board;
    uint16_t size;
    bool isWhiteBoard; // хранит информацию о том, какой стороне принадлежит борд
};