cmake_minimum_required(VERSION 3.16.3)
project(Checkers)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML/")

find_package(SFML COMPONENTS graphics audio REQUIRED)
add_executable(Checkers main.cpp interface/game.h interface/header.h
        interface/menu.h interface/menu.cpp interface/elements.h interface/elements.cpp
        interface/config.h interface/config.cpp interface/exitWindow.h interface/exitWindow.cpp engine/board.h engine/board.cpp)
target_link_libraries(Checkers sfml-graphics sfml-audio sfml-window)

