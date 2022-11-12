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

        game.SetCurrentTIme();
        game.CheckActive(sf::Mouse::getPosition(window));

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.setActive(false);
                return;
            }

            if (event.type == sf::Event::Closed) {
                if (std::filesystem::exists("../config/custom_settings.txt")){
                    std::system("rm -r ../config/custom_settings.txt");
                }
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if (game.GetPauseActivity()){ // проверка нажатия на кнопку паузы
                    window.setActive(false);
                    sf::Thread GameExitThread(GameExitWindow, std::ref(window));
                    GameExitThread.launch();
                    GameExitThread.wait();
                    window.setActive(true);
                } else {
                    game.Move(sf::Mouse::getPosition(window));
                    game.FigureSelection(sf::Mouse::getPosition(window));
                }
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

    if (gameType == GameType::International){
        FIRST_FIGURE_POSITION_X = BIG_FIRST_FIGURE_POSITION_X;
        FIRST_FIGURE_POSITION_Y = BIG_FIRST_FIGURE_POSITION_Y;
        FIGURE_DISPLACEMENT_X = BIG_FIGURE_DISPLACEMENT_X;
        FIGURE_DISPLACEMENT_Y = BIG_FIGURE_DISPLACEMENT_Y;
    } else {
        FIRST_FIGURE_POSITION_X = SMALL_FIRST_FIGURE_POSITION_X;
        FIRST_FIGURE_POSITION_Y = SMALL_FIRST_FIGURE_POSITION_Y;
        FIGURE_DISPLACEMENT_X = SMALL_FIGURE_DISPLACEMENT_X;
        FIGURE_DISPLACEMENT_Y = SMALL_FIGURE_DISPLACEMENT_Y;
    }

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

    fin >> buff;
    if (buff == "Player_2")
        fin >> player2Name;
    else
        player2Name = "player_1";

    if (isSingleGame){
        player2Name = "Bot-Oleg";
    }

    std::string boardStyleStr;
    std::string moveSelectorStr;
    std::string figureSelectorStr;
    std::string black_pawnStr;
    std::string black_kingStr;
    std::string white_pawnStr;
    std::string white_kingStr;
    std::string pauseButtonStr = "../textures/elements/pause.png";
    std::string activePauseButtonStr = "../textures/elements/active_pause.png";

    fin >> buff;
    if (buff == "Game_style") {
        fin >> buff;

        if (buff == "standart"){
            if (gameType == GameType::International){
                boardStyleStr = "../textures/boards/big_yellow.png";
                moveSelectorStr = "../textures/elements/move_selector.png";
                figureSelectorStr = "../textures/elements/figure_selector.png";
                black_pawnStr = "../textures/figures/Standart/black_pawn.png";
                black_kingStr = "../textures/figures/Standart/black_king.png";
                white_pawnStr = "../textures/figures/Standart/white_pawn.png";
                white_kingStr = "../textures/figures/Standart/white_king.png";

            } else {
                boardStyleStr = "../textures/boards/yellow.png";
                moveSelectorStr = "../textures/elements/big_move_selector.png";
                figureSelectorStr = "../textures/elements/big_figure_selector.png";
                black_pawnStr = "../textures/figures/Standart/big_black_pawn.png";
                black_kingStr = "../textures/figures/Standart/big_black_king.png";
                white_pawnStr = "../textures/figures/Standart/big_white_pawn.png";
                white_kingStr = "../textures/figures/Standart/big_white_king.png";
            }
        } else if (buff == "black_and_white"){
            if (gameType == GameType::International){
                boardStyleStr = "../textures/boards/big_bw.png";
                moveSelectorStr = "../textures/elements/move_selector.png";
                figureSelectorStr = "../textures/elements/figure_selector.png";
                black_pawnStr = "../textures/figures/black_and_white/black_pawn.png";
                black_kingStr = "../textures/figures/black_and_white/black_king.png";
                white_pawnStr = "../textures/figures/black_and_white/white_pawn.png";
                white_kingStr = "../textures/figures/black_and_white/white_king.png";

            } else {
                boardStyleStr = "../textures/boards/bw.png";
                moveSelectorStr = "../textures/elements/big_move_selector.png";
                figureSelectorStr = "../textures/elements/big_figure_selector.png";
                black_pawnStr = "../textures/figures/black_and_white/big_black_pawn.png";
                black_kingStr = "../textures/figures/black_and_white/big_black_king.png";
                white_pawnStr = "../textures/figures/black_and_white/big_white_pawn.png";
                white_kingStr = "../textures/figures/black_and_white/big_white_king.png";
            }
        }
    }

    fin.close();

    textFont.loadFromFile("../fonts/GOUDYSTO.TTF");

    score.first = 0;
    score.second = 0;

    scoreText.setFillColor(sf::Color::Black);
    scoreText.setFont(textFont);
    scoreText.setCharacterSize(35);
    scoreText.setPosition(990, 805);
    scoreText.setString("Score " + std::to_string(score.first) + " : " + std::to_string(score.second));
    scoreText.setStyle(sf::Text::Bold);

    scoreRect.setSize(sf::Vector2f(360, 55));
    scoreRect.setFillColor(sf::Color::White);
    scoreRect.setOutlineColor(sf::Color::Black);
    scoreRect.setOutlineThickness(4);
    scoreRect.setPosition(975, 800);


    roundsText.setFillColor(sf::Color::Black);
    roundsText.setFont(textFont);
    roundsText.setCharacterSize(35);
    roundsText.setPosition(1020, 737);
    roundsText.setString("Round " + std::to_string(currentRound));
    roundsText.setStyle(sf::Text::Bold);

    roundsRect.setSize(sf::Vector2f(280, 55));
    roundsRect.setFillColor(sf::Color::White);
    roundsRect.setOutlineColor(sf::Color::Black);
    roundsRect.setOutlineThickness(4);
    roundsRect.setPosition(1015, 730);


    gameTimeString = "";
    gameTimeText.setFillColor(sf::Color::Black);
    gameTimeText.setFont(textFont);
    gameTimeText.setCharacterSize(45);
    gameTimeText.setPosition(1070, 115);
    gameTimeText.setString("00:00");
    gameTimeText.setStyle(sf::Text::Bold);

    gameTimeRect.setSize(sf::Vector2f(200, 55));
    gameTimeRect.setFillColor(sf::Color::White);
    gameTimeRect.setOutlineColor(sf::Color::Black);
    gameTimeRect.setOutlineThickness(4);
    gameTimeRect.setPosition(1055, 115);


    player1TextName.setFillColor(sf::Color::Black);
    player1TextName.setFont(textFont);
    player1TextName.setCharacterSize(20);
    player1TextName.setPosition(45, 23);
    player1TextName.setString(player1Name);
    player1TextName.setStyle(sf::Text::Bold);

    player1Rect.setSize(sf::Vector2f(250, 30));
    player1Rect.setFillColor(sf::Color::White);
    player1Rect.setOutlineColor(sf::Color::Black);
    player1Rect.setOutlineThickness(3);
    player1Rect.setPosition(43, 20);


    player2TextName.setFillColor(sf::Color::Black);
    player2TextName.setFont(textFont);
    player2TextName.setCharacterSize(20);
    player2TextName.setPosition(45, 865);
    player2TextName.setString(player2Name);
    player2TextName.setStyle(sf::Text::Bold);

    player2Rect.setSize(sf::Vector2f(250, 30));
    player2Rect.setFillColor(sf::Color::White);
    player2Rect.setOutlineColor(sf::Color::Black);
    player2Rect.setOutlineThickness(3);
    player2Rect.setPosition(43, 862);


    pauseButton.texture.loadFromFile(pauseButtonStr);
    pauseButton.sprite.setTexture(pauseButton.texture);
    pauseButton.sprite.setPosition(1360, 400);

    activePauseButton.texture.loadFromFile(activePauseButtonStr);
    activePauseButton.sprite.setTexture(activePauseButton.texture);
    activePauseButton.sprite.setPosition(1360, 400);


    moveSelector.texture.loadFromFile(moveSelectorStr);
    moveSelector.sprite.setTexture(moveSelector.texture);

    figureSelector.texture.loadFromFile(figureSelectorStr);
    figureSelector.sprite.setTexture(figureSelector.texture);


    boardStyle.texture.loadFromFile(boardStyleStr);
    boardStyle.sprite.setTexture(boardStyle.texture);
    boardStyle.sprite.setPosition(42,56);

    black_pawn.texture.loadFromFile(black_pawnStr);
    black_pawn.sprite.setTexture(black_pawn.texture);

    black_king.texture.loadFromFile(black_kingStr);
    black_king.sprite.setTexture(black_king.texture);

    white_pawn.texture.loadFromFile(white_pawnStr);
    white_pawn.sprite.setTexture(white_pawn.texture);

    white_king.texture.loadFromFile(white_kingStr);
    white_king.sprite.setTexture(white_king.texture);

    gameTime.restart();
}

