
#ifndef IPSO_H
#define IPSO_H

#include "include/ips4o.hpp"
#include "SampleSort.generated.h"
#include "QuickSort.h"

namespace external
{

template <int BaseCaseType, int SampleSortType, typename TValueType>
void IpsoWrapper(
    TValueType* first, 
    TValueType* last, 
    bool(*compareFunc)(TValueType left, TValueType right), 
    void(*sortFunc)(TValueType*,size_t))
{
    ips4o::sort<ips4o::Config<BaseCaseType, SampleSortType>>(first, last);
}

} // namespace external

#endif