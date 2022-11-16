#include "elements.h"

Background::Background(const std::string& path_background_image) {
    texture_background.loadFromFile(path_background_image);
    sprite_background.setTexture(texture_background);
}

void Background::drawBackground(sf::RenderWindow& window) {
    window.draw(sprite_background);
}

Button::Button(const sf::Vector2<float> &size, float thickness,
               float pos_button_x, float pos_button_y,
               sf::Color color_outline, sf::Color color_text,
               int text_size, const std::string& path_font,
               float pos_text_x, float pos_text_y,
               const std::string& string_music_touch,
               const std::string& string_music_press,
               const std::string& string_text) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_button_x, pos_button_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);

    music_press.openFromFile(string_music_press);
    music_touch.openFromFile(string_music_touch);
}


Button::Button(const sf::Vector2<float> &size, float thickness,
               float pos_button_x, float pos_button_y,
               sf::Color color_outline, sf::Color color_text,
               int text_size, const std::string& path_font,
               float pos_text_x, float pos_text_y,
               const std::string& string_text) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_button_x, pos_button_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void Button::playSongsPress() {

}

void Button::setColorText(const sf::Color color_text) {
    text.setColor(color_text);
}

void Button::setColorFigure(sf::Color color_outline) {
    figure.setOutlineColor(color_outline);
}

void Button::drawButton(sf::RenderWindow &window) {
    window.draw(figure);
    window.draw(text);
}

Arrow::Arrow(sf::Vector2<float> size, float pos_arrow_x, float pos_arrow_y,
             const std::string &path_arrow, const std::string &path_arrow_activated,
             const std::string &string_music_touch, const std::string &string_music_press) {
    texture_arrow_activated.loadFromFile(path_arrow_activated);

    texture_arrow.loadFromFile(path_arrow);
    sprite_arrow.setTexture(texture_arrow);

    sprite_arrow.setPosition(pos_arrow_x, pos_arrow_y);
    sprite_arrow.setScale(size);

    music_press.openFromFile(string_music_press);
    music_touch.openFromFile(string_music_touch);
}

void Arrow::setColor(bool is_on_arrow) {
    if (is_on_arrow) {
        sprite_arrow.setTexture(texture_arrow_activated);
    }
    else {
        sprite_arrow.setTexture(texture_arrow);
    }
}

void Arrow::drawArrow(sf::RenderWindow &window) {
    window.draw(sprite_arrow);
}

void Arrow::playSongsPress() {
    sf::Time time = sf::seconds(0.2);
    music_press.play();
    sleep(time);
    music_press.stop();
}

Text::Text(const sf::Vector2<float> &size, float thickness,
           float pos_figure_x, float pos_figure_y,
           sf::Color color_outline, sf::Color color_text,
           int text_size, const std::string& path_font,
           const std::string& string_text,
           float pos_text_x, float pos_text_y) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_figure_x, pos_figure_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void Text::drawText(sf::RenderWindow &window) {
    window.draw(figure);
    window.draw(text);
}

InputFieldRounds::InputFieldRounds(const sf::Vector2<float> &size, float thickness,
                                   float pos_figure_x, float pos_figure_y,
                                   sf::Color color_outline, sf::Color color_text,
                                   int text_size, const std::string& path_font,
                                   const std::string& string_text,
                                   float pos_text_x, float pos_text_y, uint32_t &roundsNum) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_figure_x, pos_figure_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void InputFieldRounds::setValue(bool is_mouse_on_left_round_arrows,
                                bool is_mouse_on_right_round_arrows) {
    if (is_mouse_on_left_round_arrows && roundsNum > 1) {
        --roundsNum;
        number_of_round = std::to_string(roundsNum);
        text.setString(number_of_round);
    }
    else if (is_mouse_on_right_round_arrows && roundsNum < 5) {
        ++roundsNum;
        number_of_round = std::to_string(roundsNum);
        text.setString(number_of_round);
    }
}