void Game::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    window.draw(boardStyle.sprite);

    window.draw(scoreRect);
    window.draw(scoreText);

    window.draw(roundsRect);
    window.draw(roundsText);

    window.draw(gameTimeRect);
    window.draw(gameTimeText);

    window.draw(player1Rect);
    window.draw(player1TextName);

    window.draw(player2Rect);
    window.draw(player2TextName);

    if (pauseIsActive){
        activePauseButton.Draw(window);
    } else {
        pauseButton.Draw(window);
    }

    if (isSelected){
        figureSelector.Draw(window);

        std::pair<uint16_t, uint16_t> pos;
        for(auto i: movePos){
            pos = board.convertPos(i);
            moveSelector.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*pos.first + 1, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*pos.second);
            moveSelector.Draw(window);
        }
    }

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

void Game::FigureSelection(const sf::Vector2i& mousePos){

    bool isMissed = false; // проверка на нажатие не на фигуру. В таком случае выделения фигуры убираются

    if (gameTime.getElapsedTime() <= sf::seconds(0.2)){
        return;
    }

    for (auto i: board.whiteFigures){
        if (mousePos.x >= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x &&
                mousePos.x <= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*(i.x + 1) &&
                mousePos.y >= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y &&
                mousePos.y <= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*(i.y + 1)){
            isSelected = true;
            isMissed = true;

            selectedPos.first = i.x;
            selectedPos.second = i.y;

            figureSelector.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);

            movePos = board.possibles(i.x, i.y);
            break;
        }
    }

    for (auto i: board.blackFigures){
        if (mousePos.x >= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x &&
            mousePos.x <= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*(i.x + 1) &&
            mousePos.y >= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y &&
            mousePos.y <= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*(i.y + 1)){
            isSelected = true;
            isMissed = true;

            selectedPos.first = i.x;
            selectedPos.second = i.y;

            figureSelector.SetPosition(FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*i.x + 1, FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*i.y);

            movePos = board.possibles(i.x, i.y);
            break;
        }
    }

    if (!isMissed){
        selectedPos.first = 99;
        selectedPos.second = 99;
        isSelected = false;
        movePos.clear();
    }
}

