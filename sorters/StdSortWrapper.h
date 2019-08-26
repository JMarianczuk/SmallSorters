
#ifndef STD_SORT_WRAPPER_H
#define STD_SORT_WRAPPER_H

#include <cstdlib>

#include "../Sortable.generated.h"

namespace measurement
{

void StdSortWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef left, SortableRef right));

void QuicksortCopyWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef left, SortableRef right));

// void QuicksortCopyMsvcWrapper(
//     SortableRef* first,
//     SortableRef* last,
//     bool(*compareFunc)(SortableRef left, SortableRef right),
//     void(*sortFunc)(SortableRef*, size_t));

// void SampleSortWrapper(
//     SortableRef* first,
//     SortableRef* last,
//     bool(*compareFunc)(SortableRef left,SortableRef right),
//     void(*sortFunc)(SortableRef*, size_t));

void InsertionSortWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef* left,SortableRef* right));

void RadixSortThrillWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef left,SortableRef right));

void SkaSortWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef left,SortableRef right));
    
}

#endif