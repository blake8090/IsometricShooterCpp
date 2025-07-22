cmake_minimum_required(VERSION 3.2)

add_executable(IsometricShooter "main.cpp" "engine.h" "engine.cpp")

target_link_libraries(IsometricShooter PRIVATE fmt::fmt raylib)

set_target_properties( ${CMAKE_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )
