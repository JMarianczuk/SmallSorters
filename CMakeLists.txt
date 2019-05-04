cmake_minimum_required(VERSION 3.1)

file(GLOB small_sorters_SRC
    "*.h"
    "*.cpp"
    "MeasurementIpso/*.cpp"
    "lib/*.hpp"
    "include/*.hpp"
)

set(CMAKE_CXX_FLAGS "-O3 -lstdc++ -march=native")
#set(CMAKE_CXX_FLAGS "-O0 -g -lstdc++ -DIGNORE_MEASUREMENT")

add_executable (SmallSortersPerformancing ${small_sorters_SRC})
