
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <iostream>

#include "nlohmann/json.hpp"

namespace codegeneration
{

struct ConditionalSwap
{
    int LeftIndex, RightIndex;
};

struct Network 
{
    int NetworkSize;
    std::vector<ConditionalSwap> *Swaps;
};

ConditionalSwap GetSwap(int leftIndex, int rightIndex)
{
    ConditionalSwap swap = {leftIndex, rightIndex};
    return swap;
}

nlohmann::json SwapToJson(const ConditionalSwap swap)
{
    nlohmann::json swapJson;
    swapJson["LeftIndex"] = swap.LeftIndex;
    swapJson["RightIndex"] = swap.RightIndex;
    return swapJson;
}

nlohmann::json NetworkToJson(const Network network)
{
    nlohmann::json networkJson;
    networkJson["NetworkSize"] = network.NetworkSize;
    nlohmann::json swaps;
    for (auto it = network.Swaps->begin(); it != network.Swaps->end(); it++)
    {
        swaps.push_back(SwapToJson(*it));
    }
    networkJson["Swaps"] = swaps;
    return networkJson;
}

}

#endif