
#ifndef MEASURE_H
#define MEASURE_H

#include <string>
#include <vector>

#include "Result.h"
#include "ArrayHelpers.h"
#include "Performancing.h"
#include "Randomisation.generated.h"
#include "StructHelpers.generated.h"

namespace measurement
{
    
template <typename TValueType>
void Measure(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(TValueType*,size_t))
{
    // TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));
    TValueType arr[arraySize];
    TValueType copy[arraySize];
    
    int numberOfBadSorts = 0;
    randomisation::GenerateRandomArray(arr, arraySize);
    sortFunc(arr, arraySize);
    if (!IsSorted(arr, arraySize)) 
    {
        numberOfBadSorts += 1;
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        std::vector<TValueType> copy;
        CopyArray(arr, copy, arraySize);
        sortFunc(arr, arraySize);
        std::sort(copy.begin(), copy.end(), [](const TValueType& left, const TValueType& right) {return left < right;});
        if (!IsSameArray(arr, copy, arraySize))
        {
            numberOfBadSorts += 1;
            PrintVector(copy, "Correctly Sorted");
            PrintArray(arr, arraySize, "Bad Sort");
            printf("\n");
        }
    }
    perf->StopMeasuring();

    result::WriteResultLine(
        sorterName,
        perf,
        sizeof(TValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfBadSorts,
        true
    );

    // free(arr);
    // delete[] arr;
}

template <typename TValueType>
void MeasureRandomGeneration(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName)
{
    TValueType arr[arraySize];
    // TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));

    int numberOfEqualNeighbours = 0;
    randomisation::GenerateRandomArray(arr, arraySize);
    if (!NotHasEqualNeighbour(arr, arraySize))
    {
        numberOfEqualNeighbours += 1;
    }
    
    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        if (!NotHasEqualNeighbour(arr, arraySize))
        {
            numberOfEqualNeighbours += 1;
        }
    }
    perf->StopMeasuring();

    result::WriteResultLine(
        sorterName,
        perf,
        sizeof(TValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfEqualNeighbours,
        false
    );

    // free(arr);
}

}

#endif