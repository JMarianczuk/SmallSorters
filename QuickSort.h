
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "DebugHelper.h"
#include "SampleSort.generated.h"
#include "BoseNelsonParameter.generated.h"

namespace quicksort
{

#define BaseCaseLimit 16

template <typename TValueType>
static inline
void QuickSort(TValueType* items, size_t arraySize, void (*sortFunc)(TValueType*,size_t))
{
    if (arraySize > BaseCaseLimit)
    {
        // debug::WriteLine("Sorting non base case: ", std::to_string(arraySize));
        auto mid = arraySize / 2;
        auto pivot = items[mid];
        int last = arraySize - 1;
        std::swap(items[mid], items[last]);
        int firstGreater = 0;
        for (int current = 0; current < last; current += 1)
        {
            if (items[current] <= pivot)
            {
                std::swap(items[current], items[firstGreater]);
                firstGreater += 1;
            }
        }
        std::swap(items[firstGreater], items[last]);
        QuickSort(items, firstGreater, sortFunc);
        QuickSort(items + firstGreater + 1, last - firstGreater, sortFunc);
    }
    else if (arraySize >= 2)
    {
        // debug::WriteLine("Sorting base case: ", std::to_string(arraySize));
        sortFunc(items, arraySize);
    }
}

template <typename TValueType>
static inline
int QS_Partition(TValueType* items, size_t arraySize)
{
    size_t first = 0;
    size_t mid = arraySize / 2;
    size_t last = arraySize - 1;
    if (last > 40)
    {
        size_t step = (last + 1) / 8;
        size_t twoStep = step * 2;
        networks::sort9bosenelsonparameter(items[first], items[first + step], items[first + twoStep], items[mid - step], items[mid], items[mid + step], items[last - twoStep], items[last - step], items[last]);
    }
    else
    {
        networks::sort3bosenelsonparameter(items[first], items[mid], items[last]);
    }
    // debug::WriteLine("partition: mid=", std::to_string(mid), ", last=", std::to_string(last));
    std::swap(items[mid], items[first]);
    auto pivot = items[first];
    first += 1;

    while(true)
    {
        while (items[first] < pivot)
        {
            first += 1;
        }
        while (pivot < items[last])
        {
            last -= 1;
        }
        if (last <= first)
        {
            std::swap(items[0], items[last]);
            // debug::WriteLine("returning mid index ", std::to_string(last), ", size was ", std::to_string(arraySize));
            return last;
        }
        std::swap(items[first], items[last]);
        first += 1;
        last -= 1;
    }
}

template <typename TValueType>
static inline
bool templateLess(uint64_t& leftKey, TValueType& right)
{
    return leftKey < GetKey(right);
}

template <typename TValueType>
static inline
void QS_Stl(TValueType* items, size_t arraySize, size_t ideal, void(*sortFunc)(TValueType*,size_t))
{
    while (arraySize > BaseCaseLimit && ideal > 0)
    {
        // debug::WriteLine("Partitioning: arraySize=", std::to_string(arraySize));
        auto mid = QS_Partition(items, arraySize);
        // debug::WriteLine("Going into recursion");
        size_t afterMid = mid + 1;
        ideal = (ideal >> 1) + (ideal >> 2); //from std::sort (MSVC): "allow 1.5 log2(N) divisions"

        if (mid  < arraySize - afterMid)
        {
            QS_Stl(items, mid, ideal, sortFunc);
            items += afterMid;
            arraySize -= afterMid;
        }
        else
        {
            QS_Stl(items + afterMid, arraySize - afterMid, ideal, sortFunc);
            arraySize = mid;
        }
    }

    if (arraySize > BaseCaseLimit)
    {
        samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(items, arraySize, BaseCaseLimit, sortFunc, &templateLess, &GetKey<TValueType>);
    }
    else if (arraySize >= 2)
    {
        sortFunc(items, arraySize);
    }
}

}

#endif