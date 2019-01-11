
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

#include "Performancing.h"
#include "InsertionSort.h"
#include "NetworkSort_Simple.h"
#include "Result.h"
#include "GitInfo.h"
#include "EnvironmentInfo.h"
#include "Randomisation.h"
#include "ArrayHelpers.h"

void PrintArray(std::string descriptor, SortableRef_ClangVersion* arr) {
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
        sizeof(TValueType),
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
        sizeof(TValueType),
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
    SortableRef a1 = {6, 5}, b1 = {4, 7};
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
#define NumberOfMeasures 100

int main()
{
    // srand(time(NULL));
    auto seed = time(NULL);
    SetSeed(seed);
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = Environment_GetComputerName();
    SetOutputFile();

    EnvironmentInfo info;
    info.commit = commit;
    info.hostname = hostname;
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    for (int numberOfMeasures = 0; numberOfMeasures < NumberOfMeasures; numberOfMeasures += 1)
    {
        for (int arraySize = 2; arraySize <= 16; arraySize += 1)
        {
            MeasureNetworkSort<SortableRef>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-Tuple");

            // MeasureNetworkSort<Sortable_JumpXchg>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-JumpXchg");
            MeasureNetworkSort<SortableRef_JumpXchg>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-JumpXchg");

            // MeasureNetworkSort<Sortable_TwoCmovTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-TwoCmovTemp");
            MeasureNetworkSort<SortableRef_FourCmovTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-FourCmovTemp");

            // MeasureNetworkSort<Sortable_ThreeCmovVolatileTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-ThreeCmovVolatileTempl");
            MeasureNetworkSort<SortableRef_SixCmovVolatileTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-SixCmovVolatileTempl");

            // MeasureNetworkSort<Sortable_ThreeCmovRegisterTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-ThreeCmovRegisterTemp");
            MeasureNetworkSort<SortableRef_SixCmovRegisterTemp>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-SixCmovRegisterTemp");

            MeasureNetworkSort<SortableRef_ClangVersion>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Network Key-Reference-ClangVersion");

            // MeasureInsertionSort<Sortable_JumpXchg>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Insertion Sort Key-Only");
            MeasureInsertionSort<SortableRef>(perf_cpu_cycles, info, NumberOfIterations, arraySize, "Insertion Sort Key-Reference-Tuple");
        }
    }
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}