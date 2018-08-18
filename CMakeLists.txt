cmake_minimum_required(VERSION 3.9)

project(kosu)

add_compile_options(-std=c++17)

file(GLOB_RECURSE KOSU_SOURCES "*.cpp")
include_directories(".")

add_executable(kosu ${KOSU_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics window system)

target_link_libraries(kosu sfml-graphics sfml-window sfml-system)
