
#ifndef CONDITIONAL_SWAP_X86_H
#define CONDITIONAL_SWAP_X86_H

#include <inttypes.h>

namespace conditional_swap
{

class CS_Int
{
public:
    static inline void swap(int& left, int& right)
    {
        int tmp = left;
        __asm__(
            "cmp %[left],%[right]\n\t"
            "cmovb %[right],%[left]\n\t"
            "cmovb %[tmp],%[right]\n\t"
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
        __asm__( 
            "cmpq %[left_key],%[right_key]\n\t" 
            "jae %=f\n\t"
            "xchg %[left_key],%[right_key]\n\t" 
            "%=:\n\t" 
            : [left_key] "+r"(left.key), [right_key] "+r"(right.key) 
            : 
            : "cc" 
        );
    }
};

class CS_JumpXchg_Ref
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        __asm__(
            "cmpq %[left_key],%[right_key]\n\t" 
            "jae %=f\n\t"
            "xchg %[left_key],%[right_key]\n\t" 
            "xchg %[left_reference],%[right_reference]\n\t"
            "%=:\n\t" 
            : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key), [left_reference] "=&r"(left.reference), [right_reference] "=&r"(right.reference)
            : "0"(left.key), "1"(right.key), "2"(left.reference), "3"(right.reference)
            : "cc" 
        );
    }
};

class CS_TwoCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        uint64_t tmp = left.key; 
        __asm__( 
            "cmpq %[left_key],%[right_key]\n\t" 
            "cmovbq %[right_key],%[left_key]\n\t" 
            "cmovbq %[tmp],%[right_key]\n\t"
            : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key)
            : "0"(left.key), "1"(right.key), [tmp] "r"(tmp) 
            : "cc" 
        );
    }
};

class CS_FourCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        uint64_t tmp = left.key;
        uint64_t tmpRef = left.reference;
        __asm__( 
            "cmpq %[left_key],%[right_key]\n\t" 
            "cmovbq %[right_key],%[left_key]\n\t" 
            "cmovbq %[right_reference],%[left_reference]\n\t"
            "cmovbq %[tmp],%[right_key]\n\t"
            "cmovbq %[tmp_ref],%[right_reference]\n\t"
            : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key), [left_reference] "=&r"(left.reference), [right_reference] "=&r"(right.reference)
            : "0"(left.key), "1"(right.key), "2"(left.reference), "3"(right.reference), [tmp] "r"(tmp), [tmp_ref] "r"(tmpRef)
            : "cc" 
        );
    }
};

class CS_FourCmovTemp_Split
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        uint64_t tmp = left.key;
        uint64_t tmpRef = left.reference;
        __asm__ volatile ( 
            "cmpq %[left_key],%[right_key]\n\t"
            : 
            : [left_key] "r"(left.key), [right_key] "r"(right.key)
            : "cc" 
        );
        __asm__ volatile (
            "cmovbq %[right_key],%[left_key]\n\t"
            : [left_key] "=&r"(left.key)
            : "0"(left.key), [right_key] "r"(right.key)
            : 
        );
        __asm__ volatile (
            "cmovbq %[right_reference],%[left_reference]\n\t"
            : [left_reference] "=&r"(left.reference)
            : "0"(left.reference), [right_reference] "r"(right.reference)
            :
        );
        __asm__ volatile (
            "cmovbq %[tmp],%[right_key]\n\t"
            : [right_key] "=&r"(right.key)
            : "0"(right.key), [tmp] "r"(tmp)
            : 
        );
        __asm__ volatile (
            "cmovbq %[tmp_ref],%[right_reference]\n\t"
            : [right_reference] "=&r"(right.reference)
            : "0"(right.reference), [tmp_ref] "r"(tmpRef)
            : 
        );
    }
};

class CS_ThreeCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        uint64_t tmp; 
        __asm__ ( 
            "cmpq %[left_key],%[right_key]\n\t" 
            "cmovbq %[left_key],%[tmp]\n\t"
            "cmovbq %[right_key],%[left_key]\n\t" 
            "cmovbq %[tmp],%[right_key]\n\t"
            : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [tmp] "+r"(tmp)
            : 
            : "cc" 
        ); 
    }
};

class CS_SixCmovTemp
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        uint64_t tmp;
        uint64_t tmpRef;
        __asm__ ( 
            "cmpq %[left_key],%[right_key]\n\t" 
            "cmovbq %[left_key],%[tmp]\n\t"
            "cmovbq %[left_reference],%[tmp_ref]\n\t"
            "cmovbq %[right_key],%[left_key]\n\t" 
            "cmovbq %[right_reference],%[left_reference]\n\t"
            "cmovbq %[tmp],%[right_key]\n\t"
            "cmovbq %[tmp_ref],%[right_reference]\n\t"
            : [left_key] "=&r"(left.key), [right_key] "=&r"(right.key), [left_reference] "=&r"(left.reference), [right_reference] "=&r"(right.reference), [tmp] "=&r"(tmp), [tmp_ref] "=&r"(tmpRef)
            : "0"(left.key), "1"(right.key), "2"(left.reference), "3"(right.reference), "4"(tmp), "5"(tmpRef)
            : "cc" 
        ); 
    }
};

class CS_ClangVersion
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        Type* leftPointer = &left;
        Type* rightPointer = &right;
        uint64_t rightKey = right.key;
        Type tmp = left;
        __asm__ volatile(
            "cmpq %[tmp_key],%[right_key]\n\t"
            "cmovbq %[right_pointer],%[left_pointer]\n\t"
            : [left_pointer] "=&r"(leftPointer)
            : "0"(leftPointer), [right_pointer] "r"(rightPointer), [tmp_key] "m"(tmp.key), [right_key] "r"(rightKey)
            : "cc"
        );
        left = *leftPointer;
        leftPointer = &tmp;
        __asm__ volatile(
            "cmovbq %[left_pointer],%[right_pointer]\n\t"
            : [right_pointer] "=&r"(rightPointer)
            : "0"(rightPointer), [left_pointer] "r"(leftPointer)
            :
        );
        right = *rightPointer;
    }
};

class CS_ClangPredicate
{
public:
    template <typename Type>
    static inline void swap(Type& left, Type& right)
    {
        Type* leftPointer = &left;
        Type* rightPointer = &right;
        Type temp = left;
        int predicateResult = (int) (right < temp);
        __asm__ volatile(
            "cmp $0,%[predResult]\n\t"
            "cmovneq %[right_pointer],%[left_pointer]\n\t"
            : [left_pointer] "=&r"(leftPointer)
            : "0"(leftPointer), [right_pointer] "r"(rightPointer), [predResult] "r"(predicateResult)
            : "cc"
        );
        left = *leftPointer;
        leftPointer = &temp;
        __asm__ volatile(
            "cmovneq %[left_pointer],%[right_pointer]\n\t"
            : [right_pointer] "=&r"(rightPointer)
            : "0"(rightPointer), [left_pointer] "r"(leftPointer)
            :
        );
        right = *rightPointer;
    }
};
    
} // namespace conditional_swap

#endif