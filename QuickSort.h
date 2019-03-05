
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
        networks::sort3bosenelsonparameter(items[0], items[mid], items[last]);
    }
    // debug::WriteLine("partition: mid=", std::to_string(mid), ", last=", std::to_string(last));
    std::swap(items[mid], items[last]);
    auto pivot = items[last];
    size_t firstGreater = 0;
    for (size_t current = 0; current < last; current += 1)
    {
        if (items[current] <= pivot)
        {
            std::swap(items[current], items[firstGreater]);
            firstGreater += 1;
        }
    }
    std::swap(items[firstGreater], items[last]);
    return firstGreater;
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
        ideal = (ideal >> 1) + (ideal >> 2); //from std::sort: "allow 1.5 log2(N) divisions"

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
        // samplesort::SampleSort3Splitters2OversamplingFactor3BlockSize(items, arraySize, BaseCaseLimit, sortFunc);
        //TODO enable sample sort for this
        QS_Stl(items, arraySize, arraySize, sortFunc);
    }
    else if (arraySize >= 2)
    {
        sortFunc(items, arraySize);
    }
}

}

#endif