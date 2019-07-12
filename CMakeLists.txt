cmake_minimum_required(VERSION 3.1)

file(GLOB small_sorters_SRC
    "*.h"
    "*.cpp"
    "measurement/*.h"
    "measurement/*.cpp"
    "measurement/measurement_ipso/*.cpp"
    "networks/*.h"
    "sorters/*.h"
    "sorters/*.cpp"
    "environment/*.h"
    "environment/*.cpp"
    "lib/*.hpp"
    "include/*.hpp"
)

set(CMAKE_CXX_FLAGS "-O3 -lstdc++ -march=native -std=c++1z")
#set(CMAKE_CXX_FLAGS "-O0 -g -lstdc++ -DIGNORE_MEASUREMENT")

add_executable (SmallSortersPerformancing ${small_sorters_SRC})
