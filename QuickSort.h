
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "DebugHelper.h"

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
    else
    {
        // debug::WriteLine("Sorting base case: ", std::to_string(arraySize));
        sortFunc(items, arraySize);
    }
}

}

#endif