#include "cstdlib"
#include "string"
#include "vector"
#include "list"

#pragma once

// обозначение фигур: 'P' - чёрная пешка, 'p' - белая пешка, 'K' - чёрная дамка,
// 'k' - белая дамка, отсутствие фигуры - '0'

enum GameType{
    English,
    Russian,
    Giveaway, // поддавки шашки
    International // международные шашки
};

struct Figure{
    Figure() = default;
    Figure(uint16_t x, uint16_t y, char figureType): x(x), y(y), figureType(figureType) {};

    char figureType; // p - пешка(pawn), k - дамка(king)
    uint16_t x = 0;
    uint16_t y = 0;
};

class Board{
private:

public:
    Board(uint16_t size, bool isWhiteBoard, GameType typeOfGame);
    ~Board();

    bool isHere(uint16_t posX, uint16_t posY); // проверка на наличие фигуры в данной точке

    bool move(uint16_t beginX, uint16_t beginY, uint16_t endX, uint16_t endY); // движение фигуры. Возвращает true, если фигура успешно перемещена

    // проверка на возмножность походить
    // first - true, если фигура бьёт, false - если не бьёт или нет ходов. second - веткор пустой - если нет ходов или содержит координаты возможных ходов
    std::pair<bool, std::vector<int>> possibles(uint16_t posX, uint16_t posY);

    std::pair<uint16_t, uint16_t> convertPos(uint16_t pos) const; // конвертирует номер позиции в координаты

    char checkSide(uint16_t posX, uint16_t posY); // w - white, b - black, 0 - ничего

    bool getIsWhiteBoard();

    int endOfGame(); // проверка на конец игры. Возвращает 1 если выиграли белые, -1 - чёрные, 0 - игра ещё не окончена

    uint16_t getSize();

    void setFigure(uint16_t x, uint16_t y, char figure);

    void restart();

    bool GetSideChanging(); // возвращает true, если на предыдущем шаге поменялся цвет фигур

private:
    // функция инициализации борда
    void init();

    // проверка хода пешек
    // возвращаемые значения: std::pair<bool, std::vector<int>> тут bool - true, если фигура бьёт и false в противном случае
    // возвращает -1 (в векторе), если не возможно походить или если под указанными координатами не находится фигура
    // если возможно походить, возваращает номера позиций возможных ходов
    std::pair<bool, std::vector<int>> checkPawnStep_Ang(uint16_t posX, uint16_t posY);

    std::pair<bool, std::vector<int>>  checkPawnStep_Rus(uint16_t posX, uint16_t posY);


    // проверка хода для дамок
    // возвращаемые значения: std::pair<bool, std::vector<int>> тут bool - true, если фигура бьёт и false в противном случае
    // возвращает -1 (в векторе), если не возможно походить или если под указанными координатами не находится фигура
    // возваращает вектор номеров возможных позиций хождения дамки
    std::pair<bool, std::vector<int>> checkKingStep_Ang(uint16_t posX, uint16_t posY);

    std::pair<bool, std::vector<int>> checkKingStep_Rus(uint16_t posX, uint16_t posY);

    void setSideAttach();

private:
    char** board;
    uint16_t size;
    bool isWhiteBoard; // хранит информацию о том, какой стороне принадлежит борд
    GameType typeOfGame;

    // следующие переменные нужны для ограничения возможности хода, если возможно бить фигуру:
    bool whiteWay; // Переменная хранит ответ на вопрос: Ходят ли на данный момент белые?
    bool sideIsChange = true; // хранит true, если с момента последнего хода(или начала игры) не была вызвана фукнкция checkSideAttach
    bool sideIsAttach; // true, если спрашиваемая сторона должна атаковать и false в противном случае

    std::pair<uint32_t, uint32_t> attackingFigurePos; // позиция фигуры, которая уже сбила фигуру на данном ходу и может ещё раз бить
    // содержит координаты по x и y это фигуры или -1 и -1, если эта фигура не обнаружена на данном ходу


public:
    std::list<Figure> whiteFigures;
    std::list<Figure> blackFigures;
};