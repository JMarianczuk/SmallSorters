
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <inttypes.h>

#include "CustomMath.h"
#include "DebugHelper.h"
#include "SampleSort.generated.h"
#include "BoseNelsonParameter.generated.h"

namespace quicksort
{

#define BaseCaseLimit 16

template <typename TValueType>
static inline
void QuickSort(TValueType* items, size_t arraySize, void (*sortFunc)(TValueType*,size_t))
{
    if (arraySize > BaseCaseLimit)
    {
        // debug::WriteLine("Sorting non base case: ", std::to_string(arraySize));
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
        // debug::WriteLine("Sorting base case: ", std::to_string(arraySize));
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
__move_median_to_first(_Iterator __result, _Iterator __a, _Iterator __b, _Iterator __c, _Compare __comp)
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
    // __move_median_to_first(__first, __first + 1, __mid, __last - 1, __comp);
    networks::sort3bosenelsonparameter(*__mid, *__first, *(__last-1));
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
            std::partial_sort(__first, __last, __last);
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
        // __final_insertion_sort(__first, __last, __comp);
    }
}

template<typename TValueType>
inline void
sort(TValueType* __first, TValueType* __last, bool(*__comp)(TValueType,TValueType), void(*__baseCaseFunc)(TValueType*,size_t))
{
    __sort(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp), __baseCaseFunc);
}

}

#endif