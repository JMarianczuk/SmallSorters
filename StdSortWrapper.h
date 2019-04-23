
#ifndef STD_SORT_WRAPPER_H
#define STD_SORT_WRAPPER_H

#include <cstdlib>

#include "Sortable.generated.h"

namespace measurement
{

void StdSortWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef* left, SortableRef* right),
    void(*sortFunc)(SortableRef*, size_t));

void QuicksortCopyWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef* left, SortableRef* right),
    void(*sortFunc)(SortableRef*, size_t));

void QuicksortCopyMsvcWrapper(
    SortableRef* first,
    SortableRef* last,
    bool(*compareFunc)(SortableRef* left, SortableRef* right),
    void(*sortFunc)(SortableRef*, size_t));

void SampleSortWrapper(
    SortableRef_FourCmovTemp_Split* first,
    SortableRef_FourCmovTemp_Split* last,
    bool(*compareFunc)(SortableRef_FourCmovTemp_Split* left,SortableRef_FourCmovTemp_Split* right),
    void(*sortFunc)(SortableRef_FourCmovTemp_Split*, size_t));

void InsertionSortWrapper(
    SortableRef_PointerOptimized* first,
    SortableRef_PointerOptimized* last,
    bool(*compareFunc)(SortableRef_PointerOptimized* left,SortableRef_PointerOptimized* right),
    void(*sortFunc)(SortableRef_PointerOptimized*, size_t));
    
}

#endif