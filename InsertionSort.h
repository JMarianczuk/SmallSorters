
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "Sortable.h"

namespace insertionsort {

template <typename TValueType>
static inline
void InsertionSort(TValueType* items, int arraySize) {
    int inner, outer;
    for (outer = 1; outer < arraySize; outer += 1) {
        TValueType current = items[outer];
        for (inner = outer; inner > 0 && items[inner - 1] > current; inner -= 1) {
            items[inner] = items[inner - 1];
        }
        items[inner] = current;
    }
}

// template <>
// inline
// void InsertionSort<Sortable>(Sortable* items) {
//     int inner, outer;
//     for (outer = 1; outer < arraySize; outer += 1) {
//         Sortable current = items[outer];
//         for (inner = outer; inner > 0 && items[inner - 1].key > current.key; inner -= 1) {
//             items[inner] = items[inner - 1];
//         }
//         items[inner] = current;
//     }
// }

// template <>
// inline
// void InsertionSort<Sortable_JumpXchg(Sortable_JumpXchg* items) {
//     int inner, outer;
//     for (outer = 1; outer < arraySize; outer += 1) {
//         Sortable current = items[outer];
//         for (inner = outer; inner > 0 && items[inner - 1].key > current.key; inner -= 1) {
//             items[inner] = items[inner - 1];
//         }
//         items[inner] = current;
//     }
// }

}

#endif