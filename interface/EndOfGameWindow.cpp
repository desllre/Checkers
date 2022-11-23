#include "EndOfGameWindow.h"

void EndOfGameWindow(sf::RenderWindow& window, uint32_t roundsNum, uint32_t currentRound, std::pair<uint16_t, uint16_t> score, const std::string& winnerName, int &returnValue){
    window.setActive();

    if (roundsNum > currentRound){
        returnValue = 0;
    } else {
        returnValue = -1;
    }

    EndOfGame endOfGame(roundsNum, currentRound, score, winnerName);
    endOfGame.setArrowCursor(window);

    sf::RenderWindow endOfGameWindow(sf::VideoMode(695, 434), "Checkers", sf::Style::None);
    sf::Vector2i menuWindowPosition = window.getPosition();
    menuWindowPosition.x += 372;
    menuWindowPosition.y += 250;
    endOfGameWindow.setPosition(menuWindowPosition);
    endOfGameWindow.hasFocus();

    sf::Clock clock;

    while (endOfGameWindow.isOpen()) {
        sf::Event event;

        endOfGame.ActivateButton(sf::Mouse::getPosition(endOfGameWindow), endOfGameWindow);

        if (!endOfGame.IsLastRound() && clock.getElapsedTime() >= sf::seconds(5)){
            window.setActive(false);
            endOfGameWindow.close();
            return;
        }

        while (endOfGameWindow.pollEvent(event) && endOfGame.IsLastRound()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.setActive(false);
                endOfGameWindow.close();
                return;
            }

            if(endOfGame.IsLastRound()){
                switch (endOfGame.PressButton(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
                    case 0:{
                        returnValue = 1;
                        window.setActive(false);
                        endOfGameWindow.close();
                        return;
                    }
                    case 1:{
                        returnValue = 2;
                        window.setActive(false);
                        endOfGameWindow.close();
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        if (window.pollEvent(event)){}

        endOfGameWindow.clear();
        endOfGame.Draw(endOfGameWindow);
        endOfGameWindow.display();
    }

    window.setActive(false);
}

EndOfGame::EndOfGame(uint32_t roundsNum, uint32_t currentRound, std::pair<uint16_t, uint16_t> score, const std::string& winnerName):
                    roundsNum(roundsNum), currentRound(currentRound), score(score), winnerName(winnerName),
                    background(BACKGROUND_IMAGE),
                    restart(SIZE_END_OF_GAME_BUTTONS, THICKNESS, POS_RESTART_X,
                            POS_RESTART_Y, COLOR_OUTLINE, COLOR_TEXT,
                            TEXT_SIZE, PATH_FONTS, POS_RESTART_TEXT_X,
                            POS_RESTART_TEXT_Y, "RESTART"),
                    exit(SIZE_END_OF_GAME_BUTTONS, THICKNESS, POS_EXIT_X,
                         POS_EXIT_Y, COLOR_OUTLINE, COLOR_TEXT,
                         TEXT_SIZE, PATH_FONTS, POS_EXIT_TEXT_X,
                         POS_EXIT_TEXT_Y, "EXIT"){

    if (currentRound == roundsNum) {
        isLastRound = true;
    }

    font.loadFromFile(PATH_FONTS);

    scoreText.setFillColor(sf::Color::Black);
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setPosition(183.5, 218);
    scoreText.setString("Score " + std::to_string(score.first) + " : " + std::to_string(score.second));
    scoreText.setStyle(sf::Text::Bold);

    scoreRect.setSize(sf::Vector2f(350, 65));
    scoreRect.setFillColor(sf::Color::White);
    scoreRect.setOutlineColor(sf::Color::Black);
    scoreRect.setOutlineThickness(4);
    scoreRect.setPosition(172.5, 208);


    winnerNameText.setFillColor(sf::Color::Black);
    winnerNameText.setFont(font);
    winnerNameText.setCharacterSize(34);
    winnerNameText.setPosition(50, 125);
    winnerNameText.setString("Winner " + winnerName);
    winnerNameText.setStyle(sf::Text::Bold);

    winnerNameRect.setSize(sf::Vector2f(610, 90));
    winnerNameRect.setFillColor(sf::Color::White);
    winnerNameRect.setOutlineColor(sf::Color::Black);
    winnerNameRect.setOutlineThickness(4);
    winnerNameRect.setPosition(42.5, 100);

}


void EndOfGame::Draw(sf::RenderWindow& window){
    background.drawBackground(window);

    window.draw(winnerNameRect);
    window.draw(winnerNameText);

    if (roundsNum > 1){
        window.draw(scoreRect);
        window.draw(scoreText);
    }

    if (isLastRound){
        restart.drawButton(window);
        exit.drawButton(window);
    }
}

void EndOfGame::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor) {
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void EndOfGame::ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window){

    if ((isExitActive || isRestartActive) && !isMouseOnButton){

        isMouseOnButton = true;
        ChangeCursor(window, sf::Cursor::Hand);

        if (isRestartActive) {
            restart.setColorFigure(sf::Color::Red);
            restart.setColorText(sf::Color::Red);
        } else if (isExitActive) {
            exit.setColorFigure(sf::Color::Red);
            exit.setColorText(sf::Color::Red);
        }

    } else if (!(isExitActive || isRestartActive) && isMouseOnButton){

        isMouseOnButton = false;
        ChangeCursor(window, sf::Cursor::Arrow);

        restart.setColorFigure(sf::Color::Black);
        restart.setColorText(sf::Color::Black);

        exit.setColorFigure(sf::Color::Black);
        exit.setColorText(sf::Color::Black);
    }


    if (mousePosition.x >= POS_RESTART_X && mousePosition.x <= POS_RESTART_X + SIZE_X &&
        mousePosition.y >= POS_RESTART_Y && mousePosition.y <= POS_RESTART_Y + SIZE_Y) {
        isRestartActive = true;
        return;
    } else {
        isRestartActive = false;
    }

    if (mousePosition.x >= POS_EXIT_X && mousePosition.x <= POS_EXIT_X + SIZE_X &&
        mousePosition.y >= POS_EXIT_Y && mousePosition.y <= POS_EXIT_Y + SIZE_Y){
        isExitActive = true;
        return;
    }else {
        isExitActive = false;
    }

}

int EndOfGame::PressButton(bool mouse_is_pressed) const{
    if (mouse_is_pressed){
        if (isRestartActive)
            return 0;

        if (isExitActive)
            return 1;
    }

    return -1;
}

bool EndOfGame::IsLastRound(){
    return isLastRound;
}

void EndOfGame::setArrowCursor(sf::RenderWindow& window){
    cursor.loadFromSystem(sf::Cursor::Type::Arrow);
    window.setMouseCursor(cursor);
}