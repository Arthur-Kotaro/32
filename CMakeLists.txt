cmake_minimum_required(VERSION 3.30)
project(32)

set(CMAKE_CXX_STANDARD 17)


set(JSON_BuildTest OFF CACHE INTERNAL "")

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)


include_directories(FilmLib/inc)

add_library(flmLib STATIC FilmLib/inc/film.hpp FilmLib/src/film.cpp )
add_subdirectory(2)
add_subdirectory(3)
