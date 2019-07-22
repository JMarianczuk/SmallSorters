
#ifndef CONDITIONAL_SWAP_ARM32_H
#define CONDITIONAL_SWAP_ARM32_H

#include <inttypes.h>
#include "ConditionalSwapGeneric.h"

namespace conditional_swap
{

class CS_Int
{
public:
    static inline void swap(int& left, int& right)
    {
        int tmp = left;
        __asm__(
            "cmp %[right],%[left]\n\t"
            "movlo %[left],%[right]\n\t"
            "movlo %[right],%[tmp]\n\t"
            : [left] "=&r" (left), [right] "=&r"(right)
            : "0"(left), "1"(right), [tmp] "r"(tmp)
            : "cc"
        );
    }
};

class CS_JumpXchg
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_JumpXchg_Ref
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_TwoCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_FourCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_FourCmovTemp_Split
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_ThreeCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_SixCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_ClangVersion
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

class CS_ClangPredicate
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_Default::swap(left, right);
    }
};

} // namespace conditional_swap

#endif