
#include "GenerateMeasurements.hpp"

namespace codegeneration
{

std::string BuildSorterName(Sorter sorter, NetworkType networkType, MeasureType measureType, BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None, Sorter subSorter = Sorter::InsertionSort, int sampleSortSplits = 0, int sampleSortOversample = 0, int sampleSortBlockSize = 0)
{
    std::string result = "";
    switch (sorter)
    {
        case Sorter::InsertionSort:
            result += "I";
            break;
        case Sorter::SortNetwork:
            result += "N";
            break;
        case Sorter::StdSort:
            result += "StdSort ";
            switch (measureType)
            {
                case MeasureType::Complete:
                    result += "-Q ";
                    break;
                case MeasureType::SampleSort:
                    result += "-S000 ";
                    break;
                case MeasureType::Ipso:
                    result += "-4 ";
                    break;
            }
            return result;
        case Sorter::QuicksortCopy:
            result += "QSort   -Q ";
            return result;
        case Sorter::QuicksortCopyMsvc:
            result += "QSortMs -Q ";
            return result;
        case Sorter::SampleSort:
            result += "S+";
            switch (subSorter)
            {
                case Sorter::InsertionSort:
                    result += "I";
                    break;
                case Sorter::SortNetwork:
                    result += "N";
            }
            break;
    }
    result += " ";
    switch (networkType)
    {
        case NetworkType::Best:
            result += "Best";
            break;
        case NetworkType::BoseNelson:
            result += "BoNe";
            break;
        case NetworkType::Batcher:
            result += "Batc";
            break;
        case NetworkType::None:
            result += "    ";
            break;
    }
    switch (boseNelsonNetworkType)
    {
        case BoseNelsonNetworkType::Locality:
            result += "L";
            break;
        case BoseNelsonNetworkType::Parallelism:
            result += "P";
            break;
        case BoseNelsonNetworkType::Parameter:
            result += "M";
            break;
        case BoseNelsonNetworkType::None:
            result += " ";
            break;
    }
    result += " ";
    switch (measureType)
    {
        case MeasureType::Normal:
            result += "-N";
            break;
        case MeasureType::InRow:
            result += "-I";
            break;
        case MeasureType::Complete:
            result += "-Q";
            break;
        case MeasureType::Complete2:
            result += "-c";
            break;
        case MeasureType::SampleSort:
            result += "-S";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
            break;
        case MeasureType::SampleSort2:
            result += "-s";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
            break;
        case MeasureType::Ipso:
            result += "-4";
            break;
    }
    result += " ";
    return result;
}

std::string AddStructName(const std::string sorter, SortableStruct* sortableStruct)
{
    std::string result(sorter);
    result += "K";
    result += sortableStruct->HasReference ? "R" : " ";
    result += " ";

    result += sortableStruct->NameAbbreviation;

    return result;
}

MeasureParams GetParams(std::vector<SortableStruct*>* structs, std::string sortMethod, Sorter sorter, NetworkType networkType, BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None)
{
    MeasureParams result =
    {
        structs, sortMethod, sorter, networkType, boseNelsonNetworkType
    };
    return result;
}

void WriteMeasureRandomLine(
    CodeGenerator* gen,
    const std::vector<SortableStruct*>* structs,
    std::string sorter)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::MeasureRandomGeneration<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\");");
    }
}

void WriteMeasureLine(
    CodeGenerator* gen, 
    const std::vector<SortableStruct*>* structs, 
    std::string measureMethod, 
    std::string sorter,
    std::string sortMethod,
    bool measureRandomGeneration = true)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, "<", sortableStruct->FullName(), ">);");
    }
    if (measureRandomGeneration) 
    {
        WriteMeasureRandomLine(gen, structs, sorter);
    }
}


void WriteCompleteSorterMeasureLine(
    CodeGenerator* gen,
    const std::vector<SortableStruct*>* structs,
    std::string measureMethod,
    std::string sorter,
    std::string sortMethod,
    std::string additionalTemplateParameters,
    std::string baseCaseSortMethod)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        // gen->WriteLine("debug::WriteLine(\"", sorter, "\");"); //DEBUG
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, "<", sortableStruct->FullName(), additionalTemplateParameters, ">, &", baseCaseSortMethod, "<", sortableStruct->FullName(), ">);");
    }
    WriteMeasureRandomLine(gen, structs, sorter);
}

