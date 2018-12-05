
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

uint64_t GenerateRandomUint64() {
    uint64_t number = rand();
    for (int i = 0; i < 3; i += 1) {
        number = (number << 16) | rand();
    }
    return number;
}

void GenerateRandomArray(Sortable* arr, uint64_t limit) {
    uint64_t pointer = GenerateRandomUint64() % limit;
	for (int i = 0; i < ArraySize; i += 1)
	{
		arr[i].key = GenerateRandomUint64() % limit;
        arr[i].reference = (pointer + i) % limit;
	}
}
void GenerateRandomArray(Sortable* arr) {
    uint64_t max = 1 << 20;
    max -= 1;
    max << 1;
    max += 1;
    printf("Max uint: %" PRIu64 "\n", max);
    GenerateRandomArray(arr, max);
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

bool IsPermutation(Sortable* arr, Sortable* reference) {
    for (int i = 0; i < ArraySize; i += 1) {
        bool isIncluded = false;
        for (int j = 0; j < ArraySize; j += 1) {
            if (arr[i].key == reference[j].key) {
                isIncluded = true;
                break;
            }
        }
        if (!isIncluded) {
            return false;
        }
    }
    return true;
}

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

void MeasureInsertionSort(Sortable* arr, Performancing* perf) {
    perf->StartMeasuring();
    InsertionSort(arr);
    perf->StopMeasuring();
}

void Measure(Performancing* perf, int numberOfIterations, EnvironmentInfo info) {
    Sortable* arr = (Sortable*) malloc(ArraySize * sizeof(Sortable));
    
    int numberOfBadSorts = 0;
    GenerateRandomArray(arr);
    InsertionSort(arr);
    if (!IsSorted(arr)) {
        numberOfBadSorts += 1;
        PrintArray("Did not sort warmup Insertion sort", arr);
    }

    perf->StartMeasuring();    
    for (int i = 0; i < numberOfIterations; i += 1) {
        GenerateRandomArray(arr);
        InsertionSort(arr);
        if (!IsSorted(arr)) {
            numberOfBadSorts += 1;
            PrintArray("Did not sort insertion sort", arr);
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        "Insertion Sort",
        perf,
        info,
        numberOfIterations,
        numberOfBadSorts
    );



    numberOfBadSorts = 0;
    GenerateRandomArray(arr);
    NetworkSort_Naive(arr);
    if (!IsSorted(arr)) {
        numberOfBadSorts += 1;
        PrintArray("Did not sort warmup network sort naive", arr);
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1) {
        GenerateRandomArray(arr);
        NetworkSort_Naive(arr);
        if (!IsSorted(arr)) {
            numberOfBadSorts += 1;
            PrintArray("Did not sort network sort naive", arr);
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        "Network Sort Naive",
        perf,
        info,
        numberOfIterations,
        numberOfBadSorts
    );



    numberOfBadSorts = 0;
    GenerateRandomArray(arr);
    NetworkSort_Optimised(arr);
    if (!IsSorted(arr)) {
        numberOfBadSorts += 1;
        PrintArray("Did not sort warmup network sort optimised", arr);
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1) {
        GenerateRandomArray(arr);
        NetworkSort_Optimised(arr);
        if (!IsSorted(arr)) {
            numberOfBadSorts += 1;
            PrintArray("Did not sort network sort optimised", arr);
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        "Network Sort Optimised",
        perf,
        info,
        numberOfIterations,
        numberOfBadSorts
    );
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
    Sortable* arr = (Sortable*) malloc(ArraySize * sizeof(Sortable));
    Sortable* copy = (Sortable*) malloc(ArraySize * sizeof(Sortable));
    
    GenerateRandomArray(arr, 100);
    PrintArray("Source", arr);

    CopyArray(arr, copy);
    SortTestJumpXchg(copy);
    if (!IsSorted(copy) || !IsPermutation(copy, arr)) {
        PrintArray("JumpXchg", copy);
    }

    CopyArray(arr, copy);
    SortTestTwoCmovTemp(copy);
    if (!IsSorted(copy) || !IsPermutation(copy, arr)) {
        PrintArray("TwoCmovTemp", copy);
    }

    CopyArray(arr, copy);
    SortTestThreeCmovVolatileTemp(copy);
    if (!IsSorted(copy) || !IsPermutation(copy, arr)) {
        PrintArray("ThreeCmovVolatileTemp", copy);
    }

    CopyArray(arr, copy);
    SortTestThreeCmovRegisterTemp(copy);
    if (!IsSorted(copy) || !IsPermutation(copy, arr)) {
        PrintArray("ThreeCmovRegisterTemp", copy);
    }
}

int main()
{
    srand(time(NULL));
    test();
    return 0;
    SetOutputFile();
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = Environment_GetComputerName();

    printf("Commit: %s\n", commit.c_str());
    printf("Computer Name: %s \n", hostname.c_str());

    EnvironmentInfo info;
    info.commit = commit;
    info.hostname = hostname;
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    Measure(perf_cpu_cycles, 1000, info);	
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // Measure(perf_cache_misses, 1000, info);
    // delete perf_cache_misses;

    auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    Measure(perf_branch_misses, 1000, info);
    delete perf_branch_misses;

	return 0;
}