# CMakeList.txt : CMake project for Performancing, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Add source to this project's executable.
file(GLOB small_sorters_SRC
    "*.h"
    "*.cpp"
)

set(CMAKE_CXX_FLAGS "-g3")

add_executable (SmallSortersPerformancing ${small_sorters_SRC})

# TODO: Add tests and install targets if needed.
