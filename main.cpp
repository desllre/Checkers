#include "interface/game.h"

int main() {

    sf::Music bgMusic;
    bgMusic.openFromFile("../songs/bgMusic.wav");
    bgMusic.setVolume(8);
    bgMusic.setLoop(true);
    bgMusic.play();

    game();

    return 0;
}
