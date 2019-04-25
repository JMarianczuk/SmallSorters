
#ifndef IPSO_H
#define IPSO_H

#include "include/ips4o.hpp"
#include "SampleSort.generated.h"
#include "QuickSort.h"

namespace external
{
    template <typename TValueType>
    void IpsoWrapper(
        TValueType* first, 
        TValueType* last, 
        bool(*compareFunc)(TValueType left, TValueType right), 
        void(*sortFunc)(TValueType*,size_t))
    {
        ips4o::sort(first, last);
        // , [sortFunc](TValueType* start, TValueType* end){
        //     samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(start, end - start, 16, sortFunc, &quicksort::templateLess<TValueType>, &GetKey<TValueType>);
        // }
    }
}

#endif