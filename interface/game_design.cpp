#include "game_design.h"

void Game_design(sf::RenderWindow& window, const uint32_t& roundsNum, bool isSingleGame, GameType gameType, const char& figureColor){
    window.setActive();

    uint16_t boardSize = 8;
    bool playerHasWhiteBoard;

    if (gameType == GameType::International)
        boardSize = 10;

    if(figureColor == 'w'){
        playerHasWhiteBoard = true;
    } else{
        playerHasWhiteBoard = false;
    }

    Game game(roundsNum, isSingleGame, gameType, playerHasWhiteBoard, boardSize);

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
        game.Draw(window);
        window.display();
    }

    window.setActive(false);
}

Game::Game(const uint32_t& roundsNum, bool isSingleGame, GameType gameType, bool playerHasWhiteBoard, const uint16_t& boardSize):
            board(boardSize, playerHasWhiteBoard, gameType), roundsNum(roundsNum),isSingleGame(isSingleGame),
            gameType(gameType), playerHasWhiteBoard(playerHasWhiteBoard), background("../textures/backgrounds/game_bg.png"){
    std::ifstream fin;
    if (std::filesystem::exists("../config/custom_settings.txt")){
        fin.open("../config/custom_settings.txt");
    } else{
        fin.open("../config/default_settings.txt");
    }

    if (!fin.is_open()){
        throw std::exception();
    }

    std::string buff;
    fin >> buff;
    if (buff == "Player_1")
        fin >> player1Name;
    else
        player1Name = "player_1";
    buff = "";

    fin >> buff;
    if (buff == "Player_2")
        fin >> player2Name;
    else
        player2Name = "player_1";
    buff = "";

    fin >> buff;
    if (buff == "Game_style"){
        buff = "";
        fin >> buff;
        if (buff == "standart"){
            if (boardSize == 8){
                boardStyle.texture.loadFromFile("../textures/boards/yellow.png");
            } else if (boardSize == 10){
                boardStyle.texture.loadFromFile("../textures/boards/big_yellow.png");
            }
            boardStyle.sprite.setTexture(boardStyle.texture);
            boardStyle.sprite.setPosition(42,56);

            black_pawn.texture.loadFromFile("../textures/figures/Standart/black_pawn.png");
            black_pawn.sprite.setTexture(black_pawn.texture);

            black_king.texture.loadFromFile("../textures/figures/Standart/black_king.png");
            black_king.sprite.setTexture(black_king.texture);

            white_pawn.texture.loadFromFile("../textures/figures/Standart/white_pawn.png");
            white_pawn.sprite.setTexture(white_pawn.texture);

            white_king.texture.loadFromFile("../textures/figures/Standart/white_king.png");
            white_king.sprite.setTexture(white_king.texture);

        } else if (buff == "black_and_white") {
            if (boardSize == 8){
                boardStyle.texture.loadFromFile("../textures/boards/bw.png");
            } else if (boardSize == 10){
                boardStyle.texture.loadFromFile("../textures/boards/big_bw.png");
            }
            boardStyle.sprite.setTexture(boardStyle.texture);
            boardStyle.sprite.setPosition(42,56);

            black_pawn.texture.loadFromFile("../textures/figures/black_and_white/black_pawn.png");
            black_pawn.sprite.setTexture(black_pawn.texture);

            black_king.texture.loadFromFile("../textures/figures/black_and_white/black_king.png");
            black_king.sprite.setTexture(black_king.texture);

            white_pawn.texture.loadFromFile("../textures/figures/black_and_white/white_pawn.png");
            white_pawn.sprite.setTexture(white_pawn.texture);

            white_king.texture.loadFromFile("../textures/figures/black_and_white/white_king.png");
            white_king.sprite.setTexture(white_king.texture);
        }

    }


}

void Game::Object::SetPosition(int x, int y){
    sprite.setPosition(x, y);
}
void Game::Object::Draw(sf::RenderWindow& window){
    window.draw(sprite);
}

void Game::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    window.draw(boardStyle.sprite);

    for(auto i: board.blackFigures){
        if (i.figureType == 'p'){
            black_pawn.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);
            black_pawn.Draw(window);
        } else {
            black_king.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);
            black_king.Draw(window);
        }
    }

    for(auto i: board.whiteFigures){
        if (i.figureType == 'p'){
            white_pawn.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);
            white_pawn.Draw(window);
        } else {
            white_king.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);
            white_king.Draw(window);
        }
    }
}
