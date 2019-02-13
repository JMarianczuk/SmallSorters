

#include <vector>
#include <iostream>

#include "CodeGeneration.h"
#include "nlohmann/json.hpp"
#include "Network.h"
#include "GenerateBoseNelson.h"
#include "WriteNetwork.h"
#include "GenerateMeasurements.h"
#include "GenerateSortableStructs.h"
#include "GenerateStructHelpers.h"
#include "GenerateRandomisation.h"

using namespace codegeneration;

void GenerateSortableStructs()
{
    auto sortableStructsGen = new CodeGenerator("../../Sortable.generated.h");
    WriteSortableStructs(sortableStructsGen);
    delete sortableStructsGen;
}

void GenerateStructHelpers()
{
    auto structHelpersGen = new CodeGenerator("../../StructHelpers.generated.h");
    WriteStructHelpers(structHelpersGen);
    delete structHelpersGen;
}

void GenerateRandomisation()
{
    auto randomisationGen = new CodeGenerator("../../Randomisation.generated.h");
    WriteRandomisation(randomisationGen);
    delete randomisationGen;
}

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
    GenerateSortableStructs();
    GenerateStructHelpers();
    GenerateRandomisation();
    GenerateBoseNelsonNetworkJson();
    GenerateNetworks();
    GenerateMeasurements();
}