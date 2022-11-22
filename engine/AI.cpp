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

AI::AI(Board* game_board, uint16_t viewDepth): calculate_board(game_board->getSize(), game_board->getIsWhiteBoard(), game_board->getGameType()),
                                                                                viewDepth(viewDepth){
    this->game_board = game_board;
}

void AI::setSide(bool botSideIsWhite){
    this->botSideIsWhite = botSideIsWhite;
}

int AI::minEvaluation(int lEval, int rEval){
    return (lEval<rEval)?lEval:rEval;
}

int AI::maxEvaluation(int lEval, int rEval){
    return (lEval<rEval)?rEval:lEval;
}

int AI::bestEvalSearch(uint16_t depth, int alpha, int beta){
    if (depth == 0 || calculate_board.endOfGame() != 0){
        return evaluation(calculate_board.whiteFigures, calculate_board.blackFigures);
    }
    if (whiteWay){
        whiteWay = !whiteWay;
        int eval;
        int maxEval = cAlpha;
        for (auto i: calculate_board.whiteFigures) {
            for (auto j: calculate_board.generateAllMoves(i.x, i.y)){
                Moves moves = j;
                for(auto k: j.moves){
                    calculate_board.move(k.oldX, k.oldY, k.currentX, k.currentY);
                }
                eval = bestEvalSearch(depth - 1, alpha, beta);
                maxEval = maxEvaluation(maxEval, eval);

                alpha = maxEvaluation(alpha, eval);
                if (beta <= alpha){
                    calculate_board.moves = moves;
                    calculate_board.unMove();
                    return maxEval;
                }

                calculate_board.moves = moves;
                calculate_board.unMove();
            }
        }
    } else {
        whiteWay = !whiteWay;
        int eval;
        int minEval = cBeta;
        for (auto i: calculate_board.blackFigures) {
            for (auto j: calculate_board.generateAllMoves(i.x, i.y)){
                Moves moves = j;
                for(auto k: j.moves){
                    calculate_board.move(k.oldX, k.oldY, k.currentX, k.currentY);
                }
                eval = bestEvalSearch(depth - 1, alpha, beta);
                minEval = minEvaluation(minEval, eval);

                beta = minEvaluation(beta, eval);
                if (beta <= alpha){
                    calculate_board.moves = moves;
                    calculate_board.unMove();
                    return minEval;
                }

                calculate_board.moves = moves;
                calculate_board.unMove();
            }
        }
    }
}

Moves AI::bestMoveSearch(){
    whiteWay = game_board->getWhiteWay();
    calculate_board = *game_board;
    int bestEval = bestEvalSearch(viewDepth, cAlpha, cBeta);
    if (botSideIsWhite){
        for (auto i: calculate_board.whiteFigures){
            for (auto j: calculate_board.generateAllMoves(i.x, i.y)){
                for (auto k: j.moves){
                    calculate_board.move(k.oldX, k.oldY, k.currentX, k.currentY);
                }
                if (evaluation(calculate_board.whiteFigures, calculate_board.blackFigures) == bestEval){
                    return j;
                }
                calculate_board.unMove();
            }
        }
    } else {
        for (auto i: calculate_board.blackFigures){
            for (auto j: calculate_board.generateAllMoves(i.x, i.y)){
                for (auto k: j.moves){
                    calculate_board.move(k.oldX, k.oldY, k.currentX, k.currentY);
                }
                if (evaluation(calculate_board.whiteFigures, calculate_board.blackFigures) == bestEval){
                    return j;
                }
                calculate_board.unMove();
            }
        }
    }
}
