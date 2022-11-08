#include "settings.h"

void SettingsWindow(sf::RenderWindow& window){
    window.setActive();

    Settings settings;

    while (window.isOpen()) {
        sf::Event event;

        settings.ActivateButton(sf::Mouse::getPosition(window), window);

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.setActive(false);
                return;
            }

            if (event.type == sf::Event::TextEntered){
                settings.inputText(event.text.unicode);
            }
        }

        switch (settings.PressButton(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
            case 1:{
                window.setActive(false);
                return;
            }
            case 2:{
                window.setActive(false);
                return;
            }
            case 3:{
                settings.setTextInput();
                break;
            }
            case 4:{
                settings.setStyleBoardStyle("standart");
                break;
            }
            case 5:{
                settings.setStyleBoardStyle("black_and_white");
                break;
            }
            default:{
                break;
            };
        }

        if (window.pollEvent(event)){}

        window.clear();
        settings.Draw(window);
        window.display();
    }

    window.setActive(false);
}

Settings::Settings(): background(BACKGROUND_IMAGE),
                      save(SIZE_SETTINGS_BUTTONS, THICKNESS, POS_SAVE_X,
                           POS_SAVE_Y, COLOR_OUTLINE, COLOR_TEXT,
                           TEXT_BUTTON_SIZE, PATH_FONTS, POS_SAVE_TEXT_X,
                           POS_SAVE_TEXT_Y, "SAVE"),
                      back(SIZE_SETTINGS_BUTTONS, THICKNESS, POS_BACK_X,
                           POS_BACK_Y , COLOR_OUTLINE, COLOR_TEXT,
                           TEXT_BUTTON_SIZE, PATH_FONTS, POS_BACK_TEXT_X,
                           POS_BACK_TEXT_Y , "BACK"),
                      player1Field(SIZE_NAME_FIELD_PLAYER_1, SIZE_ENTER_FIELD_PLAYER_1,
                                   POS_NAME_FIELD_PLAYER_1_X, POS_NAME_FIELD_PLAYER_1_Y,
                                   POS_ENTER_FIELD_PLAYER_1_X, POS_ENTER_FIELD_PLAYER_1_Y,
                                   TEXT_NAME_FIELD_PLAYER_1_SIZE, TEXT_ENTER_FIELD_PLAYER_1_SIZE,
                                   TEXT_POS_NAME_FIELD_PLAYER_1_X, TEXT_POS_NAME_FIELD_PLAYER_1_Y,
                                   TEXT_POS_ENTER_FIELD_PLAYER_1_X, TEXT_POS_ENTER_FIELD_PLAYER_1_Y,
                                   PATH_FONTS,
                                   "PLAYER 1", "Enter name"),
                      player2Field(SIZE_NAME_FIELD_PLAYER_2, SIZE_ENTER_FIELD_PLAYER_2,
                                   POS_NAME_FIELD_PLAYER_2_X, POS_NAME_FIELD_PLAYER_2_Y,
                                   POS_ENTER_FIELD_PLAYER_2_X, POS_ENTER_FIELD_PLAYER_2_Y,
                                   TEXT_NAME_FIELD_PLAYER_2_SIZE, TEXT_ENTER_FIELD_PLAYER_2_SIZE,
                                   TEXT_POS_NAME_FIELD_PLAYER_2_X, TEXT_POS_NAME_FIELD_PLAYER_2_Y,
                                   TEXT_POS_ENTER_FIELD_PLAYER_2_X, TEXT_POS_ENTER_FIELD_PLAYER_2_Y,
                                   PATH_FONTS,
                                   "PLAYER 2", "Enter name"),
                      leftArrow(POS_LEFT_ARROW_X, POS_LEFT_ARROW_Y, LEFT_ARROW_IMAGE),
                      rightArrow(POS_RIGHT_ARROW_X, POS_RIGHT_ARROW_Y, RIGHT_ARROW_IMAGE),
                      game_styles(STANDART_STYLE_IMAGE, BLACK_AND_WHITE_STYLE_IMAGE, POS_STYLE_IMAGE_X, POS_STYLE_IMAGE_Y)
                      {}

