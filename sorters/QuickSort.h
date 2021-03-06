
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <inttypes.h>

#include "../custommath/CustomMath.h"
#include "../DebugHelper.h"
#include "SampleSort.generated.h"
#include "../networks/BoseNelsonParameter.generated.h"
#include "../conditional_swap/ConditionalSwap.h"

namespace quicksort
{

#define BaseCaseLimit 16

template <typename ValueType>
static inline
void QuickSort(ValueType* items, size_t arraySize, void (*sortFunc)(ValueType*,size_t))
{
    if (arraySize > BaseCaseLimit)
    {
        auto mid = arraySize / 2;
        auto pivot = items[mid];
        int last = arraySize - 1;
        std::swap(items[mid], items[last]);
        int firstGreater = 0;
        for (int current = 0; current < last; current += 1)
        {
            if (items[current] <= pivot)
            {
                std::swap(items[current], items[firstGreater]);
                firstGreater += 1;
            }
        }
        std::swap(items[firstGreater], items[last]);
        QuickSort(items, firstGreater, sortFunc);
        QuickSort(items + firstGreater + 1, last - firstGreater, sortFunc);
    }
    else if (arraySize >= 2)
    {
        sortFunc(items, arraySize);
    }
}

template <typename ValueType>
static inline
bool templateLess(uint64_t& leftKey, ValueType& right)
{
    return leftKey < GetKey(right);
}

//------------------------------------------------------------------------------------

template<typename _Iterator, typename = std::void_t<>>
    struct __iterator_traits { };

template<typename _Iterator>
struct __iterator_traits<_Iterator, std::void_t<typename _Iterator::value_type, typename _Iterator::difference_type>>
{
    typedef typename _Iterator::value_type        value_type;
    typedef typename _Iterator::difference_type   difference_type;
};

template<typename _Iterator>
struct iterator_traits : public __iterator_traits<_Iterator> { };

