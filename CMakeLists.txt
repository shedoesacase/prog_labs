cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "0" CACHE INTERNAL "Patch version") #третья цифра версии

set(PROJECT_VERSION_MAJOR 1) #собирается строка версии
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH ${PATCH_VERSION})

project(helloworld VERSION
    ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

configure_file(version.h.in version.h @ONLY) #генерируется заголвочный файл

add_executable(helloworld_cli main.cpp)


target_include_directories(helloworld_cli PRIVATE "${CMAKE_BINARY_DIR}") #добавляется путь где появится
