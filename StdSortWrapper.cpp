

#include "StdSortWrapper.h"
#include "Quicksort_Copy.h"
#include "Quicksort_Copy2.h"
#include "SampleSort.generated.h"
#include "StructHelpers.generated.h"
#include "conditional_swap/ConditionalSwapGeneric.h"

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
        bool(*compareFunc)(SortableRef left, SortableRef right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        std::sort(first, last, compareFunc);
    }

    void QuicksortCopyWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        quicksortcopy2::sort(first, last, compareFunc);
    }

    void QuicksortCopyMsvcWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        quicksortcopy::Quicksort_Copy_Msvc<conditional_swap::CS_Default>(first, last, compareFunc, sortFunc);
    }

    void SampleSortWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left,SortableRef right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(first, last - first, 16, sortFunc, &KeySortableCompare<SortableRef>, &GetKey<SortableRef>);
    }
    
} // namespace measurement

