
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <utility>
#include <algorithm>

#include "Sortable.generated.h"

namespace insertionsort {

template <typename TValueType>
static inline
void InsertionSort(TValueType* items, size_t arraySize) 
{
    int inner, outer;
    for (outer = 1; outer < arraySize; outer += 1) {
        TValueType current = std::move(items[outer]);
        for (inner = outer; inner > 0 && items[inner - 1] > current; inner -= 1) 
        {
            items[inner] = std::move(items[inner - 1]);
        }
        items[inner] = std::move(current);
    }
}

template<>
inline
void InsertionSort<SortableRef_ArrayIndex_FirstCheck>(SortableRef_ArrayIndex_FirstCheck* items, size_t arraySize)
{
    int inner, outer;
    for (outer = 1; outer < arraySize; outer += 1)
    {
        auto current = std::move(items[outer]);
        if (current < items[0])
        {
            std::move_backward(items, &items[outer], &items[outer + 1]);
            items[0] = std::move(current);
        }
        else 
        {
            for (inner = outer; items[inner - 1] > current; inner -= 1)
            {
                items[inner] = std::move(items[inner - 1]);
            }
            items[inner] = std::move(current);
        }
    }
}

template<>
inline
void InsertionSort<SortableRef_PointerOptimized>(SortableRef_PointerOptimized* first, size_t arraySize) 
{
    auto last = first + arraySize;
    for (auto current = first + 1; current < last; current += 1)
    {
        auto next_temp = current;
        auto val = std::move(*current);
        auto first_temp = next_temp - 1;
        while (first_temp >= first && val < *first_temp)
        {
            *next_temp = std::move(*first_temp);
            next_temp = first_temp;
            first_temp -= 1;
        }
        *next_temp = std::move(val);
    }
}

template<>
inline
void InsertionSort<SortableRef_StlVersion>(SortableRef_StlVersion* first, size_t arraySize) 
{
    SortableRef_StlVersion* last = first + arraySize;
    for (SortableRef_StlVersion* next = first; ++next < last; )
    {
        SortableRef_StlVersion val = std::move(*next);

        if (val < *first)
        {
            std::move_backward(first, next, next+1);
            *first = std::move(val);
        }
        else
        {
            SortableRef_StlVersion* next_temp = next;
            for (SortableRef_StlVersion* first_temp = next_temp; 
                val < *--first_temp; 
                next_temp = first_temp)
            {
                *next_temp = std::move(*first_temp);
            }
            *next_temp = std::move(val);
        }
    }
}

}

#endif