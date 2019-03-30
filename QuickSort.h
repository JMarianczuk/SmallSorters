
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <math.h>

#include "CustomMath.h"
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
        networks::sort9bosenelsonparameter(
            items[first + step], items[first + twoStep], items[mid - step], items[mid], 
            items[first], 
            items[mid + step], items[last - twoStep], items[last - step], items[last]);
    }
    else
    {
        networks::sort3bosenelsonparameter(
            items[mid], 
            items[first], 
            items[last]);
    } // The median is now at position first because we passed items[first] as middle parameter into the network

    // debug::WriteLine("partition: mid=", std::to_string(mid), ", last=", std::to_string(last));
    // std::swap(items[mid], items[first]); 
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
void QS_Recursion(TValueType* items, size_t arraySize, size_t ideal, void(*sortFunc)(TValueType*,size_t))
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

template <typename TValueType, typename TCompare>
TValueType* QS_UnguardedPartition(TValueType* first, TValueType* last, TValueType* pivot, TCompare compare)
{
    while (true)
    {
        while (compare(first, pivot))
        {
            ++first;
        }
        --last;
        while (compare(pivot, last))
        {
            --last;
        }
        if (!(first < last))
        {
            return first;
        }
        std::iter_swap(first, last);
        ++first;
    }
}

template <typename TValueType, typename TCompare>
inline
TValueType* QS_UnguardedPartitionPivot(TValueType* first, TValueType* last, TCompare compare)
{
    size_t size = last - first;
    TValueType* mid = first + size / 2;
    if (size > 40)
    {
        size_t step = size / 8;
        size_t twoStep = step * 2;
        networks::sort9bosenelsonparameter(
            *(first + step), *(first + twoStep), *(mid - step), *mid,
            *first,
            *(mid + step), *(last - twoStep), *(last - step), *(last - 1)
        );
    }
    else 
    {
        networks::sort3bosenelsonparameter(
            *mid, 
            *first, 
            *(last - 1));
    }
    
    return QS_UnguardedPartition(first + 1, last, first, compare);
}

template <typename TValueType, typename TCompare>
inline
void QS_Stl_Internal(TValueType* first, TValueType* last, int depthLimit, TCompare compare, void(*sortFunc)(TValueType*,size_t))
{
    while (last - first > BaseCaseLimit)
    {
        if (depthLimit == 0)
        {
            samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(first, last - first, BaseCaseLimit, sortFunc, &templateLess, &GetKey<TValueType>);
            // std::partial_sort(first, last, last, compare);
            return;
        }
        depthLimit -= 1;
        TValueType* cut = QS_UnguardedPartitionPivot(first, last, compare);
        QS_Stl_Internal(cut, last, depthLimit, compare, sortFunc);
        last = cut;
    }
    sortFunc(first, last - first);
}

template <typename TValueType>
inline
void QS_Stl(TValueType* first, TValueType* last, bool(*compare)(TValueType*,TValueType*), void(*sortFunc)(TValueType*,size_t))
{
    QS_Stl_Internal(first, last, custommath::intlog2((int) (last - first)) * 2, compare, sortFunc);
}

}

#endif