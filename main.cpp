
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


void SetOutputFile() {
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/output_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stdout);
}

#define ElementCount 4
void test()
{
    uint test[32];
    uint test_2[32];
    auto seed = time(NULL);
    for (int i = 0; i < 32; i += 1)
    {
        seed = seed * 48271 % 200000;
        test[i] = (int) seed;
    }
    test[0] = 55000;
    test[1] = 155000;
    for (int i = 0; i < 32; i += 1)
    {
        test_2[i] = test[i];
    }
    uint splitters[3];
    splitters[0] = 50000;
    splitters[1] = 100000;
    splitters[2] = 150000;

    printf("Array before: ");
    for (int i = 0; i < 32; i += 1)
    {
        printf("%u, ", test[i]);
    }
    printf("\n");
    SampleSort3Splitters2BlockSize(test, 32, splitters);
    printf("After samplesort: ");
    for (int i = 0; i < 32; i += 1)
    {
        printf("%u, ", test[i]);
    }
    printf("\n");
    insertionsort::InsertionSort(test_2, 32);
    printf("Correctly Sorted: ");
    for (int i = 0; i < 32; i += 1)
    {
        printf("%u, ", test_2[i]);
    }
    printf("\n");
}

#define NumberOfIterations 100
#define NumberOfMeasures 500

int main()
{
    auto seed = time(NULL);
    randomisation::SetSeed(seed);
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = Environment_GetComputerName();
    SetOutputFile();
    printf("General Info: Commit=%s, Hostname=%s\n", commit.c_str(), hostname.c_str());
    result::WriteAbbreviationExplanatoryLine();
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    {
        for (int arraySize = 2; arraySize <= 16; arraySize += 1)
        {
            measurement::MeasureSorting(perf_cpu_cycles, NumberOfIterations, arraySize, measureIteration);
        }
    }
    randomisation::SetSeed(seed);
    for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    {
        for (int arraySize = 2; arraySize <= 16; arraySize += 1)
        {
            measurement::MeasureRandomGenerationAndSortedChecking(perf_cpu_cycles, NumberOfIterations, arraySize, measureIteration);
        }
    }
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}