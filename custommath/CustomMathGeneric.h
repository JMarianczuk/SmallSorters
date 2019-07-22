
#ifndef CUSTOM_MATH_GENERIC_H
#define CUSTOM_MATH_GENERIC_H

#include <math.h>

namespace custommath
{

static int intlog2(const int x)
{
    return (int) log2(x);
}
static int64_t longlog2(const int64_t x)
{
    return (int64_t) log2(x);
}

}

#endif