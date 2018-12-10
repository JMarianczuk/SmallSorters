
#ifndef NETWORK_SORT_SIMPLE_H
#define NETWORK_SORT_SIMPLE_H

#include "Sortable.h"
#include <fstream>
#include <iostream>

// void NetworkSortSimple_Generic(SortableRef* items);

// void SortTestJumpXchg(SortableRef* items);
// void SortTestTwoCmovTemp(SortableRef* items);
// void SortTestThreeCmovVolatileTemp(SortableRef* items);
// void SortTestThreeCmovRegisterTemp(SortableRef* items);

namespace networks {

template <typename TValueType>
static inline
void ConditionalSwap(TValueType& left, TValueType& right)
{
    if (left > right) {std::swap(left, right); }
}

// template<>
// inline
// void ConditionalSwap<Sortable>(SortableRef& left, SortableRef& right)
// {
//     if (left.key > right.key) {std::swap(left, right); }
// }

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
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [tmp] "+r"(tmp) 
        : 
        : "cc" 
    ); \
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
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [left_reference] "+r"(left.reference), [right_reference] "+r"(right.reference), [tmp] "+r"(tmp), [tmp_ref] "+r"(tmpRef)
        : 
        : "cc" 
    ); \
}



template<>
inline
void ConditionalSwap<Sortable_ThreeCmovVolatileTemp>(Sortable_ThreeCmovVolatileTemp& left, Sortable_ThreeCmovVolatileTemp& right)
{
    volatile uint64_t tmp; 
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
void ConditionalSwap<SortableRef_SixCmovVolatileTemp>(SortableRef_SixCmovVolatileTemp& left, SortableRef_SixCmovVolatileTemp& right)
{
    volatile uint64_t tmp;
    volatile uint64_t tmpRef;
    __asm__ ( 
        "cmpq %[left_key],%[right_key]\n\t" 
        "cmovbq %[left_key],%[tmp]\n\t"
        "cmovbq %[left_reference],%[tmp_ref]\n\t"
        "cmovbq %[right_key],%[left_key]\n\t" 
        "cmovbq %[right_reference],%[left_reference]\n\t"
        "cmovbq %[tmp],%[right_key]\n\t"
        "cmovbq %[tmp_ref],%[right_reference]\n\t"
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [left_reference] "+r"(left.reference), [right_reference] "+r"(right.reference), [tmp] "+r"(tmp), [tmp_ref] "+r"(tmpRef)
        : 
        : "cc" 
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
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [tmp] "+r"(tmp) \
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
        : [left_key] "+r"(left.key), [right_key] "+r"(right.key), [left_reference] "+r"(left.reference), [right_reference] "+r"(right.reference), [tmp] "+r"(tmp), [tmp_ref] "+r"(tmpRef)
        : 
        : "cc" 
    ); 
}



template<>
inline
void ConditionalSwap<SortableRef_ClangVersion>(SortableRef_ClangVersion& left, SortableRef_ClangVersion& right)
{
    register SortableRef_ClangVersion* leftPointer = &left;
    register SortableRef_ClangVersion* rightPointer = &right;
    register uint64_t registerThree = right.key;
    SortableRef_ClangVersion tmp = left;
    __asm__(
        // "movups %[left],%%xmm0\n\t"
        // "movaps %%xmm0,-24(%%rsp)\n\t"
        // "movq %[right_key],%[register_three]\n\t"
        "cmpq %[tmp_key],%[register_three]\n\t"
        "cmovbq %[right_pointer],%[left_pointer]\n\t"
        "movups (%[left_pointer]),%%xmm0\n\t"
        "movups %%xmm0,%[left]\n\t"
        "movq %[tmp_pointer],%[left_pointer]\n\t"
        "cmovaeq %[right_pointer],%[left_pointer]\n\t"
        "movups (%[right_pointer]),%%xmm0\n\t"
        "movups %%xmm0,%[right]\n\t"
        : [left] "+m"(left), [right] "+m"(right), [register_three] "+r"(registerThree), [left_pointer] "+r"(leftPointer)
        : [right_pointer] "r"(rightPointer), [tmp_key] "m"(tmp.key), [tmp_pointer] "r"(&tmp)
        : "cc", "%xmm0"
    );
}

template <typename TValueType> static inline
void sort2(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
}

template <typename TValueType> static inline
void sort3(TValueType* A)
{
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[0], A[1]);
}

