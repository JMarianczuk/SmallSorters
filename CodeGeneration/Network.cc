
#include "Network.hpp"

namespace codegeneration
{

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

template <typename ValueType>
void ArrayWrite(ValueType* arr, int arrSize, ValueType value)
{
    for (int i = 0; i < arrSize; i += 1)
    {
        arr[i] = value;
    }
}

void GetLevels(
    std::vector<std::vector<ConditionalSwap>*>& levels, 
    std::vector<ConditionalSwap>* source, 
    int maxNetworkIndex)
{
    bool *indexTaken = (bool*) malloc(sizeof(bool) * (maxNetworkIndex + 1));
    ArrayWrite(indexTaken, maxNetworkIndex + 1, false);
    int currentLevel = 0;
    levels.push_back(new std::vector<ConditionalSwap>());
    for (ConditionalSwap cs : *source)
    {
        if (indexTaken[cs.LeftIndex] || indexTaken[cs.RightIndex])
        {
            levels.push_back(new std::vector<ConditionalSwap>());
            currentLevel += 1;
            ArrayWrite(indexTaken, maxNetworkIndex + 1, false);
        }
        levels[currentLevel]->push_back(cs);
        indexTaken[cs.LeftIndex] = indexTaken[cs.RightIndex] = true;
    }
    free(indexTaken);
}

std::vector<ConditionalSwap>* MergeNetworksForParallelism(
    std::vector<ConditionalSwap>* left, 
    std::vector<ConditionalSwap>* right, 
    int maxNetworkIndex)
{
    if (left->size() == 0)
    {
        delete left;
        return right;
    }
    if (right->size() == 0)
    {
        delete right;
        return left;
    }
    //assertion: The swaps from left are completely independent from the swaps from right
    //but within left and right the order has to be kept in case of data dependencies
    std::vector<std::vector<ConditionalSwap>*> leftLevels;
    std::vector<std::vector<ConditionalSwap>*> rightLevels;
    
    GetLevels(leftLevels, left, maxNetworkIndex);
    GetLevels(rightLevels, right, maxNetworkIndex);

    int minLength = std::min(leftLevels.size(), rightLevels.size());

    auto result = new std::vector<ConditionalSwap>();
    for (int i = 0; i < minLength; i += 1)
    {
        for (ConditionalSwap cs : *leftLevels[i])
        {
            result->push_back(cs);
        }
        for (ConditionalSwap cs : *rightLevels[i])
        {
            result->push_back(cs);
        }
    }
    for (int i = minLength; i < leftLevels.size(); i += 1)
    {
        for (ConditionalSwap cs : *leftLevels[i])
        {
            result->push_back(cs);
        }
    }
    for (int i = minLength; i < rightLevels.size(); i += 1)
    {
        for (ConditionalSwap cs : *rightLevels[i])
        {
            result->push_back(cs);
        }
    }
    delete left;
    delete right;
    for (auto level : leftLevels)
    {
        delete level;
    }
    for (auto level : rightLevels)
    {
        delete level;
    }
    return result;
}

void Dispose(Network network)
{
    delete network.Swaps;
}

}