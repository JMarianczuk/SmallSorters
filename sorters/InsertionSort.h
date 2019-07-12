
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <utility>
#include <algorithm>

namespace insertionsort {

class InsertionSort_Default
{
public:
    template <typename Type>
    static inline void sort(Type* items, size_t arraySize)
    {
        int inner, outer;
        for (outer = 1; outer < arraySize; outer += 1) {
            Type current = std::move(items[outer]);
            for (inner = outer; inner > 0 && items[inner - 1] > current; inner -= 1) 
            {
                items[inner] = std::move(items[inner - 1]);
            }
            items[inner] = std::move(current);
        }
    }
};

class InsertionSort_ArrayIndex_FirstCheck
{
public:
    template <typename Type>
    static inline void sort(Type* items, size_t arraySize)
    {
        int inner, outer;
        for (outer = 1; outer < arraySize; outer += 1)
        {
            auto current = std::move(items[outer]);
            if (current < items[0])
            {
                std::move_backward(items, &items[outer], &items[outer + 1]);
                items[0] = std::move(current);
            }
            else 
            {
                for (inner = outer; items[inner - 1] > current; inner -= 1)
                {
                    items[inner] = std::move(items[inner - 1]);
                }
                items[inner] = std::move(current);
            }
        }
    }
};

class InsertionSort_PointerOptimized
{
public:
    template <typename Type>
    static inline void sort(Type* first, size_t arraySize)
    {
        auto last = first + arraySize;
        for (auto current = first + 1; current < last; current += 1)
        {
            auto next_temp = current;
            auto val = std::move(*current);
            auto first_temp = next_temp - 1;
            while (first_temp >= first && val < *first_temp)
            {
                *next_temp = std::move(*first_temp);
                next_temp = first_temp;
                first_temp -= 1;
            }
            *next_temp = std::move(val);
        }
    }
};

class InsertionSort_StlVersion
{
public:
    template <typename Type>
    static inline void sort(Type* first, size_t arraySize)
    {
        Type* last = first + arraySize;
        for (Type* next = first; ++next < last; )
        {
            Type val = std::move(*next);

            if (val < *first)
            {
                std::move_backward(first, next, next+1);
                *first = std::move(val);
            }
            else
            {
                Type* next_temp = next;
                for (Type* first_temp = next_temp; 
                    val < *--first_temp; 
                    next_temp = first_temp)
                {
                    *next_temp = std::move(*first_temp);
                }
                *next_temp = std::move(val);
            }
        }
    }
};

template <typename InsertionSortImplementation, typename ValueType>
static inline
void InsertionSort(ValueType* items, size_t arraySize) 
{
    InsertionSortImplementation::sort(items, arraySize);
}

} // namespace insertionsort

#endif