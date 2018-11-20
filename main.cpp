
#include <stdexcept>
#include <string>

#include "Performancing.h"
#include "InsertionSort.h"
#include "NetworkSort.h"
#include "Result.h"

using namespace std;

void GenerateRandomArray(Sortable* arr) {
    int pointer = rand();
	for (int i = 0; i < ArraySize; i += 1)
	{
		arr[i].key = rand();
        arr[i].pointer = pointer + i;
	}
}

void CopyArray(Sortable* source, Sortable* destination) {
    for (int i = 0; i < ArraySize; i += 1) {
        destination[i] = source[i];
    }
}

bool IsSorted(Sortable* items) {
    for (int i = 0; i < ArraySize - 1; i += 1) {
        if (items[i].key > items[i + 1].key) {
            return false;
        }
    }
    return true;
}

void PrintArray(string descriptor, Sortable* arr) {
    printf("%s: ", descriptor.c_str());
    for (int i = 0; i < ArraySize; i += 1) {
        printf("%i, ", arr[i].key);
    }
    printf("\n");
}

void MeasureInsertionSort(Sortable* arr, Performancing* perf) {
    perf->StartMeasuring();
    InsertionSort(arr);
    perf->StopMeasuring();
}

void Measure(Performancing* perf) {
    Sortable* arr = (Sortable*) malloc(ArraySize * sizeof(Sortable));
    Sortable* copy = (Sortable*) malloc(ArraySize * sizeof(Sortable));

	for (int iteration = 0; iteration < 20; iteration += 1)
	{
        GenerateRandomArray(arr);

        CopyArray(arr, copy);
		perf->StartMeasuring();
		InsertionSort(copy);
		perf->StopMeasuring();

        if (IsSorted(copy)) {
            WriteResultLine(
                Sorter::INSERTION_SORT, 
                perf, 
                iteration
            );
        } else {
            PrintArray("Original Array", arr);
            PrintArray("Did not sort INSERTION SORT:", copy);
        }
		

        CopyArray(arr, copy);
        perf->StartMeasuring();
        NetworkSort_Naive(copy);
        perf->StopMeasuring();

        if (IsSorted(copy)) {
            WriteResultLine(
                Sorter::SORTING_NETWORK_NAIVE, 
                perf, 
                iteration
            );
        } else {
            PrintArray("Original Array", arr);
            PrintArray("Did not sort NETWORK SORT NAIVE:", copy);
        }
        

        CopyArray(arr, copy);
        perf->StartMeasuring();
        NetworkSort_Optimised(copy);
        perf->StopMeasuring();

        if (IsSorted(copy)) {
            WriteResultLine(
                Sorter::SORTING_NETWORK_OPTIMISED, 
                perf, 
                iteration
            );
        } else {
            PrintArray("Original Array", arr);
            PrintArray("Did not sort NETWORK SORT OPTIMISED:", copy);
        }
        
	}

    free(arr);
    free(copy);
}

int main()
{
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    Measure(perf_cpu_cycles);	
	delete perf_cpu_cycles;

    auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    Measure(perf_cache_misses);
    delete perf_cache_misses;

    auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    Measure(perf_branch_misses);
    delete perf_branch_misses;

	return 0;
}