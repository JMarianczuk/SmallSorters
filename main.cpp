
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

#include "Performancing.h"
#include "InsertionSort.h"
#include "BestNetworks.generated.h"
#include "BoseNelson.generated.h"
#include "Result.h"
#include "GitInfo.h"
#include "EnvironmentInfo.h"
#include "Randomisation.h"
#include "ArrayHelpers.h"
#include "Sortable.generated.h"
#include "Measurement.generated.h"
#include "SampleSort.generated.h"
#include "QuickSort.h"


void SetOutputFile() {
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/output_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stdout);
}

#define ElementCount 128
void test()
{
    uint test[ElementCount];
    uint test_2[ElementCount];
    auto seed = time(NULL);
    for (int i = 0; i < ElementCount; i += 1)
    {
        seed = seed * 48271 % 200000;
        test[i] = (int) seed;
    }
    for (int i = 0; i < ElementCount; i += 1)
    {
        test_2[i] = test[i];
    }

    printf("Array before: ");
    for (int i = 0; i < ElementCount; i += 1)
    {
        printf("%u, ", test[i]);
    }
    printf("\n");
    samplesort::SampleSort3Splitters5OversamplingFactor5BlockSize(test, ElementCount, 16, &networks::sortNbest<uint>);
    printf("After samplesort: ");
    for (int i = 0; i < ElementCount; i += 1)
    {
        printf("%u, ", test[i]);
    }
    printf("\n");
    insertionsort::InsertionSort(test_2, ElementCount);
    printf("Correctly Sorted: ");
    for (int i = 0; i < ElementCount; i += 1)
    {
        printf("%u, ", test_2[i]);
    }
    printf("\n");
}



#define NumberOfIterations 100
#define NumberOfMeasures 500
#define SmallestArraySize 2
#define LargestArraySize 16

void badSort(SortableRef* arr, size_t arraySize)
{
    for (int i = 0; i < arraySize; i += 1)
    {
        arr[i].key = i;
    }
}
void badSort2(SortableRef* arr, size_t arraySize)
{
    SortableRef first = arr[0];
    for (int i = 0; i < arraySize - 1; i += 1)
    {
        arr[i] = arr[i+1];
    }
    arr[arraySize - 1] = first;
}

void testPermutationCheck()
{
    SetOutputFile();
    randomisation::SetSeed(time(NULL));
    auto perf = new Performancing(PerformanceMetric::CPU_CYCLES);
    printf("Testing Bad Sort that ignores permutation\n");
    measurement::Measure<SortableRef>(perf, NumberOfIterations, 16, 0, "BadSort", &badSort);
    printf("Testing Bad Sort that ignores sorting\n");
    measurement::Measure<SortableRef>(perf, NumberOfIterations, 16, 0, "BadSort", &badSort2);
    printf("Testing Bad Sort that sorts correctly\n");
    measurement::Measure<SortableRef>(perf, NumberOfIterations, 16, 0, "BadSort", &insertionsort::InsertionSort<SortableRef>);
    delete perf;
}

void testQuickSort()
{
    randomisation::SetSeed(time(NULL));
    size_t totalArraySize = 1024 * 1024;
    printf("before array allocation\n");
    SortableRef *arr = (SortableRef*) malloc(sizeof(SortableRef) * totalArraySize);
    printf("before array random generation\n");
    randomisation::GenerateRandomArray(arr, totalArraySize);
    uint64_t permutation_key_iter = 1;
    uint64_t permutation_reference_iter = 1;
    uint64_t permutation_key_value;
    uint64_t permutation_reference_value;

    printf("before permutation values\n");
    permutation_key_value = GetPermutationValue(arr, totalArraySize, &GetKey<SortableRef>, permutation_key_iter);
    permutation_reference_value = GetPermutationValue(arr, totalArraySize, &GetReference<SortableRef>, permutation_reference_iter);

    printf("before quick sort\n");
    quicksort::QuickSort(arr, totalArraySize, &networks::sortNbest);
    printf("after quick sort\n");

    if (!IsSorted(arr, totalArraySize) 
        || !CheckPermutationValue(arr, totalArraySize, &GetKey<SortableRef>, permutation_key_iter, permutation_key_value)
        || !CheckPermutationValue(arr, totalArraySize, &GetReference<SortableRef>, permutation_reference_iter, permutation_reference_value))
    {
        printf("Wrong sort!\n");
    }
}

int main()
{
    // testQuickSort();
    // return 0;
    uint64_t seed;
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = Environment_GetComputerName();
    SetOutputFile();
    printf("General Info: Commit=%s, Hostname=%s\n", commit.c_str(), hostname.c_str());
    result::WriteAbbreviationExplanatoryLine();
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    {
        seed = time(NULL);
        for (int arraySize = SmallestArraySize; arraySize <= LargestArraySize; arraySize += 1)
        {
            measurement::MeasureSorting(perf_cpu_cycles, seed, NumberOfIterations, arraySize, measureIteration);
        }
    }
    // randomisation::SetSeed(seed);
    // for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    // {
    //     for (int arraySize = SmallestArraySize; arraySize <= LargestArraySize; arraySize += 1)
    //     {
    //         measurement::MeasureRandomGenerationAndSortedChecking(perf_cpu_cycles, NumberOfIterations, arraySize, measureIteration);
    //     }
    // }
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}