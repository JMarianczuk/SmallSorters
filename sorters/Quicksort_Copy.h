
#ifndef QUICKSORT_COPY_H
#define QUICKSORT_COPY_H

#include <utility>
#include <algorithm>
#include <inttypes.h>
#include <type_traits>

#include "../custommath/CustomMath.h"
#include "../networks/BoseNelsonParameter.generated.h"
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

//---------------------------------------------------------------------------------------------

template<typename RandomIterator, typename Compare>
void unguarded_linear_insert(RandomIterator last, Compare compare)
{
    typename iterator_traits<RandomIterator>::value_type val = std::move(*last);
    RandomIterator next = last;
    --next;
    while (compare(&val, next))
    {
        *last = std::move(*next);
        last = next;
        --next;
    }
    *last = std::move(val);
}

template<typename RandomIterator, typename Compare>
inline void unguarded_insertion_sort(RandomIterator first, RandomIterator last, Compare compare)
{
    for (RandomIterator i = first; i != last; ++i)
    {
        unguarded_linear_insert(i, compare);
    }
}

template<typename RandomIterator, typename Compare>
void insertion_sort(RandomIterator first, RandomIterator last, Compare compare)
{
    if (first == last) 
    {
        return;
    }

    for (RandomIterator i = first + 1; i != last; ++i)
    {
        if (compare(i, first))
        {
            typename iterator_traits<RandomIterator>::value_type val = std::move(*i);
            std::move_backward(first, i, i + 1);
            *first = std::move(val);
        }
        else
        {
            unguarded_linear_insert(i, compare);
        }
        
    }
}

template<typename RandomIterator, typename Compare>
void final_insertion_sort(RandomIterator first, RandomIterator last, Compare compare)
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

template<typename RandomIterator, typename Compare>
RandomIterator unguarded_partition(RandomIterator first, RandomIterator last, RandomIterator pivot, Compare compare)
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

template<typename RandomIterator, typename Compare>
void move_median_to_first(RandomIterator result, RandomIterator one, RandomIterator two, RandomIterator three, Compare compare)
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

template<typename RandomIterator, typename Compare>
inline 
RandomIterator unguarded_partition_pivot(RandomIterator first, RandomIterator last, Compare compare)
{
    RandomIterator mid = first + (last - first) / 2;
    move_median_to_first(first, first + 1, mid, last - 1, compare);
    return unguarded_partition(first + 1, last, first, compare);
}

template <typename RandomIterator, typename Size, typename Compare>
void introsort_loop(RandomIterator first, RandomIterator last, Size depth_limit, Compare compare)
{
    while (last - first > S_threshold)
	{
        if (depth_limit == 0)
        {
            partial_sort(first, last, last, compare);
            return;
        }
        --depth_limit;
        RandomIterator cut = unguarded_partition_pivot(first, last, compare);
        introsort_loop(cut, last, depth_limit, compare);
        last = cut;
	}
}

template <typename RandomIterator, typename Compare>
void Quicksort_Copy_Stl(RandomIterator first, RandomIterator last, Compare compare)
{
    if (first != last)
	{
        introsort_loop(first, last, (int64_t) custommath::intlog2((int) (last - first)) * 2, compare);
        final_insertion_sort(first, last, compare);
	}
}

//-------------------------------------------------------------------------------------------

#define ISortMax 16

template <typename ValueType, typename Predicate>
inline
void insertion_sort_unchecked(ValueType* first, ValueType* last, Predicate predicate)
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

template <typename CSwap, typename ValueType, typename Predicate>
inline
void guess_median_unchecked(ValueType* first, ValueType* mid, ValueType* last, Predicate predicate)
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

template <typename CSwap, typename ValueType, typename Predicate>
inline
ValueType* partition_by_median_guess_unchecked(ValueType* first, ValueType* last, Predicate predicate)
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



template <typename CSwap, typename ValueType, typename Predicate, typename BaseCaseSort>
inline
void sort_unchecked(ValueType* first, ValueType* last, uint64_t ideal, Predicate predicate, BaseCaseSort baseCaseSort)
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

template <typename CSwap, typename ValueType, typename Predicate, typename BaseCaseSort>
void Quicksort_Copy_Msvc(ValueType* first, ValueType* last, Predicate predicate, BaseCaseSort baseCaseSort)
{
    sort_unchecked<CSwap>(first, last, (uint64_t) (last - first), __gnu_cxx::__ops::__iter_comp_iter(predicate), baseCaseSort);
}

} // namespace quicksortcopy

#endif // QUICKSORT_COPY_H