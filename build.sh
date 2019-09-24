mkdir build -p
cd build
cmake -DCMAKE_BUILD_TYPE=Release clear ..
cd CMakeFiles/SmallSortersPerformancing.dir
rm *.o
mkdir MeasurementIpso
cd MeasurementIpso
rm *.o
cd ../../..
make -j4