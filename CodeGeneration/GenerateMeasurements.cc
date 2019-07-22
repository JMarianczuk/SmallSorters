
#include "GenerateMeasurements.hpp"

namespace codegeneration
{

SortableStruct* DefSortable()
{
    return (*sortableStructs())[0];
}
SortableStruct* FourCSSortable()
{
    return (*sortableStructs())[4];
}
SortableStruct* POpSortable()
{
    return (*sortableStructs())[11];
}

std::string BuildSorterName(Sorter sorter, NetworkType networkType, MeasureType measureType, BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None, Sorter subSorter = Sorter::InsertionSort, int sampleSortSplits = 0, int sampleSortOversample = 0, int sampleSortBlockSize = 0, int ipsoBaseCaseSize = 0, bool isInsertionPlusNetwork = false)
{
    std::string result = "";
    switch (sorter)
    {
        case Sorter::InsertionSort:
            result += "I";
            if (isInsertionPlusNetwork)
            {
                result += " + N";
            }
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
            result += "BN";
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
            result += "Loc";
            break;
        case BoseNelsonNetworkType::Parallelism:
            result += "PL ";
            break;
        case BoseNelsonNetworkType::Parameter:
            result += "PM ";
            break;
        case BoseNelsonNetworkType::Recursive:
            result += "Rec";
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
            result += "-4 " + std::to_string(ipsoBaseCaseSize) + "_";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
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
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, "<", sortableStruct->CSName(), ", ", sortableStruct->FullName(), ">);");
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
    std::string baseCaseSortMethod)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, "<", sortableStruct->FullName(), ">, &", baseCaseSortMethod, "<", sortableStruct->CSName(), ", ", sortableStruct->FullName(), ">);");
    }
    WriteMeasureRandomLine(gen, structs, sorter);
}

void WriteSampleSortMeasureLine(
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
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, "<", sortableStruct->FullName(), additionalTemplateParameters, ">, &", baseCaseSortMethod, "<", sortableStruct->CSName(), ", ", sortableStruct->FullName(), ">);");
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
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine("measurement::", measureMethod, "<", sortableStruct->FullName(), ">(perf, numberOfIterations, arraySize, measureIteration, \"", AddStructName(sorter, sortableStruct), "\", &", sortMethod, ", &", baseCaseSortMethod, "<", sortableStruct->CSName(), ", ", sortableStruct->FullName(), ">);");
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
        switch (measureParams._BoseNelsonNetworkType)
        {
            case BoseNelsonNetworkType::Locality:
                return "2";
            case BoseNelsonNetworkType::Parallelism:
                return "3";
            case BoseNelsonNetworkType::Parameter:
                return "4";
            case BoseNelsonNetworkType::Recursive:
                return "6";
        }
    }
    if (measureParams._NetworkType == NetworkType::None)
    {
        return "5";
    }
}

void WriteIndividualIpsoMethod(std::string filename, std::string ipsoMeasureName, std::vector<MeasureParams> mpList, std::string opt, int baseCaseSize, std::string samplesort, int extraAction = 0)
{
    std::vector<SortableStruct*> sRef = {DefSortable()}; // Def
    auto ipsoGen = new CPlusPlusCodeGenerator(filename);
    ipsoGen->WriteLine(GetAutogeneratedPreamble());
    ipsoGen->WriteLine("");

    ipsoGen->WriteIncludeBrackets(
        "inttypes.h"
    );
    ipsoGen->WriteIncludeQuotes(
        "../Measure.h",
        "../../environment/Performancing.h",
        "../../sorters/StdSortWrapper.h",
        "../../sorters/Ipso.h");
    ipsoGen->WriteNamespace("measurement", [=]{
        std::vector<SortableStruct*> sRef = {DefSortable()}; // Def
        std::vector<SortableStruct*> csRef = {FourCSSortable()}; // 4CS
        WriteMeasureMethod(
            ipsoGen,
            ipsoMeasureName,
            mpList,
            [=](MeasureParams measureParams) {
                WriteCompleteSorterWrapperMeasureLine(
                    ipsoGen,
                    measureParams.Structs,
                    "MeasureCompleteSorter",
                    BuildSorterName(Sorter::SampleSort, measureParams._NetworkType, MeasureType::Ipso, measureParams._BoseNelsonNetworkType, measureParams._Sorter, 3, 3, std::stoi(samplesort), baseCaseSize),
                    "external::IpsoWrapper<" + opt + ">",
                    "measurement::BaseCaseSortBlank"
                );
            },
            [=] {
                if (extraAction == 1)
                {
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &csRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::Ipso, BoseNelsonNetworkType::None, Sorter::InsertionSort, 0, 0, 0, 16, true),
                        "external::IpsoWrapper<30,0,0>",
                        "measurement::BaseCaseSortBlank"
                    );
                } else if (extraAction == 2) {
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::Ipso, BoseNelsonNetworkType::None, Sorter::InsertionSort, 0, 0, 0, 32),
                        "external::IpsoWrapper<10,0,0>",
                        "measurement::BaseCaseSortBlank"
                    );
                } else if (extraAction == 3) {
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::Ipso, BoseNelsonNetworkType::None, Sorter::InsertionSort, 0, 0, 0, 16),
                        "external::IpsoWrapper<20,0,0>",
                        "measurement::BaseCaseSortBlank"
                    );
                } else if (extraAction == 4) {
                    WriteCompleteSorterWrapperMeasureLine(
                        ipsoGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Ipso),
                        "measurement::StdSortWrapper",
                        "measurement::BaseCaseSortBlank"
                    );
                }
            }
        );
    }, "");

    delete ipsoGen;
}

