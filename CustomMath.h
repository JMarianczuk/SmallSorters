
#ifndef CUSTOM_MATH_H
#define CUSTOM_MATH_H

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
    static long longlog2(const long x)
    {
        long y;
        __asm__(
            "bsrq %[in],%[out]\n\t"
            : [out] "=rm"(y)
            : [in] "rm"(x)
        );
        return y;
    }
}

#endif