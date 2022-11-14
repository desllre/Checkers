#include "board.h"

Board::Board(uint16_t size, bool isWhiteBoard, GameType typeOfGame): size(size), isWhiteBoard(isWhiteBoard), typeOfGame(typeOfGame) {
    if (isWhiteBoard)
        whiteWay = true;
    else
        whiteWay = false;

    attackingFigurePos.first = -1;
    attackingFigurePos.second = -1;

    init();
}

Board::~Board(){
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

void Board::init(){
    board = new char*[size];
    for (size_t i = 0; i < size; ++i) {
        board[i] = new char[size];
    }

    for (uint16_t i = 0; i < size ; ++i){ // заполнение борда
        if (i == size/2 || i == size/2 - 1) {
            for (size_t j = 0; j < size ; ++j)
                board[i][j] = '0';
        } else {
            for (size_t j = 0; j < size ; ++j) {
                if (i < size / 2){
                    if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                        board[i][j] = 'P';
                        blackFigures.emplace_back(Figure(j, i,char('p')));
                    }

                } else{
                    if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                        board[i][j] = 'p';
                        whiteFigures.emplace_back(Figure(j,i,char('p')));
                    }
                }
            }
        }
    }
}

bool Board::isHere(uint16_t posX, uint16_t posY) {
    if (board[posY][posX] != '0') return true;
    return false;
}


bool Board::move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY){

    bool isMoving = false;

    char figureType = board[beginY][beginX];
    char figureSide = checkSide(beginX, beginY);

    if (figureType == '0') return false;

    if (whiteWay && figureSide != 'w') // проверка фигуры на цвет, ходящий на данный момент
        return false;
    else if(!whiteWay && figureSide != 'b')
        return false;

    std::pair<bool, std::vector<int>> possiblesPair = possibles(beginX, beginY);

    int endPos = endY * size + endX;

    for (auto i: possiblesPair.second) { // проверка на наличие возможности походить
        if (endPos == i){
            isMoving = true;
            break;
        }
    }

    if (isMoving){
        board[beginY][beginX] = '0';

        if (endY == 0 && figureSide == 'w'){ // преобразование
            figureType = 'k';
        } else if (endY == size - 1  && figureSide == 'b') {
            figureType = 'K';
        }
        board[endY][endX] = figureType;

        if (figureSide == 'w'){
            bool isFindPos = false;
            auto it = whiteFigures.begin();
            for (auto i = whiteFigures.begin(); i != whiteFigures.end(); ++i){
                if(i->x == beginX && i->y == beginY){
                    isFindPos = true;
                    it = i;
                    break;
                }
            }
            if (isFindPos){
                whiteFigures.erase(it);
                whiteFigures.emplace_back(endX, endY, static_cast<char>(std::tolower(figureType)));
            }
        } else {
            bool isFindPos = false;
            auto it = blackFigures.begin();
            for (auto i = blackFigures.begin(); i != blackFigures.end(); ++i){
                if(i->x == beginX && i->y == beginY){
                    isFindPos = true;
                    it = i;
                    break;
                }
            }
            if (isFindPos){
                blackFigures.erase(it);
                blackFigures.emplace_back(endX, endY, static_cast<char>(std::tolower(figureType)));
            }
        }


        int diffX = static_cast<int>(endX) - static_cast<int>(beginX);
        int diffY = static_cast<int>(endY) - static_cast<int>(beginY);

        int enemyPosX, enemyPosY;
        int posX = beginX, posY = beginY; // убираем сбитую фигуру
        int biasX = 0, biasY = 0;
        if (diffX < 0)
            biasX += -1;
        else
            biasX += 1;

        if (diffY < 0)
            biasY += -1;
        else
            biasY += 1;

        posX += biasX;
        posY += biasY;

        for (;posX != endX && posY != endY; posX+=biasX, posY+=biasY) {
            if (board[posY][posX] != '0'){
                enemyPosX = posX;
                enemyPosY = posY;

                if (checkSide(enemyPosX, enemyPosY) == 'w'){
                    for (auto i = whiteFigures.begin(); i != whiteFigures.end() ; ++i) {
                        if (i->x == enemyPosX && i->y == enemyPosY){
                            whiteFigures.erase(i);
                            break;
                        }
                    }
                } else if(checkSide(enemyPosX, enemyPosY) == 'b'){
                    for (auto i = blackFigures.begin(); i != blackFigures.end() ; ++i) {
                        if (i->x == enemyPosX && i->y == enemyPosY){
                            blackFigures.erase(i);
                            break;
                        }
                    }
                }
                board[enemyPosY][enemyPosX] = '0';
            }
        }
    }

    if (isMoving){
        if (sideIsAttach){
            attackingFigurePos.first = endX;
            attackingFigurePos.second = endY;
            if (!possibles(endX, endY).first) {
                attackingFigurePos.first = -1;
                attackingFigurePos.second = -1;
                whiteWay = !whiteWay;
                sideIsChange = true;
                sideIsAttach = false;
            }
        } else{
            whiteWay = !whiteWay;
            sideIsChange = true;
            sideIsAttach = false;
        }
    }

    return isMoving;
}


