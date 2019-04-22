
#ifndef IPSO_H
#define IPSO_H

#include "include/ips4o.hpp"

namespace external
{
    template <typename TValueType>
    void IpsoWrapper(
        TValueType* first, 
        TValueType* last, 
        bool(*compareFunc)(TValueType* left, TValueType* right), 
        void(*sortFunc)(TValueType*,size_t))
    {
        ips4o::sort(first, last, compareFunc);
    }
}

#endif