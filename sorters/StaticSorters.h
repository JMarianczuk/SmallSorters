
#ifndef SORTERS_H
#define SORTERS_H

#include "../Sortable.generated.h"
#include "../Networks_Fwd.h"
#include "../sorters/InsertionSort.h"

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

} // namespace static_sorters

#endif // SORTERS_H