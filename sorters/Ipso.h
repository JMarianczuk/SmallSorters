
#ifndef IPSO_H
#define IPSO_H

#include "../include/ips4o.hpp"
#include "../Enumerations.h"
#include "SampleSort.generated.h"
#include "QuickSort.h"

namespace external
{

template <IpsoBaseCaseType BaseCaseType, IpsoSampleSortType SampleSortType, int BaseCaseSize, typename ValueType>
void IpsoWrapper(
    ValueType* first, 
    ValueType* last, 
    bool(*compareFunc)(ValueType left, ValueType right))
{
    ips4o::sort<ips4o::Config<BaseCaseType, SampleSortType, true, BaseCaseSize, 256 / BaseCaseSize>>(first, last);
}

} // namespace external

#endif