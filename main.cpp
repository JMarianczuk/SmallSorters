
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

void test() {
    int a = 6, b = 4;
    SortableRef a1 = {6, 5}, b1 = {4, 7};
    Sortable_JumpXchg a2 = {6}, b2 = {4};
    Sortable_TwoCmovTemp a3 = {6}, b3 = {4};
    Sortable_ThreeCmovRegisterTemp a5 = {6}, b5 = {4};

    networks::ConditionalSwap(a, b);
    networks::ConditionalSwap(a1, b1);
    networks::ConditionalSwap(a2, b2);
    networks::ConditionalSwap(a3, b3);
    networks::ConditionalSwap(a5, b5);
}

#define NumberOfIterations 1000
#define NumberOfMeasures 100

int main()
{
    // srand(time(NULL));
    auto seed = time(NULL);
    randomisation::SetSeed(seed);
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
            measurement::MeasureSorting(perf, info, NumberOfIterations, arraySize);
        }
    }
    randomisation::SetSeed(seed);
    for (int numberOfMeasures = 0; numberOfMeasure < NumberOfMeasures; numberOfMeasure += 1)
    {
        for (int arraySize = 2; arraySize <= 16; arraySize += 1)
        {
            measurement::MeasureRandomGenerationAndSortedChecking(perf, info, NumberOfIterations, arraySize);
        }
    }
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}