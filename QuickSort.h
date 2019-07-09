
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <inttypes.h>

#include "CustomMath.h"
#include "DebugHelper.h"
#include "SampleSort.generated.h"
#include "networks/BoseNelsonParameter.generated.h"

namespace quicksort
{

#define BaseCaseLimit 16

template <typename TValueType>
static inline
void QuickSort(TValueType* items, size_t arraySize, void (*sortFunc)(TValueType*,size_t))
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

template <typename TValueType>
static inline
bool templateLess(uint64_t& leftKey, TValueType& right)
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

template <typename TRanIt, typename TDistance, typename TValueType, typename TCompare>
void push_heap(TRanIt first, TDistance holeIndex, TDistance topIndex, TValueType value, TCompare& compare)
{
    TDistance parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && compare(first + parent, &value))
    {
        *(first + holeIndex) = std::move(*(first + parent));
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = std::move(value);
}

template <typename TRanIt, typename TDistance, typename TValueType, typename TCompare>
void adjust_heap(TRanIt first, TDistance holeIndex, TDistance len, TValueType value, TCompare compare)
{
    const TDistance topIndex = holeIndex;
    TDistance secondChild = holeIndex;
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

template <typename TRanIt, typename TCompare>
void make_heap(TRanIt first, TRanIt last, TCompare& compare)
{
    typedef typename iterator_traits<TRanIt>::value_type TValueType;
    typedef typename iterator_traits<TRanIt>::difference_type TDistanceType;
    if (last - first < 2)
    {
        return;
    }

    const TDistanceType len = last - first;
    TDistanceType parent = (len - 2) / 2;
    while (true)
    {
        TValueType value = std::move(*(first + parent));
        adjust_heap(first, parent, len, std::move(value), compare);
        if (parent == 0)
        {
            return;
        }
        parent--;
    }
}

template <typename TRanIt, typename TCompare>
inline
void pop_heap(TRanIt first, TRanIt last, TRanIt result, TCompare& compare)
{
    typedef typename iterator_traits<TRanIt>::value_type TValueType;
    typedef typename iterator_traits<TRanIt>::difference_type TDistanceType;

    TValueType value = std::move(*result);
    *result = std::move(*first);
    adjust_heap(first, TDistanceType(0), TDistanceType(last - first), std::move(value), compare);
}

template <typename TRanIt, typename TCompare>
void sort_heap(TRanIt first, TRanIt last, TCompare& compare)
{
    while (last - first > 1)
    {
        --last;
        pop_heap(first, last, last, compare);
    }
}


template <typename TRanIt, typename TCompare>
void heap_select(TRanIt first, TRanIt middle, TRanIt last, TCompare compare)
{
    make_heap(first, middle, compare);
    for (TRanIt i = middle; i < last; ++i)
    {
        if (compare(i, first))
        {
            pop_heap(first, middle, i, compare);
        }
    }
}

template <typename TRanIt, typename TCompare>
inline
void partial_sort(TRanIt first, TRanIt middle, TRanIt last, TCompare compare)
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
    networks::bosenelsonparameter::sort3(*__mid, *__first, *(__last-1));
    return __unguarded_partition(__first + 1, __last, __first, __comp);
}

template<typename _RandomAccessIterator, typename _Size, typename _Compare, typename _BaseCaseFunc>
void
__introsort_loop(
    _RandomAccessIterator __first,
    _RandomAccessIterator __last,
    _Size __depth_limit, 
    _Compare __comp, 
    _BaseCaseFunc __baseCaseFunc)
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
        __introsort_loop(__cut, __last, __depth_limit, __comp, __baseCaseFunc);
        __last = __cut;
    }
    __baseCaseFunc(__first, __last - __first);
}

template<typename _RandomAccessIterator, typename _Compare, typename _BaseCaseFunc>
inline void
__sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp, _BaseCaseFunc __baseCaseFunc)
{
    if (__first != __last)
    {
        __introsort_loop(__first, __last, custommath::longlog2(__last - __first) * 2, __comp, __baseCaseFunc);
    }
}

template<typename TValueType>
inline void
sort(TValueType* __first, TValueType* __last, bool(*__comp)(TValueType,TValueType), void(*__baseCaseFunc)(TValueType*,size_t))
{
    __sort(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp), __baseCaseFunc);
}

} // quicksort

#endif // QUICKSORT_H