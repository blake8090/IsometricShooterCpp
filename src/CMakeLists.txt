cmake_minimum_required(VERSION 3.2)

add_executable(${CMAKE_PROJECT_NAME} "main.cpp")

add_subdirectory(engine)
add_subdirectory(game)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE engine game fmt::fmt raylib)

set_target_properties( ${CMAKE_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )
