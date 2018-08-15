cmake_minimum_required(VERSION 3.9)

project(kosu)

add_executable(kosu main.cpp)

find_package(SFML 2.5 COMPONENTS graphics window system)

target_link_libraries(kosu sfml-graphics sfml-window sfml-system)
