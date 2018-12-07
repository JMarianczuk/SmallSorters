
#include <algorithm>
#include <fstream>
#include <iostream>

#include "NetworkSort_Simple.h"
#include "ConditionalSwap.h"



// void Compare_Brute(Sortable* items, int left, int right) {
//     uint64_t tmpKey = items[left].key;
//     uint64_t tmpReference = items[left].reference;

//     __asm__(
//         "cmpq %[left_key],%[right_key]\n"
//         "cmovbq %[right_key],%[left_key]\n"
//         "cmovbq %[right_reference],%[left_reference]\n"
//         "cmovbq %[tmp_key],%[right_key]\n"
//         "cmovbq %[tmp_reference],%[right_reference]\n"
//         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [left_reference] "+r"(items[left].reference), [right_reference] "+r"(items[right].reference)
//         : [tmp_key] "rm"(tmpKey), [tmp_reference] "rm"(tmpReference)
//         : "cc"
//     );
// }

// void Compare_Copied(Sortable* items, int left, int right) {

// }

// void SortTestJumpXchg(Sortable* items) {
//     for (int outer = 0; outer < ArraySize; outer += 1) {
//         for (int inner = 0; inner < ArraySize - 1; inner += 1) {
//             ConditionalSwap_JumpXchg(inner, inner + 1);
//         }
//     }
// }

// void SortTestTwoCmovTemp(Sortable* items) {
//     for (int outer = 0; outer < ArraySize; outer += 1) {
//         for (int inner = 0; inner < ArraySize - 1; inner += 1) {
//             ConditionalSwap_TwoCmovTemp(inner, inner + 1);
//         }
//     }
// }

// void SortTestThreeCmovVolatileTemp(Sortable* items) {
//     for (int outer = 0; outer < ArraySize; outer += 1) {
//         for (int inner = 0; inner < ArraySize - 1; inner += 1) {
//             ConditionalSwap_ThreeCmovVolatileTemp(inner, inner + 1);
//         }
//     }
// }

// void SortTestThreeCmovRegisterTemp(Sortable* items) {
//     for (int outer = 0; outer < ArraySize; outer += 1) {
//         for (int inner = 0; inner < ArraySize - 1; inner += 1) {
//             ConditionalSwap_ThreeCmovRegisterTemp(inner, inner + 1);
//         }
//     }
// }

#define Compare(left, right) ConditionalSwap_JumpXchg(left, right)

void NetworkSort_Generic(Sortable* items) {
    Compare(32, 48)
    // Compare(3, 4)
    // Compare(0, 2)
}

// void NetworkSortSimple_Optimised(Sortable* items) {
//     CompareM(items, 0, 1);
//     CompareM(items, 3, 4);
//     CompareM(items, 0, 2);
// }

#define Compare_Swap(left, right) if (items[left].key > items[right].key) {std::swap(items[left], items[right]);}

void NetworkSortSimple_Naive(Sortable* items) {
    Compare_Swap(0, 1);
    Compare_Swap(3, 4);
    Compare_Swap(0, 2);
}

// void SingleSort(Sortable* items) {
//     __asm__(
//         "leaq 32(%rdi), %rax\n\t"
//         "movups 32(%rdi), %xmm0\n\t"
//         "movaps %xmm0, -24(%rsp)\n\t"
//         "leaq 48(%rdi), %rcx\n\t"
//         "movq 48(%rdi), %rdx\n\t"
//         "cmpq -24(%rsp), %rdx\n\t"
//         "cmovbq %rcx, %rax\n\t"
//         "movups (%rax), %xmm0\n\t"
//         "movups %xmm0, 32(%rdi)\n\t"
//         "leaq -24(%rsp), %rax\n\t"
//         "cmovaeq %rcx, %rax\n\t"
//         "movups (%rax), %xmm0\n\t"
//         "movups %xmm0, 48(%rdi)"
//     );
// }
