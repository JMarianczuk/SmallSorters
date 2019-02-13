

#include <vector>
#include <iostream>

#include "CodeGeneration.h"
#include "nlohmann/json.hpp"
#include "Network.h"
#include "GenerateBoseNelson.h"
#include "WriteNetwork.h"
#include "GenerateMeasurements.h"

using namespace codegeneration;

void GenerateBoseNelsonNetworkJson()
{
    auto boseNelsonJsonGen = new CodeGenerator("../BoseNelsonNetworks.json");
    std::vector<nlohmann::json> boseNelsonNetworks;
    for (int arraySize = 2; arraySize <= 16; arraySize += 1)
    {
        boseNelsonNetworks.push_back(NetworkToJson(GenerateBoseNelsonNetwork(arraySize)));
    }
    nlohmann::json boseNelsonResult = nlohmann::json::array();
    for (auto network : boseNelsonNetworks)
    {
        boseNelsonResult.push_back(network);
    }
    boseNelsonJsonGen->WriteJson(boseNelsonResult);
    delete boseNelsonJsonGen;
}

void GenerateNetworks()
{
    auto boseNelsonGen = new CodeGenerator("../../BoseNelson.generated.h");
    WriteNetwork(boseNelsonGen, "BOSENELSON_GENERATED_H", "bosenelson", "../BoseNelsonNetworks.json");
    delete boseNelsonGen;

    auto bestNetworkGen = new CodeGenerator("../../BestNetworks.generated.h");
    WriteNetwork(bestNetworkGen, "BESTNETWORKS_GENERATED_H", "best", "../BestNetworks.json");
    delete bestNetworkGen;
}

void GenerateMeasurements()
{
    auto measurementGen = new CodeGenerator("../../Measurement.generated.h");
    GenerateMeasurementMethod(measurementGen);
    delete measurementGen;
}

int main()
{
    GenerateBoseNelsonNetworkJson();

    GenerateNetworks();

    GenerateMeasurements();
}