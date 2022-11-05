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
        if (figureType == 'k' || figureType == 'K'){
            buff = checkPawnStep_Rus(posX, posY, 'r');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }

            buff = checkPawnStep_Rus(posX, posY, 'l');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Rus(posX, posY, 'r');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }

            buff = checkKingStep_Rus(posX, posY, 'l');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        }
    } else  if(GameType == 'a'){
        std::vector<int> buff;
        if (figureType == 'k' || figureType == 'K'){
            buff = checkPawnStep_Ang(posX, posY, 'r');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }

            buff = checkPawnStep_Ang(posX, posY, 'l');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Ang(posX, posY, 'r');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }

            buff = checkKingStep_Ang(posX, posY, 'l');
            if (buff[0] != -1){
                for (auto i: buff){
                    possibles.emplace_back(i);
                }
            }
        }
    }


}



std::vector<int> Board::checkPawnStep_Ang(uint16_t posX, uint16_t posY, char direct){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = 0, biasY = 0;

    if (direct == 'r'){
        biasX = 1;
    } else if (direct == 'l'){
        biasX = -1;
    } else{
        throw std::exception();
    }

    if (figureSide == 'w'){
        biasY = -1;
    } else if (figureSide == 'b'){
        biasY = 1;
    }

    int i = posY + biasY;
    int j = posX + biasX;
    uint16_t step = 1;
    for ( ; i < size && i >= 0 && j < size && j >= 0 && size != 2; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            possibles.emplace_back(i*size + j);
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        }
    }
    if (possibles.empty()){
        possibles.emplace_back(-1);
    }
    return possibles;
}

std::vector<int>  Board::checkPawnStep_Rus(uint16_t posX, uint16_t posY, char direct){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = 0, biasY = 0;

    if (direct == 'r'){
        biasX = 1;
    } else if (direct == 'l'){
        biasX = -1;
    } else{
        throw std::exception();
    }

    bool isAttach = false;
    biasY = -1;
    int i = posY + biasY;
    int j = posX + biasX;
    uint16_t step = 1;

    for ( ; i < size && i >= 0 && j < size && j >= 0 && step != 2; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            possibles.emplace_back(i*size + j);
        } else if (step == 2) {
            break;
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                isAttach = true;
                possibles.clear();
                possibles.emplace_back(i*size + j);
            }
            break;
        }
    }

    step = 1;
    biasY = 1;
    i = posY + biasY;
    j = posX + biasX;

    for ( ; i < size && i >= 0 && j < size && j >= 0 && step != 2; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            if (!isAttach){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach)
                    possibles.clear();

                possibles.emplace_back(i*size + j);
            }
            break;
        }
    }

    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}



std::vector<int> Board::checkKingStep_Ang(uint16_t posX, uint16_t posY, char direct){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = 0, biasY = 0;

    if (direct == 'r'){
        biasX = 1;
    } else if (direct == 'l'){
        biasX = -1;
    } else{
        throw std::exception();
    }

    bool isAttach = false;
    biasY = -1;
    int i = posY + biasY;
    int j = posX + biasX;
    uint16_t step = 1;

    for ( ; i < size && i >= 0 && j < size && j >= 0 && step != 2; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            possibles.emplace_back(i*size + j);
        } else if (step == 2) {
            break;
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                isAttach = true;
                possibles.clear();
                possibles.emplace_back(i*size + j);
            }
            break;
        }
    }

    step = 1;
    biasY = 1;
    i = posY + biasY;
    j = posX + biasX;

    for ( ; i < size && i >= 0 && j < size && j >= 0 && step != 2; i += biasY, j += biasX, ++step){
        if (board[i][j] == '0') {
            if (!isAttach){
                possibles.emplace_back(i*size + j);
            }
        }else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach)
                    possibles.clear();

                possibles.emplace_back(i*size + j);
            }
            break;
        }
    }

    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}

std::vector<int> Board::checkKingStep_Rus(uint16_t posX, uint16_t posY, char direct){

    std::vector<int> possibles;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        return possibles;
    }

    int biasX = 0, biasY = 0;

    if (direct == 'r'){
        biasX = 1;
    } else if (direct == 'l'){
        biasX = -1;
    } else{
        throw std::exception();
    }

    bool isAttach = false;
    biasY = -1;
    int i = posY + biasY;
    int j = posX + biasX;

    for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX){
        if (board[i][j] == '0') {
            possibles.emplace_back(i*size + j);
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                isAttach = true;
                possibles.clear();
                possibles.emplace_back(i*size + j);
            }
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
        } else if (figureSide == 'w' && std::islower(board[i][j])){
            break;
        } else if (figureSide == 'b' && std::isupper(board[i][j])){
            break;
        } else {
            i += biasY, j += biasX;
            if (board[i][j] == '0' && i < size && i >= 0 && j < size && j >= 0){
                if (!isAttach)
                    possibles.clear();
                possibles.emplace_back(i*size + j);
            }

            break;
        }
    }

    if (possibles.empty())
        possibles.emplace_back(-1);

    return possibles;
}



std::pair<uint16_t, uint16_t> Board::convertPos(uint16_t pos){
    std::pair<uint16_t, uint16_t> pair(pos % size, pos / size);
    return pair;
}

char Board::checkSide(uint16_t posX, uint16_t posY){
    if (std::islower(board[posY][posX]))
        return 'w';
    else
        return 'b';
}
