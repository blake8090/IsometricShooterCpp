cmake_minimum_required(VERSION 3.2)

add_library(engine STATIC
        "engine.cpp" "state.h" "assets.cpp"
        render/renderer.cpp
        render/shapes.h
        projection.cpp
        box.h
        actor.h
        world.h
        world.cpp
)
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine PRIVATE fmt::fmt raylib)
