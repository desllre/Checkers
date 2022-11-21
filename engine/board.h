#include "cstdlib"
#include "string"
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
    Figure(){ figureType = '0'; figureColor = '0';}
    Figure(uint16_t x, uint16_t y, char figureType): x(x), y(y), figureType(figureType) {};
    Figure(uint16_t x, uint16_t y, char figureType, char figureColor): x(x), y(y), figureType(figureType), figureColor(figureColor) {};

    Figure(const Figure& other){
        figureType = other.figureType;
        figureColor = other.figureColor;
        x = other.x;
        y = other.y;
    }

    Figure& operator =(const Figure& other){
        figureType = other.figureType;
        figureColor = other.figureColor;
        x = other.x;
        y = other.y;
    }

    char figureType; // p - пешка(pawn), k - дамка(king) - для белых. P и K для чёрных
    char figureColor;
    uint16_t x = 0;
    uint16_t y = 0;
};

// структура - движение(движение может быть не полным ходом, в случае сбитиия не одной фигуры). Хранит конечную позиция и предыдущую позицию
struct Motion{
    Motion() = default;
    Motion(int currentX, int currentY, int oldX, int oldY): currentX(currentX), currentY(currentY), oldX(oldX), oldY(oldY){};
    Motion(int currentX, int currentY, int oldX, int oldY, Figure chargeFigure): currentX(currentX), currentY(currentY), oldX(oldX), oldY(oldY), chargeFigure(chargeFigure){};
    Motion(const Motion& other){
        oldFigureType = other.oldFigureType;
        newFigureType = other.newFigureType;
        chargeFigure = other.chargeFigure;
        currentX = other.currentX;
        currentY = other.currentY;
        oldX = other.oldX;
        oldY = other.oldY;
    }
    Motion& operator =(const Motion& other){
        oldFigureType = other.oldFigureType;
        newFigureType = other.newFigureType;
        chargeFigure = other.chargeFigure;
        currentX = other.currentX;
        currentY = other.currentY;
        oldX = other.oldX;
        oldY = other.oldY;
    }

    Figure chargeFigure; // фигура, которую бьёт(если не бьёт, то figureType = '0')
    int currentX;
    int currentY;
    int oldX;
    int oldY;
    char oldFigureType;
    char newFigureType;
};

// структура, содержащая полный ход
struct Moves{
    Moves() = default;
    ~Moves() = default;
    Moves(const Moves& other){ moves = other.moves; }
    Moves& operator=(const Moves& other){ moves = other.moves; }
    std::list<Motion> moves;
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
    std::pair<bool, std::list<int>> possibles(uint16_t posX, uint16_t posY);

    std::pair<uint16_t, uint16_t> convertPos(uint16_t pos) const; // конвертирует номер позиции в координаты

    char checkSide(uint16_t posX, uint16_t posY); // w - white, b - black, 0 - ничего

    // проверка на конец игры. Возвращает 1 если выиграли белые, -1 - чёрные, 0 - игра ещё не окончена
    int endOfGame();


    void setFigure(uint16_t x, uint16_t y, char figure);

    void restart();

    void unMove(); // возвращается к предыдущему ходу на основе moves

    uint16_t getSize();
    bool getIsWhiteBoard();
    bool GetSideChanging(); // возвращает true, если на предыдущем шаге поменялся цвет фигур
    GameType getGameType();

    std::list<Moves> generateAllMoves(uint16_t posX, uint16_t posY); // возвращает vector со всеми возможными ходами фигуры под заданными координатами

private:
    // функция инициализации борда
    void init();

    // проверка хода пешек
    // возвращаемые значения: std::pair<bool, std::list<int>> тут bool - true, если фигура бьёт и false в противном случае
    // возвращает -1 (в векторе), если не возможно походить или если под указанными координатами не находится фигура
    // если возможно походить, возваращает номера позиций возможных ходов
    std::pair<bool, std::list<int>> checkPawnStep_Ang(uint16_t posX, uint16_t posY);

    std::pair<bool, std::list<int>>  checkPawnStep_Rus(uint16_t posX, uint16_t posY);


    // проверка хода для дамок
    // возвращаемые значения: std::pair<bool, std::list<int>> тут bool - true, если фигура бьёт и false в противном случае
    // возвращает -1 (в векторе), если не возможно походить или если под указанными координатами не находится фигура
    // возваращает вектор номеров возможных позиций хождения дамки
    std::pair<bool, std::list<int>> checkKingStep_Ang(uint16_t posX, uint16_t posY);

    std::pair<bool, std::list<int>> checkKingStep_Rus(uint16_t posX, uint16_t posY);

    void setSideAttach();

    void clearMoves(char figureSide); // очищает Moves, если изменна ходящая фигура

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
    // содержит координаты по x и y этой фигуры или -1 и -1, если эта фигура не обнаружена на данном ходу

    Moves moves; // хранит последний ход

public:
    std::list<Figure> whiteFigures;
    std::list<Figure> blackFigures;
};