template <typename TValueType> static inline
void sort4(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[1], A[2]);
}

template <typename TValueType> static inline
void sort5(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[1], A[2]);
}

template <typename TValueType> static inline
void sort6(TValueType* A)
{
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[2], A[3]);
}

template <typename TValueType> static inline
void sort7(TValueType* A)
{
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[2], A[3]);
}

template <typename TValueType> static inline
void sort8(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[3], A[6]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[3], A[4]);
}

template <typename TValueType> static inline
void sort9(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[3], A[6]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[4], A[7]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[5], A[8]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[5], A[6]);
}

template <typename TValueType> static inline
void sort10(TValueType* A)
{
    ConditionalSwap(A[4], A[9]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[2], A[7]);
    ConditionalSwap(A[1], A[6]);
    ConditionalSwap(A[0], A[5]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[6], A[9]);
    ConditionalSwap(A[0], A[3]);
    ConditionalSwap(A[5], A[8]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[3], A[6]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[4], A[7]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[4], A[5]);
}

template <typename TValueType> static inline
void sort11(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[6], A[10]);
    ConditionalSwap(A[5], A[9]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[6], A[10]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[4], A[8]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[7], A[10]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[7], A[8]);
}

template <typename TValueType> static inline
void sort12(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[6], A[10]);
    ConditionalSwap(A[5], A[9]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[6], A[10]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[7], A[11]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[4], A[8]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[7], A[11]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[7], A[10]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[7], A[8]);
}

