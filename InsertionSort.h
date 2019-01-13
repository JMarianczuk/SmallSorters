
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "Sortable.generated.h"

namespace insertionsort {

template <typename TValueType>
static inline
void InsertionSort(TValueType* items, size_t arraySize) {
    int inner, outer;
    for (outer = 1; outer < arraySize; outer += 1) {
        TValueType current = items[outer];
        for (inner = outer; inner > 0 && items[inner - 1] > current; inner -= 1) {
            items[inner] = items[inner - 1];
        }
        items[inner] = current;
    }
}

template<>
inline
void InsertionSort<SortableRef_StlVersion>(SortableRef_StlVersion* first, size_t arraySize) {
    SortableRef_StlVersion* last = first + arraySize - 1;
    for (SortableRef_StlVersion* next = first; ++next != last; )
    {
        SortableRef_StlVersion* next_temp = next;
        SortableRef_StlVersion val = *next;

        if (val <= *first)
        {
            next_temp++;
            while (first != next)
            {
                *--next_temp = *--next;
            }
            *first = val;
        }
        else
        {
            for (SortableRef_StlVersion* first_temp = next_temp; 
                val <= *--first_temp; 
                next_temp = first_temp)
            {
                *next_temp = *first_temp;
            }
            *next_temp = val;
        }
    }
}

}

#endif