std::pair<bool, std::vector<int>> Board::possibles(uint16_t posX, uint16_t posY){

    if (sideIsChange)
        setSideAttach();

    std::vector<int> possibles;
    std::pair<bool, std::vector<int>> returnPair;

    char figureSide = checkSide(posX, posY);
    char figureType = board[posY][posX];

    if (figureType == '0' || (whiteWay && figureSide != 'w') || (!whiteWay && figureSide != 'b')) {
        returnPair.first = false;
        return returnPair;
    }

    if (attackingFigurePos.first != -1 && attackingFigurePos.second != -1){
        if (attackingFigurePos.first != posX && attackingFigurePos.second != posY){
            returnPair.first = false;
            return returnPair;
        }
    }

    if (typeOfGame == GameType::Russian|| typeOfGame == GameType::Giveaway || typeOfGame == GameType::International){
        std::pair<bool, std::vector<int>> buff;
        if (figureType == 'p' || figureType == 'P'){
            buff = checkPawnStep_Rus(posX, posY);
            if (buff.first == sideIsAttach && buff.second[0] != -1){
                for (auto i: buff.second){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Rus(posX, posY);
            if (buff.first == sideIsAttach && buff.second[0] != -1){
                for (auto i: buff.second){
                    possibles.emplace_back(i);
                }
            }
        }
    } else {
        std::pair<bool, std::vector<int>> buff;
        if (figureType == 'p' || figureType == 'P'){
            buff = checkPawnStep_Ang(posX, posY);
            if (buff.first == sideIsAttach && buff.second[0] != -1){
                for (auto i: buff.second){
                    possibles.emplace_back(i);
                }
            }
        } else{
            buff = checkKingStep_Ang(posX, posY);
            if (buff.first == sideIsAttach && buff.second[0] != -1){
                for (auto i: buff.second){
                    possibles.emplace_back(i);
                }
            }
        }
    }

    if (possibles.empty())
        returnPair.first = false;
    else
        returnPair.first = sideIsAttach;

    returnPair.second = possibles;

    return returnPair;
}


std::pair<bool, std::vector<int>> Board::checkPawnStep_Ang(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    std::pair<bool, std::vector<int>> returnPair;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        returnPair.first = false;
        returnPair.second = possibles;
        return returnPair;
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
        if (i >= 0 && j >= 0 && i < size && j < size){
            if (board[i][j] == '0') {
                if (!isAttach){
                    possibles.emplace_back(i*size + j);
                }
            }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }

                    possibles.emplace_back(i*size + j);
                }
            }
        }
    }
    if (possibles.empty()){
        possibles.emplace_back(-1);
    }

    returnPair.first = isAttach;
    returnPair.second = possibles;
    return returnPair;
}

std::pair<bool, std::vector<int>>  Board::checkPawnStep_Rus(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    std::pair<bool, std::vector<int>> returnPair;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'p' && figureType != 'P'){
        possibles.emplace_back(-1);
        returnPair.first = false;
        returnPair.second = possibles;
        return returnPair;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {
        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;

        if (i >= 0 && j >= 0 && i < size && j < size){
            if (board[i][j] == '0') {
                if (!isAttach && figureSide == 'w'){
                    possibles.emplace_back(i*size + j);
                }
            }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }

                    possibles.emplace_back(i*size + j);
                }
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        if (i >= 0 && j >= 0 && i < size && j < size){
            if (board[i][j] == '0') {
                if (!isAttach && figureSide == 'b'){
                    possibles.emplace_back(i*size + j);
                }
            }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }

                    possibles.emplace_back(i*size + j);
                }
            }
        }
    }



    if (possibles.empty())
        possibles.emplace_back(-1);

    returnPair.first = isAttach;
    returnPair.second = possibles;
    return returnPair;
}