std::string InputFieldRounds::getStringValue() {
    return number_of_round;
}

uint32_t InputFieldRounds::getCurrentRound(){
    return roundsNum;
}

InputFieldTypeRules::InputFieldTypeRules(const sf::Vector2<float> &size, float thickness,
                                   float pos_figure_x, float pos_figure_y,
                                   sf::Color color_outline, sf::Color color_text,
                                   int text_size, const std::string& path_font,
                                   const std::string& string_text,
                                   float pos_text_x, float pos_text_y, GameType &game_type) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_figure_x, pos_figure_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void InputFieldTypeRules::setValue(bool is_mouse_on_left_round_arrows,
                                bool is_mouse_on_right_round_arrows) {
    if (is_mouse_on_left_round_arrows && index > 0) {
        --index;
        text.setString(array_type_of_game[index].c_str());
    }
    else if (is_mouse_on_right_round_arrows && index < 3) {
        ++index;
        text.setString(array_type_of_game[index].c_str());
    }

    if (array_type_of_game[index].compare("Russian")) {
        game_type = Russian;
    }
    else if (array_type_of_game[index].compare("English")) {
        game_type = English;
    }
    else if (array_type_of_game[index].compare("Giveaway")) {
        game_type = Giveaway;
    }
    else if (array_type_of_game[index].compare("International")) {
        game_type = International;
    }
}

GameType InputFieldTypeRules::getStringValue() {
    return game_type;
}

InputFieldColor::InputFieldColor(const sf::Vector2<float> &size, float thickness,
                                 float pos_figure_x, float pos_figure_y,
                                 sf::Color color_outline, sf::Color color_text,
                                 int text_size, const std::string& path_font,
                                 const std::string& string_text,
                                 float pos_text_x, float pos_text_y, char &color_of_checkers) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_figure_x, pos_figure_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void InputFieldColor::setValue(bool is_mouse_on_left_color_arrows, bool is_mouse_on_right_color_arrows) {
    if (is_mouse_on_left_color_arrows && index > 0) {
        --index;
        text.setString(array_color_of_checkers[index].c_str());
    }
    else if (is_mouse_on_right_color_arrows && index < 1) {
        ++index;
        text.setString(array_color_of_checkers[index].c_str());
    }
    if (array_color_of_checkers[index].compare("White")) {
        color_of_checkers = 'w';
    }
    else if (array_color_of_checkers[index].compare("Black")) {
        color_of_checkers = 'b';
    }
}

char InputFieldColor::getStringValue() {
    return color_of_checkers;
}



InputFieldMultiplayer::InputFieldMultiplayer(const sf::Vector2<float> &size, float thickness,
                                 float pos_figure_x, float pos_figure_y,
                                 sf::Color color_outline, sf::Color color_text,
                                 int text_size, const std::string& path_font,
                                 const std::string& string_text,
                                 float pos_text_x, float pos_text_y) {
    figure.setFillColor(sf::Color::White);
    figure.setOutlineColor(color_outline);
    figure.setOutlineThickness(thickness);
    figure.setSize(size);
    figure.setPosition(pos_figure_x, pos_figure_y);

    font.loadFromFile(path_font);

    text.setColor(color_text);
    text.setStyle(sf::Text::Bold);
    text.setFont(font);
    text.setCharacterSize(text_size);
    text.setPosition(pos_text_x, pos_text_y);
    text.setString(string_text);
}

void InputFieldMultiplayer::setValue(bool is_mouse_on_left_multiplayer_arrows,
                                    bool is_mouse_on_right_multiplayer_arrows){
    if (is_mouse_on_right_multiplayer_arrows && index == 0){
        index = 1;
        is_single_game = false;
    } else if (is_mouse_on_left_multiplayer_arrows && index == 1){
        index = 0;
        is_single_game = true;
    }
    text.setString(array_multiplayer_of_checkers[index].c_str());
}

bool InputFieldMultiplayer::getValue(){
    return is_single_game;
}
