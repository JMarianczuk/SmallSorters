
#ifndef STD_SORT_WRAPPER_H
#define STD_SORT_WRAPPER_H

#include <cstdlib>

#include "../Sortable.generated.h"
#include "StaticSorters.h"

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

    template <typename BaseCaseSorter>
    void RadixSortThrillWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void RadixSortThrillWrapper<static_sorters::SampleSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void RadixSortThrillWrapper<static_sorters::StdSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void RadixSortThrillWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right));

    template <typename BaseCaseSorter>
    void SkaSortWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void SkaSortWrapper<static_sorters::SampleSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void SkaSortWrapper<static_sorters::StdSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right));

    template <>
    void SkaSortWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right));
    
}

#endif