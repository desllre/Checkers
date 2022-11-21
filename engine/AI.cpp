#include "AI.h"

int evaluation(const std::list<Figure>& whiteFigures, const std::list<Figure>& blackFigures){
    int eval = 0;
    for (auto i : whiteFigures){
        if (i.figureType == 'p')
            ++eval;
        else
            eval += 3;
    }
    for (auto i : blackFigures){
        if (i.figureType == 'p')
            --eval;
        else
            eval -= 3;
    }
    return eval;
}

AI::AI(Board* game_board): calculate_board(game_board->getSize(), game_board->getIsWhiteBoard(), game_board->getGameType()){

}
