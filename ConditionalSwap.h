#ifndef CONDITIONAL_SWAP_H
#define CONDITIONAL_SWAP_H

#define ConditionalSwap_JumpXchg(left, right) __asm__( \
    "cmpq %[left_key],%[right_key]; \
    jb %=f; \
    xchg %[left_key],%[right_key]; \
    %=:;" \
    : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key) \
    : \
    : "cc" \
);

#define ConditionalSwap_TwoCmovTmp(left, right) { \
    uint64_t tmp = items[left].key; \
    __asm__( \
        "cmpq %[left_key],%[right_key]; \
        cmovbq %[right_key],%[left_key]; \
        cmovbq %[tmp],%[right_key];" \
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [tmp] "+r"(tmp) \
        : \
        : "cc" \
    ); \
}

#define ConditionalSwap_ThreeCmovVolatileTemp(left, right) { \
    volatile uint64_t tmp; \
    __asm__ ( \
        "cmpq %[left_key],%[right_key]; \
        cmovbq %[left_key],%[tmp]; \
        cmovbq %[right_key],%[left_key]; \
        cmovbq %[tmp],%[right_key];" \
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [tmp] "+r"(tmp) \
        : \
        : "cc" \
    ); \
}

#define ConditionalSwap_ThreeCmovRegisterTemp(left, right) { \
    register uint64_t tmp; \
    __asm__ ( \
        "cmpq %[left_key],%[right_key]; \
        cmovbq %[left_key],%[tmp]; \
        cmovbq %[right_key],%[left_key]; \
        cmovbq %[tmp],%[right_key];" \
        : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [tmp] "+r"(tmp) \
        : \
        : "cc" \
    ); \
}

#define ConditionalSwap_TwoCmovMemoryAddress(left, right) __asm__ ( \
    "leaq left(%rdi), %rax; \
    movups left(%rdi), %xmm0; \
    movaps %xmm0, -24(%rsp); \
    leaq right(%rdi), %rcx; \
    movq right(%rdi), %rdx; \
    cmpq -24(%rsp), %rdx; \
    cmovbq %rcx, %rax; \
    movups (%rax), %xmm0; \
    movups %xmm0, left(%rdi); \
    leaq -24(%rsp), %rax; \
    cmovaeq %rcx, %rax; \
    movups (%rax), %xmm0; \
    movups %xmm0, right(%rdi);" \
);

#endif