// #if __x86_64__
//   #include "funcs_x86_64.h"
// #elif defined(__i386__)
//   #include "funcs_x86_32.h"
// #elif __aarch64__
//   #include "funcs_arm64.h"
// #elif __arm__
//   #include "funcs_arm.h"
// #else
//   #include "funcs_c.h"
// #endif

void WriteMeasurementIncludes(CPlusPlusCodeGenerator* gen)
{
    gen->WriteIncludeQuotes(
        "Measure.h",
        "../environment/Performancing.h",
        "../Networks_Fwd.h",
        "../conditional_swap/ConditionalSwapGeneric.h",
        "../sorters/InsertionSort.h"
    );
    gen->WriteLine("");
    gen->WriteLine("#if __x86_64__");
    gen->WriteIndented([=]{
        gen->WriteIncludeQuotes("../conditional_swap/ConditionalSwapX86.h");
    });
    gen->WriteLine("#elif defined(__i386__)");
    gen->WriteIndented([=]{
        gen->WriteIncludeQuotes("../conditional_swap/ConditionalSwapX86.h");
    });
    gen->WriteLine("#elif __aarch64__");
    gen->WriteIndented([=]{
        gen->WriteIncludeQuotes("../conditional_swap/ConditionalSwapARM32.h");
    });
    gen->WriteLine("#elif __arm__");
    gen->WriteIndented([=]{
        gen->WriteIncludeQuotes("../conditional_swap/ConditionalSwapARM32.h");
    });
    gen->WriteLine("#else");
    gen->WriteIndented([=]{

    });
    gen->WriteLine("#endif");
    gen->WriteLine("");
}

