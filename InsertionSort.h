
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

}

#endif