
#ifndef MEASUREMENT_SAMPLESORT_HELPER_H
#define MEASUREMENT_SAMPLESORT_HELPER_H

#include <inttypes.h>

#include "../Sortable.generated.h"
#include "../sorters/InsertionSort.h"

namespace measurement
{

void InsertionSortWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef left,SortableRef right))
{
    insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized>(first, last - first);
}

}

#endif