
#include <algorithm>

#include "NetworkSort_Simple.h"

void Compare(Sortable* items, int left, int right) {
    uint64_t tmp = items[left].key;
    // __asm__(
    //     "cmpq %[left_key],%[right_key]\n"
    //     "cmovbq %[items_left],%[items_right]\n"
    //     "cmovbq %[items_right],%[tmp]\n"
    //     : [items_left] "+r"(items[left]), [items_right] "+r"(items[right])
    //     : [tmp] "rm"(tmp), [left_key] "x"(items[left].key), [right_key] "xm"(items[right].key)
    //     : "cc"
    // );
    __asm__(
        "cmpq %[left_key],%[right_key]\n"
        "cmovbq %[right_key],%[left_key]\n"
        "cmovbq %[tmp],%[right_key]\n"
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key)
        : [tmp] "r"(tmp)
        : "cc"
    );
}

void NetworkSortSimple_Optimised(Sortable* items) {
    Compare(items, 0, 1);
    Compare(items, 3, 4);
    Compare(items, 0, 2);
    // Compare(items, 1, 2);
    // Compare(items, 0, 3);
    // Compare(items, 2, 3);
    // Compare(items, 1, 4);
    // Compare(items, 1, 2);
    // Compare(items, 3, 4);
}

#define Compare_Swap(left, right) if (items[left].key > items[right].key) {std::swap(items[left], items[right]);}

void NetworkSortSimple_Naive(Sortable* items) {
    Compare_Swap(0, 1);
    Compare_Swap(3, 4);
    Compare_Swap(0, 2);
    // Compare_Swap(1, 2);
    // Compare_Swap(0, 3);
    // Compare_Swap(2, 3);
    // Compare_Swap(1, 4);
    // Compare_Swap(1, 2);
    // Compare_Swap(3, 4);
}