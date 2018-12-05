   1              		.file	"asm_test.cpp"
   2              	# GNU C++14 (Ubuntu 7.3.0-27ubuntu1~18.04) version 7.3.0 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 7.3.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl ve
   4              	
   5              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   6              	# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE asm_test.cpp
   7              	# -march=bdver2 -mmmx -mno-3dnow -msse -msse2 -msse3 -mssse3 -msse4a -mcx16
   8              	# -msahf -mno-movbe -maes -mno-sha -mpclmul -mpopcnt -mabm -mlwp -mfma
   9              	# -mfma4 -mxop -mbmi -mno-sgx -mno-bmi2 -mtbm -mavx -mno-avx2 -msse4.2
  10              	# -msse4.1 -mlzcnt -mno-rtm -mno-hle -mno-rdrnd -mf16c -mno-fsgsbase
  11              	# -mno-rdseed -mprfchw -mno-adx -mfxsr -mxsave -mno-xsaveopt -mno-avx512f
  12              	# -mno-avx512er -mno-avx512cd -mno-avx512pf -mno-prefetchwt1
  13              	# -mno-clflushopt -mno-xsavec -mno-xsaves -mno-avx512dq -mno-avx512bw
  14              	# -mno-avx512vl -mno-avx512ifma -mno-avx512vbmi -mno-avx5124fmaps
  15              	# -mno-avx5124vnniw -mno-clwb -mno-mwaitx -mno-clzero -mno-pku -mno-rdpid
  16              	# --param l1-cache-size=16 --param l1-cache-line-size=64
  17              	# --param l2-cache-size=2048 -mtune=bdver2 -masm=att -g -O3 -fverbose-asm
  18              	# -fstack-protector-strong -Wformat -Wformat-security
  19              	# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
  20              	# -falign-labels -fasynchronous-unwind-tables -fauto-inc-dec
  21              	# -fbranch-count-reg -fcaller-saves -fchkp-check-incomplete-type
  22              	# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
  23              	# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
  24              	# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
  25              	# -fchkp-use-wrappers -fcode-hoisting -fcombine-stack-adjustments -fcommon
  26              	# -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
  27              	# -fdefer-pop -fdelete-null-pointer-checks -fdevirtualize
  28              	# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
  29              	# -feliminate-unused-debug-types -fexceptions -fexpensive-optimizations
  30              	# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse
  31              	# -fgcse-after-reload -fgcse-lm -fgnu-runtime -fgnu-unique
  32              	# -fguess-branch-probability -fhoist-adjacent-loads -fident -fif-conversion
  33              	# -fif-conversion2 -findirect-inlining -finline -finline-atomics
  34              	# -finline-functions -finline-functions-called-once
  35              	# -finline-small-functions -fipa-bit-cp -fipa-cp -fipa-cp-clone -fipa-icf
  36              	# -fipa-icf-functions -fipa-icf-variables -fipa-profile -fipa-pure-const
  37              	# -fipa-ra -fipa-reference -fipa-sra -fipa-vrp -fira-hoist-pressure
  38              	# -fira-share-save-slots -fira-share-spill-slots
  39              	# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
  40              	# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
  41              	# -fmath-errno -fmerge-constants -fmerge-debug-strings
  42              	# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
  43              	# -foptimize-strlen -fpartial-inlining -fpeel-loops -fpeephole -fpeephole2
  44              	# -fplt -fpredictive-commoning -fprefetch-loop-arrays -free
  45              	# -freg-struct-return -freorder-blocks -freorder-functions
  46              	# -frerun-cse-after-loop -fsched-critical-path-heuristic
  47              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  48              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  49              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
  50              	# -fschedule-insns2 -fsemantic-interposition -fshow-column -fshrink-wrap
  51              	# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
  52              	# -fsplit-loops -fsplit-paths -fsplit-wide-types -fssa-backprop
  53              	# -fssa-phiopt -fstack-protector-strong -fstdarg-opt -fstore-merging
  54              	# -fstrict-aliasing -fstrict-overflow -fstrict-volatile-bitfields
  55              	# -fsync-libcalls -fthread-jumps -ftoplevel-reorder -ftrapping-math
  56              	# -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp -ftree-ch
  57              	# -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
  58              	# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
  59              	# -ftree-loop-distribute-patterns -ftree-loop-if-convert -ftree-loop-im
  60              	# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-loop-vectorize
  61              	# -ftree-parallelize-loops= -ftree-partial-pre -ftree-phiprop -ftree-pre
  62              	# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
  63              	# -ftree-slp-vectorize -ftree-slsr -ftree-sra -ftree-switch-conversion
  64              	# -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time -funswitch-loops
  65              	# -funwind-tables -fvar-tracking -fvar-tracking-assignments -fverbose-asm
  66              	# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387 -mabm -maes
  67              	# -malign-stringops -mavx -mavx256-split-unaligned-store -mbmi -mcx16
  68              	# -mf16c -mfancy-math-387 -mfma -mfma4 -mfp-ret-in-387 -mfxsr -mglibc
  69              	# -mieee-fp -mlong-double-80 -mlwp -mlzcnt -mmmx -mpclmul -mpopcnt
  70              	# -mprefer-avx128 -mprfchw -mpush-args -mred-zone -msahf -msse -msse2
  71              	# -msse3 -msse4 -msse4.1 -msse4.2 -msse4a -mssse3 -mstv -mtbm
  72              	# -mtls-direct-seg-refs -mvzeroupper -mxop -mxsave
  73              	
  74              		.text
  75              	.Ltext0:
  76              		.p2align 4,,10
  77              		.p2align 3
  78              		.globl	_Z7CompareP8Sortableii
  80              	_Z7CompareP8Sortableii:
  81              	.LFB901:
  82              		.file 1 "asm_test.cpp"
   1:asm_test.cpp  **** 
   2:asm_test.cpp  **** #include <algorithm>
   3:asm_test.cpp  **** 
   4:asm_test.cpp  **** #include "NetworkSort_Simple.h"
   5:asm_test.cpp  **** 
   6:asm_test.cpp  **** void Compare(Sortable* items, int left, int right) {
  83              		.loc 1 6 0
  84              		.cfi_startproc
  85              	.LVL0:
  86              	# asm_test.cpp:7:     uint64_t tmp = items[left].key;
   7:asm_test.cpp  ****     uint64_t tmp = items[left].key;
  87              		.loc 1 7 0
  88 0000 4863F6   		movslq	%esi, %rsi	# left, left
  89              	# asm_test.cpp:20:         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key)
   8:asm_test.cpp  ****     // __asm__(
   9:asm_test.cpp  ****     //     "cmpq %[left_key],%[right_key]\n"
  10:asm_test.cpp  ****     //     "cmovbq %[items_left],%[items_right]\n"
  11:asm_test.cpp  ****     //     "cmovbq %[items_right],%[tmp]\n"
  12:asm_test.cpp  ****     //     : [items_left] "+r"(items[left]), [items_right] "+r"(items[right])
  13:asm_test.cpp  ****     //     : [tmp] "rm"(tmp), [left_key] "x"(items[left].key), [right_key] "xm"(items[right].key)
  14:asm_test.cpp  ****     //     : "cc"
  15:asm_test.cpp  ****     // );
  16:asm_test.cpp  ****     __asm__(
  17:asm_test.cpp  ****         "cmpq %[left_key],%[right_key]\n"
  18:asm_test.cpp  ****         "cmovbq %[right_key],%[left_key]\n"
  19:asm_test.cpp  ****         "cmovbq %[tmp],%[right_key]\n"
  20:asm_test.cpp  ****         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key)
  90              		.loc 1 20 0
  91 0003 4863D2   		movslq	%edx, %rdx	# right, right
  92 0006 48C1E204 		salq	$4, %rdx	#, tmp101
  93              	.LVL1:
  94              	# asm_test.cpp:7:     uint64_t tmp = items[left].key;
   7:asm_test.cpp  ****     uint64_t tmp = items[left].key;
  95              		.loc 1 7 0
  96 000a 48C1E604 		salq	$4, %rsi	#, tmp99
  97              	.LVL2:
  98 000e 4801FE   		addq	%rdi, %rsi	# items, _3
  99              	.LVL3:
 100              	# asm_test.cpp:20:         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key)
 101              		.loc 1 20 0
 102 0011 4801D7   		addq	%rdx, %rdi	# tmp101, _6
 103              	.LVL4:
 104              	# asm_test.cpp:23:     );
  21:asm_test.cpp  ****         : [tmp] "r"(tmp)
  22:asm_test.cpp  ****         : "cc"
  23:asm_test.cpp  ****     );
 105              		.loc 1 23 0
 106 0014 488B06   		movq	(%rsi), %rax	# _3->key, tmp102
 107 0017 488B17   		movq	(%rdi), %rdx	# _6->key, tmp103
 108              	#APP
 109              	# 23 "asm_test.cpp" 1
  24 001d 480F42C2 	}
  25 0021 480F42D0 	
  26              	void Compare_Brute(Sortable* items, int left, int right) {
  27              	    uint64_t tmpKey = items[left].key;
 110              		cmpq %rax,%rdx	# tmp102, tmp103
 111              	cmovbq %rdx,%rax	# tmp103, tmp102
 112              	cmovbq %rax,%rdx	# tmp102, tmp103
 113              	
 114              	# 0 "" 2
 115              	#NO_APP
 116 0025 488906   		movq	%rax, (%rsi)	# tmp102, _3->key
 117              	.LVL5:
 118 0028 488917   		movq	%rdx, (%rdi)	# tmp103, _6->key
 119              	# asm_test.cpp:24: }
  24:asm_test.cpp  **** 
 120              		.loc 1 24 0
 121 002b C3       		ret
 122              		.cfi_endproc
 123              	.LFE901:
 125 002c 0F1F4000 		.p2align 4,,10
 126              		.p2align 3
 127              		.globl	_Z13Compare_BruteP8Sortableii
 129              	_Z13Compare_BruteP8Sortableii:
 130              	.LFB902:
  26:asm_test.cpp  ****     uint64_t tmpKey = items[left].key;
 131              		.loc 1 26 0
 132              		.cfi_startproc
 133              	.LVL6:
 134              	# asm_test.cpp:27:     uint64_t tmpKey = items[left].key;
 135              		.loc 1 27 0
 136 0030 4863F6   		movslq	%esi, %rsi	# left, left
 137              	# asm_test.cpp:36:         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), 
  28:asm_test.cpp  ****     uint64_t tmpReference = items[left].reference;
  29:asm_test.cpp  **** 
  30:asm_test.cpp  ****     __asm__(
  31:asm_test.cpp  ****         "cmpq %[left_key],%[right_key]\n"
  32:asm_test.cpp  ****         "cmovbq %[right_key],%[left_key]\n"
  33:asm_test.cpp  ****         "cmovbq %[right_reference],%[left_reference]\n"
  34:asm_test.cpp  ****         "cmovbq %[tmp_key],%[right_key]\n"
  35:asm_test.cpp  ****         "cmovbq %[tmp_reference],%[right_reference]\n"
  36:asm_test.cpp  ****         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [left_reference] "+
 138              		.loc 1 36 0
 139 0033 4863D2   		movslq	%edx, %rdx	# right, right
 140 0036 48C1E204 		salq	$4, %rdx	#, tmp103
 141              	.LVL7:
 142              	# asm_test.cpp:27:     uint64_t tmpKey = items[left].key;
  27:asm_test.cpp  ****     uint64_t tmpReference = items[left].reference;
 143              		.loc 1 27 0
 144 003a 48C1E604 		salq	$4, %rsi	#, tmp101
 145              	.LVL8:
 146 003e 4801FE   		addq	%rdi, %rsi	# items, _3
 147              	.LVL9:
 148              	# asm_test.cpp:36:         : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), 
 149              		.loc 1 36 0
 150 0041 4801D7   		addq	%rdx, %rdi	# tmp103, _6
 151              	.LVL10:
 152              	# asm_test.cpp:39:     );
  37:asm_test.cpp  ****         : [tmp_key] "rm"(tmpKey), [tmp_reference] "rm"(tmpReference)
  38:asm_test.cpp  ****         : "cc"
  39:asm_test.cpp  ****     );
 153              		.loc 1 39 0
 154 0044 4C8B07   		movq	(%rdi), %r8	# _6->key, tmp105
 155 0047 488B16   		movq	(%rsi), %rdx	# _3->key, tmp104
 156 004a 488B4608 		movq	8(%rsi), %rax	# _3->reference, tmp106
 157 004e 488B4F08 		movq	8(%rdi), %rcx	# _6->reference, tmp107
 158              	#APP
 159              	# 39 "asm_test.cpp" 1
  40 0055 490F42D0 	}
  41 0059 480F42C1 	
  42 005d 4C0F42C2 	// #define Compare_Brute(left, right) __asm__( \
  43 0061 480F42C8 	//     "cmpq %[left_key],%[right_key]\n" \
  44              	//     "cmovbq %[right_key],%[left_key]\n" \
  45              	//     "cmovbq %[right_reference],%[left_reference]\n" \
 160              		cmpq %rdx,%r8	# tmp104, tmp105
 161              	cmovbq %r8,%rdx	# tmp105, tmp104
 162              	cmovbq %rcx,%rax	# tmp107, tmp106
 163              	cmovbq %rdx,%r8	# tmp104, tmp105
 164              	cmovbq %rax,%rcx	# tmp106, tmp107
 165              	
 166              	# 0 "" 2
 167              	#NO_APP
 168 0065 488916   		movq	%rdx, (%rsi)	# tmp104, _3->key
 169              	.LVL11:
 170 0068 4C8907   		movq	%r8, (%rdi)	# tmp105, _6->key
 171 006b 48894608 		movq	%rax, 8(%rsi)	# tmp106, _3->reference
 172              	.LVL12:
 173 006f 48894F08 		movq	%rcx, 8(%rdi)	# tmp107, _6->reference
 174              	# asm_test.cpp:40: }
  40:asm_test.cpp  **** 
 175              		.loc 1 40 0
 176 0073 C3       		ret
 177              		.cfi_endproc
 178              	.LFE902:
 180              		.p2align 4,,10
 181 0074 0F1F4000 		.p2align 3
 182              		.globl	_Z14Compare_CopiedP8Sortableii
 184              	_Z14Compare_CopiedP8Sortableii:
 185              	.LFB903:
  46:asm_test.cpp  **** //     "cmovbq %[tmp_key],%[right_key]\n" \
  47:asm_test.cpp  **** //     "cmovbq %[tmp_reference],%[right_reference]\n" \
  48:asm_test.cpp  **** //     : [left_key] "+r"(items[left].key), [right_key] "+r"(items[right].key), [left_reference] "+r
  49:asm_test.cpp  **** //     : [tmp_key] "rm"(tmpKey), [tmp_reference] "rm"(tmpReference) \
  50:asm_test.cpp  **** //     : "cc" \
  51:asm_test.cpp  **** // );
  52:asm_test.cpp  **** 
  53:asm_test.cpp  **** void Compare_Copied(Sortable* items, int left, int right) {
 186              		.loc 1 53 0
 187              		.cfi_startproc
 188              	.LVL13:
 189              	# asm_test.cpp:55: }
  54:asm_test.cpp  **** 
  55:asm_test.cpp  **** }
 190              		.loc 1 55 0
 191 0078 C3       		ret
 192              		.cfi_endproc
 193              	.LFE903:
 195 0079 0F1F8000 		.p2align 4,,10
 195      000000
 196              		.p2align 3
 197              		.globl	_Z27NetworkSortSimple_OptimisedP8Sortable
 199              	_Z27NetworkSortSimple_OptimisedP8Sortable:
 200              	.LFB904:
  56:asm_test.cpp  **** 
  57:asm_test.cpp  **** void NetworkSortSimple_Optimised(Sortable* items) {
 201              		.loc 1 57 0
 202              		.cfi_startproc
 203              	.LVL14:
 204              	.LBB20:
 205              	.LBB21:
 206              	# asm_test.cpp:39:     );
  39:asm_test.cpp  **** }
 207              		.loc 1 39 0
 208 0080 488B17   		movq	(%rdi), %rdx	# items_2(D)->key, tmp104
 209 0083 488B7710 		movq	16(%rdi), %rsi	# MEM[(struct Sortable *)items_2(D) + 16B].key, tmp105
 210 0087 488B4708 		movq	8(%rdi), %rax	# items_2(D)->reference, tmp106
 211 008b 488B4F18 		movq	24(%rdi), %rcx	# MEM[(struct Sortable *)items_2(D) + 16B].reference, tmp107
 212              	.LBE21:
 213              	.LBE20:
 214              	.LBB23:
 215              	.LBB24:
 216 008f 4C8B4F40 		movq	64(%rdi), %r9	# MEM[(struct Sortable *)items_2(D) + 64B].key, tmp111
 217 0093 4C8B4748 		movq	72(%rdi), %r8	# MEM[(struct Sortable *)items_2(D) + 64B].reference, tmp113
 218              	.LBE24:
 219              	.LBE23:
 220              	.LBB27:
 221              	.LBB22:
 222              	#APP
 223              	# 39 "asm_test.cpp" 1
 224              		cmpq %rdx,%rsi	# tmp104, tmp105
 225              	cmovbq %rsi,%rdx	# tmp105, tmp104
 226              	cmovbq %rcx,%rax	# tmp107, tmp106
 227              	cmovbq %rdx,%rsi	# tmp104, tmp105
 228              	cmovbq %rax,%rcx	# tmp106, tmp107
 229              	
 230              	# 0 "" 2
 231              	#NO_APP
 232 00aa 48897710 		movq	%rsi, 16(%rdi)	# tmp105, _16->key
 233 00ae 48894F18 		movq	%rcx, 24(%rdi)	# tmp107, _16->reference
 234              	.LVL15:
 235              	.LBE22:
 236              	.LBE27:
 237              	.LBB28:
 238              	.LBB25:
 239 00b2 488B7730 		movq	48(%rdi), %rsi	# MEM[(struct Sortable *)items_2(D) + 48B].key, tmp110
 240 00b6 488B4F38 		movq	56(%rdi), %rcx	# MEM[(struct Sortable *)items_2(D) + 48B].reference, tmp112
 241              	#APP
 242              	# 39 "asm_test.cpp" 1
 243              		cmpq %rsi,%r9	# tmp110, tmp111
 244              	cmovbq %r9,%rsi	# tmp111, tmp110
 245              	cmovbq %r8,%rcx	# tmp113, tmp112
 246              	cmovbq %rsi,%r9	# tmp110, tmp111
 247              	cmovbq %rcx,%r8	# tmp112, tmp113
 248              	
 249              	# 0 "" 2
 250              	#NO_APP
 251 00cd 48897730 		movq	%rsi, 48(%rdi)	# tmp110, _8->key
 252              	.LVL16:
 253 00d1 48894F38 		movq	%rcx, 56(%rdi)	# tmp112, _8->reference
 254              	.LVL17:
 255              	.LBE25:
 256              	.LBE28:
 257              	.LBB29:
 258              	.LBB30:
 259 00d5 488B7720 		movq	32(%rdi), %rsi	# MEM[(struct Sortable *)items_2(D) + 32B].key, tmp117
 260 00d9 488B4F28 		movq	40(%rdi), %rcx	# MEM[(struct Sortable *)items_2(D) + 32B].reference, tmp119
 261              	.LBE30:
 262              	.LBE29:
 263              	.LBB32:
 264              	.LBB26:
 265 00dd 4C894F40 		movq	%r9, 64(%rdi)	# tmp111, _11->key
 266 00e1 4C894748 		movq	%r8, 72(%rdi)	# tmp113, _11->reference
 267              	.LVL18:
 268              	.LBE26:
 269              	.LBE32:
 270              	.LBB33:
 271              	.LBB31:
 272              	#APP
 273              	# 39 "asm_test.cpp" 1
 274              		cmpq %rdx,%rsi	# tmp116, tmp117
 275              	cmovbq %rsi,%rdx	# tmp117, tmp116
 276              	cmovbq %rcx,%rax	# tmp119, tmp118
 277              	cmovbq %rdx,%rsi	# tmp116, tmp117
 278              	cmovbq %rax,%rcx	# tmp118, tmp119
 279              	
 280              	# 0 "" 2
 281              	.LVL19:
 282              	#NO_APP
 283 00f8 488917   		movq	%rdx, (%rdi)	# tmp116, items_2(D)->key
 284 00fb 48897720 		movq	%rsi, 32(%rdi)	# tmp117, _5->key
 285 00ff 48894708 		movq	%rax, 8(%rdi)	# tmp118, items_2(D)->reference
 286 0103 48894F28 		movq	%rcx, 40(%rdi)	# tmp119, _5->reference
 287              	.LVL20:
 288              	.LBE31:
 289              	.LBE33:
 290              	# asm_test.cpp:67: }
  58:asm_test.cpp  ****     Compare_Brute(items, 0, 1);
  59:asm_test.cpp  ****     Compare_Brute(items, 3, 4);
  60:asm_test.cpp  ****     Compare_Brute(items, 0, 2);
  61:asm_test.cpp  ****     // Compare(items, 1, 2);
  62:asm_test.cpp  ****     // Compare(items, 0, 3);
  63:asm_test.cpp  ****     // Compare(items, 2, 3);
  64:asm_test.cpp  ****     // Compare(items, 1, 4);
  65:asm_test.cpp  ****     // Compare(items, 1, 2);
  66:asm_test.cpp  ****     // Compare(items, 3, 4);
  67:asm_test.cpp  **** }
 291              		.loc 1 67 0
 292 0107 C3       		ret
 293              		.cfi_endproc
 294              	.LFE904:
 296 0108 0F1F8400 		.p2align 4,,10
 296      00000000 
 297              		.p2align 3
 298              		.globl	_Z23NetworkSortSimple_NaiveP8Sortable
 300              	_Z23NetworkSortSimple_NaiveP8Sortable:
 301              	.LFB905:
  68:asm_test.cpp  **** 
  69:asm_test.cpp  **** #define Compare_Swap(left, right) if (items[left].key > items[right].key) {std::swap(items[left], i
  70:asm_test.cpp  **** 
  71:asm_test.cpp  **** void NetworkSortSimple_Naive(Sortable* items) {
 302              		.loc 1 71 0
 303              		.cfi_startproc
 304              	.LVL21:
 305              	# asm_test.cpp:72:     Compare_Swap(0, 1);
  72:asm_test.cpp  ****     Compare_Swap(0, 1);
 306              		.loc 1 72 0
 307 0110 488B07   		movq	(%rdi), %rax	# items_11(D)->key, _1
 308 0113 483B4710 		cmpq	16(%rdi), %rax	# MEM[(struct Sortable *)items_11(D) + 16B].key, _1
 309 0117 761C     		jbe	.L7	#,
 310              	.LVL22:
 311              	.LBB34:
 312              	.LBB35:
 313              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 314              		.file 2 "/usr/include/c++/7/bits/move.h"
   1:/usr/include/c++/7/bits/move.h **** // Move, forward and identity for C++11 + swap -*- C++ -*-
   2:/usr/include/c++/7/bits/move.h **** 
   3:/usr/include/c++/7/bits/move.h **** // Copyright (C) 2007-2017 Free Software Foundation, Inc.
   4:/usr/include/c++/7/bits/move.h **** //
   5:/usr/include/c++/7/bits/move.h **** // This file is part of the GNU ISO C++ Library.  This library is free
   6:/usr/include/c++/7/bits/move.h **** // software; you can redistribute it and/or modify it under the
   7:/usr/include/c++/7/bits/move.h **** // terms of the GNU General Public License as published by the
   8:/usr/include/c++/7/bits/move.h **** // Free Software Foundation; either version 3, or (at your option)
   9:/usr/include/c++/7/bits/move.h **** // any later version.
  10:/usr/include/c++/7/bits/move.h **** 
  11:/usr/include/c++/7/bits/move.h **** // This library is distributed in the hope that it will be useful,
  12:/usr/include/c++/7/bits/move.h **** // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13:/usr/include/c++/7/bits/move.h **** // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14:/usr/include/c++/7/bits/move.h **** // GNU General Public License for more details.
  15:/usr/include/c++/7/bits/move.h **** 
  16:/usr/include/c++/7/bits/move.h **** // Under Section 7 of GPL version 3, you are granted additional
  17:/usr/include/c++/7/bits/move.h **** // permissions described in the GCC Runtime Library Exception, version
  18:/usr/include/c++/7/bits/move.h **** // 3.1, as published by the Free Software Foundation.
  19:/usr/include/c++/7/bits/move.h **** 
  20:/usr/include/c++/7/bits/move.h **** // You should have received a copy of the GNU General Public License and
  21:/usr/include/c++/7/bits/move.h **** // a copy of the GCC Runtime Library Exception along with this program;
  22:/usr/include/c++/7/bits/move.h **** // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23:/usr/include/c++/7/bits/move.h **** // <http://www.gnu.org/licenses/>.
  24:/usr/include/c++/7/bits/move.h **** 
  25:/usr/include/c++/7/bits/move.h **** /** @file bits/move.h
  26:/usr/include/c++/7/bits/move.h ****  *  This is an internal header file, included by other library headers.
  27:/usr/include/c++/7/bits/move.h ****  *  Do not attempt to use it directly. @headername{utility}
  28:/usr/include/c++/7/bits/move.h ****  */
  29:/usr/include/c++/7/bits/move.h **** 
  30:/usr/include/c++/7/bits/move.h **** #ifndef _MOVE_H
  31:/usr/include/c++/7/bits/move.h **** #define _MOVE_H 1
  32:/usr/include/c++/7/bits/move.h **** 
  33:/usr/include/c++/7/bits/move.h **** #include <bits/c++config.h>
  34:/usr/include/c++/7/bits/move.h **** #include <bits/concept_check.h>
  35:/usr/include/c++/7/bits/move.h **** 
  36:/usr/include/c++/7/bits/move.h **** namespace std _GLIBCXX_VISIBILITY(default)
  37:/usr/include/c++/7/bits/move.h **** {
  38:/usr/include/c++/7/bits/move.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  39:/usr/include/c++/7/bits/move.h **** 
  40:/usr/include/c++/7/bits/move.h ****   // Used, in C++03 mode too, by allocators, etc.
  41:/usr/include/c++/7/bits/move.h ****   /**
  42:/usr/include/c++/7/bits/move.h ****    *  @brief Same as C++11 std::addressof
  43:/usr/include/c++/7/bits/move.h ****    *  @ingroup utilities
  44:/usr/include/c++/7/bits/move.h ****    */
  45:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
  46:/usr/include/c++/7/bits/move.h ****     inline _GLIBCXX_CONSTEXPR _Tp*
  47:/usr/include/c++/7/bits/move.h ****     __addressof(_Tp& __r) _GLIBCXX_NOEXCEPT
  48:/usr/include/c++/7/bits/move.h ****     { return __builtin_addressof(__r); }
  49:/usr/include/c++/7/bits/move.h **** 
  50:/usr/include/c++/7/bits/move.h **** _GLIBCXX_END_NAMESPACE_VERSION
  51:/usr/include/c++/7/bits/move.h **** } // namespace
  52:/usr/include/c++/7/bits/move.h **** 
  53:/usr/include/c++/7/bits/move.h **** #if __cplusplus >= 201103L
  54:/usr/include/c++/7/bits/move.h **** #include <type_traits> // Brings in std::declval too.
  55:/usr/include/c++/7/bits/move.h **** 
  56:/usr/include/c++/7/bits/move.h **** namespace std _GLIBCXX_VISIBILITY(default)
  57:/usr/include/c++/7/bits/move.h **** {
  58:/usr/include/c++/7/bits/move.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
  59:/usr/include/c++/7/bits/move.h **** 
  60:/usr/include/c++/7/bits/move.h ****   /**
  61:/usr/include/c++/7/bits/move.h ****    *  @addtogroup utilities
  62:/usr/include/c++/7/bits/move.h ****    *  @{
  63:/usr/include/c++/7/bits/move.h ****    */
  64:/usr/include/c++/7/bits/move.h **** 
  65:/usr/include/c++/7/bits/move.h ****   /**
  66:/usr/include/c++/7/bits/move.h ****    *  @brief  Forward an lvalue.
  67:/usr/include/c++/7/bits/move.h ****    *  @return The parameter cast to the specified type.
  68:/usr/include/c++/7/bits/move.h ****    *
  69:/usr/include/c++/7/bits/move.h ****    *  This function is used to implement "perfect forwarding".
  70:/usr/include/c++/7/bits/move.h ****    */
  71:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
  72:/usr/include/c++/7/bits/move.h ****     constexpr _Tp&&
  73:/usr/include/c++/7/bits/move.h ****     forward(typename std::remove_reference<_Tp>::type& __t) noexcept
  74:/usr/include/c++/7/bits/move.h ****     { return static_cast<_Tp&&>(__t); }
  75:/usr/include/c++/7/bits/move.h **** 
  76:/usr/include/c++/7/bits/move.h ****   /**
  77:/usr/include/c++/7/bits/move.h ****    *  @brief  Forward an rvalue.
  78:/usr/include/c++/7/bits/move.h ****    *  @return The parameter cast to the specified type.
  79:/usr/include/c++/7/bits/move.h ****    *
  80:/usr/include/c++/7/bits/move.h ****    *  This function is used to implement "perfect forwarding".
  81:/usr/include/c++/7/bits/move.h ****    */
  82:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
  83:/usr/include/c++/7/bits/move.h ****     constexpr _Tp&&
  84:/usr/include/c++/7/bits/move.h ****     forward(typename std::remove_reference<_Tp>::type&& __t) noexcept
  85:/usr/include/c++/7/bits/move.h ****     {
  86:/usr/include/c++/7/bits/move.h ****       static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
  87:/usr/include/c++/7/bits/move.h **** 		    " substituting _Tp is an lvalue reference type");
  88:/usr/include/c++/7/bits/move.h ****       return static_cast<_Tp&&>(__t);
  89:/usr/include/c++/7/bits/move.h ****     }
  90:/usr/include/c++/7/bits/move.h **** 
  91:/usr/include/c++/7/bits/move.h ****   /**
  92:/usr/include/c++/7/bits/move.h ****    *  @brief  Convert a value to an rvalue.
  93:/usr/include/c++/7/bits/move.h ****    *  @param  __t  A thing of arbitrary type.
  94:/usr/include/c++/7/bits/move.h ****    *  @return The parameter cast to an rvalue-reference to allow moving it.
  95:/usr/include/c++/7/bits/move.h ****   */
  96:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
  97:/usr/include/c++/7/bits/move.h ****     constexpr typename std::remove_reference<_Tp>::type&&
  98:/usr/include/c++/7/bits/move.h ****     move(_Tp&& __t) noexcept
  99:/usr/include/c++/7/bits/move.h ****     { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
 100:/usr/include/c++/7/bits/move.h **** 
 101:/usr/include/c++/7/bits/move.h **** 
 102:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
 103:/usr/include/c++/7/bits/move.h ****     struct __move_if_noexcept_cond
 104:/usr/include/c++/7/bits/move.h ****     : public __and_<__not_<is_nothrow_move_constructible<_Tp>>,
 105:/usr/include/c++/7/bits/move.h ****                     is_copy_constructible<_Tp>>::type { };
 106:/usr/include/c++/7/bits/move.h **** 
 107:/usr/include/c++/7/bits/move.h ****   /**
 108:/usr/include/c++/7/bits/move.h ****    *  @brief  Conditionally convert a value to an rvalue.
 109:/usr/include/c++/7/bits/move.h ****    *  @param  __x  A thing of arbitrary type.
 110:/usr/include/c++/7/bits/move.h ****    *  @return The parameter, possibly cast to an rvalue-reference.
 111:/usr/include/c++/7/bits/move.h ****    *
 112:/usr/include/c++/7/bits/move.h ****    *  Same as std::move unless the type's move constructor could throw and the
 113:/usr/include/c++/7/bits/move.h ****    *  type is copyable, in which case an lvalue-reference is returned instead.
 114:/usr/include/c++/7/bits/move.h ****    */
 115:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
 116:/usr/include/c++/7/bits/move.h ****     constexpr typename
 117:/usr/include/c++/7/bits/move.h ****     conditional<__move_if_noexcept_cond<_Tp>::value, const _Tp&, _Tp&&>::type
 118:/usr/include/c++/7/bits/move.h ****     move_if_noexcept(_Tp& __x) noexcept
 119:/usr/include/c++/7/bits/move.h ****     { return std::move(__x); }
 120:/usr/include/c++/7/bits/move.h **** 
 121:/usr/include/c++/7/bits/move.h ****   // declval, from type_traits.
 122:/usr/include/c++/7/bits/move.h **** 
 123:/usr/include/c++/7/bits/move.h **** #if __cplusplus > 201402L
 124:/usr/include/c++/7/bits/move.h ****   // _GLIBCXX_RESOLVE_LIB_DEFECTS
 125:/usr/include/c++/7/bits/move.h ****   // 2296. std::addressof should be constexpr
 126:/usr/include/c++/7/bits/move.h **** # define __cpp_lib_addressof_constexpr 201603
 127:/usr/include/c++/7/bits/move.h **** #endif
 128:/usr/include/c++/7/bits/move.h ****   /**
 129:/usr/include/c++/7/bits/move.h ****    *  @brief Returns the actual address of the object or function
 130:/usr/include/c++/7/bits/move.h ****    *         referenced by r, even in the presence of an overloaded
 131:/usr/include/c++/7/bits/move.h ****    *         operator&.
 132:/usr/include/c++/7/bits/move.h ****    *  @param  __r  Reference to an object or function.
 133:/usr/include/c++/7/bits/move.h ****    *  @return   The actual address.
 134:/usr/include/c++/7/bits/move.h ****   */
 135:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
 136:/usr/include/c++/7/bits/move.h ****     inline _GLIBCXX17_CONSTEXPR _Tp*
 137:/usr/include/c++/7/bits/move.h ****     addressof(_Tp& __r) noexcept
 138:/usr/include/c++/7/bits/move.h ****     { return std::__addressof(__r); }
 139:/usr/include/c++/7/bits/move.h **** 
 140:/usr/include/c++/7/bits/move.h ****   // _GLIBCXX_RESOLVE_LIB_DEFECTS
 141:/usr/include/c++/7/bits/move.h ****   // 2598. addressof works on temporaries
 142:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
 143:/usr/include/c++/7/bits/move.h ****     const _Tp* addressof(const _Tp&&) = delete;
 144:/usr/include/c++/7/bits/move.h **** 
 145:/usr/include/c++/7/bits/move.h ****   // C++11 version of std::exchange for internal use.
 146:/usr/include/c++/7/bits/move.h ****   template <typename _Tp, typename _Up = _Tp>
 147:/usr/include/c++/7/bits/move.h ****     inline _Tp
 148:/usr/include/c++/7/bits/move.h ****     __exchange(_Tp& __obj, _Up&& __new_val)
 149:/usr/include/c++/7/bits/move.h ****     {
 150:/usr/include/c++/7/bits/move.h ****       _Tp __old_val = std::move(__obj);
 151:/usr/include/c++/7/bits/move.h ****       __obj = std::forward<_Up>(__new_val);
 152:/usr/include/c++/7/bits/move.h ****       return __old_val;
 153:/usr/include/c++/7/bits/move.h ****     }
 154:/usr/include/c++/7/bits/move.h **** 
 155:/usr/include/c++/7/bits/move.h ****   /// @} group utilities
 156:/usr/include/c++/7/bits/move.h **** _GLIBCXX_END_NAMESPACE_VERSION
 157:/usr/include/c++/7/bits/move.h **** } // namespace
 158:/usr/include/c++/7/bits/move.h **** 
 159:/usr/include/c++/7/bits/move.h **** #define _GLIBCXX_MOVE(__val) std::move(__val)
 160:/usr/include/c++/7/bits/move.h **** #define _GLIBCXX_FORWARD(_Tp, __val) std::forward<_Tp>(__val)
 161:/usr/include/c++/7/bits/move.h **** #else
 162:/usr/include/c++/7/bits/move.h **** #define _GLIBCXX_MOVE(__val) (__val)
 163:/usr/include/c++/7/bits/move.h **** #define _GLIBCXX_FORWARD(_Tp, __val) (__val)
 164:/usr/include/c++/7/bits/move.h **** #endif
 165:/usr/include/c++/7/bits/move.h **** 
 166:/usr/include/c++/7/bits/move.h **** namespace std _GLIBCXX_VISIBILITY(default)
 167:/usr/include/c++/7/bits/move.h **** {
 168:/usr/include/c++/7/bits/move.h **** _GLIBCXX_BEGIN_NAMESPACE_VERSION
 169:/usr/include/c++/7/bits/move.h **** 
 170:/usr/include/c++/7/bits/move.h ****   /**
 171:/usr/include/c++/7/bits/move.h ****    *  @addtogroup utilities
 172:/usr/include/c++/7/bits/move.h ****    *  @{
 173:/usr/include/c++/7/bits/move.h ****    */
 174:/usr/include/c++/7/bits/move.h **** 
 175:/usr/include/c++/7/bits/move.h ****   /**
 176:/usr/include/c++/7/bits/move.h ****    *  @brief Swaps two values.
 177:/usr/include/c++/7/bits/move.h ****    *  @param  __a  A thing of arbitrary type.
 178:/usr/include/c++/7/bits/move.h ****    *  @param  __b  Another thing of arbitrary type.
 179:/usr/include/c++/7/bits/move.h ****    *  @return   Nothing.
 180:/usr/include/c++/7/bits/move.h ****   */
 181:/usr/include/c++/7/bits/move.h ****   template<typename _Tp>
 182:/usr/include/c++/7/bits/move.h ****     inline
 183:/usr/include/c++/7/bits/move.h **** #if __cplusplus >= 201103L
 184:/usr/include/c++/7/bits/move.h ****     typename enable_if<__and_<__not_<__is_tuple_like<_Tp>>,
 185:/usr/include/c++/7/bits/move.h **** 			      is_move_constructible<_Tp>,
 186:/usr/include/c++/7/bits/move.h **** 			      is_move_assignable<_Tp>>::value>::type
 187:/usr/include/c++/7/bits/move.h ****     swap(_Tp& __a, _Tp& __b)
 188:/usr/include/c++/7/bits/move.h ****     noexcept(__and_<is_nothrow_move_constructible<_Tp>,
 189:/usr/include/c++/7/bits/move.h **** 	            is_nothrow_move_assignable<_Tp>>::value)
 190:/usr/include/c++/7/bits/move.h **** #else
 191:/usr/include/c++/7/bits/move.h ****     void
 192:/usr/include/c++/7/bits/move.h ****     swap(_Tp& __a, _Tp& __b)
 193:/usr/include/c++/7/bits/move.h **** #endif
 194:/usr/include/c++/7/bits/move.h ****     {
 195:/usr/include/c++/7/bits/move.h ****       // concept requirements
 196:/usr/include/c++/7/bits/move.h ****       __glibcxx_function_requires(_SGIAssignableConcept<_Tp>)
 197:/usr/include/c++/7/bits/move.h **** 
 198:/usr/include/c++/7/bits/move.h ****       _Tp __tmp = _GLIBCXX_MOVE(__a);
 199:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 315              		.loc 2 199 0 discriminator 1
 316 0119 C5F8104F 		vmovups	16(%rdi), %xmm1	# MEM[(struct Sortable &)items_11(D) + 16], tmp101
 316      10
 317              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 318              		.loc 2 198 0 discriminator 1
 319 011e 488B4F08 		movq	8(%rdi), %rcx	# MEM[(struct Sortable &)items_11(D) + 8], __tmp$reference
 320              	.LVL23:
 321              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 322              		.loc 2 199 0 discriminator 1
 323 0122 488B5710 		movq	16(%rdi), %rdx	# MEM[(struct Sortable &)items_11(D) + 16], tmp99
 324              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 200:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 325              		.loc 2 200 0 discriminator 1
 326 0126 48894710 		movq	%rax, 16(%rdi)	# _1, MEM[(struct Sortable *)items_11(D) + 16B]
 327              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 328              		.loc 2 199 0 discriminator 1
 329 012a C5F8110F 		vmovups	%xmm1, (%rdi)	# tmp101, *items_11(D)
 330              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 331              		.loc 2 200 0 discriminator 1
 332 012e 48894F18 		movq	%rcx, 24(%rdi)	# __tmp$reference, MEM[(struct Sortable *)items_11(D) + 24B]
 333              	.LVL24:
 334 0132 4889D0   		movq	%rdx, %rax	# tmp99, _1
 335              	.LVL25:
 336              	.L7:
 337              	.LBE35:
 338              	.LBE34:
 339              	# asm_test.cpp:73:     Compare_Swap(3, 4);
  73:asm_test.cpp  ****     Compare_Swap(3, 4);
 340              		.loc 1 73 0
 341 0135 488B5730 		movq	48(%rdi), %rdx	# MEM[(struct Sortable *)items_11(D) + 48B].key, _3
 342 0139 483B5740 		cmpq	64(%rdi), %rdx	# MEM[(struct Sortable *)items_11(D) + 64B].key, _3
 343 013d 7616     		jbe	.L8	#,
 344              	.LVL26:
 345              	.LBB36:
 346              	.LBB37:
 347              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 348              		.loc 2 199 0 discriminator 1
 349 013f C5F81057 		vmovups	64(%rdi), %xmm2	# MEM[(struct Sortable &)items_11(D) + 64], tmp102
 349      40
 350              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 351              		.loc 2 198 0 discriminator 1
 352 0144 488B4F38 		movq	56(%rdi), %rcx	# MEM[(struct Sortable &)items_11(D) + 56], __tmp$reference
 353              	.LVL27:
 354              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 355              		.loc 2 200 0 discriminator 1
 356 0148 48895740 		movq	%rdx, 64(%rdi)	# _3, MEM[(struct Sortable *)items_11(D) + 64B]
 357              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 358              		.loc 2 199 0 discriminator 1
 359 014c C5F81157 		vmovups	%xmm2, 48(%rdi)	# tmp102, MEM[(struct Sortable *)items_11(D) + 48B]
 359      30
 360              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 361              		.loc 2 200 0 discriminator 1
 362 0151 48894F48 		movq	%rcx, 72(%rdi)	# __tmp$reference, MEM[(struct Sortable *)items_11(D) + 72B]
 363              	.LVL28:
 364              	.L8:
 365              	.LBE37:
 366              	.LBE36:
 367              	# asm_test.cpp:74:     Compare_Swap(0, 2);
  74:asm_test.cpp  ****     Compare_Swap(0, 2);
 368              		.loc 1 74 0
 369 0155 48394720 		cmpq	%rax, 32(%rdi)	# _1, MEM[(struct Sortable *)items_11(D) + 32B].key
 370 0159 7315     		jnb	.L10	#,
 371              	.LVL29:
 372              	.LBB38:
 373              	.LBB39:
 374              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 375              		.loc 2 199 0 discriminator 1
 376 015b C5F81047 		vmovups	32(%rdi), %xmm0	# MEM[(struct Sortable &)items_11(D) + 32], tmp103
 376      20
 377              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 378              		.loc 2 198 0 discriminator 1
 379 0160 488B5708 		movq	8(%rdi), %rdx	# MEM[(struct Sortable &)items_11(D) + 8], __tmp$reference
 380              	.LVL30:
 381              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 382              		.loc 2 200 0 discriminator 1
 383 0164 48894720 		movq	%rax, 32(%rdi)	# _1, MEM[(struct Sortable *)items_11(D) + 32B]
 384              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 385              		.loc 2 199 0 discriminator 1
 386 0168 C5F81107 		vmovups	%xmm0, (%rdi)	# tmp103, *items_11(D)
 387              	.LVL31:
 388              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 389              		.loc 2 200 0 discriminator 1
 390 016c 48895728 		movq	%rdx, 40(%rdi)	# __tmp$reference, MEM[(struct Sortable *)items_11(D) + 40B]
 391              	.LVL32:
 392              	.L10:
 393              	.LBE39:
 394              	.LBE38:
 395              	# asm_test.cpp:81: }
  75:asm_test.cpp  ****     // Compare_Swap(1, 2);
  76:asm_test.cpp  ****     // Compare_Swap(0, 3);
  77:asm_test.cpp  ****     // Compare_Swap(2, 3);
  78:asm_test.cpp  ****     // Compare_Swap(1, 4);
  79:asm_test.cpp  ****     // Compare_Swap(1, 2);
  80:asm_test.cpp  ****     // Compare_Swap(3, 4);
  81:asm_test.cpp  **** }
 396              		.loc 1 81 0
 397 0170 C3       		ret
 398              		.cfi_endproc
 399              	.LFE905:
 401              		.section	.text.startup,"ax",@progbits
 402              		.p2align 4,,10
 403              		.p2align 3
 404              		.globl	main
 406              	main:
 407              	.LFB906:
  82:asm_test.cpp  **** 
  83:asm_test.cpp  **** int main() {}
 408              		.loc 1 83 0
 409              		.cfi_startproc
 410              	# asm_test.cpp:83: int main() {}
 411              		.loc 1 83 0
 412 0000 31C0     		xorl	%eax, %eax	#
 413 0002 C3       		ret
 414              		.cfi_endproc
 415              	.LFE906:
 417              		.text
 418              		.p2align 4,,10
 419 0171 0F1F8000 		.p2align 3
 419      000000
 420              		.globl	_Z10SingleSortP8Sortable
 422              	_Z10SingleSortP8Sortable:
 423              	.LFB907:
  84:asm_test.cpp  **** 
  85:asm_test.cpp  **** void SingleSort(Sortable* items) {
 424              		.loc 1 85 0
 425              		.cfi_startproc
 426              	.LVL33:
 427              	# asm_test.cpp:99:     );
  86:asm_test.cpp  ****     __asm__(
  87:asm_test.cpp  ****         "leaq 32(%rdi), %rax\n\t"
  88:asm_test.cpp  ****         "movups 32(%rdi), %xmm0\n\t"
  89:asm_test.cpp  ****         "movaps %xmm0, -24(%rsp)\n\t"
  90:asm_test.cpp  ****         "leaq 48(%rdi), %rdx\n\t"
  91:asm_test.cpp  ****         "movq 48(%rdi), %rsi\n\t"
  92:asm_test.cpp  ****         "cmpq -24(%rsp), %rsi\n\t"
  93:asm_test.cpp  ****         "cmovbq %rdx, %rax\n\t"
  94:asm_test.cpp  ****         "movups (%rax), %xmm0\n\t"
  95:asm_test.cpp  ****         "movups %xmm0, 32(%rdi)\n\t"
  96:asm_test.cpp  ****         "cmovbq %rcx, %rdx\n\t"
  97:asm_test.cpp  ****         "movups (%rdx), %xmm0\n\t"
  98:asm_test.cpp  ****         "movups %xmm0, 48(%rdi)"
  99:asm_test.cpp  ****     );
 428              		.loc 1 99 0
 429              	#APP
 430              	# 99 "asm_test.cpp" 1
 100 017c 0F104720 	}...
 431              		leaq 32(%rdi), %rax
 432              		movups 32(%rdi), %xmm0
 433              		movaps %xmm0, -24(%rsp)
 434              		leaq 48(%rdi), %rdx
 435              		movq 48(%rdi), %rsi
 436              		cmpq -24(%rsp), %rsi
 437              		cmovbq %rdx, %rax
 438              		movups (%rax), %xmm0
 439              		movups %xmm0, 32(%rdi)
 440              		cmovbq %rcx, %rdx
 441              		movups (%rdx), %xmm0
 442              		movups %xmm0, 48(%rdi)
 443              	# 0 "" 2
 444              	# asm_test.cpp:100: }
 445              		.loc 1 100 0
 446              	#NO_APP
 447 01a8 C3       		ret
 448              		.cfi_endproc
 449              	.LFE907:
 451              	.Letext0:
 452              		.file 3 "/usr/include/c++/7/type_traits"
 453              		.file 4 "/usr/include/x86_64-linux-gnu/c++/7/bits/c++config.h"
 454              		.file 5 "/usr/include/c++/7/bits/stl_pair.h"
 455              		.file 6 "/usr/include/c++/7/debug/debug.h"
 456              		.file 7 "/usr/include/c++/7/cstdlib"
 457              		.file 8 "/usr/include/c++/7/bits/algorithmfwd.h"
 458              		.file 9 "/usr/include/c++/7/bits/exception_ptr.h"
 459              		.file 10 "/usr/include/c++/7/new"
 460              		.file 11 "/usr/include/c++/7/bits/stl_algo.h"
 461              		.file 12 "/usr/include/c++/7/bits/predefined_ops.h"
 462              		.file 13 "/usr/include/c++/7/ext/numeric_traits.h"
 463              		.file 14 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
 464              		.file 15 "/usr/include/stdlib.h"
 465              		.file 16 "/usr/include/x86_64-linux-gnu/bits/types.h"
 466              		.file 17 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h"
 467              		.file 18 "/usr/include/x86_64-linux-gnu/bits/stdlib-bsearch.h"
 468              		.file 19 "/usr/include/x86_64-linux-gnu/bits/stdlib.h"
 469              		.file 20 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h"
 470              		.file 21 "Sortable.h"
 471              		.file 22 "<built-in>"