void WriteCompleteSorterWrapperMeasureLine(
    CodeGenerator* gen,
    const std::vector<SortableStruct*>* structs,
    std::string measureMethod,
    std::string sorter,
    std::string sortMethod,
    std::string baseCaseSortMethod)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        // gen->WriteLine("debug::WriteLine(\"", sorter, "\");"); //DEBUG
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, ", &", baseCaseSortMethod, "<", sortableStruct->FullName(), ">);");
    }
    WriteMeasureRandomLine(gen, structs, sorter);
}

void WriteMeasureMethodName(CodeGenerator *gen, std::string measureMethodName, bool isDeclaration = false)
{
    gen->WriteLine("void ", measureMethodName, "(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)", (isDeclaration ? ";" : ""));
}

void WriteMeasureMethod(
    CodeGenerator *gen,
    std::string measureMethodName,
    std::vector<MeasureParams> measureParamsList,
    std::function<void(MeasureParams)> multicallAction,
    std::function<void()> additionalAction = nullptr)
{
    WriteMeasureMethodName(gen, measureMethodName, false);
    gen->WriteBlock([=](){
        Multicall<MeasureParams>(
            multicallAction, 
            measureParamsList);
        if (additionalAction != nullptr)
        {
            additionalAction();
        }
    });
}

std::string GetNetworkId(MeasureParams measureParams)
{
    if (measureParams._NetworkType == NetworkType::Best)
    {
        return "1";
    }
    if (measureParams._NetworkType == NetworkType::BoseNelson)
    {
        if (measureParams._BoseNelsonNetworkType == BoseNelsonNetworkType::Locality)
        {
            return "2";
        }
        if (measureParams._BoseNelsonNetworkType == BoseNelsonNetworkType::Parallelism)
        {
            return "3";
        }
        if (measureParams._BoseNelsonNetworkType == BoseNelsonNetworkType::Parameter)
        {
            return "4";
        }
    }
    if (measureParams._NetworkType == NetworkType::None)
    {
        return "5";
    }
}

void WriteIpsoMethod(CPlusPlusCodeGenerator* ipsoGen, std::string ipsoMeasureName, std::vector<MeasureParams> measureParamsList, std::string opt)
{
    ipsoGen->WriteNamespace("measurement", [=]{
            std::vector<SortableStruct*> sRef = {(*sortableStructs())[0]}; // Def
            // std::vector<SortableStruct*> iRef = {(*sortableStructs())[15]}; // IPS
            std::vector<MeasureParams> ipsoMeasureParamsList = 
            {
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort() && ss->NameAbbreviation.compare("Def") != 0;}), "networks::sortNbosenelson", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Locality)
            };
            //ipsoGen->WriteLine("template <int ssType>");
            std::vector<std::string> opts = {"0", "1"};
            WriteMeasureMethod(
                ipsoGen,
                ipsoMeasureName + opt,
                measureParamsList,
                [=](MeasureParams measureParams) {
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        measureParams.Structs,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::SampleSort, measureParams._NetworkType, MeasureType::Ipso, measureParams._BoseNelsonNetworkType, measureParams._Sorter, 3, 3, 2),
                        "external::IpsoWrapper<" + GetNetworkId(measureParams) + "," + opt + ">",
                        "measurement::BaseCaseSortBlank"
                    );
                },
                [=]{
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::Ipso),
                        "external::IpsoWrapper<0," + opt + ">",
                        "measurement::BaseCaseSortBlank"
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Ipso),
                        "measurement::StdSortWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                }
            );
        }, "");
}

