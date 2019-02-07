
#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include <iostream>
#include <string>
#include <vector>
#include "Sortable.generated.h"

template<typename TValueType>
void PrintArray(TValueType* source, int arraySize, std::string comment)
{
    printf("%s: ", comment.c_str());
    for (int i = 0; i < arraySize; i += 1)
    {
        printf("%" PRIu64 ", ", GetKey(source[i]));
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
        if (items[i] > items[i + 1]) 
        {
            return false;
        }
    }
    return true;
}

template <typename TComparable>
bool IsSameArray(TComparable* left, std::vector<TComparable> right, size_t arraySize)
{
    for (int i = 0; i < arraySize; i += 1)
    {
        if (left[i] != right[i])
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
        if (left[i] != right[i])
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
        if (items[i] > fakeCompareTo)
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
        if (items[i] == items[i + 1]) 
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