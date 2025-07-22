cmake_minimum_required(VERSION 3.2)

project(IsometricShooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)

add_subdirectory(src)