void Settings::ActivateButton(const sf::Vector2i& mousePosition, sf::RenderWindow& window){

    if ((is_mouse_on_left_arrow || is_mouse_on_right_arrow) && !is_mouse_on_arrow){
        is_mouse_on_arrow = true;

        if (is_mouse_on_right_arrow && game_styles.isStandartStyle){ //the right arrow will not work if the style is not standard
            ChangeCursor(window, sf::Cursor::Type::Hand);
        } else if (is_mouse_on_left_arrow && !game_styles.isStandartStyle){ // left arrow won't work if default style is set
            ChangeCursor(window, sf::Cursor::Type::Hand);
        }

    } else if(!(is_mouse_on_left_arrow || is_mouse_on_right_arrow) && is_mouse_on_arrow){
        is_mouse_on_arrow = false;
        ChangeCursor(window, sf::Cursor::Type::Arrow);
    }

    if ((is_mouse_on_enter_player_1_field || is_mouse_on_enter_player_2_field) && !is_mouse_on_enter_field){
        is_mouse_on_enter_field = true;
        ChangeCursor(window, sf::Cursor::Type::Text);

    } else if(!(is_mouse_on_enter_player_1_field || is_mouse_on_enter_player_2_field) && is_mouse_on_enter_field){
        is_mouse_on_enter_field = false;
        ChangeCursor(window, sf::Cursor::Type::Arrow);
    }

    if ((is_mouse_on_save_button || is_mouse_on_back_button) && !is_mouse_on_button){
        is_mouse_on_button = true;
        ChangeCursor(window, sf::Cursor::Type::Hand);

        if (is_mouse_on_save_button) {
            save.setColorFigure(sf::Color::Red);
            save.setColorText(sf::Color::Red);
        } else if(is_mouse_on_back_button) {
            back.setColorFigure(sf::Color::Red);
            back.setColorText(sf::Color::Red);
        }

    } else if(!(is_mouse_on_save_button || is_mouse_on_back_button) && is_mouse_on_button){
        is_mouse_on_button = false;
        ChangeCursor(window, sf::Cursor::Type::Arrow);

        save.setColorFigure(sf::Color::Black);
        save.setColorText(sf::Color::Black);

        back.setColorFigure(sf::Color::Black);
        back.setColorText(sf::Color::Black);
    }

    if (mousePosition.x >= POS_SAVE_X && mousePosition.x <= POS_SAVE_X + SIZE_SETTINGS_BUTTON_X &&
        mousePosition.y >= POS_SAVE_Y && mousePosition.y <= POS_SAVE_Y + SIZE_SETTINGS_BUTTON_Y){
        is_mouse_on_save_button = true;
        return;
    } else {
        is_mouse_on_save_button = false;
    }

    if (mousePosition.x >= POS_BACK_X && mousePosition.x <= POS_BACK_X + SIZE_SETTINGS_BUTTON_X &&
        mousePosition.y >= POS_BACK_Y && mousePosition.y <= POS_BACK_Y + SIZE_SETTINGS_BUTTON_Y){
        is_mouse_on_back_button = true;
        return;
    } else {
        is_mouse_on_back_button = false;
    }

    if (mousePosition.x >= POS_ENTER_FIELD_PLAYER_1_X && mousePosition.x <= POS_ENTER_FIELD_PLAYER_1_X + SIZE_ENTER_FIELD_PLAYER_1_X &&
        mousePosition.y >= POS_ENTER_FIELD_PLAYER_1_Y && mousePosition.y <= POS_ENTER_FIELD_PLAYER_1_Y + SIZE_ENTER_FIELD_PLAYER_1_Y){
        is_mouse_on_enter_player_1_field = true;
        return;
    } else {
        is_mouse_on_enter_player_1_field = false;
    }

    if (mousePosition.x >= POS_ENTER_FIELD_PLAYER_2_X && mousePosition.x <= POS_ENTER_FIELD_PLAYER_2_X + SIZE_ENTER_FIELD_PLAYER_2_X &&
        mousePosition.y >= POS_ENTER_FIELD_PLAYER_2_Y && mousePosition.y <= POS_ENTER_FIELD_PLAYER_2_Y + SIZE_ENTER_FIELD_PLAYER_2_Y){
        is_mouse_on_enter_player_2_field = true;
        return;
    } else {
        is_mouse_on_enter_player_2_field = false;
    }

    // Due to the wrong size of the arrow images, constants have been added for the sensitivity of the cursor when hovering over the arrow
    if (mousePosition.x >= POS_LEFT_ARROW_X + 40 && mousePosition.x <= POS_LEFT_ARROW_X + 80 &&
        mousePosition.y >= POS_LEFT_ARROW_Y + 20 && mousePosition.y <= POS_LEFT_ARROW_Y + 90){
        is_mouse_on_left_arrow = true;
        return;
    } else {
        is_mouse_on_left_arrow = false;
    }

    if (mousePosition.x >= POS_RIGHT_ARROW_X + 40 && mousePosition.x <= POS_RIGHT_ARROW_X + 80 &&
        mousePosition.y >= POS_RIGHT_ARROW_Y + 30 && mousePosition.y <= POS_RIGHT_ARROW_Y + 100){
        is_mouse_on_right_arrow = true;
        return;
    } else {
        is_mouse_on_right_arrow = false;
    }
}

int Settings::PressButton(bool mouse_is_pressed){
    if (mouse_is_pressed){

        if (is_mouse_on_enter_player_1_field){
            is_player_2_name_input = false;

            if (player_2_Name.empty()) {
                player2Field.enterFieldText.setString("Enter name");
            }

            return 3;
        } else if (is_mouse_on_enter_player_2_field){
            is_player_1_name_input = false;

            if (player_1_Name.empty()){
                player1Field.enterFieldText.setString("Enter name");
            }

            return 3;
        } else{
            is_player_1_name_input = false;
            is_player_2_name_input = false;

            if (player_1_Name.empty()){
                player1Field.enterFieldText.setString("Enter name");
            }

            if (player_2_Name.empty()) {
                player2Field.enterFieldText.setString("Enter name");
            }
        }


        if (is_mouse_on_save_button)
            return 1;

        if (is_mouse_on_back_button)
            return 2;

        if (is_mouse_on_left_arrow)
            return 4;

        if (is_mouse_on_right_arrow)
            return 5;

    }
    return 0;
}

void Settings::Draw(sf::RenderWindow& window){
    background.drawBackground(window);
    player1Field.Draw(window);
    player2Field.Draw(window);
    window.draw(game_styles.sprite);
    leftArrow.drawArrow(window);
    rightArrow.drawArrow(window);
    save.drawButton(window);
    back.drawButton(window);
}

void Settings::setStyleBoardStyle(const std::string& styleName){
    if (styleName == "standart" && !game_styles.isStandartStyle){
        game_styles.isStandartStyle = true;
        game_styles.sprite.setTexture(game_styles.textures[0]);
    } else if (styleName == "black_and_white" && game_styles.isStandartStyle){
        game_styles.isStandartStyle = false;
        game_styles.sprite.setTexture(game_styles.textures[1]);
    }
}

void Settings::ChangeCursor(sf::RenderWindow &window, sf::Cursor::Type type_cursor){
    cursor.loadFromSystem(type_cursor);
    window.setMouseCursor(cursor);
}

void Settings::setTextInput(){
    if (is_mouse_on_enter_player_1_field){
        is_player_1_name_input = true;

        if (player_1_Name.empty())
            player1Field.enterFieldText.setString("");

    } else if (is_mouse_on_enter_player_2_field){
        is_player_2_name_input = true;

        if (player_2_Name.empty())
            player2Field.enterFieldText.setString("");
    }
}

void Settings::inputText(const uint32_t& inputSymbol){
    char symbol = static_cast<char>(inputSymbol);
    if (is_player_1_name_input){
        if (std::to_string(inputSymbol) == "8"){ // if pressed backspace, delete last symbol
            if (player_1_Name.size() != 0){
                player_1_Name.pop_back();
            }
        } else if (player_1_Name.size() != 12){ // set character limit
            player_1_Name.push_back(symbol);
        }
        player1Field.enterFieldText.setString(player_1_Name);
    }

    if (is_player_2_name_input){
        if (std::to_string(inputSymbol) == "8"){ // if pressed backspace, delete last symbol
            if (player_2_Name.size() != 0){
                player_2_Name.pop_back();
            }
        } else if (player_2_Name.size() != 12){ // set character limit
            player_2_Name.push_back(symbol);
        }
        player2Field.enterFieldText.setString(player_2_Name);
    }
}

Settings::InputNameField::InputNameField(sf::Vector2<float> nameFieldSize, sf::Vector2<float> enterFieldSize,
                                         float nameField_posX, float nameField_posY,
                                         float enterField_posX, float enterField_posY,
                                         int nameField_textSize, int enterField_textSize,
                                         float nameField_text_posX, float nameField_text_posY,
                                         float enterField_text_posX, float enterField_text_posY,
                                         const std::string& path_font,
                                         const std::string& nameFieldString, const std::string& enterFieldString) {
    nameField.setSize(nameFieldSize);
    nameField.setOutlineThickness(5);
    nameField.setOutlineColor(sf::Color::Black);
    nameField.setFillColor(sf::Color::White);
    nameField.setPosition(nameField_posX, nameField_posY);

    enterField.setSize(enterFieldSize);
    enterField.setOutlineThickness(5);
    enterField.setOutlineColor(sf::Color::Black);
    enterField.setFillColor(sf::Color::White);
    enterField.setPosition(enterField_posX, enterField_posY);

    font.loadFromFile(path_font);

    nameFieldText.setFillColor(sf::Color::Black);
    nameFieldText.setFont(font);
    nameFieldText.setCharacterSize(nameField_textSize);
    nameFieldText.setPosition(nameField_text_posX, nameField_text_posY);
    nameFieldText.setString(nameFieldString);
    nameFieldText.setStyle(sf::Text::Bold);

    enterFieldText.setFillColor(sf::Color::Black);
    enterFieldText.setFont(font);
    enterFieldText.setCharacterSize(enterField_textSize);
    enterFieldText.setPosition(enterField_text_posX, enterField_text_posY);
    enterFieldText.setString(enterFieldString);

}

void Settings::InputNameField::Draw(sf::RenderWindow& window) const{
    window.draw(nameField);
    window.draw(enterField);

    window.draw(nameFieldText);
    window.draw(enterFieldText);
}



Settings::Game_Styles::Game_Styles(const std::string& textureImg_1, const std::string& textureImg_2, float x, float y): x(x), y(y){
    textures[0].loadFromFile(textureImg_1);
    textures[1].loadFromFile(textureImg_2);

    sprite.setTexture(textures[0]);
    sprite.setPosition(x, y);
}

