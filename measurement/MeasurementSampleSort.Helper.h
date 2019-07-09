
#ifndef MEASUREMENT_SAMPLESORT_HELPER_H
#define MEASUREMENT_SAMPLESORT_HELPER_H

#include <inttypes.h>

#include "../Sortable.generated.h"
#include "../InsertionSort.h"

namespace measurement
{

void InsertionSortWrapper(
    SortableRef_PointerOptimized* first,
    SortableRef_PointerOptimized* last,
    bool(*compareFunc)(SortableRef_PointerOptimized left,SortableRef_PointerOptimized right),
    void(*sortFunc)(SortableRef_PointerOptimized*, size_t))
{
    insertionsort::InsertionSort(first, last - first);
}

}

#endif