void GenerateMeasurementMethod(
    CPlusPlusCodeGenerator* headerGen, 
    CPlusPlusCodeGenerator* normalGen, 
    CPlusPlusCodeGenerator* inrowGen, 
    CPlusPlusCodeGenerator* completeGen, 
    CPlusPlusCodeGenerator* sampleSortGen,
    CPlusPlusCodeGenerator* ipso0Gen,
    CPlusPlusCodeGenerator* ipso1Gen)
{
    std::vector<MeasureParams> measureParamsList = 
    {
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbest", Sorter::SortNetwork, NetworkType::Best),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelson", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Locality),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelsonparallel", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parallelism),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelsonparameter", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parameter),
        //GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbatcher", Sorter::SortNetwork, NetworkType::Batcher, BoseNelsonNetworkType::Parallelism),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForInsertionSort();}), "insertionsort::InsertionSort", Sorter::InsertionSort, NetworkType::None)
    };
    headerGen->WriteLine(GetAutogeneratedPreamble());
    normalGen->WriteLine(GetAutogeneratedPreamble());
    inrowGen->WriteLine(GetAutogeneratedPreamble());
    completeGen->WriteLine(GetAutogeneratedPreamble());
    sampleSortGen->WriteLine(GetAutogeneratedPreamble());
    ipso0Gen->WriteLine(GetAutogeneratedPreamble());
    ipso1Gen->WriteLine(GetAutogeneratedPreamble());
    
    headerGen->WriteLine("");
    normalGen->WriteLine("");
    inrowGen->WriteLine("");
    completeGen->WriteLine("");
    sampleSortGen->WriteLine("");
    ipso0Gen->WriteLine("");
    ipso1Gen->WriteLine("");

    headerGen->WriteHeaderPragma("MEASUREMENT_GENERATED_H", [=](){
        headerGen->WriteIncludeBrackets("inttypes.h");
        headerGen->WriteIncludeQuotes(
            "Sortable.generated.h",
            "Performancing.h",
            "Measure.h",
            "BestNetworks.generated.h",
            "BoseNelson.generated.h",
            "BoseNelsonParallel.generated.h",
            "BoseNelsonParameter.generated.h",
            "InsertionSort.h",
            "Randomisation.h");
        headerGen->WriteLine("");

        std::string normalMeasureName = "MeasureSorting";
        std::string inrowMeasureName = "MeasureSortingInRow";
        std::string completeMeasureName = "MeasureCompleteSorting";
        std::string sampleSortMeasureName = "MeasureSampleSort";
        std::string ipsoMeasureName = "MeasureIpso";

        headerGen->WriteNamespace("measurement", [=](){
            WriteMeasureMethodName(headerGen, normalMeasureName, true);      
            WriteMeasureMethodName(headerGen, inrowMeasureName, true);      
            WriteMeasureMethodName(headerGen, completeMeasureName, true);      
            WriteMeasureMethodName(headerGen, sampleSortMeasureName, true);          
            WriteMeasureMethodName(headerGen, ipsoMeasureName + "0", true);
            WriteMeasureMethodName(headerGen, ipsoMeasureName + "1", true);
        }, "");
        normalGen->WriteIncludeQuotes("Measurement.generated.h");
        normalGen->WriteNamespace("measurement", [=]{
            WriteMeasureMethod(
                normalGen, 
                normalMeasureName, 
                measureParamsList, 
                [=](MeasureParams measureParams){
                    WriteMeasureLine(
                        normalGen, 
                        measureParams.Structs, 
                        "Measure", 
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::Normal, measureParams._BoseNelsonNetworkType), 
                        measureParams.SortMethod);
                    normalGen->WriteLine("");
                }
            );
        }, "");
        inrowGen->WriteIncludeQuotes("Measurement.generated.h");
        inrowGen->WriteNamespace("measurement", [=]{
            WriteMeasureMethod(
                inrowGen,
                inrowMeasureName,
                measureParamsList,
                [=](MeasureParams measureParams){
                    WriteMeasureLine(
                        inrowGen,
                        measureParams.Structs,
                        "MeasureInRow",
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::InRow, measureParams._BoseNelsonNetworkType),
                        measureParams.SortMethod,
                        false);
                    inrowGen->WriteLine("");
                }
            );
        }, "");
        completeGen->WriteIncludeQuotes(
            "Measurement.generated.h",
            "QuickSort.h",
            "StdSortWrapper.h");
        completeGen->WriteNamespace("measurement", [=]{
            std::vector<SortableStruct*> sRef = {(*sortableStructs())[0]}; // Def
            std::vector<SortableStruct*> bRef = {(*sortableStructs())[5]}; // 4CS
            WriteMeasureMethod(
                completeGen,
                completeMeasureName,
                measureParamsList,
                [=](MeasureParams measureParams) {
                    WriteCompleteSorterMeasureLine(
                        completeGen,
                        measureParams.Structs,
                        "MeasureCompleteSorter",
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::Complete, measureParams._BoseNelsonNetworkType),
                        "quicksort::sort",
                        "",
                        measureParams.SortMethod);
                    completeGen->WriteLine("");
                },
                [=]{
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Complete),
                        "measurement::StdSortWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::QuicksortCopy, NetworkType::None, MeasureType::Complete),
                        "measurement::QuicksortCopyWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                    // WriteCompleteSorterWrapperMeasureLine(
                    //     completeGen,
                    //     &bRef,
                    //     "MeasureCompleteSorter",
                    //     BuildSorterName(Sorter::SampleSort, NetworkType::Best, MeasureType::Complete, BoseNelsonNetworkType::None, Sorter::SortNetwork),
                    //     "measurement::SampleSortWrapper",
                    //     "networks::sortNbest"
                    // );
                }
            );
        }, "");
        sampleSortGen->WriteIncludeQuotes(
            "Measurement.generated.h",
            "SampleSort.generated.h",
            "MeasurementSampleSort.Helper.h",
            "StdSortWrapper.h");
        sampleSortGen->WriteNamespace("measurement", [=]{
            std::vector<MeasureParams> sampleSortMeasureParams = 
            {
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbest", Sorter::SortNetwork, NetworkType::Best),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelson", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Locality),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelsonparallel", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parallelism),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelsonparameter", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parameter),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("PointerOptimized") == 0;}), "insertionsort::InsertionSort", Sorter::InsertionSort, NetworkType::None)
            };
            std::vector<SortableStruct*> sRef = {(*sortableStructs())[0]}; // Def
            std::vector<SortableStruct*> sPOp = {(*sortableStructs())[13]}; // POp
            WriteMeasureMethod(
                sampleSortGen,
                sampleSortMeasureName,
                sampleSortMeasureParams,
                [=](MeasureParams measureParams) {
                    for (int splits = 3; splits <= 3; splits += 1)
                    {
                        std::string splitStr = std::to_string(splits);
                        for (int oversample = 1; oversample * splits <= 16; oversample += 1)
                        {
                            std::string oversampleStr = std::to_string(oversample);
                            for (int blockSize = 1; blockSize <= 5; blockSize += 1)
                            {
                                std::string blockStr = std::to_string(blockSize);
                                std::string sampleSortName = "SampleSort" + splitStr + "Splitters" + oversampleStr + "OversamplingFactor" + blockStr + "BlockSize";
                                WriteCompleteSorterMeasureLine(
                                    sampleSortGen,
                                    measureParams.Structs,
                                    "MeasureSampleSort",
                                    BuildSorterName(
                                        measureParams._Sorter, 
                                        measureParams._NetworkType, 
                                        MeasureType::SampleSort, 
                                        measureParams._BoseNelsonNetworkType,
                                        Sorter::InsertionSort,
                                        splits, oversample, blockSize),
                                    "samplesort::" + sampleSortName,
                                    ", uint64_t",
                                    measureParams.SortMethod);
                                sampleSortGen->WriteLine("");
                            }
                        }
                    }
                },
                [=] {
                    Multicall<MeasureParams>(
                        [=](MeasureParams measureParams){
                            WriteCompleteSorterMeasureLine(
                                sampleSortGen,
                                measureParams.Structs,
                                "MeasureSampleSort",
                                BuildSorterName(
                                    measureParams._Sorter,
                                    measureParams._NetworkType,
                                    MeasureType::SampleSort2,
                                    measureParams._BoseNelsonNetworkType,
                                    Sorter::InsertionSort,
                                    3, 3, 2),
                                "samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize", 
                                ", uint64_t", 
                                measureParams.SortMethod);
                            sampleSortGen->WriteLine("");
                        },
                        measureParamsList
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        sampleSortGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::SampleSort),
                        "measurement::StdSortWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        sampleSortGen,
                        &sPOp,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::SampleSort),
                        "measurement::InsertionSortWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                }
            );
        }, "");
        ipso0Gen->WriteIncludeQuotes(
            "Measurement.generated.h",
            "StdSortWrapper.h",
            "Ipso.h");
        ipso1Gen->WriteIncludeQuotes(
            "Measurement.generated.h",
            "StdSortWrapper.h",
            "Ipso.h");
        WriteIpsoMethod(ipso0Gen, ipsoMeasureName, measureParamsList, "0");
        WriteIpsoMethod(ipso1Gen, ipsoMeasureName, measureParamsList, "1");
    });
}

}