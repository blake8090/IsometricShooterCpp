cmake_minimum_required(VERSION 3.2)

add_library(engine STATIC "engine.cpp" "state.h" "assets.cpp")

target_link_libraries(engine PRIVATE fmt::fmt raylib)
