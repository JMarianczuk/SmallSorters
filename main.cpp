
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
#include "CommandLineOptions.h"
#include "DebugHelper.h"


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
#define NumberOfIterationsCompleteSort 20
#define NumberOfMeasures 500
#define NumberOfMeasuresInRow 10
#define SmallestArraySize 2
#define LargestArraySize 16
#define CompleteSortArraySize 1024 * 16

int main(int argumentCount, char** arguments)
{
    auto options = commandline::ParseOptions(arguments, argumentCount);
    if (options.HelpRequested 
        || !options.ParsingSuccessful 
        || (!options.MeasureNormal && !options.MeasureInRow && !options.MeasureCompleteSort))
    {
        commandline::PrintHelpText(std::cout);
        return 0;
    }
    uint64_t seed;
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = environment::GetComputerName();
    SetOutputFile();
    printf("General Info: Commit=%s, Hostname=%s\n", commit.c_str(), hostname.c_str());
    size_t cacheSize = environment::GetCacheSizeInBytes(hostname);
    result::WriteAbbreviationExplanatoryLine();
    
	auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    {
        seed = time(NULL);
        if (options.MeasureNormal || options.MeasureInRow)
        {
            for (int arraySize = SmallestArraySize; arraySize <= LargestArraySize; arraySize += 1)
            {
                if (options.MeasureNormal) 
                {
                    measurement::MeasureSorting(perf_cpu_cycles, seed, NumberOfIterations, arraySize, measureIteration);
                }
                if (options.MeasureInRow && measureIteration < NumberOfMeasuresInRow)
                {
                    int numberOfArrays = 1.2f * cacheSize / (arraySize * sizeof(SortableRef));
                    measurement::MeasureSortingInRow(perf_cpu_cycles, seed, numberOfArrays, arraySize, measureIteration);
                }
            }
        }
        if (options.MeasureCompleteSort)
        {
            measurement::MeasureCompleteSorting(perf_cpu_cycles, seed, NumberOfIterationsCompleteSort, CompleteSortArraySize, measureIteration);
        }
        
    }
	delete perf_cpu_cycles;

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}