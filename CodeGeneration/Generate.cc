

#include <vector>
#include <iostream>

#include "CodeGeneration.hpp"
#include "nlohmann/json.hpp"
#include "Network.hpp"
#include "GenerateBoseNelson.hpp"
#include "GenerateBatcher.hpp"
#include "WriteNetwork.hpp"
#include "GenerateMeasurements.hpp"
#include "GenerateSortableStructs.hpp"
#include "GenerateStructHelpers.hpp"
#include "GenerateRandomisation.hpp"
#include "GenerateSampleSort.hpp"
#include "GenerateNetworkVerifier.hpp"

#include "GenerateMeasurementLatex.hpp"

#include "BoseNelsonHelper.hpp"

using namespace codegeneration;

void GenerateSortableStructs()
{
    auto sortableStructsGen = 
        new CPlusPlusCodeGenerator("../../Sortable.generated.h");
    WriteSortableStructs(sortableStructsGen);
    delete sortableStructsGen;
}

void GenerateStructHelpers()
{
    auto structHelpersGen = 
        new CPlusPlusCodeGenerator("../../StructHelpers.generated.h");
    WriteStructHelpers(structHelpersGen);
    delete structHelpersGen;
}

void GenerateRandomisation()
{
    auto randomisationHeaderGen = 
        new CPlusPlusCodeGenerator("../../Randomisation.generated.h");
    auto randomisationImplGen =
        new CPlusPlusCodeGenerator("../../Randomisation.generated.cpp");
    WriteRandomisation(randomisationHeaderGen, randomisationImplGen);
    delete randomisationHeaderGen;
    delete randomisationImplGen;
}

void GenerateBoseNelsonNetworkWithArrangement(
    std::string filename, 
    NetworkArrangement arrangement)
{
    std::ofstream filestream;
    filestream.open(filename);
    nlohmann::json boseNelsonNetworks = nlohmann::json::array();
    for (int arraySize = 2; arraySize <= 16; arraySize += 1)
    {
        auto network = GenerateBoseNelsonNetwork(
            arraySize, 
            arrangement);
        boseNelsonNetworks.push_back(
            NetworkToJson(network));
        Dispose(network);
    }
    filestream << std::setw(2) << boseNelsonNetworks << std::endl;
    filestream.flush();
    filestream.close();
}

void GenerateBoseNelsonNetwork_ParameterStyle(std::string filename)
{
    std::ofstream filestream;
    filestream.open(filename);
    std::vector<nlohmann::json> boseNelsonRecursive;
    for (int arraySize = 2; arraySize <= 16; arraySize += 1)
    {
        auto network = GenerateBoseNelsonRecursiveParameterNetwork(arraySize);
        boseNelsonRecursive.push_back(
            RecursiveNetworkToJson(network));
        Dispose(network);
    }
    nlohmann::json boseNelsonResult = nlohmann::json::array();
    for (auto network : boseNelsonRecursive)
    {
        boseNelsonResult.push_back(network);
    }
    filestream << std::setw(2) << boseNelsonResult << std::endl;
    filestream.flush();
    filestream.close();
}

void GenerateBoseNelsonNetworksJson()
{
    GenerateBoseNelsonNetworkWithArrangement(
        "../BoseNelsonNetworks_Locality.json", 
        NetworkArrangement::Locality);
    GenerateBoseNelsonNetworkWithArrangement(
        "../BoseNelsonNetworks_Parallelism.json", 
        NetworkArrangement::Parallelism);
    GenerateBoseNelsonNetwork_ParameterStyle(
        "../BoseNelsonNetworks_ParameterStyle.json");
}

void GenerateBatcherNetworksJson()
{
    std::ofstream filestream;
    filestream.open("../BatcherNetworks.json");
    nlohmann::json batcherNetworks = nlohmann::json::array();
    for (int arraySize = 2; arraySize <= 16; arraySize += 1)
    {
        auto network = GenerateBatcherNetwork(arraySize);
        batcherNetworks.push_back(NetworkToJson(network));
        Dispose(network);
    }
    filestream << std::setw(2) << batcherNetworks << std::endl;
    filestream.flush();
    filestream.close();
}

