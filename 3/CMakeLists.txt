cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)


add_executable(main3 record.pb.cc record.pb.h)
target_include_directories(main3 PUBLIC inc)