template <typename TValueType> static inline
void sort13(TValueType* A)
{
    ConditionalSwap(A[1], A[7]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[8]);
    ConditionalSwap(A[0], A[12]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[11]);
    ConditionalSwap(A[7], A[12]);
    ConditionalSwap(A[5], A[9]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[6], A[12]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[11], A[12]);
    ConditionalSwap(A[4], A[9]);
    ConditionalSwap(A[6], A[10]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[1], A[7]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[4], A[7]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[0], A[5]);
    ConditionalSwap(A[2], A[5]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
}

template <typename TValueType> static inline
void sort14(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[12], A[13]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[8], A[12]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[9], A[13]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[0], A[8]);
    ConditionalSwap(A[1], A[9]);
    ConditionalSwap(A[2], A[10]);
    ConditionalSwap(A[3], A[11]);
    ConditionalSwap(A[4], A[12]);
    ConditionalSwap(A[5], A[13]);
    ConditionalSwap(A[5], A[10]);
    ConditionalSwap(A[6], A[9]);
    ConditionalSwap(A[3], A[12]);
    ConditionalSwap(A[7], A[11]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[8]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[7], A[13]);
    ConditionalSwap(A[2], A[8]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[13]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[7], A[12]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[10], A[12]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[12]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
}

template <typename TValueType> static inline
void sort15(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[12], A[13]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[12], A[14]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[8], A[12]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[9], A[13]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[10], A[14]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[0], A[8]);
    ConditionalSwap(A[1], A[9]);
    ConditionalSwap(A[2], A[10]);
    ConditionalSwap(A[3], A[11]);
    ConditionalSwap(A[4], A[12]);
    ConditionalSwap(A[5], A[13]);
    ConditionalSwap(A[6], A[14]);
    ConditionalSwap(A[5], A[10]);
    ConditionalSwap(A[6], A[9]);
    ConditionalSwap(A[3], A[12]);
    ConditionalSwap(A[13], A[14]);
    ConditionalSwap(A[7], A[11]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[8]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[7], A[13]);
    ConditionalSwap(A[2], A[8]);
    ConditionalSwap(A[11], A[14]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[13]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[7], A[12]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[10], A[12]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[12]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
}

template <typename TValueType>
static inline
void sort16(TValueType* A)
{
    ConditionalSwap(A[0], A[1]);
    ConditionalSwap(A[2], A[3]);
    ConditionalSwap(A[4], A[5]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
    ConditionalSwap(A[10], A[11]);
    ConditionalSwap(A[12], A[13]);
    ConditionalSwap(A[14], A[15]);
    ConditionalSwap(A[0], A[2]);
    ConditionalSwap(A[4], A[6]);
    ConditionalSwap(A[8], A[10]);
    ConditionalSwap(A[12], A[14]);
    ConditionalSwap(A[1], A[3]);
    ConditionalSwap(A[5], A[7]);
    ConditionalSwap(A[9], A[11]);
    ConditionalSwap(A[13], A[15]);
    ConditionalSwap(A[0], A[4]);
    ConditionalSwap(A[8], A[12]);
    ConditionalSwap(A[1], A[5]);
    ConditionalSwap(A[9], A[13]);
    ConditionalSwap(A[2], A[6]);
    ConditionalSwap(A[10], A[14]);
    ConditionalSwap(A[3], A[7]);
    ConditionalSwap(A[11], A[15]);
    ConditionalSwap(A[0], A[8]);
    ConditionalSwap(A[1], A[9]);
    ConditionalSwap(A[2], A[10]);
    ConditionalSwap(A[3], A[11]);
    ConditionalSwap(A[4], A[12]);
    ConditionalSwap(A[5], A[13]);
    ConditionalSwap(A[6], A[14]);
    ConditionalSwap(A[7], A[15]);
    ConditionalSwap(A[5], A[10]);
    ConditionalSwap(A[6], A[9]);
    ConditionalSwap(A[3], A[12]);
    ConditionalSwap(A[13], A[14]);
    ConditionalSwap(A[7], A[11]);
    ConditionalSwap(A[1], A[2]);
    ConditionalSwap(A[4], A[8]);
    ConditionalSwap(A[1], A[4]);
    ConditionalSwap(A[7], A[13]);
    ConditionalSwap(A[2], A[8]);
    ConditionalSwap(A[11], A[14]);
    ConditionalSwap(A[2], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[13]);
    ConditionalSwap(A[3], A[8]);
    ConditionalSwap(A[7], A[12]);
    ConditionalSwap(A[6], A[8]);
    ConditionalSwap(A[10], A[12]);
    ConditionalSwap(A[3], A[5]);
    ConditionalSwap(A[7], A[9]);
    ConditionalSwap(A[3], A[4]);
    ConditionalSwap(A[5], A[6]);
    ConditionalSwap(A[7], A[8]);
    ConditionalSwap(A[9], A[10]);
    ConditionalSwap(A[11], A[12]);
    ConditionalSwap(A[6], A[7]);
    ConditionalSwap(A[8], A[9]);
}

template <typename TValueType> static inline
void sortN(TValueType* A, size_t n)
{
    switch (n) {
        case 0: break;
        case 1: break;
        case 2: 
            sort2(A);
            break;
        case 3: 
            sort3(A);
            break;
        case 4: 
            sort4(A);
            break;
        case 5: 
            sort5(A);
            break;
        case 6: 
            sort6(A);
            break;
        case 7: 
            sort7(A);
            break;
        case 8: 
            sort8(A);
            break;
        case 9: 
            sort9(A);
            break;
        case 10: 
            sort10(A);
            break;
        case 11: 
            sort11(A);
            break;
        case 12: 
            sort12(A);
            break;
        case 13: 
            sort13(A);
            break;
        case 14: 
            sort14(A);
            break;
        case 15: 
            sort15(A);
            break;
        case 16: 
            sort16(A);
            break;
        default:
            abort();
            break;
    }
}

}

#endif