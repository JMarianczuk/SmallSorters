
#ifndef MEASURE_H
#define MEASURE_H

#include <string>
#include <vector>

#include "../Result.h"
#include "../ArrayHelpers.h"
#include "../Performancing.h"
#include "../sorters/QuickSort.h"
#include "../sorters/InsertionSort.h"
#include "../sorters/Quicksort_Copy.h"
#include "../Randomisation.generated.h"
#include "../StructHelpers.generated.h"
#include "../DebugHelper.h"

namespace measurement
{
    
template <typename ValueType>
void Measure(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(ValueType*,size_t))
{
    ValueType *arr = (ValueType*) malloc(sizeof(ValueType) * arraySize);
    
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
        sizeof(ValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfBadSorts,
        true
    );

    free(arr);
}

template <typename ValueType>
void MeasureInRow(
    Performancing* perf,
    int numberOfArrays,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(ValueType*,size_t))
{
    ValueType *arr = (ValueType*) malloc(sizeof(ValueType) * numberOfArrays * arraySize);
    ValueType *arrEnd = arr + numberOfArrays * arraySize;
    ValueType *compare = (ValueType*) malloc(sizeof(ValueType) * numberOfArrays * arraySize);
    ValueType *compareEnd = compare + numberOfArrays * arraySize;
    ValueType warmupArr[arraySize];

    randomisation::GenerateRandomArray(arr, numberOfArrays * arraySize);
    CopyArray(arr, compare, numberOfArrays * arraySize);
    randomisation::GenerateRandomArray(warmupArr, arraySize);

    for (ValueType* current = compare; current < compareEnd; current += arraySize)
    {
        insertionsort::InsertionSort<insertionsort::InsertionSort_Default>(current, arraySize);
    }

    int numberOfBadSorts = 0;
    sortFunc(warmupArr, arraySize);
    if (!IsSorted(warmupArr, arraySize))
    {
        numberOfBadSorts += 1;
    }
    
    perf->StartMeasuring();
    for (ValueType* current = arr; current < arrEnd; current += arraySize)
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
        sizeof(ValueType),
        arraySize,
        measureIteration,
        numberOfArrays,
        numberOfBadSorts,
        true
    );

    free(arr);
    free(compare);
}

template <typename ValueType>
void MeasureSampleSort(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*sortFunc)(ValueType*,size_t,size_t,void(*)(ValueType*,size_t), bool(*)(uint64_t&,ValueType&),uint64_t(*)(ValueType&)),
    void(*baseCaseSortFunc)(ValueType*,size_t))
{
    ValueType *arr = (ValueType*) malloc(sizeof(ValueType) * arraySize);
    randomisation::GenerateRandomArray(arr, arraySize);
    int numberOfBadSorts = 0;
    uint64_t key_iter = 1;
    uint64_t ref_iter = 1;
    uint64_t key_value;
    uint64_t ref_value;
    PutPermutationValues(arr, arraySize, key_value, key_iter, ref_value, ref_iter);
    sortFunc(arr, arraySize, 16, baseCaseSortFunc, &quicksort::templateLess<ValueType>, &GetKey<ValueType>);
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
        sortFunc(arr, arraySize, 16, baseCaseSortFunc, &quicksort::templateLess<ValueType>, &GetKey<ValueType>);
        if (!IsSortedAndPermutation(arr, arraySize, key_iter, key_value, ref_iter, ref_value))
        {
            numberOfBadSorts += 1;
        }
    }
    perf->StopMeasuring();

    result::WriteResultLine(
        sorterName,
        perf,
        sizeof(ValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfBadSorts,
        true
    );

    free(arr);
}

template <typename Implementation, typename ValueType>
void BaseCaseSortBlank(ValueType* arr, size_t arraySize) {}

template <typename ValueType>
bool IteratorCompare(ValueType* left, ValueType* right)
{
    return *left < *right;
}

template <typename ValueType>
bool NormalCompare(ValueType left, ValueType right)
{
    return left < right;
}

template <typename ValueType>
void MeasureCompleteSorter(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName,
    void(*completeSorter)(ValueType*,ValueType*,bool(*)(ValueType,ValueType),void(*)(ValueType*,size_t)),
    void(*baseCaseSortFunc)(ValueType*,size_t))
{
    ValueType *arr = (ValueType*) malloc(sizeof(ValueType) * arraySize);
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
        sizeof(ValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfBadSorts,
        true
    );

    free(arr);
}

template <typename ValueType>
void MeasureRandomGeneration(
    Performancing* perf,
    int numberOfIterations,
    size_t arraySize,
    int measureIteration,
    std::string sorterName)
{
    ValueType *arr = (ValueType*) malloc(sizeof(ValueType) * arraySize);

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
        sizeof(ValueType),
        arraySize,
        measureIteration,
        numberOfIterations,
        numberOfEqualNeighbours,
        false
    );

    free(arr);
}

} // namespace measurement

#endif // MEASURE_H