
#ifndef QUICKSORT_COPY_H
#define QUICKSORT_COPY_H

#include <utility>
#include <algorithm>
#include <inttypes.h>

#include "CustomMath.h"
#include "BoseNelsonParameter.generated.h"
#include "InsertionSort.h"

namespace quicksortcopy
{

#define S_threshold 16

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
void insertion_sort(TValueType* first, TValueType* last, TCompare compare)
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

//-------------------------------------------------------------------------------------------

#define ISortMax 32

template <typename TValueType, typename TPredicate>
inline
void insertion_sort_unchecked(TValueType* first, TValueType* last, TPredicate predicate)
{
    if (first != last)
    {
        for (TValueType* next = first; ++next != last; )
        {
            TValueType val = std::move(*next);

            if (predicate(&val, first))
            {
                std::move_backward(first, next, next+1);
                *first = std::move(val);
            }
            else
            {
                TValueType* next_temp = next;
                for (TValueType* first_temp = next_temp; 
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

template <typename TValueType, typename TPredicate>
inline
void guess_median_unchecked(TValueType* first, TValueType* mid, TValueType* last, TPredicate predicate)
{
    uint64_t count = (uint64_t) (last - first);
    if (count > 40)
    {
        uint64_t step = (count + 1) >> 3;
        uint64_t twoStep = step << 1;
        networks::sort9bosenelsonparameter(
            *(first + step), *(first + twoStep), *(mid - step), *mid, 
            *first,
            *(mid + step), *(last - twoStep), *(last - step), *last);
    }
    else
    {
        networks::sort3bosenelsonparameter(
            *mid, 
            *first, 
            *last);
    }
}

template <typename TValueType, typename TPredicate>
inline
TValueType* partition_by_median_guess_unchecked(TValueType* first, TValueType* last, TPredicate predicate)
{
    TValueType* mid = first + ((last - first) >> 1);
    guess_median_unchecked(first, mid, last - 1, predicate);

    TValueType* pivot = first;
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



template <typename TValueType, typename TPredicate>
inline
void sort_unchecked(TValueType* first, TValueType* last, uint64_t ideal, TPredicate predicate)
{
    uint64_t count;
    while (ISortMax < (count = (uint64_t) (last - first)) && ideal > 0)
    {
        auto mid = partition_by_median_guess_unchecked(first, last, predicate);
        auto afterMid = mid + 1;

        ideal = (ideal >> 1) + (ideal >> 2);

        if (mid - first < last - afterMid)
        {
            sort_unchecked(first, mid, ideal, predicate);
            first = afterMid;
        }
        else
        {
            sort_unchecked(afterMid, last, ideal, predicate);
            last = mid;
        }
    }

    if (count > ISortMax)
    {
        std::partial_sort(first, last, last);
    }
    else if(count >= 2)
    {
        insertion_sort_unchecked(first, last, predicate);
    }
}

template <typename TValueType, typename TPredicate>
void Quicksort_Copy_Msvc(TValueType* first, TValueType* last, TPredicate predicate)
{
    sort_unchecked(first, last, (uint64_t) (last - first), predicate);
}

}

#endif