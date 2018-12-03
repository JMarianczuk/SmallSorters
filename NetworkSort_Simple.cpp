
#include "NetworkSort_Simple.h"

void Compare(Sortable* items, int left, int right) {
    Sortable tmp = items[left];
    // __asm__(
    //     "cmpq %[left_key],%[right_key]\n"
    //     "cmovbq %[items_left],%[items_right]\n"
    //     "cmovbq %[items_right],%[tmp]\n"
    //     : [items_left] "+r"(items[left]), [items_right] "+r"(items[right])
    //     : [tmp] "rm"(tmp), [left_key] "x"(items[left].key), [right_key] "xm"(items[right].key)
    //     : "cc"
    // );
}

void NetworkSortSimple_Naive(Sortable* items) {

}

void NetworkSortSimple_Optimised(Sortable* items) {
    Compare(items, 0, 1);
    Compare(items, 3, 4);
    Compare(items, 0, 2);
    Compare(items, 1, 2);
    Compare(items, 0, 3);
    Compare(items, 2, 3);
    Compare(items, 1, 4);
    Compare(items, 1, 2);
    Compare(items, 3, 4);
}