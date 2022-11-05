#include "cstdlib"
#include "string"
#include "vector"

#pragma once

// обозначение фигур: 'P' - чёрная пешка, 'p' - белая пешка, 'K' - чёрная дамка,
// 'k' - белая дамка, отсутствие фигуры - '0'

class Board{
private:

public:
    Board(uint16_t size, bool isWhiteBoard, char GameType);
    ~Board();

    bool isHere(uint16_t posX, uint16_t posY); // проверка на наличие фигуры в данной точке

    bool move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY); // движение фигуры. Возвращает true, если фигура успешно перемещена

    std::vector<int> possibles(uint16_t posX, uint16_t posY); // проверка на возмножность походить

    std::pair<uint16_t, uint16_t> convertPos(uint16_t pos); // конвертирует номер позиции в координаты

    char checkSide(uint16_t posX, uint16_t posY); // w - white, b - black

private:
    // direct - влево - 'l', вправо - 'r'

    // проверка хода в конкретном направлении на 1 шаг вперёд для пешек
    // Возвращает -1 если не возможно походить в заданном направлении или если под указанными координатами не находится фигура
    // если возможно походить, возваращает номер позиции возможного хода (след клетка или через 1, если бьём)
    std::vector<int> checkPawnStep_Ang(uint16_t posX, uint16_t posY, char direct);

    std::vector<int>  checkPawnStep_Rus(uint16_t posX, uint16_t posY, char direct);


    // проверка хода для дамок в заданном направлении
    // возваращает вектор номеров возможных позиций хождения дамки
    // если нет места для ходов вернёт - -1
    std::vector<int> checkKingStep_Ang(uint16_t posX, uint16_t posY, char direct);

    std::vector<int> checkKingStep_Rus(uint16_t posX, uint16_t posY, char direct);

private:
    char** board;
    uint16_t size;
    bool isWhiteBoard; // хранит информацию о том, какой стороне принадлежит борд
    char GameType; // Тип игры: русские шашки - 'r', поддавки - 'p', английские - 'a', международные - 'm'
};