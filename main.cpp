
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
#include "Quicksort_Copy.h"
#include "Quicksort_Copy2.h"
#include "VerifyNetworks.h"
#include "VerifyNetworks.generated.h"
#include "CommandLineOptions.h"
#include "DebugHelper.h"

void SetDebugOutputFile()
{
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/data/debug_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stderr);
}

void SetResultOutputFile() 
{
    time_t now = time(0);
    struct tm tstruct;
    char filename_buffer[80];
    tstruct = *localtime(&now);
    strftime(filename_buffer, sizeof(filename_buffer), "../result/data/output_%Y-%m-%d_%H-%M-%S.txt", &tstruct);

    auto _ = freopen(filename_buffer, "w", stdout);
}

bool sref_less(uint64_t& leftKey, SortableRef_FourCmovTemp& right)
{
    return leftKey < right.key;
}

#define ElementCount 128
void test()
{
    // auto arr = (SortableRef*) malloc(sizeof(SortableRef) * 400);
    // for (int i = 0; i < 50; i += 1)
    // {
    //     randomisation::GenerateRandomArray(arr, 400);
    //     quicksortcopy2::partial_sort(arr, arr + 400, arr + 400, &measurement::IteratorCompare<SortableRef>);
    //     uint64_t ki, ri, kv, rv;
    //     PutPermutationValues(arr, 400, kv, ki, rv, ri);
    //     if (!IsSortedAndPermutation(arr, 400, ki, kv, ri, rv))
    //     {
    //         debug::WriteLine("bad sort partial sort");
    //     }
    //     else
    //     {
    //         debug::WriteLine("good sort");
    //     }
    // }
    
    // debug::WriteLine(std::to_string(sizeof(SortableRef*)));
    // debug::WriteLine(std::to_string(sizeof(long)));
    // debug::WriteLine(std::to_string(sizeof(long long)));
}

#define NumberOfIterations 100
#define NumberOfIterationsCompleteSort 20
#define NumberOfIterationsSampleSort 50
#define NumberOfIterationsIpso 50
#define NumberOfMeasures 500
#define NumberOfMeasuresInRow 10
#define NumberOfMeasuresComplete 200
#define NumberOfSampleSorts 200
#define NumberOfMeasuresIpso 200
#define SmallestArraySize 2
#define LargestArraySize 16
#define CompleteSortArraySize 1024 * 16
#define SampleSortArraySize 256
#define IpsoArraySize 1024 * 32

uint64_t ID(int& value) {return (uint64_t) value;}

int main(int argumentCount, char** arguments)
{
    auto options = commandline::ParseOptions(arguments, argumentCount);
    if (!options.ParsingSuccessful)
    {
        commandline::PrintHelpText(std::cout);
        return 0;
    }
    if (options.DebugToFile)
    {
        SetDebugOutputFile();
    }
    if (options.VerifyNetworks)
    {
        verification::VerifyNetworks();
        return 0;
    }
    if (options.ExecuteTestMethod)
    {
        std::cout << "Executing test method" << std::endl;
        test();
        return 0;
    }
    if (options.HelpRequested 
        || (!options.MeasureNormal && !options.MeasureInRow && !options.MeasureSampleSort && !options.MeasureQuickSort && !options.MeasureIpso))
    {
        commandline::PrintHelpText(std::cout);
        return 0;
    }
    if (options.ReadableNumbers)
    {
        // randomisation::readableNumbers = true;
    }

    uint64_t seed;
    std::string commit = GetGitCommitOfContainingRepository();
    std::string hostname = environment::GetComputerName();
    SetResultOutputFile();
    printf("General Info: Commit=%s, Hostname=%s\n", commit.c_str(), hostname.c_str());
    printf("Parameters: ");
    for (int i = 0; i < argumentCount; i += 1)
    {
        printf("%s ", arguments[i]);
    }
    printf("\n");
    size_t cacheSize = environment::GetCacheSizeInBytes(hostname);
    result::WriteAbbreviationExplanatoryLine();
    
    auto timeBefore = time(NULL);
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
        if (options.MeasureQuickSort && measureIteration < NumberOfMeasuresComplete)
        {
            measurement::MeasureCompleteSorting(perf_cpu_cycles, seed, NumberOfIterationsCompleteSort, CompleteSortArraySize, measureIteration);
        }
        if (options.MeasureSampleSort && measureIteration < NumberOfSampleSorts)
        {
            measurement::MeasureSampleSort(perf_cpu_cycles, seed, NumberOfIterationsSampleSort, SampleSortArraySize, measureIteration);
        }
        if (options.MeasureIpso && measureIteration < NumberOfMeasuresIpso)
        {
            if (hostname == "i10pc133")
            {
                measurement::MeasureIpso1(perf_cpu_cycles, seed, NumberOfIterationsIpso, IpsoArraySize, measureIteration);
            }
            else
            {
                measurement::MeasureIpso0(perf_cpu_cycles, seed, NumberOfIterationsIpso, IpsoArraySize, measureIteration);
            }
            
        }
    }
	delete perf_cpu_cycles;
    auto timeAfter = time(NULL);
    auto secondsElapsed = timeAfter - timeBefore;
    auto minutesElapsed = secondsElapsed / ((int64_t) 60);
    printf("Time elapsed during measurement\n");
    printf("In seconds: %" PRIi64 "\n", secondsElapsed);
    printf("In minutes: %" PRIi64 "\n", minutesElapsed);

    // auto perf_cache_misses = new Performancing(PerformanceMetric::CACHE_MISSES);
    // delete perf_cache_misses;

    // auto perf_branch_misses = new Performancing(PerformanceMetric::BRANCH_MISSES);
    // delete perf_branch_misses;

	return 0;
}
