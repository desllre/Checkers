#include "header.h"

/********All elements which using in game********/
class Background { //Class for create background
public:
    Background() = default;

    ~Background() = default;

    Background(const std::string path_background_image) {
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

class Button { //Class for create button
public:
    Button() = default;

    ~Button() = default;

    Button(const sf::Vector2<float> size, const float thickness,
           const float pos_button_x, const float pos_button_y,
           sf::Color color_outline, sf::Color color_text,
           const int text_size, const std::string& path_font,
           const float pos_text_x, const float pos_text_y,
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

    void setColorText(sf::Color color_text) { //Setter for change color
        text.setColor(color_text);
    }

    void setColorFigure(sf::Color color_outline) { //Setter for change color
        figure.setOutlineColor(color_outline);
    }

    void drawButton(sf::RenderWindow& window) {
        window.draw(figure);
        window.draw(text);
    }

private:
    sf::RectangleShape figure;
    sf::Font font;
    sf::Text text;
    sf::Music music_touch;
    sf::Music music_press;
};