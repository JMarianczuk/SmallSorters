
#ifndef IPSO_H
#define IPSO_H

#include "include/ips4o.hpp"
#include "SampleSort.generated.h"
#include "QuickSort.h"

namespace external
{

template <int BaseCaseType, int SampleSortType, int BaseCaseSize, typename ValueType>
void IpsoWrapper(
    ValueType* first, 
    ValueType* last, 
    bool(*compareFunc)(ValueType left, ValueType right), 
    void(*sortFunc)(ValueType*,size_t))
{
    if constexpr (BaseCaseType == 10)
    {
        ips4o::sort<ips4o::Config<0, 0, true, 32, 8>>(first, last);
    }
    else if constexpr (BaseCaseType == 20)
    {
        ips4o::sort<ips4o::Config<0, 0>>(first, last);
    }
    else if constexpr (BaseCaseType == 30)
    {
        ips4o::sort<ips4o::Config<2, 3>>(first, last);
    }
    else
    {
        ips4o::sort<ips4o::Config<BaseCaseType, SampleSortType, true, BaseCaseSize, 256 / BaseCaseSize>>(first, last);
    }
}

} // namespace external

#endif