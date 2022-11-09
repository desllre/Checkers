#include "game_design.h"

void Game_design(sf::RenderWindow& window, const uint32_t& roundsNum, bool isSingleGame, GameType gameType, const char& figureColor){
    window.setActive();


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.setActive(false);
                return;
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.display();
    }

    window.setActive(false);
}

Game::Game(const uint32_t& roundsNum, bool isSingleGame, GameType gameType, bool playerHasWhiteBoard, const uint16_t& boardSize, bool isWhiteBoard): board(boardSize, playerHasWhiteBoard, gameType){

}
