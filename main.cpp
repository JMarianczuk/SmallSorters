
#include <stdexcept>

#include "Performancing.h"
#include "InsertionSort.h"
#include "NetworkSort.h"
#include "Result.h"

Sortable* GenerateRandomArray(int size) {
    Sortable* arr = (Sortable*) malloc(size * sizeof(Sortable));
    void* pointer = (void*) rand();
	for (int i = 0; i < size; i += 1)
	{
		arr[i].key = rand();
        arr[i].pointer = pointer + i;
	}
	return arr;
}

Sortable* CopyArray(Sortable* items, int count) {
    Sortable* arr = (Sortable*) malloc(count * sizeof(Sortable));
    for (int i = 0; i < count; i += 1) {
        arr[i] = items[i];
    }
}

void ThrowIfNotSorted(Sortable* items, int count) {
    for (int i = 0; i < count - 1; i += 1) {
        if (items[i].key > items[i + 1].key) {
            throw logic_error("Array not sorted");
        }
    }
}

int main()
{
	auto perf = new Performancing(PerformanceMetric::CPU_CYCLES);

	for (int iteration = 0; iteration < 20; iteration += 1)
	{
        Sortable* arr = GenerateRandomArray(ArraySize);

        Sortable* copy = CopyArray(arr, ArraySize);
		perf->StartMeasuring();
		InsertionSort(copy);
		perf->StopMeasuring();

        ThrowIfNotSorted(arr, ArraySize);
		WriteResultLine(
			Sorter::INSERTION_SORT, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );

        free(copy);
        copy = CopyArray(arr, ArraySize);
        perf->StartMeasuring();
        NetworkSort_Naive(copy);
        perf->StopMeasuring();

        ThrowIfNotSorted(copy, ArraySize);
        WriteResultLine(
			Sorter::SORTING_NETWORK_NAIVE, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );

        free(copy);
        copy = CopyArray(arr, ArraySize);
        perf->StartMeasuring();
        NetworkSort_Optimised(copy);
        perf->StopMeasuring();

        ThrowIfNotSorted(copy, ArraySize);
        WriteResultLine(
			Sorter::SORTING_NETWORK_OPTIMISED, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration
        );

        free(copy);
        free(arr);
	}
	
	delete perf;

	return 0;
}