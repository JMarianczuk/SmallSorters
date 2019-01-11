
#ifndef MEASURE_H
#define MEASURE_H

#include <string>

#include "Result.h"

namespace measurement
{
    
template <typename TValueType>
void Measure(
    Performancing* perf,
    EnvironmentInfo info,
    int numberOfIterations,
    size_t arraySize,
    std::string sorterName,
    void(*sortFunc)(TValueType*,size_t))
{
    TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));
    
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
        sortFunc(arr, arraySize);
        if (!IsSorted(arr, arraySize))
        {
            numberOfBadSorts += 1;
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        sorterName,
        perf,
        info,
        sizeof(TValueType),
        arraySize,
        numberOfIterations,
        numberOfBadSorts,
        true
    );

    free(arr);
}

template <typename TValueType>
void MeasureInsertionSort(
    Performancing* perf, 
    EnvironmentInfo info, 
    int numberOfIterations, 
    size_t arraySize,
    std::string sorterName) 
{
    Measure<TValueType>(perf, info, numberOfIterations, arraySize, sorterName, &insertionsort::InsertionSort<TValueType>);
}

template <typename TValueType>
void MeasureNetworkSort(
    Performancing* perf, 
    EnvironmentInfo info, 
    int numberOfIterations, 
    size_t arraySize,
    std::string sorterName) 
{
    Measure<TValueType>(perf, info, numberOfIterations, arraySize, sorterName, &networks::sortN<TValueType>);
}

template <typename TValueType>
void MeasureRandomGeneration(
    Performancing* perf,
    EnvironmentInfo info,
    int numberOfIterations,
    size_t arraySize,
    std::string sorterName)
{
    TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));

    int numberOfEqualNeighbours = 0;
    randomisation::GenerateRandomArray(arr, arraySize);
    if (HasEqualNeighbour(arr, arraySize))
    {
        numberOfEqualNeighbours += 1;
    }
    
    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        if (HasEqualNeighbour(arr, arraySize))
        {
            numberOfEqualNeighbours += 1;
        }
    }
    perf->StopMeasuring();

    WriteResultLine(
        sorterName,
        perf,
        info,
        sizeof(TValueType),
        arraySize,
        numberOfIterations,
        numberOfEqualNeighbours,
        false
    );
}

}

#endif