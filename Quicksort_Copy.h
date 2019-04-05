
#ifndef QUICKSORT_COPY_H
#define QUICKSORT_COPY_H

#include <utility>
#include <algorithm>

#include "CustomMath.h"

namespace quicksortcopy
{

#define S_threshold 16

// template<typename _RandomAccessIterator, typename _Distance,
// 	   typename _Tp, typename _Compare>
// void __adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
//         _Distance __len, _Tp __value, _Compare __comp)
// {
//     const _Distance __topIndex = __holeIndex;
//     _Distance __secondChild = __holeIndex;
//     while (__secondChild < (__len - 1) / 2)
//     {
//         __secondChild = 2 * (__secondChild + 1);
//         if (__comp(__first + __secondChild,
//                 __first + (__secondChild - 1)))
//         __secondChild--;
//         *(__first + __holeIndex) = std::move(*(__first + __secondChild));
//         __holeIndex = __secondChild;
//     }

//     if ((__len & 1) == 0 && __secondChild == (__len - 2) / 2)
//     {
//         __secondChild = 2 * (__secondChild + 1);
//         *(__first + __holeIndex) = std::move(*(__first
//                                 + (__secondChild - 1)));
//         __holeIndex = __secondChild - 1;
//     }
//     __decltype(__gnu_cxx::__ops::__iter_comp_val(std::move(__comp)))
// __cmp(std::move(__comp));
//     std::__push_heap(__first, __holeIndex, __topIndex,
//             std::move(__value), __cmp);
// }

// template<typename _RandomAccessIterator, typename _Compare>
// void make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
//     _Compare& __comp)
// {
//     typedef typename iterator_traits<_RandomAccessIterator>::value_type _ValueType;
//     typedef typename iterator_traits<_RandomAccessIterator>::difference_type _DistanceType;

//     if (__last - __first < 2)
//     {
//         return;
//     }

//     const _DistanceType __len = __last - __first;
//     _DistanceType __parent = (__len - 2) / 2;
//     while (true)
//     {
//         _ValueType __value = std::move(*(__first + __parent));
//         std::__adjust_heap(__first, __parent, __len, std::move(__value), __comp);
//         if (__parent == 0)
//         {
//             return;
//         }
//         __parent--;
//     }
// }

// template<typename TValueType*, typename TCompare>
// void heap_select(TValueType* first, TValueType* middle, TValueType* last, TCompare compare)
// {
//     make_heap(first, middle, compare);
//     // for (TValueType* i = middle; i < last; ++i)
//     // {
//     //     if (compare(i, first))
//     //     {
//     //         pop_heap(first, middle, i, compare);
//     //     }
//     // }
    
// }

// template <typename TValueType*, typename TCompare>
// void partial_sort(TValueType* first, TValueType* middle, TValueType* last, TCompare compare)
// {
//     heap_select(first, middle, last, compare);
//     sort_heap(first, middle, compare);
// }

template<typename TValueType, typename TCompare>
void unguarded_linear_insert(TValueType* last, TCompare compare)
{
    TValueType val = std::move(*last);
    TValueType* next = last;
    --next;
    while (compare(&val, next))
    {
        *last = std::move(*next);
        last = next;
        --next;
    }
    *last = std::move(val);
}

template<typename TValueType, typename TCompare>
inline void unguarded_insertion_sort(TValueType* first, TValueType* last, TCompare compare)
{
    for (TValueType* i = first; i != last; ++i)
    {
        unguarded_linear_insert(i, compare);
    }
}

template<typename TValueType, typename TCompare>
void insertion_sort(TValueType* first,
            TValueType* last, TCompare compare)
{
    if (first == last) 
    {
        return;
    }

    for (TValueType* i = first + 1; i != last; ++i)
    {
        if (compare(i, first))
        {
            TValueType val = std::move(*i);
            std::move_backward(first, i, i + 1);
            *first = std::move(val);
        }
        else
        {
            unguarded_linear_insert(i, compare);
        }
        
    }
}

template<typename TValueType, typename TCompare>
void final_insertion_sort(TValueType* first, TValueType* last, TCompare compare)
{
    if (last - first > S_threshold)
    {
        insertion_sort(first, first + S_threshold, compare);
        unguarded_insertion_sort(first + S_threshold, last, compare);
    }
    else
    {
        insertion_sort(first, last, compare);
    }
}

template<typename TValueType, typename TCompare>
TValueType* unguarded_partition(TValueType* first, TValueType* last, TValueType* pivot, TCompare compare)
{
    while (true)
    {
        while (compare(first, pivot))
        {
            ++first;
        }
        --last;
        while (compare(pivot, last))
        {
            --last;
        }
        if (!(first < last))
        {
            return first;
        }
        std::iter_swap(first, last);
        ++first;
    }
}

template<typename TValueType, typename TCompare>
void move_median_to_first(TValueType* result, TValueType* one, TValueType* two, TValueType* three, TCompare compare)
{
    if (compare(one, two))
    {
        if (compare(two, three))
        {
            std::iter_swap(result, two);
        }
        else if (compare(one, three))
        {
            std::iter_swap(result, three);
        }
        else
        {
            std::iter_swap(result, one);
        }
        
    }
    else if (compare(one, three))
    {
        std::iter_swap(result, one);
    }
    else if (compare(two, three))
    {
        std::iter_swap(result, three);
    }
    else
    {
        std::iter_swap(result, two);
    }
}

template<typename TValueType, typename TCompare>
inline TValueType* unguarded_partition_pivot(TValueType* first, TValueType* last, TCompare compare)
{
    TValueType* mid = first + (last - first) / 2;
    move_median_to_first(first, first + 1, mid, last - 1, compare);
    return unguarded_partition(first + 1, last, first, compare);
}


template <typename TValueType, typename TSize, typename TCompare>
void introsort_loop(TValueType* first, TValueType* last, TSize depth_limit, TCompare compare)
{
    while (last - first > S_threshold)
	{
        if (depth_limit == 0)
        {
            std::partial_sort(first, last, last);
            return;
        }
        --depth_limit;
        TValueType* cut =
        unguarded_partition_pivot(first, last, compare);
        introsort_loop(cut, last, depth_limit, compare);
        last = cut;
	}
}

template <typename TValueType, typename TCompare>
void Quicksort_Copy_Stl(TValueType* first, TValueType* last, TCompare compare)
{
    if (first != last)
	{
        introsort_loop(first, last, custommath::intlog2((int) (last - first)) * 2, compare);
        final_insertion_sort(first, last, compare);
	}
}

}

#endif