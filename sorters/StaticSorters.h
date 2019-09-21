
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
class BestNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::best::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelson::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonParallelNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonparallel::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonParameterNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonparameter::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename Implementation>
class InsertionSort
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        insertionsort::InsertionSort<Implementation, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonRecursiveNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelsonrecursive::sortN<CSwap, ValueType>(array, arraySize);
    }
};

template <typename CSwap>
class BoseNelsonUnrolledNetworks
{
public:
    template <typename ValueType>
    static inline void sort(ValueType* array, size_t arraySize)
    {
        networks::bosenelson_2::sortN<CSwap, ValueType>(array, arraySize);
    }
};

class SampleSort
{
public:
    template <typename ValueType, typename Predicate>
    static inline void sort(ValueType* begin, ValueType* end, Predicate pred)
    {
        samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize<static_sorters::BoseNelsonNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRefKeyGetter>(begin, end - begin, 16, &quicksort::templateLess<SortableRef>);
    }
};

class StdSort
{
public:
    template <typename ValueType, typename Predicate>
    static inline void sort(ValueType* begin, ValueType* end, Predicate pred)
    {
        std::sort(begin, end, pred);
    }
};

template <typename Implementation>
class InsertionSortPred
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