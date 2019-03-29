
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
}

#endif