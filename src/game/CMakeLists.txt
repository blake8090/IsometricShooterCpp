cmake_minimum_required(VERSION 3.2)

add_library(game STATIC "mainmenu.cpp")

target_link_libraries(game PRIVATE engine fmt::fmt raylib)
