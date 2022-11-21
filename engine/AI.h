#include "board.h"

#include "list"

#pragma once



// Оценка позиции на столе. Вес фигур: пешка 1, дамка 3.
// Возвращает разницу между суммой вессов белых фигур и чёрных.
// То есть если возвращает отрицательно число, то перевес в сторону чёрных, положительное - в сторону белых
int evaluation(const std::list<Figure>& whiteFigures, const std::list<Figure>& blackFigures);


class AI{
public:
    AI(Board* game_board);
    ~AI() = default;

private:
    Board* game_board; // борд, на котором происходит игра
    Board calculate_board; // борд, для расчёта ходов бота

};