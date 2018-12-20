mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cd CMakeLists/SmallSortersPerformancing.dir
rm *.o
cd ../..
make