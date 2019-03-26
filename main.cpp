
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
    SortableRef_FourCmovTemp testArr[ElementCount];
    SortableRef_FourCmovTemp test_2[ElementCount];
    randomisation::SetSeed(time(NULL));
    randomisation::GenerateRandomArray(testArr, ElementCount);
    CopyArray(testArr, test_2, ElementCount);

    PrintArray(testArr, ElementCount, "Array before");
    samplesort::SampleSort3Splitters5OversamplingFactor5BlockSize(testArr, ElementCount, 16, &networks::sortNbest, &sref_less, &GetKey);
    PrintArray(testArr, ElementCount, "After samplesort");
    insertionsort::InsertionSort(test_2, ElementCount);
    PrintArray(test_2, ElementCount, "Correctly sorted");
    debug::WriteLine("Is correctly sorted: ", std::to_string(IsSameArray(testArr, test_2, ElementCount)));
}

#define NumberOfIterations 100
// #define NumberOfIterationsCompleteSort 20
#define NumberOfIterationsCompleteSort 5
#define NumberOfIterationsSampleSort 50
#define NumberOfMeasures 500
#define NumberOfMeasuresInRow 10
// #define NumberOfMeasuresComplete 200
#define NumberOfMeasuresComplete 5
#define NumberOfSampleSorts 200
#define SmallestArraySize 2
#define LargestArraySize 16
// #define CompleteSortArraySize 1024 * 16
#define CompleteSortArraySize 256
#define SampleSortArraySize 256

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
        // for (int size = 2; size <= 16; size += 1)
        // {
        //     int* arr = (int*) malloc(sizeof(int) * size);
        //     int perm = 0;
        //     for (int i = 0; i < size; i += 1)
        //     {
        //         arr[i] = i;
        //     }
        //     do
        //     {
        //         perm += 1;
        //     } while (verification::NextPermutation(arr, arr + size));
        //     debug::WriteLine(std::to_string(perm), " permutations for size ", std::to_string(size));
        // }
        debug::WriteLine("This is not yet supported because it is too slow");
        // verification::VerifyNetworks();
        return 0;
    }
    if (options.ExecuteTestMethod)
    {
        std::cout << "Executing test method" << std::endl;
        test();
        return 0;
    }
    if (options.HelpRequested 
        || (!options.MeasureNormal && !options.MeasureInRow && !options.MeasureSampleSort && !options.MeasureCompleteSort))
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
        if (options.MeasureCompleteSort && measureIteration < NumberOfMeasuresComplete)
        {
            measurement::MeasureCompleteSorting(perf_cpu_cycles, seed, NumberOfIterationsCompleteSort, CompleteSortArraySize, measureIteration);
        }
        if (options.MeasureSampleSort && measureIteration < NumberOfSampleSorts)
        {
            measurement::MeasureSampleSort(perf_cpu_cycles, seed, NumberOfIterationsSampleSort, SampleSortArraySize, measureIteration);
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