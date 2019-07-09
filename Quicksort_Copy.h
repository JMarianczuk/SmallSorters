
#ifndef QUICKSORT_COPY_H
#define QUICKSORT_COPY_H

#include <utility>
#include <algorithm>
#include <inttypes.h>
#include <type_traits>

#include "CustomMath.h"
#include "networks/BoseNelsonParameter.generated.h"
#include "InsertionSort.h"

namespace quicksortcopy
{

  template<typename _Iterator, typename = std::void_t<>>
    struct __iterator_traits { };

  template<typename _Iterator>
    struct __iterator_traits<_Iterator,
			     std::void_t<typename _Iterator::value_type,
				      typename _Iterator::difference_type>>
    {
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
    };

  template<typename _Iterator>
    struct iterator_traits
    : public __iterator_traits<_Iterator> { };

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

//--------------------------------------------------------------------------------------------------

#define S_threshold 16

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

//---------------------------------------------------------------------------------------------

template<typename TRanIt, typename TCompare>
void unguarded_linear_insert(TRanIt last, TCompare compare)
{
    typename iterator_traits<TRanIt>::value_type val = std::move(*last);
    TRanIt next = last;
    --next;
    while (compare(&val, next))
    {
        *last = std::move(*next);
        last = next;
        --next;
    }
    *last = std::move(val);
}

template<typename TRanIt, typename TCompare>
inline void unguarded_insertion_sort(TRanIt first, TRanIt last, TCompare compare)
{
    for (TRanIt i = first; i != last; ++i)
    {
        unguarded_linear_insert(i, compare);
    }
}

template<typename TRanIt, typename TCompare>
void insertion_sort(TRanIt first, TRanIt last, TCompare compare)
{
    if (first == last) 
    {
        return;
    }

    for (TRanIt i = first + 1; i != last; ++i)
    {
        if (compare(i, first))
        {
            typename iterator_traits<TRanIt>::value_type val = std::move(*i);
            std::move_backward(first, i, i + 1);
            *first = std::move(val);
        }
        else
        {
            unguarded_linear_insert(i, compare);
        }
        
    }
}

template<typename TRanIt, typename TCompare>
void final_insertion_sort(TRanIt first, TRanIt last, TCompare compare)
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

template<typename TRanIt, typename TCompare>
TRanIt unguarded_partition(TRanIt first, TRanIt last, TRanIt pivot, TCompare compare)
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

template<typename TRanIt, typename TCompare>
void move_median_to_first(TRanIt result, TRanIt one, TRanIt two, TRanIt three, TCompare compare)
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

template<typename TRanIt, typename TCompare>
inline 
TRanIt unguarded_partition_pivot(TRanIt first, TRanIt last, TCompare compare)
{
    TRanIt mid = first + (last - first) / 2;
    move_median_to_first(first, first + 1, mid, last - 1, compare);
    return unguarded_partition(first + 1, last, first, compare);
}

template <typename TRanIt, typename TSize, typename TCompare>
void introsort_loop(TRanIt first, TRanIt last, TSize depth_limit, TCompare compare)
{
    while (last - first > S_threshold)
	{
        if (depth_limit == 0)
        {
            partial_sort(first, last, last, compare);
            return;
        }
        --depth_limit;
        TRanIt cut = unguarded_partition_pivot(first, last, compare);
        introsort_loop(cut, last, depth_limit, compare);
        last = cut;
	}
}

template <typename TRanIt, typename TCompare>
void Quicksort_Copy_Stl(TRanIt first, TRanIt last, TCompare compare)
{
    if (first != last)
	{
        introsort_loop(first, last, (int64_t) custommath::intlog2((int) (last - first)) * 2, compare);
        final_insertion_sort(first, last, compare);
	}
}

//-------------------------------------------------------------------------------------------

#define ISortMax 16

template <typename ValueType, typename TPredicate>
inline
void insertion_sort_unchecked(ValueType* first, ValueType* last, TPredicate predicate)
{
    if (first != last)
    {
        for (ValueType* next = first; ++next != last; )
        {
            ValueType val = std::move(*next);

            if (predicate(&val, first))
            {
                std::move_backward(first, next, next+1);
                *first = std::move(val);
            }
            else
            {
                ValueType* next_temp = next;
                for (ValueType* first_temp = next_temp; 
                    predicate(&val, --first_temp); 
                    next_temp = first_temp)
                {
                    *next_temp = std::move(*first_temp);
                }
                *next_temp = std::move(val);
            }
        }
    }
}

template <typename CSwap, typename ValueType, typename TPredicate>
inline
void guess_median_unchecked(ValueType* first, ValueType* mid, ValueType* last, TPredicate predicate)
{
    uint64_t count = (uint64_t) (last - first);
    if (count > 40)
    {
        uint64_t step = (count + 1) >> 3;
        uint64_t twoStep = step << 1;
        networks::bosenelsonparameter::sort9<CSwap>(
            *(first + step), *(first + twoStep), *(mid - step), *mid, 
            *first,
            *(mid + step), *(last - twoStep), *(last - step), *last);
    }
    else
    {
        networks::bosenelsonparameter::sort3<CSwap>(
            *mid, 
            *first, 
            *last);
    }
}

template <typename CSwap, typename ValueType, typename TPredicate>
inline
ValueType* partition_by_median_guess_unchecked(ValueType* first, ValueType* last, TPredicate predicate)
{
    ValueType* mid = first + ((last - first) >> 1);
    guess_median_unchecked<CSwap>(first, mid, last - 1, predicate);

    ValueType* pivot = first;
    while (true)
    {
        ++first;
        --last;
        while (predicate(first, pivot))
        {
            ++first;
        }
        while (predicate(pivot, last))
        {
            --last;
        }
        if (last <= first)
        {
            std::iter_swap(pivot, last);
            return last;
        }
        std::iter_swap(first, last);
    }
}



template <typename CSwap, typename ValueType, typename TPredicate, typename TBaseCaseSort>
inline
void sort_unchecked(ValueType* first, ValueType* last, uint64_t ideal, TPredicate predicate, TBaseCaseSort baseCaseSort)
{
    uint64_t count;
    while (ISortMax < (count = (uint64_t) (last - first)) && ideal > 0)
    {
        auto mid = partition_by_median_guess_unchecked<CSwap>(first, last, predicate);
        auto afterMid = mid + 1;

        ideal = (ideal >> 1) + (ideal >> 2);

        if (mid - first < last - afterMid)
        {
            sort_unchecked<CSwap>(first, mid, ideal, predicate, baseCaseSort);
            first = afterMid;
        }
        else
        {
            sort_unchecked<CSwap>(afterMid, last, ideal, predicate, baseCaseSort);
            last = mid;
        }
    }

    if (count > ISortMax)
    {
        std::partial_sort(first, last, last);
    }
    else if(count >= 2)
    {
        baseCaseSort(first, count);
    }
}

template <typename CSwap, typename ValueType, typename TPredicate, typename TBaseCaseSort>
void Quicksort_Copy_Msvc(ValueType* first, ValueType* last, TPredicate predicate, TBaseCaseSort baseCaseSort)
{
    sort_unchecked<CSwap>(first, last, (uint64_t) (last - first), __gnu_cxx::__ops::__iter_comp_iter(predicate), baseCaseSort);
}

} // namespace quicksortcopy

#endif // QUICKSORT_COPY_H