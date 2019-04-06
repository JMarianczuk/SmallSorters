
#include "GenerateBatcher.hpp"

#include <vector>

#include "../DebugHelper.h"

namespace codegeneration
{


Network GenerateBatcherNetwork(int arraySize)
{
    int t = (int) std::ceil(std::log2(arraySize));
    int p = 1 << (t - 1);

    auto result = new std::vector<ConditionalSwap>();

    while (true)
    {
        int q = 1 << (t - 1);
        int r = 0;
        int d = p;

        while (true)
        {
            for (int i = 0; i < arraySize - d; i += 1)
            {
                if ((i & p) == r)
                {
                    result->push_back(GetSwap(i, i + d));
                }
            }
            if (q != p)
            {
                d = q - p;
                q = q / 2;
                r = p;
            }
            else
            {
                break;
            }
            
        }

        p = p / 2;
        if (p == 0)
        {
            break;
        }
    }

    Network network;
    network.NetworkSize = arraySize;
    network.Swaps = result;
    return network;
}

}