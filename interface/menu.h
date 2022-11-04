#include "header.h"

class Background {
public:
    Background() = delete;

    Background(const std::string& path_background_image) {
        texture_background.loadFromFile(path_background_image);
        sprite_background.setTexture(texture_background);
    }

    void drawBackground(sf::RenderWindow& window) {
        window.draw(sprite_background);
    }

private:
    sf::Texture texture_background;
    sf::Sprite sprite_background;
};

class Button {
public:
    Button() = delete;

    Button(sf::Vector2<float>& size, const float thickness,
           const float pos_button_x, const float pos_button_y,
           const int text_size, const std::string path_font_text,
           const float pos_text_x, const float pos_text_y,
           const std::string string_text) {

        figure.setFillColor(sf::Color::White); //Create play_button
        figure.setOutlineColor(sf::Color::Black);
        figure.setOutlineThickness(thickness);
        figure.setSize(size);
        figure.setPosition(pos_button_x, pos_button_y);

        font.loadFromFile(path_font_text);

        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);
        text.setFont(font);
        text.setCharacterSize(text_size);
        text.setPosition(pos_text_x, pos_text_y);
        text.setString(string_text);
    }

    void drawButton(sf::RenderWindow& window) {
        window.draw(figure);
        window.draw(text);
    }

private:
    sf::RectangleShape figure;
    sf::Font font;
    sf::Text text;
};

