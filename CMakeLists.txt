cmake_minimum_required(VERSION 3.23)
project(Checkers)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML/")

find_package(SFML COMPONENTS graphics audio REQUIRED)
add_executable(Checkers main.cpp interface/game.h interface/header.h interface/menu.h interface/elements.h)
target_link_libraries(Checkers sfml-graphics sfml-audio sfml-window)

