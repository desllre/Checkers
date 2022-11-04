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
        for (uint16_t i = 0; i < size ; ++i){
            if (i == size/2 || i == size/2 + 1) {
                for (size_t j = 0; j < size ; ++j)
                    board[i][j] = '0';
            } else {
                for (size_t j = 0; j < size ; ++j) {
                    if (i < size / 2){
                        board[i][j] = 'p';
                    } else{
                        board[i][j] = 'P';
                    }
                }
            }
        }
    }
}

Board::~Board(){
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

bool Board::isHere(uint16_t posX, uint16_t posY) {
    if (board[posY][posX] != '0') return true;
    return false;
}


bool Board::move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY){

    char figureType = board[beginY][beginX];
    if (figureType == '0') return false;

    return true;
}

std::vector<uint16_t> Board::possibles(uint16_t posX, uint16_t posY){
    void (*enumeration) (std::vector<uint16_t>&, uint16_t, uint16_t);

    enumeration = [](std::vector<uint16_t>& vect, uint16_t x, uint16_t y){

    };

    char figureType = board[posY][posX];
    std::vector<uint16_t> possibles;
    if (figureType == '0'){
        possibles.push_back(999);
        return possibles;
    }

    uint16_t rPossible = checkStep(posX, posY, 'r');
    uint16_t lPossible = checkStep(posX, posY, 'l');

    if (rPossible != 999) {

    }



    uint16_t rPos = checkStep(posX, posY, 'r');
    uint16_t lPos = checkStep(posX, posY, 'l');

}

/*
void drevo(int** arr, int x, int y){
    if (x < 0 || x >= size || y < 0 || y >= size)
        return;
    std::cout << arr[y][x] << std::endl;
    drevo(arr, x + 1, y + 1);
    drevo(arr, x - 1, y + 1);
    return;
}
*/

uint16_t Board::checkStep(uint16_t posX, uint16_t posY, char direct){

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType == '0') return 999;

    int biasX, biasY;

    if (direct == 'r'){
        biasX = 1;
    } else if (direct == 'l'){
        biasX = -1;
    } else{
        throw "Error. Not correct direct value";
    }

    if (figureSide == 'w'){
        biasY = -1;
    } else if (figureSide == 'b'){
        biasY = 1;
    }

    int i = posY + biasY;
    int j = posX + biasX;
    uint16_t step = 1;
    for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            return i*size + j;
        } else if (step == 2) {
            return 999;
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            return 999;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            return 999;
        }
    }

}

std::pair<uint16_t, uint16_t> Board::convertPos(uint16_t pos){
    return std::pair<uint16_t, uint16_t>(pos % size, pos / size);
}

char Board::checkSide(uint16_t posX, uint16_t posY){
    if (std::islower(board[posY][posX]))
        return 'w';
    else
        return 'b';
}





