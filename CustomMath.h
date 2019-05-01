
#ifndef CUSTOM_MATH_H
#define CUSTOM_MATH_H

#include <inttypes.h>

namespace custommath
{

static int intlog2(const int x)
{
    int y;
    __asm__(
        "bsr %[in],%[out]\n\t"
        : [out] "=r"(y)
        : [in] "r"(x)
    );
    return y;
}
static int64_t longlog2(const int64_t x)
{
    int64_t y;
    __asm__(
        "bsrq %[in],%[out]\n\t"
        : [out] "=r"(y)
        : [in] "r"(x)
    );
    return y;
}

} // namespace custommath

#endif