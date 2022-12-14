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
        if (i.figureType == 'P')
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

int AI::minEvaluation(int lEval, int rEval){
    return (lEval<rEval)?lEval:rEval;
}

int AI::maxEvaluation(int lEval, int rEval){
    return (lEval<rEval)?rEval:lEval;
}

int AI::bestEvalSearch(uint16_t depth, int alpha, int beta){
    int a = calculate_board.endOfGame();
    if (depth == 0 ||  a != 0){
        return evaluation(calculate_board.whiteFigures, calculate_board.blackFigures);
    }

    whiteWay = calculate_board.getWhiteWay();
    if (whiteWay){
        int eval;
        int maxEval = cAlpha;
        std::list<Figure> figures = calculate_board.whiteFigures;
        for (auto i: figures) {
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
        return maxEval;
    } else {
        int eval;
        int minEval = cBeta;
        std::list<Figure> figures = calculate_board.blackFigures;
        for (auto i: figures) {
            for (auto j: calculate_board.generateAllMoves(i.x, i.y)){
                Moves moves = j;
                for(auto k: j.moves){
                    calculate_board.move(k.oldX, k.oldY, k.currentX, k.currentY);
                }
                eval = bestEvalSearch(depth - 1, alpha, beta);

                if (minEval >= eval){
                    minEval = eval;
                    if (depth == viewDepth){
                        bestMovesStorage.emplace_back(j);
                    }
                }

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
        return minEval;
    }
}

Moves AI::bestMoveSearch(){

    whiteWay = game_board->getWhiteWay();
    calculate_board = *game_board;
    int bestEval = bestEvalSearch(viewDepth, cAlpha, cBeta);
    Moves moves;

    if (bestMovesStorage.size() != 0){
        std::srand(time(NULL));
        int randomMoveNum = rand() % bestMovesStorage.size(); // ???? ???????????? ?????????? ???????????????? ????????
        moves = bestMovesStorage[randomMoveNum];
        bestMovesStorage.clear();
    }
    return moves;
}

void AI::move(){
    Moves moves = bestMoveSearch();
    for (auto i: moves.moves){
        game_board->move(i.oldX, i.oldY, i.currentX, i.currentY);
    }
}