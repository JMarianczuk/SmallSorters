
#ifndef GENERATE_BOSENELSON_H
#define GENERATE_BOSENELSON_H

#include <iostream>
#include <vector>
#include "Network.h"
#include "VectorHelpers.h"

namespace codegeneration
{

std::vector<ConditionalSwap>* BoseNelsonMerge(int leftStart, int leftLength, int rightStart, int rightLength)
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

        VectorConcatenate<ConditionalSwap>(
            result, 
            BoseNelsonMerge(leftStart, leftMiddle, rightStart, rightMiddle),
            BoseNelsonMerge(leftStart + leftMiddle, leftLength - leftMiddle, rightStart + rightMiddle, rightLength - rightMiddle),
            BoseNelsonMerge(leftStart + leftMiddle, leftLength - leftMiddle, rightStart, rightMiddle));
    }
    return result;
}

std::vector<ConditionalSwap>* BoseNelsonSplit(int start, int length)
{
    auto result = new std::vector<ConditionalSwap>();
    if (length >= 2)
    {
        int middle = length / 2;
        VectorConcatenate<ConditionalSwap>(
            result, 
            BoseNelsonSplit(start, middle), 
            BoseNelsonSplit(start + middle, length - middle), 
            BoseNelsonMerge(start, middle, start + middle, length - middle));
    }
    return result;
}

Network GenerateBoseNelsonNetwork(int arraySize)
{
    Network network;
    network.NetworkSize = arraySize;
    network.Swaps = BoseNelsonSplit(0, arraySize);
    return network;
}

}

#endif