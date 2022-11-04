#include "board.h"

Board::Board(uint16_t size, bool isWhiteBoard): size(size), isWhiteBoard(isWhiteBoard) {
    board = new char*[size];
    for (size_t i = 0; i < size; ++i) {
        board[i] = new char[size];
    }

    if (isWhiteBoard){
        for (uint16_t i = 0; i < size ; ++i){
            if (i == size/2 || i == size/2 + 1) {
                for (size_t j = 0; j < size ; ++j)
                    board[i][j] = '0';
            } else {
                for (size_t j = 0; j < size ; ++j) {
                    if (i < size / 2){
                        board[i][j] = 'P';
                    } else{
                        board[i][j] = 'p';
                    }
                }
            }
        }

    } else {

    }
}

Board::~Board(){
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

bool Board::isHere(uint16_t posX, uint16_t posY) {
    if (board[posX][posY] != '0') return true;
    return false;
}

/*std::vector<std::pair<uint16_t, uint16_t>> Board::possibles(uint16_t x, uint16_t y){
    std::vector<std::pair<uint16_t, uint16_t>> possibles;

    char figureType = board[x][y];

    if (figureType == 'P' || figureType == 'p'){

    } else{

    }

    return possibles;
}*/

std::pair<uint16_t, uint16_t> checkStep(uint16_t posX, uint16_t posY, char direct){
    return std::pair<uint16_t, uint16_t>();
}

bool Board::move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY){

    char figureType = board[beginX][beginY];
    if (figureType == '0') return false;

    return true;
}

std::vector<std::pair<uint16_t, uint16_t>> Board::possibles(uint16_t posX, uint16_t posY){
    return std::vector<std::pair<uint16_t, uint16_t>>();
}




