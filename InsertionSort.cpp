
#include "InsertionSort.h"

void InsertionSort(Sortable* items) {
    int inner, outer;
    for (outer = 1; outer < ArraySize; outer += 1) {
        Sortable current = items[outer];
        for (inner = outer; inner > 0 && items[inner - 1].key > current.key; inner -= 1) {
            items[inner] = items[inner - 1];
        }
        items[inner] = current;
    }
}