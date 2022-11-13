cmake_minimum_required(VERSION 3.16.3)
project(Checkers)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML/")

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(Checkers main.cpp engine/board.cpp engine/board.h
        interface/game.h interface/header.h
        interface/menu.h interface/menu.cpp
        interface/elements.h interface/elements.cpp
        interface/config.h interface/config.cpp
        interface/exitWindow.h interface/exitWindow.cpp
        interface/settings.h interface/settings.cpp
        interface/game_design.cpp interface/game_design.h
        interface/gameExitWindow.cpp interface/gameExitWindow.h
        interface/EndOfGameWindow.h interface/EndOfGameWindow.cpp)

target_link_libraries(Checkers sfml-graphics sfml-audio sfml-window)


