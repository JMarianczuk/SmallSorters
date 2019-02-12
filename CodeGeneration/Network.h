
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>

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
    std::vector<ConditionalSwap> Swaps;
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
}

nlohmann::json NetworkToJson(const Network network)
{
    nlohmann::json networkJson;
    networkJson["NetworkSize"] = network.NetworkSize;
    networkJson["Swaps"] = nlohmann::json::array();
    for (ConditionalSwap swap : network.Swaps)
    {
        networkJson["Swaps"].push_back(SwapToJson(swap));
    }
    return networkJson;
}

}

#endif