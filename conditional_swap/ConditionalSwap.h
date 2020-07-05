
#ifndef CONDITONAL_SWAP_H
#define CONDITONAL_SWAP_H

#include "ConditionalSwapGeneric.h"

#if __x86_64__
	#include "ConditionalSwapX86.h"
#elif defined(__i386__)
	#include "ConditionalSwapX86.h"
#elif __aarch64__
	#include "ConditionalSwapARM64.h"
#elif __arm__
	#include "ConditionalSwapARM32.h"
#else
	#include "ConditionalSwapDummy.h"
#endif

#endif