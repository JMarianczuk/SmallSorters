cmake_minimum_required (VERSION 3.10)

file(GLOB small_sorters_SRC
    "*.h"
    "*.cpp"
)

set(CMAKE_CXX_FLAGS "-O3 -lstdc++")

add_executable (SmallSortersPerformancing ${small_sorters_SRC})
