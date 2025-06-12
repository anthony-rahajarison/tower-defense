cmake_minimum_required(VERSION 3.10)
project(TowerDefense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_PREFIX_PATH "C:/msys64/mingw64")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(TowerDefense     src/main.cpp
    src/MainMenu.cpp
    src/Game.cpp  
    src/tower.cpp 
    src/player.cpp
    src/enemy.cpp
    src/projectile.cpp
    src/position.cpp)

# ${SOURCES}

target_include_directories(TowerDefense PRIVATE include ${SFML_INCLUDE_DIR})


target_link_libraries(TowerDefense sfml-graphics sfml-window sfml-system sfml-audio)