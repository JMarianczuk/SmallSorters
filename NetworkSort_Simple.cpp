
#include <algorithm>

#include "NetworkSort_Simple.h"

void Compare(Sortable* items, int left, int right) {
    uint64_t tmp = items[left].key;
    // __asm__(
    //     "cmpq %[left_key],%[right_key]\n"
    //     "cmovbq %[items_left],%[items_right]\n"
    //     "cmovbq %[items_right],%[tmp]\n"
    //     : [items_left] "+r"(items[left]), [items_right] "+r"(items[right])
    //     : [tmp] "rm"(tmp), [left_key] "x"(items[left].key), [right_key] "xm"(items[right].key)
    //     : "cc"
    // );
    __asm__(
        "cmpq %[left_key],%[right_key]\n"
        "cmovbq %[right_key],%[left_key]\n"
        "cmovbq %[tmp],%[right_key]\n"
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key)
        : [tmp] "r"(tmp)
        : "cc"
    );
}

void Compare_Brute(Sortable* items, int left, int right) {
    uint64_t tmpKey = items[left].key;
    uint64_t tmpReference = items[left].reference;

    __asm__(
        "cmpq %[left_key],%[right_key]\n"
        "cmovbq %[right_key],%[left_key]\n"
        "cmovbq %[right_reference],%[left_reference]\n"
        "cmovbq %[tmp_key],%[right_key]\n"
        "cmovbq %[tmp_reference],%[right_reference]\n"
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [left_reference] "+r"(items[left].reference), [right_reference] "+r"(items[right].reference)
        : [tmp_key] "rm"(tmpKey), [tmp_reference] "rm"(tmpReference)
        : "cc"
    );
}

// #define Compare_Brute(left, right) __asm__( \
//     "cmpq %[left_key],%[right_key]\n" \
//     "cmovbq %[right_key],%[left_key]\n" \
//     "cmovbq %[right_reference],%[left_reference]\n" \
//     "cmovbq %[tmp_key],%[right_key]\n" \
//     "cmovbq %[tmp_reference],%[right_reference]\n" \
//     : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [left_reference] "+r"(items[left].reference), [right_reference] "+r"(items[right].reference) \
//     : [tmp_key] "rm"(tmpKey), [tmp_reference] "rm"(tmpReference) \
//     : "cc" \
// );

void Compare_Copied(Sortable* items, int left, int right) {

}

void NetworkSortSimple_Optimised(Sortable* items) {
    Compare_Brute(items, 0, 1);
    Compare_Brute(items, 3, 4);
    Compare_Brute(items, 0, 2);
    // Compare(items, 1, 2);
    // Compare(items, 0, 3);
    // Compare(items, 2, 3);
    // Compare(items, 1, 4);
    // Compare(items, 1, 2);
    // Compare(items, 3, 4);
}

#define Compare_Swap(left, right) if (items[left].key > items[right].key) {std::swap(items[left], items[right]);}

void NetworkSortSimple_Naive(Sortable* items) {
    Compare_Swap(0, 1);
    Compare_Swap(3, 4);
    Compare_Swap(0, 2);
    // Compare_Swap(1, 2);
    // Compare_Swap(0, 3);
    // Compare_Swap(2, 3);
    // Compare_Swap(1, 4);
    // Compare_Swap(1, 2);
    // Compare_Swap(3, 4);
}

void SingleSort(Sortable* items) {
    __asm__(
        "leaq 32(%rdi), %rax\n\t"
        "movups 32(%rdi), %xmm0\n\t"
        "movaps %xmm0, -24(%rsp)\n\t"
        "leaq 48(%rdi), %rcx\n\t"
        "movq 48(%rdi), %rdx\n\t"
        "cmpq -24(%rsp), %rdx\n\t"
        "cmovbq %rcx, %rax\n\t"
        "movups (%rax), %xmm0\n\t"
        "movups %xmm0, 32(%rdi)\n\t"
        "leaq -24(%rsp), %rax\n\t"
        "cmovaeq %rcx, %rax\n\t"
        "movups (%rax), %xmm0\n\t"
        "movups %xmm0, 48(%rdi)"
    );
}