
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

#include "Performancing.h"
#include "InsertionSort.h"
#include "NetworkSort.h"
#include "NetworkSort_Simple.h"
#include "Result.h"
#include "GitInfo.h"
#include "EnvironmentInfo.h"
#include "Randomisation.h"
#include "ArrayHelpers.h"

void PrintArray(std::string descriptor, Sortable* arr) {
    printf("%s: \nKeys: ", descriptor.c_str());
    for (int i = 0; i < ArraySize; i += 1) {
        printf("%i: %" PRIu64 ", ", i, arr[i].key);
    }
    printf("\nReferences: ");
    for (int i = 0; i < ArraySize; i += 1) {
        printf("%i: %" PRIu64 ", ", i, arr[i].reference);
    }
    printf("\n");
    
}

template <typename TValueType>
void MeasureInsertionSort(
    Performancing* perf, 
    EnvironmentInfo info, 
    int numberOfIterations, 
    int arraySize,
    std::string sorterName) 
{
    TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));
    
    int numberOfBadSorts = 0;
    GenerateRandomArray(arr, arraySize);
    insertionsort::InsertionSort(arr, arraySize);
    if (!IsSorted(arr, arraySize)) 
    {
        numberOfBadSorts += 1;
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        GenerateRandomArray(arr, arraySize);
        insertionsort::InsertionSort(arr, arraySize);
        if (!IsSorted(arr, arraySize))
        {
            numberOfBadSorts += 1;
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        sorterName,
        perf,
        info,
        arraySize,
        numberOfIterations,
        numberOfBadSorts
    );

    free(arr);
}

template <typename TValueType>
void MeasureNetworkSort(
    Performancing* perf, 
    EnvironmentInfo info, 
    int numberOfIterations, 
    int arraySize,
    std::string sorterName) 
{
    TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));

    int numberOfBadSorts = 0;
    GenerateRandomArray(arr, arraySize);
    networks::sortN(arr, arraySize);
    if (!IsSorted(arr, arraySize)) 
    {
        numberOfBadSorts += 1;
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        GenerateRandomArray(arr, arraySize);
        networks::sortN(arr, arraySize);
        if (!IsSorted(arr, arraySize)) 
        {
            numberOfBadSorts += 1;
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        sorterName,
        perf,
        info,
        arraySize,
        numberOfIterations,
        numberOfBadSorts
    );

    free(arr);
}

void SetOutputFile() {
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/output_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stdout);
}

void test() {
    int a = 6, b = 4;
    Sortable a1 = {6, 5}, b1 = {4, 7};
    Sortable_JumpXchg a2 = {6}, b2 = {4};
    Sortable_TwoCmovTemp a3 = {6}, b3 = {4};
    Sortable_ThreeCmovVolatileTemp a4 = {6}, b4 = {4};
    Sortable_ThreeCmovRegisterTemp a5 = {6}, b5 = {4};

    networks::ConditionalSwap(a, b);
    networks::ConditionalSwap(a1, b1);
    networks::ConditionalSwap(a2, b2);
    networks::ConditionalSwap(a3, b3);
    networks::ConditionalSwap(a4, b4);
    networks::ConditionalSwap(a5, b5);
}

#define NumberOfIterations 1000

int main()
{
    srand(time(NULL));
    // test();
    // return 0;
    SetOutputFile();
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = Environment_GetComputerName();

    printf("Commit: %s\n", commit.c_str());
    printf("Computer Name: %s \n", hostname.c_str());

    EnvironmentInfo info;
    info.commit = commit;
    info.hostname = hostname;
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    for (int arraySize = 2; arraySize <= 16; arraySize += 1)
    {
        MeasureNetworkSort<Sortable>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-Tuple");
        MeasureNetworkSort<Sortable_JumpXchg>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-JumpXchg");
        MeasureNetworkSort<Sortable_TwoCmovTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-TwoCmovTemp");
        MeasureNetworkSort<Sortable_ThreeCmovVolatileTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-ThreeCmovVolatileTempl");
        MeasureNetworkSort<Sortable_ThreeCmovRegisterTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-ThreeCmovRegisterTemp");
        MeasureInsertionSort<Sortable>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Insertion Sort Key-Reference-Tuple");
        MeasureInsertionSort<Sortable_JumpXchg>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Insertion Sort Key-Only");
    }
    // Measure(perf_cpu_cycles, 1000, info);	
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // Measure(perf_cache_misses, 1000, info);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // Measure(perf_branch_misses, 1000, info);
    // delete perf_branch_misses;

	return 0;
}