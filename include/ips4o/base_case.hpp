/******************************************************************************
 * ips4o/base_case.hpp
 *
 * In-place Parallel Super Scalar Samplesort (IPS⁴o)
 *
 ******************************************************************************
 * BSD 2-Clause License
 *
 * Copyright © 2017, Michael Axtmann <michael.axtmann@kit.edu>
 * Copyright © 2017, Daniel Ferizovic <daniel.ferizovic@student.kit.edu>
 * Copyright © 2017, Sascha Witt <sascha.witt@kit.edu>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#pragma once

#include <algorithm>
#include <cstddef>
#include <utility>
#include <stdexcept>

#include "ips4o_fwd.hpp"
#include "utils.hpp"
#include "../../Sortable.generated.h"
#include "../../sorters/QuickSort.h"
#include "../../Networks_Fwd.h"
#include "../../conditional_swap/ConditionalSwap.h"

namespace ips4o {
namespace detail {

/**
 * Insertion sort.
 */
template <class It, class Comp>
void insertionSort(const It begin, const It end, Comp comp) {
    IPS4O_ASSUME_NOT(begin >= end);

    for (It it = begin + 1; it < end; ++it) {
        auto val = std::move(*it);
        if (comp(val, *begin)) {
            std::move_backward(begin, it, it + 1);
            *begin = std::move(val);
        } else {
            auto cur = it;
            for (auto next = it - 1; comp(val, *next); --next) {
                *cur = std::move(*next);
                cur = next;
            }
            *cur = std::move(val);
        }
    }
}

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


/**
 * Wrapper for base case sorter, for easier swapping.
 */
template <class Cfg, class It, class Comp>
inline void baseCaseSort(It begin, It end, Comp&& comp) {
    if (begin == end) return;

    // printf("RESULT\tbs=%" PRIu64 "\n", end - begin);
    if constexpr (Cfg::kBaseCaseType == 0)
    {
        detail::insertionSort(std::move(begin), std::move(end), std::forward<Comp>(comp));
    }
    else
    {
        typedef typename iterator_traits<It>::value_type ValueType;
        void(*sort)(ValueType*,size_t);
        if constexpr (Cfg::kBaseCaseType == 1)         {
            sort = &networks::best::sortN<conditional_swap::CS_FourCmovTemp, ValueType>;
        } else if constexpr (Cfg::kBaseCaseType == 2) {
            sort = &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, ValueType>;
        } else if constexpr (Cfg::kBaseCaseType == 3) {
            sort = &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, ValueType>;
        } else if constexpr (Cfg::kBaseCaseType == 5) {
            sort = &insertionsort::InsertionSort<conditional_swap::CS_FourCmovTemp, ValueType>;
        } else if constexpr (Cfg::kBaseCaseType == 6) {
            sort = &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, ValueType>;
        } else {
            throw std::logic_error("Invalid base case type");
        }
        if constexpr (Cfg::kSampleSortType == 1) {
            samplesort::SampleSort3Splitters3OversamplingFactor1BlockSize(begin, end - begin, 16, sort, &quicksort::templateLess<ValueType>, &GetKey<ValueType>);
        } else if constexpr (Cfg::kSampleSortType == 2) {
            samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(begin, end - begin, 16, sort, &quicksort::templateLess<ValueType>, &GetKey<ValueType>);
        } else if constexpr (Cfg::kSampleSortType == 3) {
            if (end - begin <= 16)
            {
                sort(begin, end - begin);
            }
            else
            {
                detail::insertionSort(std::move(begin), std::move(end), std::forward<Comp>(comp));
            }
        } else {
            throw std::logic_error("Invalid base case type");
        }
    }
}

}  // namespace detail
}  // namespace ips4o
