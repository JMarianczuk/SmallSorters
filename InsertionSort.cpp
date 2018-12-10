
#include "InsertionSort.h"

void InsertionSort(SortableRef* items) {
    int inner, outer;
    for (outer = 1; outer < ArraySize; outer += 1) {
        SortableRef current = items[outer];
        for (inner = outer; inner > 0 && items[inner - 1].key > current.key; inner -= 1) {
            items[inner] = items[inner - 1];
        }
        items[inner] = current;
    }
}