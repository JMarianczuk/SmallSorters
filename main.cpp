
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

#include "Performancing.h"
#include "InsertionSort.h"
#include "Networks_Fwd.h"
#include "Result.h"
#include "GitInfo.h"
#include "EnvironmentInfo.h"
#include "Randomisation.h"
#include "ArrayHelpers.h"
#include "Sortable.generated.h"
#include "measurement/Measurement.generated.h"
#include "measurement/MeasurementIpso.Helper.h"
#include "SampleSort.generated.h"
#include "QuickSort.h"
#include "Quicksort_Copy.h"
#include "Quicksort_Copy2.h"
#include "VerifyNetworks.h"
#include "VerifyNetworks.generated.h"
#include "CommandLineOptions.h"
#include "DebugHelper.h"

template <typename ValueType, void(*swap)(ValueType&,ValueType&)>
void TemplateTest(ValueType* arr)
{
    swap(arr[0], arr[1]);
}

template <typename ValueType, typename TSwap, TSwap swap>
void TemplateTest2(ValueType* arr)
{
    swap(arr[0], arr[1]);
}

template <typename TSwap, TSwap swap, typename ValueType>
void TemplateTest3(ValueType* arr)
{
    swap(arr[0], arr[1]);
}

template <typename CSwap, typename ValueType>
void TemplateTest4(ValueType* arr)
{
    CSwap::swap(arr[0], arr[1]);
}

class ConditionalSwapJumpXchg
{
public:
    template <typename Type>
    static void swap(Type& left, Type& right) {
        __asm__(
            "cmpq %[left_key],%[right_key]\n\t"
            "jae %=f\n\t"
            "xchg %[left_key],%[right_key]\n\t"
            "%=:\n\t"
            : [left_key] "+r"(left), [right_key] "+r"(right)
            :
            : "cc"
            );
    }
};

void test_class()
{
    auto arr = (size_t*) malloc(sizeof(size_t) * 5);
    arr[0] = 500;
    arr[1] = 1;

    TemplateTest4<ConditionalSwapJumpXchg>(arr);
    debug::WriteLine("first: ", std::to_string(arr[0]));
    debug::WriteLine("second: ", std::to_string(arr[1]));
}

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
    auto arr = (int*) malloc(sizeof(int) * 5);
    arr[0] = 500;
    arr[1] = 1;

    TemplateTest<int, &networks::ConditionalSwap<int>>(arr);
    debug::WriteLine("first: ", std::to_string(arr[0]));
    debug::WriteLine("second: ", std::to_string(arr[1]));

    arr[0] = 499;
    arr[1] = 2;

    TemplateTest2<int, void(*)(int&,int&), &networks::ConditionalSwap<int>>(arr);
    debug::WriteLine("first: ", std::to_string(arr[0]));
    debug::WriteLine("second: ", std::to_string(arr[1]));

    arr[0] = 498;
    arr[1] = 3;

    TemplateTest3<void(*)(int&,int&), &networks::ConditionalSwap<int>>(arr);

    free(arr);
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
            measurement::MeasureIpsoAll(perf_cpu_cycles, seed, NumberOfIterationsIpso, IpsoArraySize, measureIteration);
            
        }
    }
	delete perf_cpu_cycles;
    auto timeAfter = time(NULL);
    auto secondsElapsed = timeAfter - timeBefore;
    auto minutesElapsed = secondsElapsed / ((int64_t) 60);
    printf("Time elapsed during measurement\n");
    printf("In seconds: %" PRIi64 "\n", secondsElapsed);
    printf("In minutes: %" PRIi64 "\n", minutesElapsed);

	return 0;
}
