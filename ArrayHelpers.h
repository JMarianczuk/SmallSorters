
#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include <iostream>
#include <string>
#include <vector>
#include "Sortable.generated.h"
#include "StructHelpers.generated.h"
#include "DebugHelper.h"

template<typename TValueType>
void PrintArray(TValueType* source, int arraySize, std::string comment, uint64_t(*getKeyFunc)(TValueType&) = nullptr)
{
    if (getKeyFunc == nullptr)
    {
        getKeyFunc = &GetKey<TValueType>;
    }
    printf("%s: ", comment.c_str());
    for (int i = 0; i < arraySize; i += 1)
    {
        printf("%" PRIu64 ", ", getKeyFunc(source[i]));
    }
    printf("\n");
}

template <typename TValueType>
void PrintVector(std::vector<TValueType> source, std::string comment)
{
    printf("%s: ", comment.c_str());
    for (TValueType ele : source)
    {
        printf("%" PRIu64 ", ", GetKey(ele));
    }
    printf("\n");
}

template <typename TValueType>
void CopyArray(TValueType* source, std::vector<TValueType>& destination, int arraySize) 
{
    for (int i = 0; i < arraySize; i += 1) 
    {
        destination.push_back(source[i]);
    }
}

template <typename TValueType>
void CopyArray(TValueType* source, TValueType* destination, size_t arraySize)
{
    for (int i = 0; i < arraySize; i += 1) 
    {
        destination[i] = source[i];
    }
}

template <typename TComparable>
bool IsSorted(TComparable* items, size_t arraySize) 
{
    for (int i = 0; i < arraySize - 1; i += 1) 
    {
        if (__builtin_expect(items[i] > items[i + 1], 0)) 
        {
            return false;
        }
    }
    return true;
}

static const uint64_t p = 4294967291; // largest prime < 2^32
static const uint64_t two_to_power_of_31_minus_1 = 2147483647;

template<typename TComparable>
uint64_t GetPermutationValue(TComparable* items, size_t arraySize, uint64_t(*value_func)(TComparable& item), size_t& iteration)
{
    for (uint64_t iter = 1; iter < 100000; iter += 1)
    {
        //Keys are at most 2^32, so take a z that is guaranteed larger than 2^32
        uint64_t z = ((uint64_t) items) + iter;
        z = (z % two_to_power_of_31_minus_1) + two_to_power_of_31_minus_1;
        uint64_t v = 1;
        uint64_t diff;

        for (size_t i = 0; i < arraySize; i += 1)
        {
            diff = (z - value_func(items[i])) % p;
            v = (v * diff) % p;
        }
        if (v != 0)
        {
            iteration = iter;
            return v;
        }
    }
    return 0;
}

template <typename TComparable>
void PutPermutationValues(TComparable* items, size_t arraySize, uint64_t& keyValue, size_t& keyIter, uint64_t& refValue, size_t& refIter)
{
    keyValue = GetPermutationValue(items, arraySize, &GetKey<TComparable>, keyIter);
    refValue = GetPermutationValue(items, arraySize, &GetReference<TComparable>, refIter);
}

template<typename TComparable>
bool CheckPermutationValue(TComparable* items, size_t arraySize, uint64_t(*value_func)(TComparable& item), size_t iteration, uint64_t permutationValueBefore)
{
    uint64_t z = ((uint64_t) items) + iteration;
    z = (z % two_to_power_of_31_minus_1) + two_to_power_of_31_minus_1;
    uint64_t w = 1;
    uint64_t diff;

    for (size_t i = 0; i < arraySize; i += 1)
    {
        diff = (z - value_func(items[i])) % p;
        w = (w * diff) % p;
    }
    return permutationValueBefore == w;
}

template <typename TComparable>
bool IsSortedAndPermutation(TComparable* items, size_t arraySize, size_t keyIteration, uint64_t keyValue, size_t referenceIteration, uint64_t referenceValue)
{
    return IsSorted(items, arraySize)
        && CheckPermutationValue(items, arraySize, &GetKey<TComparable>, keyIteration, keyValue)
        && CheckPermutationValue(items, arraySize, &GetReference<TComparable>, referenceIteration, referenceValue);
}

template <typename TComparable>
bool IsSameArray(TComparable* left, std::vector<TComparable> right, size_t arraySize)
{
    for (int i = 0; i < arraySize; i += 1)
    {
        if (__builtin_expect(left[i] != right[i], 0))
        {
            return false;
        }
    }
    return true;
}

template <typename TComparable>
bool IsSameArray(TComparable* left, TComparable* right, size_t arraySize)
{
    for (int i = 0; i < arraySize; i += 1)
    {
        if (__builtin_expect(left[i] != right[i], 0))
        {
            return false;
        }
    }
    return true;
}

template <typename TComparable>
bool IsSortedFake(TComparable* items, size_t arraySize, TComparable fakeCompareTo) 
{
    for (int i = 0; i < arraySize - 1; i += 1)
    {
        if (__builtin_expect(items[i] > fakeCompareTo, 0))
        {
            return false;
        }
    }
    return true;
}

template <typename TComparable>
bool NotHasEqualNeighbour(TComparable* items, size_t arraySize) 
{
    for (int i = 0; i < arraySize - 1; i += 1) 
    {
        if (__builtin_expect(items[i] == items[i + 1], 0)) 
        {
            return false;
        }
    }
    return true;
}

template <typename TEquatable>
bool IsPermutation(TEquatable* arr, TEquatable* reference, int arraySize) 
{
    for (int i = 0; i < arraySize; i += 1) 
    {
        bool isIncluded = false;
        for (int j = 0; j < arraySize; j += 1) 
        {
            if (arr[i] == reference[j])
            {
                isIncluded = true;
                break;
            }
        }
        if (!isIncluded) 
        {
            return false;
        }
    }
    return true;
}

#endif