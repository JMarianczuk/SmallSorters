
#ifndef NETWORK_SORT_H
#define NETWORK_SORT_H

#include "Sortable.generated.h"

#include <algorithm>
#include <inttypes.h>

namespace networks {

template <typename TValueType>
static inline
void ConditionalSwap(TValueType& left, TValueType& right)
{
    if (left > right) {std::swap(left, right); }
}

template<>
inline
void ConditionalSwap<int>(int& left, int& right)
{
    register int tmp = left;
    __asm__(
        "cmp %[left],%[right]\n\t"
        "cmovb %[right],%[left]\n\t"
        "cmovb %[tmp],%[right]\n\t"
        : [left] "=&r" (left), [right] "=&r"(right)
        : "0"(left), "1"(right), [tmp] "r"(tmp)
        : "cc"
    );
}

template<>
inline
void ConditionalSwap<Sortable_JumpXchg>(Sortable_JumpXchg& left, Sortable_JumpXchg& right)
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
template<>
inline
void ConditionalSwap<SortableRef_JumpXchg>(SortableRef_JumpXchg& left, SortableRef_JumpXchg& right)
{
    __asm__(
        "cmpq %[left_key],%[right_key]\n\t" 
        "jae %=f\n\t"
        "xchg %[left_key],%[right_key]\n\t" 
        "xchg %[left_reference],%[right_reference]\n\t"
        "%=:\n\t" 
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [left_reference] "+r"(left.reference), [right_reference] "+r"(right.reference)
        : 
        : "cc" 
    );
}



template<>
inline
void ConditionalSwap<Sortable_TwoCmovTemp>(Sortable_TwoCmovTemp& left, Sortable_TwoCmovTemp& right)
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
template<>
inline
void ConditionalSwap<SortableRef_FourCmovTemp>(SortableRef_FourCmovTemp& left, SortableRef_FourCmovTemp& right)
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
template<>
inline
void ConditionalSwap<SortableRef_FourCmovTemp_Split>(SortableRef_FourCmovTemp_Split& left, SortableRef_FourCmovTemp_Split& right)
{
    uint64_t tmp = left.key;
    uint64_t tmpRef = left.reference;
    __asm__( 
        "cmpq %[left_key],%[right_key]\n\t"
        : 
        : [left_key] "r"(left.key), [right_key] "r"(right.key)
        : "cc" 
    );
    __asm__(
        "cmovbq %[right_key],%[left_key]\n\t"
        : [left_key] "=&r"(left.key)
        : "0"(left.key), [right_key] "r"(right.key)
        : 
    );
    __asm__(
        "cmovbq %[right_reference],%[left_reference]\n\t"
        : [left_reference] "=&r"(left.reference)
        : "0"(left.reference), [right_reference] "r"(right.reference)
        :
    );
    __asm__(
        "cmovbq %[tmp],%[right_key]\n\t"
        : [right_key] "=&r"(right.key)
        : "0"(right.key), [tmp] "r"(tmp)
        : 
    );
    __asm__(
        "cmovbq %[tmp_ref],%[right_reference]\n\t"
        : [right_reference] "=&r"(right.reference)
        : "0"(right.reference), [tmp_ref] "r"(tmpRef)
        : 
    );
}

template<>
inline
void ConditionalSwap<Sortable_ThreeCmovRegisterTemp>(Sortable_ThreeCmovRegisterTemp& left, Sortable_ThreeCmovRegisterTemp& right)
{
    register uint64_t tmp; 
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
template<>
inline
void ConditionalSwap<SortableRef_SixCmovRegisterTemp>(SortableRef_SixCmovRegisterTemp& left, SortableRef_SixCmovRegisterTemp& right)
{
    register uint64_t tmp;
    register uint64_t tmpRef;
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

template<>
inline
void ConditionalSwap<SortableRef_ClangVersion>(SortableRef_ClangVersion& left, SortableRef_ClangVersion& right)
{
    register SortableRef_ClangVersion* leftPointer = &left;
    register SortableRef_ClangVersion* rightPointer = &right;
    register uint64_t rightKey = right.key;
    SortableRef_ClangVersion tmp = left;
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

}

#endif