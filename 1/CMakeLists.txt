cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)

#find_package(nlohmann_json 3.12.0 REQUIRED)
#add_library())
add_executable(main1 src/main1.cpp inc/main1.hpp)
target_include_directories(main1 PUBLIC inc)
#target_link_libraries(main1 PRIVATE nlohmann_json::nlohmann_json)
