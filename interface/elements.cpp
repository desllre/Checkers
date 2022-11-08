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
    sf::Time time = sf::seconds(0.6);
    music_press.play();
    sleep(time);
    music_press.stop();
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
             const std::string &path_arrow, const std::string &string_music_touch,
             const std::string &string_music_press) {
    texture_arrow.loadFromFile(path_arrow);
    sprite_arrow.setTexture(texture_arrow);

    sprite_arrow.setPosition(pos_arrow_x, pos_arrow_y);
    sprite_arrow.setScale(size);

    sprite_arrow.setPosition(pos_arrow_x, pos_arrow_y);
    sprite_arrow.setScale(size);

    music_press.openFromFile(string_music_press);
    music_touch.openFromFile(string_music_touch);
}

void Arrow::setColor(const std::string &path_arrow) {
    texture_arrow.loadFromFile(path_arrow);
    sprite_arrow.setTexture(texture_arrow);
}

void Arrow::drawArrow(sf::RenderWindow &window) {
    window.draw(sprite_arrow);
}