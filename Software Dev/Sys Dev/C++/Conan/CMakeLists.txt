cmake_minimum_required(VERSION 3.28.3)
project(Conan Reference)

find_package(mylib REQUIRED)

include_directories(include)

add_executable(${PROJECT_NAME} src/main.cpp )

target_link_libraries(${PROJECT_NAME} glib::glib-2.0)
target_link_libraries(${PROJECT_NAME} glib::gio-2.0)
