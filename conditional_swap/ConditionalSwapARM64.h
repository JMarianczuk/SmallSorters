
#ifndef CONDITIONAL_SWAP_ARM64_H
#define CONDITIONAL_SWAP_ARM64_H

#include <inttypes.h>
#include "ConditionalSwapGeneric.h"

namespace conditional_swap
{

// ARM has Intel-like syntax, so the parameters are turned around from the X86 ASM

class CS_Int
{
public:
    static inline void swap(int& left, int& right)
    {
        int tmp = left;
        __asm__(
            "cmp %[right],%[left]\n\t"
            "csel %[left],%[right],%[left],LO\n\t"
            "csel %[right],%[tmp],%[right],LO\n\t"
            // "movmi %[right],%[tmp]\n\t"
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
        uint64_t tmp = left.key;
        uint64_t tmpRef = left.reference;
        __asm__(
            "cmp %[right_key],%[left_key]\n\t"
            "b.hs %=f\n\t" //branch higher or same
            "mov %[left_key],%[right_key]\n\t" 
            "mov %[left_reference],%[right_reference]\n\t"
            "mov %[right_key],%[tmp]\n\t"
            "mov %[right_reference],%[tmp_ref]\n\t"
            "%=:\n\t"
            : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key), [left_reference] "=&r"(left.reference), [right_reference] "=&r"(right.reference)
            : "0"(left.key), "1"(right.key), "2"(left.reference), "3"(right.reference), [tmp] "r"(tmp), [tmp_ref] "r"(tmpRef)
            : "cc" 
        );
        // CS_Default::swap(left, right);
    }
};

class CS_TwoCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        // uint64_t tmp = left.key; 
        // __asm__( 
        //     "cmp %[right_key],%[left_key]\n\t" 
        //     "movmi %[left_key],%[right_key]\n\t" 
        //     "movmi %[right_key],%[tmp]\n\t"
        //     : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key)
        //     : "0"(left.key), "1"(right.key), [tmp] "r"(tmp) 
        //     : "cc" 
        // );
    }
};

class CS_FourCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        // uint64_t tmp = left.key;
        // uint64_t tmpRef = left.reference;
        // __asm__( 
        //     "cmp %[right_key],%[left_key]\n\t" 
        //     "movmi %[left_key],%[right_key]\n\t" 
        //     "movmi %[left_reference],%[right_reference]\n\t"
        //     "movmi %[right_key],%[tmp]\n\t"
        //     "movmi %[right_reference],%[tmp_ref]\n\t"
        //     : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key), [left_reference] "=&r"(left.reference), [right_reference] "=&r"(right.reference)
        //     : "0"(left.key), "1"(right.key), "2"(left.reference), "3"(right.reference), [tmp] "r"(tmp), [tmp_ref] "r"(tmpRef)
        //     : "cc" 
        // );
    }
};

class CS_FourCmovTemp_Split
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        // uint64_t tmp = left.key;
        // uint64_t tmpRef = left.reference;
        // __asm__ volatile ( 
        //     "cmp %[right_key],%[left_key]\n\t"
        //     : 
        //     : [left_key] "r"(left.key), [right_key] "r"(right.key)
        //     : "cc" 
        // );
        // __asm__ volatile (
        //     "movmi %[lefkt_key],%[right_key]\n\t"
        //     : [left_key] "=&r"(left.key)
        //     : "0"(left.key), [right_key] "r"(right.key)
        //     : 
        // );
        // __asm__ volatile (
        //     "movmi %[left_reference],%[right_reference]\n\t"
        //     : [left_reference] "=&r"(left.reference)
        //     : "0"(left.reference), [right_reference] "r"(right.reference)
        //     :
        // );
        // __asm__ volatile (
        //     "movmi %[right_key],%[tmp]\n\t"
        //     : [right_key] "=&r"(right.key)
        //     : "0"(right.key), [tmp] "r"(tmp)
        //     : 
        // );
        // __asm__ volatile (
        //     "movmi %[right_reference],%[tmp_ref]\n\t"
        //     : [right_reference] "=&r"(right.reference)
        //     : "0"(right.reference), [tmp_ref] "r"(tmpRef)
        //     : 
        // );
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
        // Type* leftPointer = &left;
        // Type* rightPointer = &right;
        // uint64_t rightKey = right.key;
        // Type tmp = left;
        // __asm__ volatile(
        //     "cmp %[right_key],%[tmp_key]\n\t"
        //     "movmi %[left_pointer],%[right_pointer]\n\t"
        //     : [left_pointer] "=&r"(leftPointer)
        //     : "0"(leftPointer), [right_pointer] "r"(rightPointer), [tmp_key] "r"(tmp.key), [right_key] "r"(rightKey)
        //     : "cc"
        // );
        // left = *leftPointer;
        // leftPointer = &tmp;
        // __asm__ volatile(
        //     "movmi %[right_pointer],%[left_pointer]\n\t"
        //     : [right_pointer] "=&r"(rightPointer)
        //     : "0"(rightPointer), [left_pointer] "r"(leftPointer)
        //     :
        // );
        // right = *rightPointer;
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