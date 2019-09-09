

#include "StdSortWrapper.h"
#include "Quicksort_Copy.h"
#include "Quicksort_Copy2.h"
#include "../StructHelpers.generated.h"
#include "ska_sort.h"
#include "radix_sort_thrill.h"

namespace measurement
{
    template <typename ValueType>
    bool NormalCompare(ValueType& left, ValueType& right)
    {
        return left < right;
    }

    template <typename ValueType>
    bool IteratorCompare(ValueType* left, ValueType* right)
    {
        return *left < *right;
    }

    template <typename ValueType>
    bool KeySortableCompare(uint64_t& key, ValueType& value)
    {
        return key < GetKey(value);
    }

    void StdSortWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right))
    {
        std::sort(first, last, compareFunc);
    }

    void QuicksortCopyWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right))
    {
        quicksortcopy2::sort(first, last, compareFunc);
    }

    // void QuicksortCopyMsvcWrapper(
    //     SortableRef* first,
    //     SortableRef* last,
    //     bool(*compareFunc)(SortableRef left, SortableRef right))
    // {
    //     quicksortcopy::Quicksort_Copy_Msvc<conditional_swap::CS_Default>(first, last, compareFunc, sortFunc);
    // }

    template <>
    void RadixSortThrillWrapper<static_sorters::SampleSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right))
    {
        thrill::common::RadixSort<static_sorters::SampleSort, SortableRef, 8> sorter(256);
        sorter(first, last, compareFunc);
    }

    template <>
    void RadixSortThrillWrapper<static_sorters::StdSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right))
    {
        thrill::common::RadixSort<static_sorters::StdSort, SortableRef, 8> sorter(256);
        sorter(first, last, compareFunc);
    }

    template <>
    void SkaSortWrapper<static_sorters::SampleSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right))
    {
        skasort::ska_sort<static_sorters::SampleSort>(first, last, [](SortableRef& item) {return item.key;});
    }

    template <>
    void SkaSortWrapper<static_sorters::StdSort>(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right))
    {
        skasort::ska_sort<static_sorters::StdSort>(first, last, [](SortableRef& item) {return item.key;});
    }
    
} // namespace measurement

