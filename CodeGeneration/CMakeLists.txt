cmake_minimum_required(VERSION 3.1)

file(GLOB generate_SRC
    "*.cc"
    "*.hpp"
    "nlohmann/*.hpp"
)

set(CMAKE_CXX_FLAGS "-g -lstdc++")

include_directories("./")

add_executable (Generate ${generate_SRC})