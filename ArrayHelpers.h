
#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H

#include "Sortable.h"

template <typename TValueType>
void CopyArray(TValueType* source, TValueType* destination, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        destination[i] = source[i];
    }
}

template <typename TComparable>
bool IsSorted(TComparable* items, int arraySize) {
    for (int i = 0; i < arraySize - 1; i += 1) {
        if (items[i] > items[i + 1]) {
            return false;
        }
    }
    return true;
}
// bool IsSorted(Sortable* items, int arraySize) {
//     for (int i = 0; i < arraySize - 1; i += 1) {
//         if (items[i].key > items[i + 1].key) {
//             return false;
//         }
//     }
//     return true;
// }

template <typename TEquatable>
bool IsPermutation(TEquatable* arr, TEquatable* reference, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        bool isIncluded = false;
        for (int j = 0; j < arraySize; j += 1) {
            if (arr[i] == reference[j]) {
                isIncluded = true;
                break;
            }
        }
        if (!isIncluded) {
            return false;
        }
    }
    return true;
}

#endif