#include "header.h"
#pragma once

/********All elements which using in game********/
class Background { //Class for create background
public:
    Background() = default;

    ~Background() = default;

    explicit Background(const std::string& path_background_image); //Construction for background

    void drawBackground(sf::RenderWindow& window); //Draw background

private:
    sf::Texture texture_background;
    sf::Sprite sprite_background;
};

class Button { //Class for create button
public:
    Button() = default;

    ~Button() = default;

    Button(const sf::Vector2<float> &size, float thickness,
           float pos_button_x, float pos_button_y,
           sf::Color color_outline, sf::Color color_text,
           int text_size, const std::string& path_font,
           float pos_text_x, float pos_text_y,
           const std::string& string_music_touch,
           const std::string& string_music_press,
           const std::string& string_text); //Construction for buttons

    Button(const sf::Vector2<float> &size, float thickness,
           float pos_button_x, float pos_button_y,
           sf::Color color_outline, sf::Color color_text,
           int text_size, const std::string& path_font,
           float pos_text_x, float pos_text_y,
           const std::string& string_text); //Construction for buttons

    void setColorText(sf::Color color_text); //Setter for change color

    void setColorFigure(sf::Color color_outline); //Setter for change color

    void drawButton(sf::RenderWindow& window); //Draw buttons

    void playSongsPress(); //Play song

private:
    sf::RectangleShape figure;
    sf::Font font;
    sf::Text text;
    sf::Music music_touch;
    sf::Music music_press;
};

class Arrow { //Class for create arrow
public:
    Arrow() = default;

    Arrow(sf::Vector2<float> size_arrow, float pos_arrow_x, float pos_arrow_y,
          const std::string &path_arrow, const std::string &path_arrow_activated,
          const std::string &string_music_touch, const std::string &string_music_press); //Construction for arrow

    ~Arrow() = default;

    void drawArrow(sf::RenderWindow &window); //Draw arrow

    void playSongsPress(); //Play song

    void setColor(bool is_on_arrow); //Change left arrow's color

private:
    sf::Texture texture_arrow_activated;
    sf::Texture texture_arrow;
    sf::Sprite sprite_arrow;
    sf::Music music_touch;
    sf::Music music_press;
};

class Text {
public:
    Text() = default;

    Text(const sf::Vector2<float> &size, float thickness,
         float pos_figure_x, float pos_figure_y,
         sf::Color color_outline, sf::Color color_text,
         int text_size, const std::string& path_font,
         const std::string& string_text,
         float pos_text_x, float pos_text_y);

    ~Text() = default;

    void drawText(sf::RenderWindow &window); //For draw text

protected:
    sf::RectangleShape figure;
    sf::Text text;
    sf::Font font;
};

class InputFieldRounds : public Text { // Class for working with name input fields
public:
    InputFieldRounds() = default;

    ~InputFieldRounds() = default;

    InputFieldRounds(const sf::Vector2<float> &size, float thickness,
                     float pos_figure_x, float pos_figure_y,
                     sf::Color color_outline, sf::Color color_text,
                     int text_size, const std::string& path_font,
                     const std::string& string_text,
                     float pos_text_x, float pos_text_y);

    void setValue(bool is_mouse_on_left_round_arrows,
                  bool is_mouse_on_right_round_arrows,
                  bool is_mouse_pressed); //Set rounds

    std::string getValue(); //Get number of round

private:
    int num = 1;
    std::string number_of_round = "1";
};