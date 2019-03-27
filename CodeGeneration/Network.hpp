
#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <iostream>
#include <inttypes.h>

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

void Dispose(Network network);

ConditionalSwap GetSwap(int leftIndex, int rightIndex);
nlohmann::json SwapToJson(const ConditionalSwap swap);
nlohmann::json NetworkToJson(const Network network);
template <typename TValueType>
void ArrayWrite(TValueType* arr, int arrSize, TValueType value);
void GetLevels(
    std::vector<std::vector<ConditionalSwap>*>& levels, 
    std::vector<ConditionalSwap>* source, 
    int maxNetworkIndex);
std::vector<ConditionalSwap>* MergeNetworksForParallelism(
    std::vector<ConditionalSwap>* left, 
    std::vector<ConditionalSwap>* right, 
    int maxNetworkIndex);

}

#endif