void GenerateMeasurementMethod(
    CPlusPlusCodeGenerator* headerGen, 
    CPlusPlusCodeGenerator* normalGen, 
    CPlusPlusCodeGenerator* inrowGen, 
    CPlusPlusCodeGenerator* completeGen, 
    CPlusPlusCodeGenerator* sampleSortGen)
{
    std::vector<MeasureParams> measureParamsList = 
    {
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
            "networks::best::sortN", 
            Sorter::SortNetwork, 
            NetworkType::Best),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
            "networks::bosenelson::sortN", 
            Sorter::SortNetwork, 
            NetworkType::BoseNelson, 
            BoseNelsonNetworkType::Locality),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
            "networks::bosenelsonparallel::sortN", 
            Sorter::SortNetwork, 
            NetworkType::BoseNelson, 
            BoseNelsonNetworkType::Parallelism),
        // GetParams(
        //     VectorWhere<SortableStruct*>(
        //         sortableStructs(), 
        //         [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
        //     "networks::bosenelsonparameter::sortN", 
        //     Sorter::SortNetwork, 
        //     NetworkType::BoseNelson, 
        //     BoseNelsonNetworkType::Parameter),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForInsertionSort();}), 
            "insertionsort::InsertionSort", 
            Sorter::InsertionSort, 
            NetworkType::None),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(),
                [](SortableStruct* ss){return ss->UseForNetworkSort();}),
            "networks::bosenelsonrecursive::sortN",
            Sorter::SortNetwork,
            NetworkType::BoseNelson,
            BoseNelsonNetworkType::Recursive)
    };
    headerGen->WriteLine(GetAutogeneratedPreamble());
    normalGen->WriteLine(GetAutogeneratedPreamble());
    inrowGen->WriteLine(GetAutogeneratedPreamble());
    completeGen->WriteLine(GetAutogeneratedPreamble());
    sampleSortGen->WriteLine(GetAutogeneratedPreamble());
    
    headerGen->WriteLine("");
    normalGen->WriteLine("");
    inrowGen->WriteLine("");
    completeGen->WriteLine("");
    sampleSortGen->WriteLine("");

    headerGen->WriteHeaderPragma("MEASUREMENT_GENERATED_H", [=](){
        headerGen->WriteIncludeBrackets("inttypes.h");
        headerGen->WriteIncludeQuotes("../environment/Performancing.h");
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
            for (std::string type : {"1", "2", "3", "4"})
            {
                WriteMeasureMethodName(headerGen, ipsoMeasureName + type, true);
            }
            for (std::string samplesort : {"1", "2"})
            {
                for (std::string basecase : {"1", "2", "6"})
                {
                    for (std::string bcSize : {"16", "32", "64"})
                    {
                        WriteMeasureMethodName(headerGen, ipsoMeasureName + basecase + samplesort + "_" + bcSize, true);
                    }
                }
            }
        }, "");
        WriteMeasurementIncludes(normalGen);
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
        WriteMeasurementIncludes(inrowGen);
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
        WriteMeasurementIncludes(completeGen);
        completeGen->WriteIncludeQuotes(
            "../sorters/QuickSort.h",
            "../sorters/StdSortWrapper.h");
        completeGen->WriteNamespace("measurement", [=]{
            std::vector<SortableStruct*> sRef = {DefSortable()}; // Def
            std::vector<SortableStruct*> bRef = {FourCSSortable()}; // 4CS
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
                }
            );
        }, "");
        WriteMeasurementIncludes(sampleSortGen);
        sampleSortGen->WriteIncludeQuotes(
            "../sorters/SampleSort.generated.h",
            "MeasurementSampleSort.Helper.h",
            "../sorters/StdSortWrapper.h");
        sampleSortGen->WriteNamespace("measurement", [=]{
            std::vector<MeasureParams> sampleSortMeasureParams = 
            {
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                    "networks::best::sortN", 
                    Sorter::SortNetwork, 
                    NetworkType::Best),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                    "networks::bosenelson::sortN", 
                    Sorter::SortNetwork, 
                    NetworkType::BoseNelson, 
                    BoseNelsonNetworkType::Locality),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                    "networks::bosenelsonparallel::sortN", 
                    Sorter::SortNetwork, 
                    NetworkType::BoseNelson, 
                    BoseNelsonNetworkType::Parallelism),
                // GetParams(
                //     VectorWhere<SortableStruct*>(
                //         sortableStructs(), 
                //         [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                //     "networks::bosenelsonparameter::sortN", 
                //     Sorter::SortNetwork, 
                //     NetworkType::BoseNelson, 
                //     BoseNelsonNetworkType::Parameter),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("PointerOptimized") == 0;}), 
                    "insertionsort::InsertionSort", 
                    Sorter::InsertionSort, 
                    NetworkType::None),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(),
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}),
                    "networks::bosenelsonrecursive::sortN",
                    Sorter::SortNetwork,
                    NetworkType::BoseNelson,
                    BoseNelsonNetworkType::Recursive)
            };
            std::vector<SortableStruct*> sRef = {DefSortable()}; // Def
            std::vector<SortableStruct*> sPOp = {POpSortable()}; // POp
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
                                WriteSampleSortMeasureLine(
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
                            WriteSampleSortMeasureLine(
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

        std::vector<MeasureParams> ipsoMeasureParamsList = 
        {
            GetParams(
                VectorWhere<SortableStruct*>(
                    sortableStructs(), 
                    [](SortableStruct* ss){
                        return ss->UseForNetworkSort() 
                            && ss->WillBeShownInResults() 
                            && ss->NameAbbreviation == "4CS";}),
                "networks::best::sortN", 
                Sorter::SortNetwork, 
                NetworkType::Best),
            GetParams(
                VectorWhere<SortableStruct*>(
                    sortableStructs(), 
                    [](SortableStruct* ss){
                        return ss->UseForNetworkSort() 
                            && ss->WillBeShownInResults() 
                            && ss->NameAbbreviation == "4CS";}), 
                "networks::bosenelson::sortN", 
                Sorter::SortNetwork, 
                NetworkType::BoseNelson, 
                BoseNelsonNetworkType::Locality),
            GetParams(
                VectorWhere<SortableStruct*>(
                    sortableStructs(), 
                    [](SortableStruct* ss){
                        return ss->UseForNetworkSort() 
                            && ss->WillBeShownInResults() 
                            && ss->NameAbbreviation == "4CS";}), 
                "networks::bosenelsonrecursive::sortN", 
                Sorter::SortNetwork, 
                NetworkType::BoseNelson, 
                BoseNelsonNetworkType::Recursive)
        };
        for (std::string samplesort : {"1", "2"})
        {
            for (auto mp : ipsoMeasureParamsList)
            {
                for (int bcSize : {16, 32, 64})
                {
                    std::string bcSizeStr = std::to_string(bcSize);
                    std::string opt = GetNetworkId(mp) + "," + samplesort + "," + bcSizeStr;
                    std::string opt2 = GetNetworkId(mp) + samplesort;
                    WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso" + GetNetworkId(mp) + samplesort + "_" + bcSizeStr + ".generated.cpp", ipsoMeasureName + opt2 + "_" + bcSizeStr, {mp}, opt, bcSize, samplesort);
                }
            }
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso1.generated.cpp", ipsoMeasureName + "1", {}, "0", 16, "", 1);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso2.generated.cpp", ipsoMeasureName + "2", {}, "0", 32, "", 2);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso3.generated.cpp", ipsoMeasureName + "3", {}, "0", 16, "", 3);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso4.generated.cpp", ipsoMeasureName + "4", {}, "0", 0, "", 4);
        }
    });
}

}