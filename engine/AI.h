#include "board.h"

#include "list"

#pragma once

// Оценка позиции на столе. Вес фигур: пешка 1, дамка 3.
// Возвращает разницу между суммой вессов белых фигур и чёрных.
// То есть, если возвращает отрицательно число, то перевес в сторону чёрных, положительное - в сторону белых
int evaluation(const std::list<Figure>& whiteFigures, const std::list<Figure>& blackFigures);

class AI{
public:
    AI(Board* game_board, uint16_t viewDepth);
    ~AI() = default;

    void Move();

    void setSide(bool botSideIsWhite);

private:
    // Поиск лучшего хода на основе лучшей оценки bestEvalSearch
    Moves bestMoveSearch();

    // Поиск лучшей оценки хода бота.
    // Основано на алгоритме alpha-beta отсечений
    int bestEvalSearch(uint16_t depth, int alpha, int beta);

    int minEvaluation(int lEval, int rEval); // принимает 2 оценки и возращает минимальную

    int maxEvaluation(int lEval, int rEval); // принимает 2 оценки и возращает максимальную

private:

    Board* game_board; // борд, на котором происходит игра
    Board calculate_board; // борд, для расчёта ходов бота

    uint16_t viewDepth; //фиксированная глубина просмотра ходов ботом

    // alpha и beta выражают границы проверки оценок ботом.
    // alpha - отвечает за оценку белых фигур
    // beta - отвечает за оценку чёрных фигур
    // поскольку максиммально возможная оценка 60 или -60(в случае международных шашек и все фигуры - дамки), alpha и beta принимают такие значения
    const int cAlpha = -61;
    const int cBeta = 61;

    bool botSideIsWhite; // бот играет за белых?
    bool whiteWay; // сейчас ходят белые?
};