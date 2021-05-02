cmake_minimum_required(VERSION 3.19)
project(stream_game_01)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)


add_executable(stream_game_01 main.cpp game_state.cpp game_state.h)

target_link_libraries(stream_game_01 sfml-graphics sfml-system sfml-window)