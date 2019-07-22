
#ifndef CUSTOM_MATH_H
#define CUSTOM_MATH_H

#if __x86_64__
  #include "CustomMathX86.h"
#elif defined(__i386__)
  #include "CustomMathX86.h"
#elif __aarch64__
  #include "CustomMathARM.h"
#elif __arm__
  #include "CustomMathARM.h"
#else
  #include "CustomMathGeneric.h"
#endif

#endif