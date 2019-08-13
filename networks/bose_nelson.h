#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

namespace networks {

namespace bosenelson_2 {

template <std::size_t H, std::size_t... Is> constexpr
std::size_t head(std::index_sequence<H, Is...>) { return H; }

template <std::size_t H, std::size_t... Is> constexpr
std::index_sequence<Is...> tail(std::index_sequence<H, Is...>) { return {}; }

template <std::size_t kSize, std::size_t... Is, std::size_t... Js> constexpr
auto take([[maybe_unused]] std::index_sequence<Is...> src, std::index_sequence<Js...> = {}) {
    if constexpr (kSize == 0) {
        return std::index_sequence<Js...>();
    } else {
        return take<kSize - 1>(tail(src), std::index_sequence<Js..., head(src)>());
    }
}

template <std::size_t kSize, std::size_t... Is> constexpr
auto drop(std::index_sequence<Is...> src) {
    if constexpr (kSize == 0) {
        return src;
    } else {
        return drop<kSize - 1>(tail(src));
    }
}

template <std::size_t kOffset, std::size_t... Is> constexpr
std::index_sequence<(kOffset + Is)...> offset_seq(std::index_sequence<Is...>) { return {}; }

template <std::size_t... Ls, std::size_t... Rs> constexpr
std::index_sequence<Ls..., Rs...> concat_seq(std::index_sequence<Ls...>, std::index_sequence<Rs...>) { return {}; }


template <std::size_t... Ls, std::size_t... Rs> constexpr
auto calc_merge_seq_for(std::index_sequence<Ls...> left, std::index_sequence<Rs...> right) {
    if constexpr (left.size() == 1 && right.size() == 1) {
        return std::index_sequence<Ls..., Rs...>();
    } else if constexpr (left.size() == 1 && right.size() == 2) {
        return std::index_sequence<head(left), head(tail(right)), head(left), head(right)>();
    } else if constexpr (left.size() == 2 && right.size() == 1) {
        return std::index_sequence<head(left), head(right), head(tail(left)), head(right)>();
    } else {
        constexpr auto kLeftMiddle = left.size() / 2;
        constexpr auto kRightMiddle = (right.size() + 1 - (left.size() % 2)) / 2;
        return concat_seq(concat_seq(
                    calc_merge_seq_for(take<kLeftMiddle>(left), take<kRightMiddle>(right)),
                    calc_merge_seq_for(drop<kLeftMiddle>(left), drop<kRightMiddle>(right))),
                    calc_merge_seq_for(drop<kLeftMiddle>(left), take<kRightMiddle>(right)));
    }
}

template <std::size_t kSize> constexpr
auto calc_seq_for() {
    if constexpr (kSize <= 1) {
        return std::index_sequence<>();
    } else {
        constexpr auto kMiddle = kSize / 2;
        constexpr auto kLeft = calc_seq_for<kMiddle>();
        constexpr auto kRight = offset_seq<kMiddle>(calc_seq_for<kSize - kMiddle>());
        constexpr auto kLeftIndex = std::make_index_sequence<kMiddle>();
        constexpr auto kRightIndex = offset_seq<kMiddle>(std::make_index_sequence<kSize - kMiddle>());

        return concat_seq(concat_seq(kLeft, kRight), calc_merge_seq_for(kLeftIndex, kRightIndex));
    }
}

template <class T>
static void swap(T& lhs, T& rhs) {
    T tmp = rhs;
    asm ("cmp %0, %1\n"
            "cmovl %0, %1\n"
            "cmovl %2, %0\n"
            : "+r"(lhs), "+&r"(rhs)
            : "r"(tmp)
            : "cc");
}

template <typename CSwap, class It, std::size_t kLhs, std::size_t kRhs, std::size_t... kTail>
void sort(It d, std::index_sequence<kLhs, kRhs, kTail...> = {}) {
    CSwap::swap(d[kLhs], d[kRhs]);
    if constexpr (sizeof...(kTail) > 0) {
        sort<CSwap, It, kTail...>(d);
    }
}

template <std::size_t kSize>
using seq_for = decltype(calc_seq_for<kSize>());

template <std::size_t kSize, typename CSwap, class It>
void sort(It begin) {
    sort<CSwap>(std::move(begin), seq_for<kSize>());
}

template <typename CSwap, typename ValueType>
void sortN(ValueType* A, size_t n)
{
    switch (n)
    {
        case 0: break;
        case 1: break;
        case 2:
            sort<2, CSwap>(A);
            return;
        case 3:
			sort<3, CSwap>(A);
			break;
		case 4:
			sort<4, CSwap>(A);
			break;
		case 5:
			sort<5, CSwap>(A);
			break;
		case 6:
			sort<6, CSwap>(A);
			break;
		case 7:
			sort<7, CSwap>(A);
			break;
		case 8:
			sort<8, CSwap>(A);
			break;
		case 9:
			sort<9, CSwap>(A);
			break;
		case 10:
			sort<10, CSwap>(A);
			break;
		case 11:
			sort<11, CSwap>(A);
			break;
		case 12:
			sort<12, CSwap>(A);
			break;
		case 13:
			sort<13, CSwap>(A);
			break;
		case 14:
			sort<14, CSwap>(A);
			break;
		case 15:
			sort<15, CSwap>(A);
			break;
		case 16:
			sort<16, CSwap>(A);
			break;
		default:
			abort();
			break;
    }
}


}  // namespace bosenelson2
}  // namespace networks

