
#ifndef MEASURE_H
#define MEASURE_H

#include <string>
#include <vector>

#include "Result.h"
#include "ArrayHelpers.h"
#include "Performancing.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "Quicksort_Copy.h"
#include "Randomisation.generated.h"
#include "StructHelpers.generated.h"
#include "DebugHelper.h"

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
    TValueType *arr = (TValueType*) malloc(sizeof(TValueType) * arraySize);
    
    int numberOfBadSorts = 0;
    randomisation::GenerateRandomArray(arr, arraySize);
    uint64_t key_iter = 1;
    uint64_t ref_iter = 1;
    uint64_t key_value;
    uint64_t ref_value;
    PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
    sortFunc(arr, arraySize);
    if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value)) 
    {
        numberOfBadSorts += 1;
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        key_iter = 1;
        ref_iter = 1;
        PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
        sortFunc(arr, arraySize);

        if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
        {
            numberOfBadSorts += 1;
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

    free(arr);
}

template <typename TValueType>
void MeasureInRow(
    Performancing* perf,
    int numberOfArrays,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(TValueType*,size_t))
{
    TValueType *arr = (TValueType*) malloc(sizeof(TValueType) * numberOfArrays * arraySize);
    TValueType *arrEnd = arr + numberOfArrays * arraySize;
    TValueType *compare = (TValueType*) malloc(sizeof(TValueType) * numberOfArrays * arraySize);
    TValueType *compareEnd = compare + numberOfArrays * arraySize;
    TValueType warmupArr[arraySize];

    randomisation::GenerateRandomArray(arr, numberOfArrays * arraySize);
    CopyArray(arr, compare, numberOfArrays * arraySize);
    randomisation::GenerateRandomArray(warmupArr, arraySize);

    for (TValueType* current = compare; current < compareEnd; current += arraySize)
    {
        insertionsort::InsertionSort(current, arraySize);
    }

    int numberOfBadSorts = 0;
    sortFunc(warmupArr, arraySize);
    if (!IsSorted(warmupArr, arraySize))
    {
        numberOfBadSorts += 1;
    }
    
    perf->StartMeasuring();
    for (TValueType* current = arr; current < arrEnd; current += arraySize)
    {
        sortFunc(current, arraySize);
    }
    perf->StopMeasuring();

    for (int i = 0; i < numberOfArrays; i += 1)
    {
        if (!IsSameArray(&arr[i * arraySize], &compare[i * arraySize], arraySize))
        {
            numberOfBadSorts += 1;
        }
    }

    result::WriteResultLine(
        sorterName, 
        perf, 
        sizeof(TValueType),
        arraySize,
        measureIteration,
        numberOfArrays,
        numberOfBadSorts,
        true
    );

    free(arr);
    free(compare);
}

template <typename TValueType>
void MeasureSampleSort(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(TValueType*,size_t,size_t,void(*)(TValueType*,size_t), bool(*)(uint64_t&,TValueType&),uint64_t(*)(TValueType&)),
    void(*baseCaseSortFunc)(TValueType*,size_t))
{
    TValueType *arr = (TValueType*) malloc(sizeof(TValueType) * arraySize);
    randomisation::GenerateRandomArray(arr, arraySize);
    int numberOfBadSorts = 0;
    uint64_t key_iter = 1;
    uint64_t ref_iter = 1;
    uint64_t key_value;
    uint64_t ref_value;
    PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
    sortFunc(arr, arraySize, 16, baseCaseSortFunc, &quicksort::templateLess<TValueType>, &GetKey<TValueType>);
    if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
    {
        numberOfBadSorts += 1;
    }

    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        key_iter = 1;
        ref_iter = 1;
        PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
        sortFunc(arr, arraySize, 16, baseCaseSortFunc, &quicksort::templateLess<TValueType>, &GetKey<TValueType>);
        if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
        {
            numberOfBadSorts += 1;
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

    free(arr);
}

template <typename TValueType>
void BaseCaseSortBlank(TValueType* arr, size_t arraySize) {}

template <typename TValueType>
bool IteratorCompare(TValueType* left, TValueType* right)
{
    return *left < *right;
}

template <typename TValueType>
bool NormalCompare(TValueType left, TValueType right)
{
    return left < right;
}


template <typename TValueType>
void MeasureCompleteSorter(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*completeSorter)(TValueType*,TValueType*,bool(*)(TValueType,TValueType),void(*)(TValueType*,size_t)),
    void(*baseCaseSortFunc)(TValueType*,size_t))
{
    TValueType *arr = (TValueType*) malloc(sizeof(TValueType) * arraySize);
    randomisation::GenerateRandomArray(arr, arraySize);
    int numberOfBadSorts = 0;
    uint64_t key_iter = 1;
    uint64_t ref_iter = 1;
    uint64_t key_value;
    uint64_t ref_value;
    PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
    completeSorter(arr, arr + arraySize, &NormalCompare, baseCaseSortFunc);
    if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
    {
        numberOfBadSorts += 1;
    }
    
    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        key_iter = 1;
        ref_iter = 1;
        PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
        completeSorter(arr, arr + arraySize, &NormalCompare, baseCaseSortFunc);
        if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
        {
            numberOfBadSorts += 1;
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

    free(arr);
}

template <typename TValueType>
void MeasureRandomGeneration(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName)
{
    TValueType *arr = (TValueType*) malloc(sizeof(TValueType) * arraySize);

    int numberOfEqualNeighbours = 0;
    randomisation::GenerateRandomArray(arr, arraySize);
    if (!NotHasEqualNeighbour(arr, arraySize))
    {
        numberOfEqualNeighbours += 1;
    }
    
    uint64_t key_iter = 1;
    uint64_t ref_iter = 1;
    uint64_t key_value;
    uint64_t ref_value;
    perf->StartMeasuring();
    for (int i = 0; i < numberOfIterations; i += 1)
    {
        randomisation::GenerateRandomArray(arr, arraySize);
        key_iter = 1;
        ref_iter = 1;
        PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
        
        if (!NotHasEqualNeighbourAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
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

    free(arr);
}


}

#endif