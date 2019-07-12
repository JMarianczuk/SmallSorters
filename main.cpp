
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

#include "environment/Performancing.h"

#include "Networks_Fwd.h"
#include "Result.h"
#include "environment/GitInfo.h"
#include "environment/EnvironmentInfo.h"
#include "Randomisation.h"
#include "ArrayHelpers.h"
#include "Sortable.generated.h"

#include "measurement/Measurement.generated.h"
#include "measurement/MeasurementIpso.Helper.h"

#include "sorters/InsertionSort.h"
#include "sorters/SampleSort.generated.h"
#include "sorters/QuickSort.h"
#include "sorters/Quicksort_Copy.h"
#include "sorters/Quicksort_Copy2.h"

#include "VerifyNetworks.h"
#include "VerifyNetworks.generated.h"
#include "environment/CommandLineOptions.h"
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

bool sref_less(uint64_t& leftKey, SortableRef& right)
{
    return leftKey < right.key;
}

#define ElementCount 128
void test()
{
    
}

#define NumberOfIterations 100
#define NumberOfIterationsCompleteSort 50
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

bool ExecuteExtraordinaryAction(commandline::CommandLineOptions options)
{
    if (options.VerifyNetworks)
    {
        verification::VerifyNetworks();
        return true;
    }
    if (options.ExecuteTestMethod)
    {
        std::cout << "Executing test method" << std::endl;
        test();
        return true;
    }
    if (options.HelpRequested 
        || (!options.MeasureNormal && !options.MeasureInRow && !options.MeasureSampleSort && !options.MeasureQuickSort && !options.MeasureIpso))
    {
        commandline::PrintHelpText(std::cout);
        return true;
    }
}

void PrintInfos(int argumentCount, char** arguments)
{
    std::string hostname = environment::GetComputerName();
    std::string commit = GetGitCommitOfContainingRepository();
    printf("General Info: Commit=%s, Hostname=%s\n", commit.c_str(), hostname.c_str());
    printf("Parameters: ");
    for (int i = 0; i < argumentCount; i += 1)
    {
        printf("%s ", arguments[i]);
    }
    printf("\n");
    result::WriteAbbreviationExplanatoryLine();
}

void PerformMeasurements(commandline::CommandLineOptions options, Performancing* perf, char** arguments, int argumentCount)
{
    uint64_t seed;
    SetResultOutputFile();
    size_t cacheSize = environment::GetCacheSizeInBytes(environment::GetComputerName());
    PrintInfos(argumentCount, arguments);
    
    auto timeBefore = time(NULL);
    for (int measureIteration = 0; measureIteration < NumberOfMeasures; measureIteration += 1)
    {
        seed = time(NULL);
        if (options.MeasureNormal || options.MeasureInRow)
        {
            for (int arraySize = SmallestArraySize; arraySize <= LargestArraySize; arraySize += 1)
            {
                if (options.MeasureNormal) 
                {
                    measurement::MeasureSorting(perf, seed, NumberOfIterations, arraySize, measureIteration);
                }
                if (options.MeasureInRow && measureIteration < NumberOfMeasuresInRow)
                {
                    int numberOfArrays = 1.2f * cacheSize / (arraySize * sizeof(SortableRef));
                    measurement::MeasureSortingInRow(perf, seed, numberOfArrays, arraySize, measureIteration);
                }
            }
        }
        if (options.MeasureQuickSort && measureIteration < NumberOfMeasuresComplete)
        {
            measurement::MeasureCompleteSorting(perf, seed, NumberOfIterationsCompleteSort, CompleteSortArraySize, measureIteration);
        }
        if (options.MeasureSampleSort && measureIteration < NumberOfSampleSorts)
        {
            measurement::MeasureSampleSort(perf, seed, NumberOfIterationsSampleSort, SampleSortArraySize, measureIteration);
        }
        if (options.MeasureIpso && measureIteration < NumberOfMeasuresIpso)
        {
            measurement::MeasureIpsoAll(perf, seed, NumberOfIterationsIpso, IpsoArraySize, measureIteration);
            
        }
    }
    auto timeAfter = time(NULL);
    auto secondsElapsed = timeAfter - timeBefore;
    auto minutesElapsed = secondsElapsed / ((int64_t) 60);
    printf("Time elapsed during measurement\n");
    printf("In seconds: %" PRIi64 "\n", secondsElapsed);
    printf("In minutes: %" PRIi64 "\n", minutesElapsed);
}

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
    if (ExecuteExtraordinaryAction(options))
    {
        return 0;
    }

    auto perf_cpu_cycles = new Performancing(PerformanceMetric::CPU_CYCLES);
    PerformMeasurements(options, perf_cpu_cycles, arguments, argumentCount);
    delete perf_cpu_cycles;

	return 0;
}
