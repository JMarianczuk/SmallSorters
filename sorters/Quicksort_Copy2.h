
#ifndef QUICKSORT_COPY2_H
#define QUICKSORT_COPY2_H

#include <algorithm>
#include "../CustomMath.h"

namespace quicksortcopy2
{

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

template <typename TRanIt, typename TDistance, typename ValueType, typename TCompare>
void push_heap(TRanIt first, TDistance holeIndex, TDistance topIndex, ValueType value, TCompare& compare)
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

template <typename TRanIt, typename TDistance, typename ValueType, typename TCompare>
void adjust_heap(TRanIt first, TDistance holeIndex, TDistance len, ValueType value, TCompare compare)
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
    typedef typename iterator_traits<TRanIt>::value_type ValueType;
    typedef typename iterator_traits<TRanIt>::difference_type TDistanceType;
    if (last - first < 2)
    {
        return;
    }

    const TDistanceType len = last - first;
    TDistanceType parent = (len - 2) / 2;
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

template <typename TRanIt, typename TCompare>
inline
void pop_heap(TRanIt first, TRanIt last, TRanIt result, TCompare& compare)
{
    typedef typename iterator_traits<TRanIt>::value_type ValueType;
    typedef typename iterator_traits<TRanIt>::difference_type TDistanceType;

    ValueType value = std::move(*result);
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
void
__unguarded_linear_insert(_RandomAccessIterator __last, _Compare __comp)
{
    typename iterator_traits<_RandomAccessIterator>::value_type __val = std::move(*__last);
    _RandomAccessIterator __next = __last;
    --__next;
    while (__comp(__val, __next))
    {
        *__last = std::move(*__next);
        __last = __next;
        --__next;
    }
    *__last = std::move(__val);
}

template<typename _RandomAccessIterator, typename _Compare>
inline void
__unguarded_insertion_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    for (_RandomAccessIterator __i = __first; __i != __last; ++__i)
    {
        std::__unguarded_linear_insert(__i, __gnu_cxx::__ops::__val_comp_iter(__comp));
    }
}

template<typename _RandomAccessIterator, typename _Compare>
void
__insertion_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    if (__first == __last) return;

    for (_RandomAccessIterator __i = __first + 1; __i != __last; ++__i)
    {
        if (__comp(__i, __first))
        {
            typename iterator_traits<_RandomAccessIterator>::value_type __val = std::move(*__i);
            std::move_backward(__first, __i, __i + 1);
            *__first = std::move(__val);
        }
        else
        {
            __unguarded_linear_insert(__i, __gnu_cxx::__ops::__val_comp_iter(__comp));
        }
    }
}

template<typename _RandomAccessIterator, typename _Compare>
void
__final_insertion_sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    if (__last - __first > int(_S_threshold))
    {
        __insertion_sort(__first, __first + int(_S_threshold), __comp);
        __unguarded_insertion_sort(__first + int(_S_threshold), __last, __comp);
    }
    else
        __insertion_sort(__first, __last, __comp);
}

template<typename _Iterator, typename _Compare>
void
__move_median_to_first(_Iterator __result,_Iterator __a, _Iterator __b, _Iterator __c, _Compare __comp)
{
    if (__comp(__a, __b))
    {
        if (__comp(__b, __c))
        {
            std::iter_swap(__result, __b);
        }
        else if (__comp(__a, __c))
        {
            std::iter_swap(__result, __c);
        }
        else
        {
            std::iter_swap(__result, __a);
        }
    }
    else if (__comp(__a, __c))
    {
        std::iter_swap(__result, __a);
    }
    else if (__comp(__b, __c))
    {
        std::iter_swap(__result, __c);
    }
    else
    {
        std::iter_swap(__result, __b);
    }
}

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
    __move_median_to_first(__first, __first + 1, __mid, __last - 1, __comp);
    return __unguarded_partition(__first + 1, __last, __first, __comp);
}

template<typename _RandomAccessIterator, typename _Size, typename _Compare>
void
__introsort_loop(_RandomAccessIterator __first,
            _RandomAccessIterator __last,
            _Size __depth_limit, _Compare __comp)
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
        __introsort_loop(__cut, __last, __depth_limit, __comp);
        __last = __cut;
    }
}

template<typename _RandomAccessIterator, typename _Compare>
inline void
__sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    if (__first != __last)
    {
        __introsort_loop(__first, __last, custommath::intlog2(__last - __first) * 2, __comp);
        __final_insertion_sort(__first, __last, __comp);
    }
}

template<typename _RandomAccessIterator, typename _Compare>
inline void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    __sort(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp));
}

} // namespace quicksortcopy2

#endif // QUICKSORT_COPY2_H