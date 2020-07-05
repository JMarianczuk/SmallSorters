
#ifndef CONDITIONAL_SWAP_DUMMY_H
#define CONDITIONAL_SWAP_DUMMY_H

#include <inttypes.h>

#include "ConditionalSwapGeneric.h"

namespace conditional_swap
{

class CS_Int final
{
public:
    static inline void swap(int& left, int& right)
    {
        CS_IfSwap::swap(left, right);
    }
};

class CS_JumpXchg final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_JumpXchg_Ref final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_TwoCmovTemp final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_CmovXor final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);
    }
};

class CS_FourCmovTemp final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_FourCmovTemp_Split final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_ThreeCmovTemp final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_SixCmovTemp final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_TwoConditionalPointerMove final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};

class CS_TwoConditionalPointerMovePredicate final
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        CS_IfSwap::swap(left, right);        
    }
};
    
} // namespace conditional_swap

#endif