    /// Partial specialization for pointer types.
template<typename _Tp>
struct iterator_traits<_Tp*>
{
    typedef _Tp                         value_type;
    typedef ptrdiff_t                   difference_type;
};

/// Partial specialization for const pointer types.
template<typename _Tp>
struct iterator_traits<const _Tp*>
{
    typedef _Tp                         value_type;
    typedef ptrdiff_t                   difference_type;
};

enum { _S_threshold = 16 };

//-------------------------------------------------------------------------------------------------------------

template <typename RandomIterator, typename Distance, typename ValueType, typename Compare>
void push_heap(RandomIterator first, Distance holeIndex, Distance topIndex, ValueType value, Compare& compare)
{
    Distance parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && compare(first + parent, &value))
    {
        *(first + holeIndex) = std::move(*(first + parent));
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = std::move(value);
}

template <typename RandomIterator, typename Distance, typename ValueType, typename Compare>
void adjust_heap(RandomIterator first, Distance holeIndex, Distance len, ValueType value, Compare compare)
{
    const Distance topIndex = holeIndex;
    Distance secondChild = holeIndex;
    while (secondChild < (len - 1) / 2)
    {
        secondChild = 2 * (secondChild + 1);
        if (compare(first + secondChild, first + (secondChild - 1)))
        {
            secondChild--;
        }
        *(first + holeIndex) = std::move(*(first + secondChild));
        holeIndex = secondChild;
    }

    if ((len & 1) == 0 && secondChild == (len - 2) / 2)
    {
        secondChild = 2 * (secondChild + 1);
        *(first + holeIndex) = std::move(*(first + (secondChild - 1)));
        holeIndex = secondChild - 1;
    }

    push_heap(first, holeIndex, topIndex, std::move(value), compare);
}

template <typename RandomIterator, typename Compare>
void make_heap(RandomIterator first, RandomIterator last, Compare& compare)
{
    typedef typename iterator_traits<RandomIterator>::value_type ValueType;
    typedef typename iterator_traits<RandomIterator>::difference_type DistanceType;
    if (last - first < 2)
    {
        return;
    }

    const DistanceType len = last - first;
    DistanceType parent = (len - 2) / 2;
    while (true)
    {
        ValueType value = std::move(*(first + parent));
        adjust_heap(first, parent, len, std::move(value), compare);
        if (parent == 0)
        {
            return;
        }
        parent--;
    }
}

template <typename RandomIterator, typename Compare>
inline
void pop_heap(RandomIterator first, RandomIterator last, RandomIterator result, Compare& compare)
{
    typedef typename iterator_traits<RandomIterator>::value_type ValueType;
    typedef typename iterator_traits<RandomIterator>::difference_type DistanceType;

    ValueType value = std::move(*result);
    *result = std::move(*first);
    adjust_heap(first, DistanceType(0), DistanceType(last - first), std::move(value), compare);
}

template <typename RandomIterator, typename Compare>
void sort_heap(RandomIterator first, RandomIterator last, Compare& compare)
{
    while (last - first > 1)
    {
        --last;
        pop_heap(first, last, last, compare);
    }
}


template <typename RandomIterator, typename Compare>
void heap_select(RandomIterator first, RandomIterator middle, RandomIterator last, Compare compare)
{
    make_heap(first, middle, compare);
    for (RandomIterator i = middle; i < last; ++i)
    {
        if (compare(i, first))
        {
            pop_heap(first, middle, i, compare);
        }
    }
}

template <typename RandomIterator, typename Compare>
inline
void partial_sort(RandomIterator first, RandomIterator middle, RandomIterator last, Compare compare)
{
    heap_select(first, middle, last, compare);
    sort_heap(first, middle, compare);
}


//-------------------------------------------------------------------------------------------------------------

template<typename _RandomAccessIterator, typename _Compare>
_RandomAccessIterator
__unguarded_partition(_RandomAccessIterator __first,
            _RandomAccessIterator __last,
            _RandomAccessIterator __pivot, _Compare __comp)
{
    while (true)
    {
        while (__comp(__first, __pivot))
        {
            ++__first;
        }
        --__last;
        while (__comp(__pivot, __last))
        {
            --__last;
        }
        if (!(__first < __last))
        {
            return __first;
        }
        std::iter_swap(__first, __last);
        ++__first;
    }
}

template<typename _RandomAccessIterator, typename _Compare>
inline _RandomAccessIterator
__unguarded_partition_pivot(_RandomAccessIterator __first,
            _RandomAccessIterator __last, _Compare __comp)
{
    _RandomAccessIterator __mid = __first + (__last - __first) / 2;
    networks::bosenelsonparameter::sort3<conditional_swap::CS_FourCmovTemp_Split>(*__mid, *__first, *(__last-1));
    return __unguarded_partition(__first + 1, __last, __first, __comp);
}

template<typename BaseCaseSorter, typename _RandomAccessIterator, typename _Size, typename _Compare>
void
__introsort_loop(
    _RandomAccessIterator __first,
    _RandomAccessIterator __last,
    _Size __depth_limit, 
    _Compare __comp)
{
    while (__last - __first > int(_S_threshold))
    {
        if (__depth_limit == 0)
        {
            partial_sort(__first, __last, __last, __comp);
            return;
        }
        --__depth_limit;
        _RandomAccessIterator __cut = __unguarded_partition_pivot(__first, __last, __comp);
        __introsort_loop<BaseCaseSorter>(__cut, __last, __depth_limit, __comp);
        __last = __cut;
    }
    BaseCaseSorter::sort(__first, __last - __first);
}

template <typename BaseCaseSorter, typename _RandomAccessIterator, typename _Compare>
inline void
__sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        __introsort_loop<BaseCaseSorter>(__first, __last, custommath::longlog2(__last - __first) * 2, __comp);
    }
}

template <typename BaseCaseSorter, typename ValueType>
inline void
sort(ValueType* __first, ValueType* __last, bool(*__comp)(ValueType,ValueType))
{
    __sort<BaseCaseSorter>(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp));
}

} // quicksort

#endif // QUICKSORT_H