
#ifndef CONDITIONAL_SWAP_GENERIC_H
#define CONDITIONAL_SWAP_GENERIC_H

#include <tuple>

namespace conditional_swap
{

class CS_IfSwap final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        if (right < left) { std::swap(left, right); }
    }
};

class CS_Tie final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        std::tie(left, right) =
            (right < left) ? std::make_tuple(right, left) : std::make_tuple(left, right);
    }
};

class CS_TernaryConditionalOperator final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        bool r = (right < left);
        Type temp = left;
        left = r ? right : left;
        right = r ? temp : right;
    }
};

} // namespace conditional_swap

#endif