void GenerateNetworks()
{
    auto boseNelsonLocalityGen = 
        new CPlusPlusCodeGenerator("../../networks/BoseNelson.generated.h");
    WriteNetwork(
        boseNelsonLocalityGen, 
        "BOSENELSON_GENERATED_H", 
        "bosenelson", 
        "../BoseNelsonNetworks_Locality.json");
    delete boseNelsonLocalityGen;

    auto boseNelsonParallelismGen =
        new CPlusPlusCodeGenerator("../../networks/BoseNelsonParallel.generated.h");
    WriteNetwork(
        boseNelsonParallelismGen,
        "BOSENELSON_PARALLEL_GENERATED_H",
        "bosenelsonparallel",
        "../BoseNelsonNetworks_Parallelism.json");
    delete boseNelsonParallelismGen;

    auto batcherNetworkGen =
        new CPlusPlusCodeGenerator("../../networks/Batcher.generated.h");
    WriteNetwork(
        batcherNetworkGen,
        "BATCHER_GENERATED_H",
        "batcher",
        "../BatcherNetworks.json");
    delete batcherNetworkGen;

    auto bestNetworkGen = 
        new CPlusPlusCodeGenerator("../../networks/BestNetworks.generated.h");
    WriteNetwork(
        bestNetworkGen, 
        "BESTNETWORKS_GENERATED_H", 
        "best", 
        "../BestNetworks.json");
    delete bestNetworkGen;
}

void GenerateNetworks_ParameterStyle()
{
    auto gen = 
        new CPlusPlusCodeGenerator("../../networks/BoseNelsonParameter.generated.h");
    WriteNetwork_ParameterStyle(
        gen,
        "BOSENELSON_PARAMETER_GENERATED_H",
        "bosenelsonparameter",
        "../BoseNelsonNetworks_ParameterStyle.json");
    delete gen;
}

void GenerateNetworks_RecursiveStype()
{
    auto gen = 
        new CPlusPlusCodeGenerator("../../networks/BoseNelsonRecursive.generated.h");
    WriteNetwork_RecursiveStyle(
        gen,
        "BOSENELSON_RECURSIVE_GENERATED_H",
        "bosenelsonrecursive",
        "../BoseNelsonNetworks_ParameterStyle.json",
        4);
    delete gen;
}

void GenerateMeasurements()
{
    auto measurementHeaderGen = 
        new CPlusPlusCodeGenerator("../../measurement/Measurement.generated.h");
    auto normalMeasurementGen =
        new CPlusPlusCodeGenerator("../../measurement/MeasurementNormal.generated.cpp");
    auto inrowMeasurementGen =
        new CPlusPlusCodeGenerator("../../measurement/MeasurementInRow.generated.cpp");
    auto completeMeasurementGen =
        new CPlusPlusCodeGenerator("../../measurement/MeasurementComplete.generated.cpp");
    auto sampleSortMeasurementGen =
        new CPlusPlusCodeGenerator("../../measurement/MeasurementSampleSort.generated.cpp");
    GenerateMeasurementMethod(
        measurementHeaderGen, 
        normalMeasurementGen, 
        inrowMeasurementGen, 
        completeMeasurementGen, 
        sampleSortMeasurementGen);
    delete measurementHeaderGen;
    delete normalMeasurementGen;
    delete inrowMeasurementGen;
    delete completeMeasurementGen;
    delete sampleSortMeasurementGen;
}

void GenerateSampleSort()
{
    auto sampleSortGen = 
        new CPlusPlusCodeGenerator("../../sorters/SampleSort.generated.h");
    sampleSortGen->WriteLine(GetAutogeneratedPreamble());
    sampleSortGen->WriteHeaderPragma("SAMPLESORT_GENERATED_H", [=]{
        sampleSortGen->WriteIncludeBrackets(
            "cstring", 
            "inttypes.h");
        sampleSortGen->WriteLine("");
        sampleSortGen->WriteIncludeQuotes(
            "InsertionSort.h",
            "../DebugHelper.h",
            "../custommath/CustomMath.h");
        sampleSortGen->WriteNamespace("samplesort", [=]{
            for (int splits = 3; splits <= 3; splits += 1)
            {
                for (int oversample = 1; oversample * splits <= 16; oversample += 1)
                {
                    WriteFindSplitters(sampleSortGen, splits, oversample);
                    for (int blockSize = 1; blockSize <= 5; blockSize += 1)
                    {
                        WriteRegisterSampleSort(sampleSortGen, splits, oversample, blockSize);
                    }
                }
            }
        }, "");
    });
    
    delete sampleSortGen;
}

void GenerateNetworkVerifier()
{
    auto verifierGen = new CPlusPlusCodeGenerator("../../VerifyNetworks.generated.h");
    WriteNetworkVerification(verifierGen);
    delete verifierGen;
}

void GenerateMeasurementLatex()
{
    auto latexGen = new LatexCodeGenerator("../../result/combined/measurements.tex");
    GenerateCombinedLatex(latexGen);
    delete latexGen;
}

int main()
{
    GenerateSortableStructs();
    GenerateStructHelpers();
    GenerateRandomisation();
    GenerateBoseNelsonNetworksJson();
    GenerateBatcherNetworksJson();
    GenerateNetworks_ParameterStyle();
    GenerateNetworks_RecursiveStype();
    GenerateNetworks();
    GenerateMeasurements();
    GenerateSampleSort();

    GenerateNetworkVerifier();

    GenerateMeasurementLatex();
}