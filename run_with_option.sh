mkdir result -p
cd build
taskset 0x1 ./SmallSortersPerformancing $1
cd ../result/data
bzip2 *.txt