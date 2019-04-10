

#include "StdSortWrapper.h"
#include "Quicksort_Copy.h"

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

    void StdSortWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef* left, SortableRef* right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        std::sort(first, last, &NormalCompare<SortableRef>);
    }

    void QuicksortCopyWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef* left, SortableRef* right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        quicksortcopy::Quicksort_Copy_Stl(first, last, compareFunc);
    }

    void QuicksortCopyMsvcWrapper(
        SortableRef* first,
        SortableRef* last,
        bool(*compareFunc)(SortableRef* left, SortableRef* right),
        void(*sortFunc)(SortableRef*, size_t))
    {
        quicksortcopy::Quicksort_Copy_Msvc(first, last, compareFunc, sortFunc);
    }

}

