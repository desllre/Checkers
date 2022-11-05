#include "header.h"

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

    Button(sf::Vector2<float> size, float thickness,
           float pos_button_x, float pos_button_y,
           sf::Color color_outline, sf::Color color_text,
           int text_size, const std::string& path_font,
           float pos_text_x, float pos_text_y,
           const std::string& string_music_touch,
           const std::string& string_music_press,
           const std::string& string_text); //Construction for buttons

    void setColorText(sf::Color color_text); //Setter for change color

    void setColorFigure(sf::Color color_outline); //Setter for change color

    void drawButton(sf::RenderWindow& window); //Draw buttons

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

    Arrow(sf::Vector2<float> size, float pos_arrow_left_x, float pos_arrow_left_y, float pos_arrow_right_x,
          float pos_arrow_right_y, const std::string &path_arrow_right, const std::string &path_arrow_left,
          const std::string &string_music_touch, const std::string &string_music_press); //Construction for arrow

    ~Arrow() = default;

    void drawArrow(sf::RenderWindow &window); //Draw arrow

    void changeArrowLeftColor(const std::string &path_arrow); //Change left arrow's color

    void changeArrowRightColor(const std::string &path_arrow_right); //Change right arrow's color

private:
    sf::Texture texture_arrow_left;
    sf::Texture texture_arrow_right;
    sf::Sprite sprite_arrow_left;
    sf::Sprite sprite_arrow_right;
    sf::Music music_touch;
    sf::Music music_press;
};