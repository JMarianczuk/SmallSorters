
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

enum class ParameterCharacteristic
{
    Array,
    SingleParameters
};

enum class RecursiveParameterNetworkType
{
    Split,
    Merge
};

struct RecursiveParameterNetworkCall;

struct RecursiveParameterNetwork
{
    int NetworkSize;
    int LeftMergeSize;
    int RightMergeSize;
    RecursiveParameterNetworkType Type;
    std::vector<RecursiveParameterNetworkCall>* RecursiveSteps;
};

struct RecursiveParameterNetworkCall
{
    RecursiveParameterNetwork Network;
    std::vector<int>* FirstContextParametersIdsToUse;
    std::vector<int>* SecondContextParametersIdsToUse;
};

RecursiveParameterNetwork GetRecursiveParameterSplit(int networkSize)
{
    RecursiveParameterNetwork network;
    network.NetworkSize = networkSize;
    network.Type = RecursiveParameterNetworkType::Split;
    network.RecursiveSteps = new std::vector<RecursiveParameterNetworkCall>();
    return network;
}

RecursiveParameterNetwork GetRecursiveParameterMerge(int leftMergeSize, int rightMergeSize)
{
    RecursiveParameterNetwork network;
    network.LeftMergeSize = leftMergeSize;
    network.RightMergeSize = rightMergeSize;
    network.Type = RecursiveParameterNetworkType::Merge;
    network.RecursiveSteps = new std::vector<RecursiveParameterNetworkCall>();
    return network;
}

RecursiveParameterNetworkCall GetRecursiveCall(RecursiveParameterNetwork network)
{
    RecursiveParameterNetworkCall call;
    call.Network = network;
    call.FirstContextParametersIdsToUse = new std::vector<int>();
    call.SecondContextParametersIdsToUse = new std::vector<int>();
    return call;
}

RecursiveParameterNetwork BoseNelsonRecursiveParameterNetworkMerge(int leftLength, int rightLength)
{
    auto network = GetRecursiveParameterMerge(leftLength, rightLength);
    if (
        (leftLength == 1 && rightLength == 1) ||
        (leftLength == 1 && rightLength == 2) ||
        (leftLength == 2 && rightLength == 1))
    {
        return network;
    }
    int leftHalfLength = leftLength / 2;
    int rightHalfLength = leftLength % 2 == 1 ? rightLength / 2 : (rightLength + 1) / 2;

    auto firstMerge = BoseNelsonRecursiveParameterNetworkMerge(leftHalfLength, rightHalfLength);
    auto secondMerge = BoseNelsonRecursiveParameterNetworkMerge(leftLength - leftHalfLength, rightLength - rightHalfLength);
    auto thirdMerge = BoseNelsonRecursiveParameterNetworkMerge(leftLength - leftHalfLength, rightHalfLength);
    
    auto firstMergeCall = GetRecursiveCall(firstMerge);
    auto secondMergeCall = GetRecursiveCall(secondMerge);
    auto thirdMergeCall = GetRecursiveCall(thirdMerge);
    for (int i = 0; i < leftHalfLength; i += 1)
    {
        firstMergeCall.FirstContextParametersIdsToUse->push_back(i);
    }
    for (int i = leftHalfLength; i < leftLength; i += 1)
    {
        secondMergeCall.FirstContextParametersIdsToUse->push_back(i);
        thirdMergeCall.FirstContextParametersIdsToUse->push_back(i);
    }
    for (int i = 0; i < rightHalfLength; i += 1)
    {
        firstMergeCall.SecondContextParametersIdsToUse->push_back(i);
        thirdMergeCall.SecondContextParametersIdsToUse->push_back(i);
    }
    for (int i = rightHalfLength; i < rightLength; i += 1)
    {
        secondMergeCall.SecondContextParametersIdsToUse->push_back(i);
    }
    network.RecursiveSteps->push_back(firstMergeCall);
    network.RecursiveSteps->push_back(secondMergeCall);
    network.RecursiveSteps->push_back(thirdMergeCall);
}

RecursiveParameterNetwork BoseNelsonRecursiveParameterNetworkSplit(int length)
{
    auto network = GetRecursiveParameterSplit(length);
    if (length >= 2)
    {
        int halfLength = length / 2;
        auto firstHalf = BoseNelsonRecursiveParameterNetworkSplit(halfLength);
        auto secondHalf = BoseNelsonRecursiveParameterNetworkSplit(length - halfLength);
        auto merge = BoseNelsonRecursiveParameterNetworkMerge(halfLength, length - halfLength);

        auto firstHalfCall = GetRecursiveCall(firstHalf);
        auto secondHalfCall = GetRecursiveCall(secondHalf);
        auto mergeCall = GetRecursiveCall(merge);
        for (int i = 0; i < halfLength; i += 1)
        {
            firstHalfCall.FirstContextParametersIdsToUse->push_back(i);
            mergeCall.FirstContextParametersIdsToUse->push_back(i);
        }
        for (int i = halfLength; i < length; i += 1)
        {
            secondHalfCall.FirstContextParametersIdsToUse->push_back(i);
            mergeCall.SecondContextParametersIdsToUse->push_back(i);
        }
        if (halfLength >= 2)
        {
            network.RecursiveSteps->push_back(firstHalfCall);
        }
        if (length - halfLength >= 2)
        {
            network.RecursiveSteps->push_back(secondHalfCall);
        }
        network.RecursiveSteps->push_back(mergeCall);
    }
    return network;
}

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

RecursiveParameterNetwork GenerateBoseNelsonRecursiveParameterNetwork(int arraySize)
{
    return BoseNelsonRecursiveParameterNetworkSplit(arraySize);
}

}

#endif