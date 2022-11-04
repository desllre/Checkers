#include "board.h"

Board::Board(uint16_t size, bool isWhiteBoard): size(size), isWhiteBoard(isWhiteBoard) {
    board = new char*[size];
    for (size_t i = 0; i < size; ++i) {
        board[i] = new char[size];
    }

    if (isWhiteBoard){
        for (uint16_t i = 0; i < size ; ++i){
            if (i == size / 2 || i == size / 2 + 1) continue;

            for (size_t j = 0; j < size ; ++j) {
                if (i < size / 2){
                    board[i][j] = 'P';
                } else{
                    board[i][j] = 'p';
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









