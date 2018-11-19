
#include <stdexcept>

#include "Performancing.h"
#include "InsertionSort.h"
#include "NetworkSort.h"
#include "Result.h"

using namespace std;

void GenerateRandomArray(Sortable* arr) {
    void* pointer = (void*) rand();
	for (int i = 0; i < size; i += 1)
	{
		arr[i].key = rand();
        arr[i].pointer = pointer + i;
	}
	return arr;
}

void CopyArray(Sortable* source, Sortable* destination) {
    for (int i = 0; i < ArraySize; i += 1) {
        destination[i] = source[i];
    }
}

void ThrowIfNotSorted(Sortable* items) {
    for (int i = 0; i < ArraySize - 1; i += 1) {
        if (items[i].key > items[i + 1].key) {
            throw logic_error("Array not sorted");
        }
    }
}

int main()
{
	auto perf = new Performancing(PerformanceMetric::CPU_CYCLES);

    Sortable* arr = (Sortable*) malloc(ArraySize * sizeof(Sortable));
    Sortable* copy = (Sortable*) malloc(ArraySize * sizeof(Sortable));
	for (int iteration = 0; iteration < 20; iteration += 1)
	{
        GenerateRandomArray(arr);

        CopyArray(arr, copy);
		perf->StartMeasuring();
		InsertionSort(copy);
		perf->StopMeasuring();

        ThrowIfNotSorted(arr);
		WriteResultLine(
			Sorter::INSERTION_SORT, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );

        CopyArray(arr, copy);
        perf->StartMeasuring();
        NetworkSort_Naive(copy);
        perf->StopMeasuring();

        ThrowIfNotSorted(copy);
        WriteResultLine(
			Sorter::SORTING_NETWORK_NAIVE, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );

        CopyArray(arr, copy);
        perf->StartMeasuring();
        NetworkSort_Optimised(copy);
        perf->StopMeasuring();

        ThrowIfNotSorted(copy);
        WriteResultLine(
			Sorter::SORTING_NETWORK_OPTIMISED, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );
	}

    free(arr);
    free(copy);
	
	delete perf;

	return 0;
}