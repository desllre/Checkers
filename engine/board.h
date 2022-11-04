#include "cstdlib"
#include "string"
#include "array"

#pragma once

// Здесь -1 означает чёрную фигуру, а 1 - белую

// обозначение фигур: 'P' - чёрная пешка, 'p' - малая пешка, 'K' - чёрная дамка, 'k' - белая дамка

class Board{
private:

public:
    Board(uint16_t size, bool isWhiteBoard);
    ~Board();



private:



    char** board;
    uint16_t size;
    bool isWhiteBoard; // хранит информацию о том, какой стороне принадлежит борд
};