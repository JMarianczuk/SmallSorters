
#ifndef GENERATE_BOSENELSON_H
#define GENERATE_BOSENELSON_H

#include <vector>
#include <iostream>

#include "VectorHelpers.hpp"
#include "Network.hpp"

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

RecursiveParameterNetwork GetRecursiveParameterSplit(int networkSize);
RecursiveParameterNetwork GetRecursiveParameterMerge(int leftMergeSize, int rightMergeSize);
RecursiveParameterNetworkCall GetRecursiveCall(RecursiveParameterNetwork network);
RecursiveParameterNetwork BoseNelsonRecursiveParameterNetworkMerge(int leftLength, int rightLength);
RecursiveParameterNetwork BoseNelsonRecursiveParameterNetworkSplit(int length);
std::vector<ConditionalSwap>* BoseNelsonMerge(
    int leftStart, int leftLength, 
    int rightStart, int rightLength, 
    NetworkArrangement arrangement);
std::vector<ConditionalSwap>* BoseNelsonSplit(
    int start,
    int length, 
    NetworkArrangement arrangement);


Network GenerateBoseNelsonNetwork(int arraySize, NetworkArrangement arrangement);
RecursiveParameterNetwork GenerateBoseNelsonRecursiveParameterNetwork(int arraySize);

}

#endif