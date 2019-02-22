
#ifndef BOSE_NELSON_HELPER_H
#define BOSE_NELSON_HELPER_H

#include <vector>
#include "GenerateBoseNelson.hpp"
#include "nlohmann/json.hpp"

namespace codegeneration
{



nlohmann::json RecursiveNetworkToJson(RecursiveParameterNetwork network)
{
    nlohmann::json networkJson;
    switch (network.Type)
    {
        case RecursiveParameterNetworkType::Split:
            networkJson["Type"] = "Split";
            networkJson["NetworkSize"] = network.NetworkSize;
            break;
        case RecursiveParameterNetworkType::Merge:
             networkJson["Type"] = "Merge";
             networkJson["LeftMergeSize"] = network.LeftMergeSize;
             networkJson["RightMergeSize"] = network.RightMergeSize;
             break;
        default:
            printf("Missing type!");
    }
    if (network.RecursiveSteps->size() != 0)
    {
        auto steps = nlohmann::json::array();
        for (auto step : *network.RecursiveSteps)
        {
            nlohmann::json stepJson;
            stepJson["Network"] = RecursiveNetworkToJson(step.Network);
            auto firstParameterIds = nlohmann::json::array();
            for (auto parameterId : *step.FirstContextParametersIdsToUse)
            {
                firstParameterIds.push_back(parameterId);
            }
            stepJson["FirstContextParameterIdsToUse"] = firstParameterIds;
            if (step.Network.Type == RecursiveParameterNetworkType::Merge)
            {
                auto secondParameterIds = nlohmann::json::array();
                for (auto parameterId : *step.SecondContextParametersIdsToUse)
                {
                    secondParameterIds.push_back(parameterId);
                }
                stepJson["SecondContextParameterIdsToUse"] = secondParameterIds;
            }
            steps.push_back(stepJson);
        }
        networkJson["RecursiveSteps"] = steps;
    }
    return networkJson;
}

}

#endif