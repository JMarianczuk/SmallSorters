
#ifndef QUICKSORT_COPY2_H
#define QUICKSORT_COPY2_H

#include <algorithm>
#include "CustomMath.h"

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

// template<typename _Compare>
// struct _Iter_comp_iter
// {
//     _Compare _M_comp;

//     explicit _GLIBCXX14_CONSTEXPR
//     _Iter_comp_iter(_Compare __comp) : _M_comp(std::move(__comp))
//     { }

//     template<typename _Iterator1, typename _Iterator2>
//     _GLIBCXX14_CONSTEXPR
//     bool
//     operator()(_Iterator1 __it1, _Iterator2 __it2)
//     { return bool(_M_comp(*__it1, *__it2)); }
// };

// template<typename _Compare>
// struct _Val_comp_iter
// {
//     _Compare _M_comp;

//     explicit
//     _Val_comp_iter(_Compare __comp) : _M_comp(std::move(__comp))
//     { }

//     explicit
//     _Val_comp_iter(const _Iter_comp_iter<_Compare>& __comp) : _M_comp(__comp._M_comp)
//     { }

//     explicit
//     _Val_comp_iter(_Iter_comp_iter<_Compare>&& __comp) : _M_comp(std::move(__comp._M_comp))
//     { }

//     template<typename _Value, typename _Iterator>
//     bool
//     operator()(_Value& __val, _Iterator __it)
//     { return bool(_M_comp(__val, *__it)); }
// };

// template<typename _Compare>
// inline _Val_comp_iter<_Compare>
// __val_comp_iter(_Compare __comp)
// { return _Val_comp_iter<_Compare>(std::move(__comp)); }

// template<typename _Compare>
// inline _Val_comp_iter<_Compare>
// __val_comp_iter(_Iter_comp_iter<_Compare> __comp)
// { return _Val_comp_iter<_Compare>(std::move(__comp)); }

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
        std::__unguarded_linear_insert(__i, __gnu_cxx::__ops::__val_comp_iter(__comp));
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
            __unguarded_linear_insert(__i, __gnu_cxx::__ops::__val_comp_iter(__comp));
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
            std::iter_swap(__result, __b);
        else if (__comp(__a, __c))
            std::iter_swap(__result, __c);
        else
            std::iter_swap(__result, __a);
    }
    else if (__comp(__a, __c))
        std::iter_swap(__result, __a);
    else if (__comp(__b, __c))
        std::iter_swap(__result, __c);
    else
        std::iter_swap(__result, __b);
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
            ++__first;
        --__last;
        while (__comp(__pivot, __last))
            --__last;
        if (!(__first < __last))
            return __first;
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
            std::partial_sort(__first, __last, __last);
            return;
        }
        --__depth_limit;
        _RandomAccessIterator __cut =
        __unguarded_partition_pivot(__first, __last, __comp);
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
        __introsort_loop(__first, __last, custommath::longlog2(__last - __first) * 2, __comp);
        __final_insertion_sort(__first, __last, __comp);
    }
}

template<typename _RandomAccessIterator, typename _Compare>
inline void
sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Compare __comp)
{
    __sort(__first, __last, __gnu_cxx::__ops::__iter_comp_iter(__comp));
}

}

#endif