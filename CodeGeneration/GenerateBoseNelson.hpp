
#ifndef GENERATE_BOSENELSON_H
#define GENERATE_BOSENELSON_H

#include <iostream>
#include <vector>
#include "Network.hpp"
#include "VectorHelpers.hpp"

namespace codegeneration
{

enum class NetworkArrangement
{
    Locality,
    Parallelism
};

std::vector<ConditionalSwap>* BoseNelsonMerge(
    int leftStart, int leftLength, 
    int rightStart, int rightLength, 
    NetworkArrangement arrangement)
{
    auto result = new std::vector<ConditionalSwap>();

    if (leftLength == 1 && rightLength == 1)
    {
        result->push_back(GetSwap(leftStart, rightStart));
    }
    else if (leftLength == 1 && rightLength == 2)
    {
        result->push_back(GetSwap(leftStart, rightStart + 1));
        result->push_back(GetSwap(leftStart, rightStart));
    }
    else if (leftLength == 2 && rightLength == 1)
    {
        result->push_back(GetSwap(leftStart, rightStart));
        result->push_back(GetSwap(leftStart + 1, rightStart));
    }
    else 
    {
        int leftMiddle = leftLength / 2;
        int rightMiddle = leftLength % 2 == 1 ? rightLength / 2 : (rightLength + 1) / 2;

        auto firstMerge = 
            BoseNelsonMerge(
                leftStart, leftMiddle, 
                rightStart, rightMiddle, 
                arrangement);
        auto secondMerge =
            BoseNelsonMerge(
                leftStart + leftMiddle, leftLength - leftMiddle, 
                rightStart + rightMiddle, rightLength - rightMiddle, 
                arrangement);
        auto thirdMerge =
            BoseNelsonMerge(
                leftStart + leftMiddle, leftLength - leftMiddle, 
                rightStart, rightMiddle, 
                arrangement);
        switch (arrangement)
        {
            case NetworkArrangement::Locality:
                VectorConcatenate(
                    result, 
                    firstMerge, 
                    secondMerge, 
                    thirdMerge);
                break;
            case NetworkArrangement::Parallelism:
                int maxNetworkIndex = 
                    std::max(leftStart + leftLength, rightStart + rightLength);
                VectorConcatenate(
                    result, 
                    MergeNetworksForParallelism(
                        firstMerge, 
                        secondMerge, 
                        maxNetworkIndex), 
                    thirdMerge);
                break;
        }
    }
    return result;
}

std::vector<ConditionalSwap>* BoseNelsonSplit(
    int start,
    int length, 
    NetworkArrangement arrangement)
{
    auto result = new std::vector<ConditionalSwap>();
    if (length >= 2)
    {
        int middle = length / 2;
        auto firstHalf = 
            BoseNelsonSplit(
                start, 
                middle, 
                arrangement);
        auto secondHalf = 
            BoseNelsonSplit(
                start + middle, 
                length - middle, 
                arrangement);
        auto merge =
            BoseNelsonMerge(
                start, middle, 
                start + middle, length - middle, 
                arrangement);
        switch (arrangement)
        {
            case NetworkArrangement::Locality:
                VectorConcatenate(
                    result, 
                    firstHalf, 
                    secondHalf, 
                    merge);
                break;
            case NetworkArrangement::Parallelism:
                VectorConcatenate(
                    result, 
                    MergeNetworksForParallelism(
                        firstHalf, 
                        secondHalf, 
                        start + length), 
                    merge);
                break;
        }
    }
    return result;
}

Network GenerateBoseNelsonNetwork(int arraySize, NetworkArrangement arrangement)
{
    Network network;
    network.NetworkSize = arraySize;
    network.Swaps = BoseNelsonSplit(0, arraySize, arrangement);
    return network;
}

}

#endif