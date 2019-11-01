
#ifndef SORTERS_H
#define SORTERS_H

#include <algorithm>

#include "../Sortable.generated.h"
#include "../Networks_Fwd.h"
#include "InsertionSort.h"
#include "SampleSort.generated.h"
#include "QuickSort.h"
#include "../StructHelpers.generated.h"

namespace static_sorters
{

template <typename CSwap>
class BestNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::best::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelson::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonParallelNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonparallel::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonParameterNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonparameter::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename Implementation>
class InsertionSort final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        insertionsort::InsertionSort<Implementation, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonRecursiveNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonrecursive::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonUnrolledNetworks final
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelson_2::sortN<CSwap, ValueType>(array, arraySize);
    }
};

class SampleSort final
{
public:
    template <typename ValueType, typename Predicate>
    static inline void sort(ValueType* begin, ValueType* end, Predicate pred)
    {
        samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize<static_sorters::BoseNelsonNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRefKeyGetter>(begin, end - begin, 16, &quicksort::templateLess<SortableRef>);
    }
};

class StdSort final
{
public:
    template <typename ValueType, typename Predicate>
    static inline void sort(ValueType* begin, ValueType* end, Predicate pred)
    {
        std::sort(begin, end, pred);
    }
};

template <typename Implementation>
class InsertionSortPred final
{
public:
    template <typename ValueType, typename Predicate>
    static inline void sort(ValueType* begin, ValueType* end, Predicate pred)
    {
        InsertionSort<Implementation>::sort(begin, end - begin);
    }
};

} // namespace static_sorters

#endif // SORTERS_H