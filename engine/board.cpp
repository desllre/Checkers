#include "board.h"

Board::Board(uint16_t size, bool isWhiteBoard, char GameType): size(size), isWhiteBoard(isWhiteBoard), GameType(GameType) {
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

std::vector<int> Board::possibles(uint16_t posX, uint16_t posY){
    std::vector<int> possibles;
    char figureType = board[posY][posX];
    if (figureType == '0') return possibles;

    if (GameType == 'r' || GameType == 'p' || GameType == 'm'){
        std::vector<int> buff;
        if (figureType == 'p' || figureType == 'P'){
            buff = checkPawnStep_Rus(posX, posY);
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Rus(posX, posY);
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        }
    } else  if(GameType == 'a'){
        std::vector<int> buff;
        if (figureType == 'p' || figureType == 'P'){
            buff = checkPawnStep_Ang(posX, posY);
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Ang(posX, posY);
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        }
    }


}



std::vector<int> Board::checkPawnStep_Ang(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = -1, biasY;

    if (figureSide == 'w'){
        biasY = -1;
    } else {
        biasY = 1;
    }

    bool isAttach = false;
    int i = posY + biasY;
    int j = posX + biasX;
    for (; biasX <= 1 ; biasX += 2){
        i = posY + biasY;
        j = posX + biasX;
        if (board[i][j] == '0') {
            if (!isAttach){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach){
                    possibles.clear();
                    isAttach = true;
                }

                possibles.emplace_back(i*size + j);
            }
        }
    }
    if (possibles.empty()){
        possibles.emplace_back(-1);
    }
    return possibles;
}

std::vector<int>  Board::checkPawnStep_Rus(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {
        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;

        if (board[i][j] == '0') {
            if (!isAttach && figureSide == 'w'){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach){
                    possibles.clear();
                    isAttach = true;
                }

                possibles.emplace_back(i*size + j);
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        if (board[i][j] == '0') {
            if (!isAttach && figureSide == 'b'){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach){
                    possibles.clear();
                    isAttach = true;
                }

                possibles.emplace_back(i*size + j);
            }
        }
    }



    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}



std::vector<int> Board::checkKingStep_Ang(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {
        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;

        if (board[i][j] == '0') {
            if (!isAttach){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach){
                    possibles.clear();
                    isAttach = true;
                }

                possibles.emplace_back(i*size + j);
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        if (board[i][j] == '0') {
            if (!isAttach){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach){
                    possibles.clear();
                    isAttach = true;
                }

                possibles.emplace_back(i*size + j);
            }
        }
    }



    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}

std::vector<int> Board::checkKingStep_Rus(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {

        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;

        for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX){
            if (board[i][j] == '0') {
                if (!isAttach){
                    possibles.emplace_back(i*size + j);
                }
            } else if (figureSide != checkSide(j, i)){
                i += biasY, j += biasX;
                if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }
                    possibles.emplace_back(i*size + j);
                }
                break;
            } else {
                break;
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX){
            if (board[i][j] == '0') {
                if (!isAttach){
                    possibles.emplace_back(i*size + j);
                }
            } else if (figureSide != checkSide(j, i)){
                i += biasY, j += biasX;
                if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }
                    possibles.emplace_back(i*size + j);
                }
                break;
            } else {
                break;
            }
        }
    }

    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}



std::pair<uint16_t, uint16_t> Board::convertPos(uint16_t pos) const{
    std::pair<uint16_t, uint16_t> pair(pos % size, pos / size);
    return pair;
}

char Board::checkSide(uint16_t posX, uint16_t posY){
    if (std::islower(board[posY][posX]))
        return 'w';
    else
        return 'b';
}
