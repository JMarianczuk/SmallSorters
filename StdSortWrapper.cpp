

#include "StdSortWrapper.h"
#include "Quicksort_Copy.h"
#include "Quicksort_Copy2.h"
#include "SampleSort.generated.h"
#include "StructHelpers.generated.h"

namespace measurement
{
    template <typename TValueType>
    bool NormalCompare(TValueType& left, TValueType& right)
    {
        return left < right;
    }

    template <typename TValueType>
    bool IteratorCompare(TValueType* left, TValueType* right)
    {
        return *left < *right;
    }

    template <typename TValueType>
    bool KeySortableCompare(uint64_t& key, TValueType& value)
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
        // quicksortcopy::Quicksort_Copy_Stl(first, last, compareFunc);
    }

    void QuicksortCopyMsvcWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef left, SortableRef right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        quicksortcopy::Quicksort_Copy_Msvc(first, last, compareFunc, sortFunc);
    }

    void SampleSortWrapper(
        SortableRef_FourCmovTemp_Split* first,
        SortableRef_FourCmovTemp_Split* last,
        bool(*compareFunc)(SortableRef_FourCmovTemp_Split left,SortableRef_FourCmovTemp_Split right),
        void(*sortFunc)(SortableRef_FourCmovTemp_Split*, size_t))
    {
        samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(first, last - first, 16, sortFunc, &KeySortableCompare<SortableRef_FourCmovTemp_Split>, &GetKey<SortableRef_FourCmovTemp_Split>);
    }
    
}

