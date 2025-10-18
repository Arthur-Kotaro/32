cmake_minimum_required(VERSION 3.30)
project(32)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)


add_subdirectory(1)
add_subdirectory(2)
add_subdirectory(3)
