
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


void SetOutputFile() {
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/output_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stdout);
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
    printf("General Info: Commit=%s, Hostname=%s", commit.c_str(), hostname.c_str());
    WriteAbbreviationExplanatoryLine();
    
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