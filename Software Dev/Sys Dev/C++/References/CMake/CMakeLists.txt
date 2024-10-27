cmake_minimum_required(VERSION 3.29.3)

project('Tut')
find_package(SFML REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test sfml::sfml)