std::pair<bool, std::vector<int>> Board::checkKingStep_Ang(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    std::pair<bool, std::vector<int>> returnPair;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        returnPair.first = false;
        returnPair.second = possibles;
        return returnPair;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {
        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;
        if (i >= 0 && j >= 0 && i < size && j < size){
            if (board[i][j] == '0') {
                if (!isAttach){
                    possibles.emplace_back(i*size + j);
                }
            }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }

                    possibles.emplace_back(i*size + j);
                }
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        if (i >= 0 && j >= 0 && i < size && j < size){
            if (board[i][j] == '0') {
                if (!isAttach){
                    possibles.emplace_back(i*size + j);
                }
            }else if (figureSide != checkSide(j, i)){ // проверяем на одинаковую сторону фигуры
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }

                    possibles.emplace_back(i*size + j);
                }
            }
        }
    }



    if (possibles.empty())
        possibles.emplace_back(-1);

    returnPair.first = isAttach;
    returnPair.second = possibles;
    return returnPair;
}

std::pair<bool, std::vector<int>> Board::checkKingStep_Rus(uint16_t posX, uint16_t posY){

    std::vector<int> possibles;

    std::pair<bool, std::vector<int>> returnPair;

    char figureType = board[posY][posX];
    char figureSide = checkSide(posX, posY);

    if (figureType != 'k' && figureType != 'K'){
        possibles.emplace_back(-1);
        returnPair.first = false;
        returnPair.second = possibles;
        return returnPair;
    }

    int biasX = -1, biasY;
    bool isAttach = false;

    int i, j;
    for (; biasX <= 1 ; biasX += 2) {

        biasY = -1;
        i = posY + biasY;
        j = posX + biasX;

        bool continueAfterAttach = false;
        for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX){
            if (board[i][j] == '0') {
                if (!isAttach || continueAfterAttach){
                    possibles.emplace_back(i*size + j);
                }
            } else if (figureSide != checkSide(j, i)){
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }
                    continueAfterAttach = true;
                    possibles.emplace_back(i*size + j);
                }
            } else {
                break;
            }
        }

        biasY = 1;
        i = posY + biasY;
        j = posX + biasX;

        continueAfterAttach = false;
        for ( ; i < size && i >= 0 && j < size && j >= 0; i += biasY, j += biasX){
            if (board[i][j] == '0') {
                if (!isAttach || continueAfterAttach){
                    possibles.emplace_back(i*size + j);
                }
            } else if (figureSide != checkSide(j, i)){
                i += biasY, j += biasX;
                if (i < size && i >= 0 && j < size && j >= 0 && board[i][j] == '0'){
                    if (!isAttach){
                        possibles.clear();
                        isAttach = true;
                    }
                    continueAfterAttach = true;
                    possibles.emplace_back(i*size + j);
                }
            } else {
                break;
            }
        }
    }

    if (possibles.empty())
        possibles.emplace_back(-1);

    returnPair.first = isAttach;
    returnPair.second = possibles;
    return returnPair;
}