void Game::Move(const sf::Vector2i& mousePos){
    std::pair<uint16_t, uint16_t> pos;
    for(auto i: movePos){
        pos = board.convertPos(i);

        if(mousePos.x >= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*pos.first &&
           mousePos.x <= FIRST_FIGURE_POSITION_X + FIGURE_DISPLACEMENT_X*(pos.first + 1) &&
           mousePos.y >= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*pos.second &&
           mousePos.y <= FIRST_FIGURE_POSITION_Y + FIGURE_DISPLACEMENT_Y*(pos.second + 1)){
            board.move(selectedPos.first, selectedPos.second, pos.first, pos.second);
        }
    }
}

void Game::SetCurrentTIme(){
    int time = static_cast<int>(gameTime.getElapsedTime().asSeconds());
    int minutes = time / 60;
    int seconds = time % 60;

    if (minutes >= 60){
        gameTimeString = "--:--";
        gameTimeText.setString(gameTimeString);
    }


    if (minutes < 10){
        gameTimeString = "0";
    }
    gameTimeString += std::to_string(minutes);
    gameTimeString += ":";
    if (seconds < 10){
        gameTimeString += "0";
    }

    gameTimeString += std::to_string(seconds);
    gameTimeText.setString(gameTimeString);
}

void Game::CheckActive(const sf::Vector2i& mousePos){
    if (mousePos.x >= 1360 && mousePos.x <= 1440 && mousePos.y >= 400 && mousePos.y <= 480){
        pauseIsActive = true;
    } else {
        pauseIsActive = false;
    }
}

bool Game::GetPauseActivity() const{
    return pauseIsActive;
}

void Game::Object::SetPosition(int x, int y){
    sprite.setPosition(float(x), float(y));
}
void Game::Object::Draw(sf::RenderWindow& window) const{
    window.draw(sprite);
}

void GameExitWindow(sf::RenderWindow& window){
    return;
}
