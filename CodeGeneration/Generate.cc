

#include <vector>

#include "CodeGeneration.h"
#include "nlohmann/json.hpp"
#include "Network.h"
#include "GenerateBoseNelson.h"


using namespace codegeneration;

int main()
{
    auto generator = new CodeGenerator("BoseNelson.generated.h");
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
    generator->WriteJson(boseNelsonResult);
    delete generator;
}