void Board::setSideAttach(){
    sideIsChange = false;
    if (whiteWay){
        if (typeOfGame == GameType::Russian|| typeOfGame == GameType::Giveaway || typeOfGame == GameType::International) {
            for (auto i: whiteFigures){
                if (i.figureType == 'p'){
                    if (checkPawnStep_Rus(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                } else {
                    if (checkKingStep_Rus(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                }
            }
        } else {
            for (auto i: whiteFigures){
                if (i.figureType == 'p'){
                    if (checkPawnStep_Ang(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                } else {
                    if (checkKingStep_Ang(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                }
            }
        }
    } else {
        if (typeOfGame == GameType::Russian|| typeOfGame == GameType::Giveaway || typeOfGame == GameType::International) {
            for (auto i: blackFigures){
                if (i.figureType == 'p'){
                    if (checkPawnStep_Rus(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                } else {
                    if (checkKingStep_Rus(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                }
            }
        } else {
            for (auto i: blackFigures){
                if (i.figureType == 'p'){
                    if (checkPawnStep_Ang(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                } else {
                    if (checkKingStep_Ang(i.x, i.y).first){
                        sideIsAttach = true;
                        return;
                    }
                }
            }
        }
    }
    sideIsAttach = false;
}

bool Board::GetSideChanging(){
    return sideIsChange;
}


std::pair<uint16_t, uint16_t> Board::convertPos(uint16_t pos) const{
    std::pair<uint16_t, uint16_t> pair(pos % size, pos / size);
    return pair;
}

char Board::checkSide(uint16_t posX, uint16_t posY){
    if (board[posY][posX] == '0') return '0';
    if (std::islower(board[posY][posX]))
        return 'w';
    else
        return 'b';
}

bool Board::getIsWhiteBoard(){
    return isWhiteBoard;
}

int Board::endOfGame() {
    // проверка на конец игры. Возвращает 1 если выиграли белые, -1 - чёрные, 0 - игра ещё не окончена
    if (typeOfGame == GameType::Russian || typeOfGame == GameType::English || typeOfGame == GameType::International){
        int counter = 0;
        if (whiteWay){
            if (whiteFigures.empty())
                return -1;

            for (auto& i: whiteFigures) {
                if (!possibles(i.x, i.y).second.empty())
                    break;
                ++counter;
            }
            if (counter == whiteFigures.size())
                return -1;
        } else {
            if (blackFigures.empty())
                return 1;

            counter = 0;
            for (auto& i: blackFigures) {
                if (!possibles(i.x, i.y).second.empty())
                    break;
                ++counter;
            }
            if (counter == blackFigures.size())
                return 1;
        }

    } else {

        int counter = 0;
        if (whiteWay){
            if (whiteFigures.empty())
                return 1;

            for (auto& i: whiteFigures) {
                if (!possibles(i.x, i.y).second.empty())
                    break;
                ++counter;
            }
            if (counter == whiteFigures.size())
                return 1;
        } else {
            if (blackFigures.empty())
                return -1;

            counter = 0;
            for (auto& i: blackFigures) {
                if (!possibles(i.x, i.y).second.empty())
                    break;
                ++counter;
            }
            if (counter == blackFigures.size())
                return -1;
        }
    }
    return 0;
}

uint16_t Board::getSize(){
    return size;
}

void Board::setFigure(uint16_t x, uint16_t y, char figure){
    if (x >= 0 && y >= 0 && x < size && y < size){
        board[y][x] = figure;
        bool isReplaced = false;
        auto it = whiteFigures.begin();
        for (auto i = whiteFigures.begin(); i !=whiteFigures.end() ; ++i){
            if (i->x == x && i->y == y){
                isReplaced = true;
                it = i;
            }
        }
        if (isReplaced){
            whiteFigures.erase(it);
        } else {
            for (auto i = blackFigures.begin(); i !=blackFigures.end() ; ++i){
                if (i->x == x && i->y == y){
                    isReplaced = true;
                    it = i;
                }
            }
        }
        if (isReplaced){
            blackFigures.erase(it);
        }

        if (std::islower(figure))
            whiteFigures.emplace_back(x, y, figure);
        else
            blackFigures.emplace_back(x, y, std::tolower(figure));

    }
}

void Board::restart(){
    sideIsAttach = false;
    sideIsChange = true;
    if (isWhiteBoard){
        whiteWay = true;
    } else{
        whiteWay = false;
    }


    whiteFigures.clear();
    blackFigures.clear();
    for (uint16_t i = 0; i < size ; ++i){ // заполнение борда
        if (i == size/2 || i == size/2 - 1) {
            for (size_t j = 0; j < size ; ++j)
                board[i][j] = '0';
        } else {
            for (size_t j = 0; j < size ; ++j) {
                if (i < size / 2){
                    if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                        board[i][j] = 'P';
                        blackFigures.emplace_back(Figure(j, i,char('p')));
                    }

                } else{
                    if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                        board[i][j] = 'p';
                        whiteFigures.emplace_back(Figure(j,i,char('p')));
                    }
                }
            }
        }
    }
}