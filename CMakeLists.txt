cmake_minimum_required(VERSION 3.10)
project(TowerDefense)

# Définir la version de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les fichiers sources
add_executable(TowerDefense main.cpp)

# Rechercher SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
set(CMAKE_PREFIX_PATH "C:/msys64/mingw64")

# Lier SFML au projet
target_link_libraries(TowerDefense sfml-graphics sfml-window sfml-system)

# Inclure les headers SFML si nécessaire
target_include_directories(TowerDefense PRIVATE ${SFML_INCLUDE_DIR})
