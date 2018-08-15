cmake_minimum_required(VERSION 3.9)

project(kosu)

file(GLOB KOSU_SOURCES "*.cpp")

add_executable(kosu ${KOSU_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics window system)

target_link_libraries(kosu sfml-graphics sfml-window sfml-system)
