   1              		.file	"NetworkSort_Simple.cpp"
   2              		.intel_syntax noprefix
   3              	# GNU C++14 (Ubuntu 7.3.0-27ubuntu1~18.04) version 7.3.0 (x86_64-linux-gnu)
   4              	#	compiled by GNU C version 7.3.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl ve
   5              	
   6              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   7              	# options passed:  -imultiarch x86_64-linux-gnu -D_GNU_SOURCE
   8              	# NetworkSort_Simple.cpp -march=bdver2 -mmmx -mno-3dnow -msse -msse2 -msse3
   9              	# -mssse3 -msse4a -mcx16 -msahf -mno-movbe -maes -mno-sha -mpclmul -mpopcnt
  10              	# -mabm -mlwp -mfma -mfma4 -mxop -mbmi -mno-sgx -mno-bmi2 -mtbm -mavx
  11              	# -mno-avx2 -msse4.2 -msse4.1 -mlzcnt -mno-rtm -mno-hle -mno-rdrnd -mf16c
  12              	# -mno-fsgsbase -mno-rdseed -mprfchw -mno-adx -mfxsr -mxsave -mno-xsaveopt
  13              	# -mno-avx512f -mno-avx512er -mno-avx512cd -mno-avx512pf -mno-prefetchwt1
  14              	# -mno-clflushopt -mno-xsavec -mno-xsaves -mno-avx512dq -mno-avx512bw
  15              	# -mno-avx512vl -mno-avx512ifma -mno-avx512vbmi -mno-avx5124fmaps
  16              	# -mno-avx5124vnniw -mno-clwb -mno-mwaitx -mno-clzero -mno-pku -mno-rdpid
  17              	# --param l1-cache-size=16 --param l1-cache-line-size=64
  18              	# --param l2-cache-size=2048 -mtune=bdver2 -masm=intel -g -O3 -fverbose-asm
  19              	# -fstack-protector-strong -Wformat -Wformat-security
  20              	# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
  21              	# -falign-labels -fasynchronous-unwind-tables -fauto-inc-dec
  22              	# -fbranch-count-reg -fcaller-saves -fchkp-check-incomplete-type
  23              	# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
  24              	# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
  25              	# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
  26              	# -fchkp-use-wrappers -fcode-hoisting -fcombine-stack-adjustments -fcommon
  27              	# -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
  28              	# -fdefer-pop -fdelete-null-pointer-checks -fdevirtualize
  29              	# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
  30              	# -feliminate-unused-debug-types -fexceptions -fexpensive-optimizations
  31              	# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse
  32              	# -fgcse-after-reload -fgcse-lm -fgnu-runtime -fgnu-unique
  33              	# -fguess-branch-probability -fhoist-adjacent-loads -fident -fif-conversion
  34              	# -fif-conversion2 -findirect-inlining -finline -finline-atomics
  35              	# -finline-functions -finline-functions-called-once
  36              	# -finline-small-functions -fipa-bit-cp -fipa-cp -fipa-cp-clone -fipa-icf
  37              	# -fipa-icf-functions -fipa-icf-variables -fipa-profile -fipa-pure-const
  38              	# -fipa-ra -fipa-reference -fipa-sra -fipa-vrp -fira-hoist-pressure
  39              	# -fira-share-save-slots -fira-share-spill-slots
  40              	# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
  41              	# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
  42              	# -fmath-errno -fmerge-constants -fmerge-debug-strings
  43              	# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
  44              	# -foptimize-strlen -fpartial-inlining -fpeel-loops -fpeephole -fpeephole2
  45              	# -fplt -fpredictive-commoning -fprefetch-loop-arrays -free
  46              	# -freg-struct-return -freorder-blocks -freorder-functions
  47              	# -frerun-cse-after-loop -fsched-critical-path-heuristic
  48              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  49              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  50              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
  51              	# -fschedule-insns2 -fsemantic-interposition -fshow-column -fshrink-wrap
  52              	# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
  53              	# -fsplit-loops -fsplit-paths -fsplit-wide-types -fssa-backprop
  54              	# -fssa-phiopt -fstack-protector-strong -fstdarg-opt -fstore-merging
  55              	# -fstrict-aliasing -fstrict-overflow -fstrict-volatile-bitfields
  56              	# -fsync-libcalls -fthread-jumps -ftoplevel-reorder -ftrapping-math
  57              	# -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp -ftree-ch
  58              	# -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
  59              	# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
  60              	# -ftree-loop-distribute-patterns -ftree-loop-if-convert -ftree-loop-im
  61              	# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-loop-vectorize
  62              	# -ftree-parallelize-loops= -ftree-partial-pre -ftree-phiprop -ftree-pre
  63              	# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
  64              	# -ftree-slp-vectorize -ftree-slsr -ftree-sra -ftree-switch-conversion
  65              	# -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time -funswitch-loops
  66              	# -funwind-tables -fvar-tracking -fvar-tracking-assignments -fverbose-asm
  67              	# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387 -mabm -maes
  68              	# -malign-stringops -mavx -mavx256-split-unaligned-store -mbmi -mcx16
  69              	# -mf16c -mfancy-math-387 -mfma -mfma4 -mfp-ret-in-387 -mfxsr -mglibc
  70              	# -mieee-fp -mlong-double-80 -mlwp -mlzcnt -mmmx -mpclmul -mpopcnt
  71              	# -mprefer-avx128 -mprfchw -mpush-args -mred-zone -msahf -msse -msse2
  72              	# -msse3 -msse4 -msse4.1 -msse4.2 -msse4a -mssse3 -mstv -mtbm
  73              	# -mtls-direct-seg-refs -mvzeroupper -mxop -mxsave
  74              	
  75              		.text
  76              	.Ltext0:
  77              		.section	.text.startup,"ax",@progbits
  78              		.p2align 4,,10
  79              		.p2align 3
  80              		.globl	main
  82              	main:
  83              	.LFB901:
  84              		.file 1 "NetworkSort_Simple.cpp"
   1:NetworkSort_Simple.cpp **** 
   2:NetworkSort_Simple.cpp **** #include <algorithm>
   3:NetworkSort_Simple.cpp **** 
   4:NetworkSort_Simple.cpp **** #include "NetworkSort_Simple.h"
   5:NetworkSort_Simple.cpp **** 
   6:NetworkSort_Simple.cpp **** int main() {
  85              		.loc 1 6 0
  86              		.cfi_startproc
  87              	# NetworkSort_Simple.cpp:8: }
   7:NetworkSort_Simple.cpp **** 
   8:NetworkSort_Simple.cpp **** }
  88              		.loc 1 8 0
  89 ???? 31C0     		xor	eax, eax	#
  90 ???? C3       		ret
  91              		.cfi_endproc
  92              	.LFE901:
  94              		.text
  95              		.p2align 4,,10
  96              		.p2align 3
  97              		.globl	_Z7CompareP8Sortableii
  99              	_Z7CompareP8Sortableii:
 100              	.LFB902:
   9:NetworkSort_Simple.cpp **** 
  10:NetworkSort_Simple.cpp **** void Compare(Sortable* items, int left, int right) {
 101              		.loc 1 10 0
 102              		.cfi_startproc
 103              	.LVL0:
 104              	# NetworkSort_Simple.cpp:11:     uint64_t tmp = items[left].key;
  11:NetworkSort_Simple.cpp ****     uint64_t tmp = items[left].key;
 105              		.loc 1 11 0
 106 ???? 4863F6   		movsx	rsi, esi	# left, left
 107              	# NetworkSort_Simple.cpp:24:         : [left_key] "=xm"(items[left].key), [right_key] "=xm"(items[r
  12:NetworkSort_Simple.cpp ****     // __asm__(
  13:NetworkSort_Simple.cpp ****     //     "cmpq %[left_key],%[right_key]\n"
  14:NetworkSort_Simple.cpp ****     //     "cmovbq %[items_left],%[items_right]\n"
  15:NetworkSort_Simple.cpp ****     //     "cmovbq %[items_right],%[tmp]\n"
  16:NetworkSort_Simple.cpp ****     //     : [items_left] "+r"(items[left]), [items_right] "+r"(items[right])
  17:NetworkSort_Simple.cpp ****     //     : [tmp] "rm"(tmp), [left_key] "x"(items[left].key), [right_key] "xm"(items[right].key)
  18:NetworkSort_Simple.cpp ****     //     : "cc"
  19:NetworkSort_Simple.cpp ****     // );
  20:NetworkSort_Simple.cpp ****     __asm__(
  21:NetworkSort_Simple.cpp ****         "cmpq %[left_key],%[right_key]\n"
  22:NetworkSort_Simple.cpp ****         "cmovbq %[left_key],%[right_key]\n"
  23:NetworkSort_Simple.cpp ****         "cmovbq %[right_key],%[tmp]\n"
  24:NetworkSort_Simple.cpp ****         : [left_key] "=xm"(items[left].key), [right_key] "=xm"(items[right].key)
 108              		.loc 1 24 0
 109 ???? 4863D2   		movsx	rdx, edx	# right, right
 110              	# NetworkSort_Simple.cpp:11:     uint64_t tmp = items[left].key;
  11:NetworkSort_Simple.cpp ****     uint64_t tmp = items[left].key;
 111              		.loc 1 11 0
 112 ???? 48C1E604 		sal	rsi, 4	# tmp98,
 113              	.LVL1:
 114              	# NetworkSort_Simple.cpp:27:     );
  25:NetworkSort_Simple.cpp ****         : [tmp] "r"(tmp)
  26:NetworkSort_Simple.cpp ****         : "cc"
  27:NetworkSort_Simple.cpp ****     );
 115              		.loc 1 27 0
 116 ???? 48C1E204 		sal	rdx, 4	# tmp102,
 117              	.LVL2:
 118              	# NetworkSort_Simple.cpp:11:     uint64_t tmp = items[left].key;
  11:NetworkSort_Simple.cpp ****     // __asm__(
 119              		.loc 1 11 0
 120 ???? 4801FE   		add	rsi, rdi	# _3, items
 121              	.LVL3:
 122              	# NetworkSort_Simple.cpp:27:     );
 123              		.loc 1 27 0
 124 ???? 488B06   		mov	rax, QWORD PTR [rsi]	# _3->key, _3->key
 125              	#APP
 126              	# 27 "NetworkSort_Simple.cpp" 1
  28              	}
  29              	
  30              	void NetworkSortSimple_Optimised(Sortable* items) {
  31              	    Compare(items, 0, 1);
 127              		cmpq xmm0,xmm1	# tmp99, tmp100
 128              	cmovbq xmm0,xmm1	# tmp99, tmp100
 129              	cmovbq xmm1,rax	# tmp100, _3->key
 130              	
 131              	# 0 "" 2
 132              	#NO_APP
 133 ???? C5F9D606 		vmovq	QWORD PTR [rsi], xmm0	# _3->key, tmp99
 134              	.LVL4:
 135 ???? C5F9D60C 		vmovq	QWORD PTR [rdi+rdx], xmm1	# _6->key, tmp100
 135      17
 136              	# NetworkSort_Simple.cpp:28: }
  28:NetworkSort_Simple.cpp **** 
 137              		.loc 1 28 0
 138 ???? C3       		ret
 139              		.cfi_endproc
 140              	.LFE902:
 142 ???? 6690     		.p2align 4,,10
 143              		.p2align 3
 144              		.globl	_Z27NetworkSortSimple_OptimisedP8Sortable
 146              	_Z27NetworkSortSimple_OptimisedP8Sortable:
 147              	.LFB903:
  30:NetworkSort_Simple.cpp ****     Compare(items, 0, 1);
 148              		.loc 1 30 0
 149              		.cfi_startproc
 150              	.LVL5:
 151              	.LBB20:
 152              	.LBB21:
 153              	# NetworkSort_Simple.cpp:27:     );
  27:NetworkSort_Simple.cpp **** }
 154              		.loc 1 27 0
 155 ???? 488B07   		mov	rax, QWORD PTR [rdi]	# items_2(D)->key, items_2(D)->key
 156              	#APP
 157              	# 27 "NetworkSort_Simple.cpp" 1
 158              		cmpq QWORD PTR -8[rsp],xmm0	# %sfp, tmp96
 159              	cmovbq QWORD PTR -8[rsp],xmm0	# %sfp, tmp96
 160              	cmovbq xmm0,rax	# tmp96, items_2(D)->key
 161              	
 162              	# 0 "" 2
 163              	#NO_APP
 164              	.LBE21:
 165              	.LBE20:
 166              	.LBB23:
 167              	.LBB24:
 168 ???? 488B4730 		mov	rax, QWORD PTR 48[rdi]	# MEM[(struct Sortable *)items_2(D) + 48B].key, MEM[(struct Sortable *)
 169              	.LBE24:
 170              	.LBE23:
 171              	.LBB27:
 172              	.LBB22:
 173 ???? C5F9D647 		vmovq	QWORD PTR 16[rdi], xmm0	# _9->key, tmp96
 173      10
 174              	.LVL6:
 175              	.LBE22:
 176              	.LBE27:
 177              	.LBB28:
 178              	.LBB25:
 179              	#APP
 180              	# 27 "NetworkSort_Simple.cpp" 1
 181              		cmpq xmm0,xmm1	# tmp98, tmp99
 182              	cmovbq xmm0,xmm1	# tmp98, tmp99
 183              	cmovbq xmm1,rax	# tmp99, MEM[(struct Sortable *)items_2(D) + 48B].key
 184              	
 185              	# 0 "" 2
 186              	#NO_APP
 187              	.LBE25:
 188              	.LBE28:
 189              	.LBB29:
 190              	.LBB30:
 191 ???? 488B4424 		mov	rax, QWORD PTR -8[rsp]	# tmp95, %sfp
 191      F8
 192              	.LVL7:
 193              	.LBE30:
 194              	.LBE29:
 195              	.LBB32:
 196              	.LBB26:
 197 ???? C5F9D647 		vmovq	QWORD PTR 48[rdi], xmm0	# _5->key, tmp98
 197      30
 198              	.LVL8:
 199 ???? C5F9D64F 		vmovq	QWORD PTR 64[rdi], xmm1	# _7->key, tmp99
 199      40
 200              	.LVL9:
 201              	.LBE26:
 202              	.LBE32:
 203              	.LBB33:
 204              	.LBB31:
 205              	#APP
 206              	# 27 "NetworkSort_Simple.cpp" 1
 207              		cmpq xmm0,xmm1	# tmp101, tmp102
 208              	cmovbq xmm0,xmm1	# tmp101, tmp102
 209              	cmovbq xmm1,rax	# tmp102, tmp95
 210              	
 211              	# 0 "" 2
 212              	#NO_APP
 213 ???? C5F9D607 		vmovq	QWORD PTR [rdi], xmm0	# items_2(D)->key, tmp101
 214              	.LVL10:
 215 ???? C5F9D64F 		vmovq	QWORD PTR 32[rdi], xmm1	# _4->key, tmp102
 215      20
 216              	.LVL11:
 217              	.LBE31:
 218              	.LBE33:
 219              	# NetworkSort_Simple.cpp:40: }
  32:NetworkSort_Simple.cpp ****     Compare(items, 3, 4);
  33:NetworkSort_Simple.cpp ****     Compare(items, 0, 2);
  34:NetworkSort_Simple.cpp ****     // Compare(items, 1, 2);
  35:NetworkSort_Simple.cpp ****     // Compare(items, 0, 3);
  36:NetworkSort_Simple.cpp ****     // Compare(items, 2, 3);
  37:NetworkSort_Simple.cpp ****     // Compare(items, 1, 4);
  38:NetworkSort_Simple.cpp ****     // Compare(items, 1, 2);
  39:NetworkSort_Simple.cpp ****     // Compare(items, 3, 4);
  40:NetworkSort_Simple.cpp **** }
 220              		.loc 1 40 0
 221 ???? C3       		ret
 222              		.cfi_endproc
 223              	.LFE903:
 225              		.p2align 4,,10
 226 ???? 0F1F00   		.p2align 3
 227              		.globl	_Z23NetworkSortSimple_NaiveP8Sortable
 229              	_Z23NetworkSortSimple_NaiveP8Sortable:
 230              	.LFB904:
  41:NetworkSort_Simple.cpp **** 
  42:NetworkSort_Simple.cpp **** #define Compare_Swap(left, right) if (items[left].key > items[right].key) {std::swap(items[left], i
  43:NetworkSort_Simple.cpp **** 
  44:NetworkSort_Simple.cpp **** void NetworkSortSimple_Naive(Sortable* items) {
 231              		.loc 1 44 0
 232              		.cfi_startproc
 233              	.LVL12:
 234              	# NetworkSort_Simple.cpp:45:     Compare_Swap(0, 1);
  45:NetworkSort_Simple.cpp ****     Compare_Swap(0, 1);
 235              		.loc 1 45 0
 236 ???? 488B07   		mov	rax, QWORD PTR [rdi]	# _1, items_11(D)->key
 237 ???? 483B4710 		cmp	rax, QWORD PTR 16[rdi]	# _1, MEM[(struct Sortable *)items_11(D) + 16B].key
 238 ???? 761C     		jbe	.L6	#,
 239              	.LVL13:
 240              	.LBB34:
 241              	.LBB35:
 242              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 243              		.file 2 "/usr/include/c++/7/bits/move.h"
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
 244              		.loc 2 199 0 discriminator 1
 245 ???? C5F8104F 		vmovups	xmm1, XMMWORD PTR 16[rdi]	# tmp101, MEM[(struct Sortable &)items_11(D) + 16]
 245      10
 246              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 247              		.loc 2 198 0 discriminator 1
 248 ???? 488B4F08 		mov	rcx, QWORD PTR 8[rdi]	# __tmp$reference, MEM[(struct Sortable &)items_11(D) + 8]
 249              	.LVL14:
 250              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 251              		.loc 2 199 0 discriminator 1
 252 ???? 488B5710 		mov	rdx, QWORD PTR 16[rdi]	# tmp99, MEM[(struct Sortable &)items_11(D) + 16]
 253              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 200:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 254              		.loc 2 200 0 discriminator 1
 255 ???? 48894710 		mov	QWORD PTR 16[rdi], rax	# MEM[(struct Sortable *)items_11(D) + 16B], _1
 256              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 257              		.loc 2 199 0 discriminator 1
 258 ???? C5F8110F 		vmovups	XMMWORD PTR [rdi], xmm1	# *items_11(D), tmp101
 259              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 260              		.loc 2 200 0 discriminator 1
 261 ???? 48894F18 		mov	QWORD PTR 24[rdi], rcx	# MEM[(struct Sortable *)items_11(D) + 24B], __tmp$reference
 262              	.LVL15:
 263 ???? 4889D0   		mov	rax, rdx	# _1, tmp99
 264              	.LVL16:
 265              	.L6:
 266              	.LBE35:
 267              	.LBE34:
 268              	# NetworkSort_Simple.cpp:46:     Compare_Swap(3, 4);
  46:NetworkSort_Simple.cpp ****     Compare_Swap(3, 4);
 269              		.loc 1 46 0
 270 ???? 488B5730 		mov	rdx, QWORD PTR 48[rdi]	# _3, MEM[(struct Sortable *)items_11(D) + 48B].key
 271 ???? 483B5740 		cmp	rdx, QWORD PTR 64[rdi]	# _3, MEM[(struct Sortable *)items_11(D) + 64B].key
 272 ???? 7616     		jbe	.L7	#,
 273              	.LVL17:
 274              	.LBB36:
 275              	.LBB37:
 276              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 277              		.loc 2 199 0 discriminator 1
 278 ???? C5F81057 		vmovups	xmm2, XMMWORD PTR 64[rdi]	# tmp102, MEM[(struct Sortable &)items_11(D) + 64]
 278      40
 279              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 280              		.loc 2 198 0 discriminator 1
 281 ???? 488B4F38 		mov	rcx, QWORD PTR 56[rdi]	# __tmp$reference, MEM[(struct Sortable &)items_11(D) + 56]
 282              	.LVL18:
 283              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 284              		.loc 2 200 0 discriminator 1
 285 ???? 48895740 		mov	QWORD PTR 64[rdi], rdx	# MEM[(struct Sortable *)items_11(D) + 64B], _3
 286              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 287              		.loc 2 199 0 discriminator 1
 288 ???? C5F81157 		vmovups	XMMWORD PTR 48[rdi], xmm2	# MEM[(struct Sortable *)items_11(D) + 48B], tmp102
 288      30
 289              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 290              		.loc 2 200 0 discriminator 1
 291 ???? 48894F48 		mov	QWORD PTR 72[rdi], rcx	# MEM[(struct Sortable *)items_11(D) + 72B], __tmp$reference
 292              	.LVL19:
 293              	.L7:
 294              	.LBE37:
 295              	.LBE36:
 296              	# NetworkSort_Simple.cpp:47:     Compare_Swap(0, 2);
  47:NetworkSort_Simple.cpp ****     Compare_Swap(0, 2);
 297              		.loc 1 47 0
 298 ???? 48394720 		cmp	QWORD PTR 32[rdi], rax	# MEM[(struct Sortable *)items_11(D) + 32B].key, _1
 299 ???? 7315     		jnb	.L9	#,
 300              	.LVL20:
 301              	.LBB38:
 302              	.LBB39:
 303              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 304              		.loc 2 199 0 discriminator 1
 305 ???? C5F81047 		vmovups	xmm0, XMMWORD PTR 32[rdi]	# tmp103, MEM[(struct Sortable &)items_11(D) + 32]
 305      20
 306              	# /usr/include/c++/7/bits/move.h:198:       _Tp __tmp = _GLIBCXX_MOVE(__a);
 198:/usr/include/c++/7/bits/move.h ****       __a = _GLIBCXX_MOVE(__b);
 307              		.loc 2 198 0 discriminator 1
 308 ???? 488B5708 		mov	rdx, QWORD PTR 8[rdi]	# __tmp$reference, MEM[(struct Sortable &)items_11(D) + 8]
 309              	.LVL21:
 310              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 311              		.loc 2 200 0 discriminator 1
 312 ???? 48894720 		mov	QWORD PTR 32[rdi], rax	# MEM[(struct Sortable *)items_11(D) + 32B], _1
 313              	# /usr/include/c++/7/bits/move.h:199:       __a = _GLIBCXX_MOVE(__b);
 199:/usr/include/c++/7/bits/move.h ****       __b = _GLIBCXX_MOVE(__tmp);
 314              		.loc 2 199 0 discriminator 1
 315 ???? C5F81107 		vmovups	XMMWORD PTR [rdi], xmm0	# *items_11(D), tmp103
 316              	.LVL22:
 317              	# /usr/include/c++/7/bits/move.h:200:       __b = _GLIBCXX_MOVE(__tmp);
 318              		.loc 2 200 0 discriminator 1
 319 ???? 48895728 		mov	QWORD PTR 40[rdi], rdx	# MEM[(struct Sortable *)items_11(D) + 40B], __tmp$reference
 320              	.LVL23:
 321              	.L9:
 322              	.LBE39:
 323              	.LBE38:
 324              	# NetworkSort_Simple.cpp:54: }
  48:NetworkSort_Simple.cpp ****     // Compare_Swap(1, 2);
  49:NetworkSort_Simple.cpp ****     // Compare_Swap(0, 3);
  50:NetworkSort_Simple.cpp ****     // Compare_Swap(2, 3);
  51:NetworkSort_Simple.cpp ****     // Compare_Swap(1, 4);
  52:NetworkSort_Simple.cpp ****     // Compare_Swap(1, 2);
  53:NetworkSort_Simple.cpp ****     // Compare_Swap(3, 4);
  54:NetworkSort_Simple.cpp **** }...
 325              		.loc 1 54 0
 326 ???? C3       		ret
 327              		.cfi_endproc
 328              	.LFE904:
 330              	.Letext0:
 331              		.file 3 "/usr/include/c++/7/type_traits"
 332              		.file 4 "/usr/include/x86_64-linux-gnu/c++/7/bits/c++config.h"
 333              		.file 5 "/usr/include/c++/7/bits/stl_pair.h"
 334              		.file 6 "/usr/include/c++/7/debug/debug.h"
 335              		.file 7 "/usr/include/c++/7/cstdlib"
 336              		.file 8 "/usr/include/c++/7/bits/algorithmfwd.h"
 337              		.file 9 "/usr/include/c++/7/bits/exception_ptr.h"
 338              		.file 10 "/usr/include/c++/7/new"
 339              		.file 11 "/usr/include/c++/7/bits/stl_algo.h"
 340              		.file 12 "/usr/include/c++/7/bits/predefined_ops.h"
 341              		.file 13 "/usr/include/c++/7/ext/numeric_traits.h"
 342              		.file 14 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
 343              		.file 15 "/usr/include/stdlib.h"
 344              		.file 16 "/usr/include/x86_64-linux-gnu/bits/types.h"
 345              		.file 17 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h"
 346              		.file 18 "/usr/include/x86_64-linux-gnu/bits/stdlib-bsearch.h"
 347              		.file 19 "/usr/include/x86_64-linux-gnu/bits/stdlib.h"
 348              		.file 20 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h"
 349              		.file 21 "Sortable.h"
 350              		.file 22 "<built-in>"
