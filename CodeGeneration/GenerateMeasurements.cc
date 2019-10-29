
#include "GenerateMeasurements.hpp"
#include "GenerateMeasurementHelpers.hpp"

#include "../Enumerations.h"

namespace codegeneration
{

void Dispose(std::vector<MeasureParams>& measureParamsList)
{
    for (auto measureParams : measureParamsList)
    {
        delete measureParams.Structs;
    }
}

MeasureParams GetParams(std::vector<SortableStruct*>* structs, std::string sortMethodPointer, std::string staticSortMethod, Sorter sorter, NetworkType networkType, BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None)
{
    MeasureParams result =
    {
        structs, sortMethodPointer, staticSortMethod, sorter, networkType, boseNelsonNetworkType
    };
    return result;
}

void WriteMeasureRandomLine(
    CodeGenerator* gen,
    const std::vector<SortableStruct*>* structs,
    std::string sorter,
    bool insertCSName = true)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine(
            "measurement::MeasureRandomGeneration<", 
            sortableStruct->FullName(), 
            ", RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, \"", 
            insertCSName ? AddStructName(sorter, sortableStruct) : sorter, 
            "\");"
        );
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
        std::string measureMethodTemplateParameters = "<" + sortableStruct->FullName() + ", RandomisationMode::DEFAULT>";
        std::string sortMethodTemplateParameters = "<" + sortableStruct->CSName() + ", " + sortableStruct->FullName() + ">";

        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine(
            "measurement::", 
            measureMethod, 
            measureMethodTemplateParameters,
            "(perf, numberOfIterations, arraySize, measureIteration, \"", 
            AddStructName(sorter, sortableStruct), 
            "\", &", 
            sortMethod, 
            sortMethodTemplateParameters,
            ");"
        );
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
        std::string measureMethodTemplateParameters = "<" + sortableStruct->FullName() + ", RandomisationMode::DEFAULT>";
        std::string sortMethodTemplateParameters = "<" + baseCaseSortMethod + "<" + sortableStruct->CSName() + ">, " + sortableStruct->FullName() + ">";

        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine(
            "measurement::", 
            measureMethod, 
            measureMethodTemplateParameters,
            "(perf, numberOfIterations, arraySize, measureIteration, \"", 
            AddStructName(sorter, sortableStruct), 
            "\", &", 
            sortMethod, 
            sortMethodTemplateParameters,
            ");"
        );
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
        std::string measureMethodTemplateParameters = "<" + sortableStruct->FullName() + ", RandomisationMode::DEFAULT>";
        std::string sortMethodTemplateParameters = "<" + baseCaseSortMethod + "<" + sortableStruct->CSName() + ">, SortableRefKeyGetter, " + sortableStruct->FullName() + additionalTemplateParameters + ">";

        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine(
            "measurement::", 
            measureMethod, 
            measureMethodTemplateParameters, 
            "(perf, numberOfIterations, arraySize, measureIteration, \"", 
            AddStructName(sorter, sortableStruct), 
            "\", &", 
            sortMethod, 
            sortMethodTemplateParameters,
            ");"
        );
    }
    WriteMeasureRandomLine(gen, structs, sorter);
}

void WriteCompleteSorterWrapperMeasureLine(
    CodeGenerator* gen,
    const std::vector<SortableStruct*>* structs,
    std::string measureMethod,
    std::string sorter,
    std::string sortMethod,
    std::string baseCaseSortMethod = "",
    bool insertCSName = true)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        std::string measureMethodTemplateParameters = "<" + sortableStruct->FullName() + ", RandomisationMode::DEFAULT>";

        gen->WriteLine("randomisation::SetSeed(seed);");
        gen->WriteLine(
            "measurement::",
            measureMethod, 
            measureMethodTemplateParameters,
            "(perf, numberOfIterations, arraySize, measureIteration, \"", 
            insertCSName ? AddStructName(sorter, sortableStruct) : sorter, 
            "\", &", 
            sortMethod, 
            ");"
        );
    }
    WriteMeasureRandomLine(gen, structs, sorter, insertCSName);
}

void WriteMeasureMethodName(CodeGenerator *gen, std::string measureMethodName, bool isDeclaration = false)
{
    gen->WriteLine(
        "void ", 
        measureMethodName, 
        "(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)", 
        (isDeclaration ? ";" : "")
    );
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
        Multicall<MeasureParams>(multicallAction, measureParamsList);
        if (additionalAction != nullptr)
        {
            additionalAction();
        }
    });
}

IpsoBaseCaseType GetIpsoBaseCaseType(MeasureParams measureParams)
{
    if (measureParams._NetworkType == NetworkType::Best)
    {
        return IpsoBaseCaseType::BEST_NETWORKS;
    }
    if (measureParams._NetworkType == NetworkType::BoseNelson)
    {
        switch (measureParams._BoseNelsonNetworkType)
        {
            case BoseNelsonNetworkType::Locality:
                return IpsoBaseCaseType::BOSE_NELSON_NETWORKS;
            case BoseNelsonNetworkType::Parallelism:
                return IpsoBaseCaseType::BOSE_NELSON_PARALLEL;
            case BoseNelsonNetworkType::Recursive:
                return IpsoBaseCaseType::BOSE_NELSON_RECURSIVE;
            case BoseNelsonNetworkType::Constexpr:
                return IpsoBaseCaseType::BOSE_NELSON_UNROLLED;
        }
    }
    if (measureParams._NetworkType == NetworkType::None)
    {
        throw std::logic_error("Wrong network type");
    }
}

std::string BaseCaseTypeToString(IpsoBaseCaseType bcType)
{
    std::string result = "IpsoBaseCaseType::";
    switch (bcType)
    {
        case IpsoBaseCaseType::BEST_NETWORKS:
            result += "BEST_NETWORKS";
            break;
        case IpsoBaseCaseType::BOSE_NELSON_NETWORKS:
            result += "BOSE_NELSON_NETWORKS";
            break;
        case IpsoBaseCaseType::BOSE_NELSON_PARALLEL:
            result += "BOSE_NELSON_PARALLEL";
            break;
        case IpsoBaseCaseType::BOSE_NELSON_RECURSIVE:
            result += "BOSE_NELSON_RECURSIVE";
            break;
        case IpsoBaseCaseType::BOSE_NELSON_UNROLLED:
            result += "BOSE_NELSON_UNROLLED";
            break;
        case IpsoBaseCaseType::CUSTOM_INSERTION_SORT:
            result += "CUSTOM_INSERTION_SORT";
            break;
        case IpsoBaseCaseType::INSERTION_SORT:
            result += "INSERTION_SORT";
            break;
        default:
            throw std::logic_error("Missing ipso base case type");
    }
    return result;
}
std::string SampleSortTypeToString(IpsoSampleSortType ssType)
{
    std::string result = "IpsoSampleSortType::";
    switch (ssType)
    {
        case IpsoSampleSortType::INSERTION_SORT_NETWORK_HYBRID:
            result += "INSERTION_SORT_NETWORK_HYBRID";
            break;
        case IpsoSampleSortType::NONE:
            result += "NONE";
            break;
        case IpsoSampleSortType::SAMPLE_SORT_331:
            result += "SAMPLE_SORT_331";
            break;
        case IpsoSampleSortType::SAMPLE_SORT_332:
            result += "SAMPLE_SORT_332";
            break;
        default:
            throw std::logic_error("missing ipso sample sort type");
    }
    return result;
}

std::string BuildIpsoWrapperName(IpsoBaseCaseType bcType, IpsoSampleSortType ssType, int baseCaseSize)
{
    return "external::IpsoWrapper<" + BaseCaseTypeToString(bcType) + ", " + SampleSortTypeToString(ssType) + ", " + std::to_string(baseCaseSize) + ">";
}

int BlockSizeFromSampleSortType(IpsoSampleSortType ssType)
{
    switch (ssType)
    {
        case IpsoSampleSortType::SAMPLE_SORT_331:
            return 1;
        case IpsoSampleSortType::SAMPLE_SORT_332:
            return 2;
        default:
            throw std::logic_error("Not applicable");
    }
}

std::string GetNetworkDisplayName(MeasureParams mp)
{
    return BuildNetworkName(mp._NetworkType, mp._BoseNelsonNetworkType, true);
}

std::string GetSampleSortDisplayName(IpsoSampleSortType ssType)
{
    switch (ssType)
    {
        case IpsoSampleSortType::SAMPLE_SORT_331:
            return "331";
        case IpsoSampleSortType::SAMPLE_SORT_332:
            return "332";
        default:
            throw std::logic_error("Not applicable");
    }
}

void WriteIndividualIpsoMethod(
    std::string filename, 
    std::string ipsoMeasureName, 
    std::vector<MeasureParams> mpList, 
    std::string opt, 
    int baseCaseSize,
    bool extraAction = false, 
    bool stdSort = false, 
    IpsoBaseCaseType bcType = IpsoBaseCaseType::INSERTION_SORT, 
    IpsoSampleSortType ssType = IpsoSampleSortType::NONE)
{
    std::vector<SortableStruct*> sRef = {IfSwapSortable()}; // ISwp
    auto ipsoGen = new CPlusPlusCodeGenerator(filename);
    ipsoGen->WriteLine(GetAutogeneratedPreamble());
    ipsoGen->WriteLine("");

    ipsoGen->WriteIncludeBrackets(
        "inttypes.h");
    ipsoGen->WriteIncludeQuotes(
        "../Measure.h",
        "../../Enumerations.h",
        "../../environment/Performancing.h",
        "../../sorters/StdSortWrapper.h",
        "../../sorters/Ipso.h");
    ipsoGen->WriteNamespace("measurement", [=]{
        std::vector<SortableStruct*> sRef = {IfSwapSortable()}; // ISwp
        std::vector<SortableStruct*> csRef = {FourCSSortable()}; // 4CmS
        WriteMeasureMethod(
            ipsoGen,
            ipsoMeasureName,
            mpList,
            [=](MeasureParams measureParams) {
                WriteCompleteSorterWrapperMeasureLine(
                    ipsoGen,
                    measureParams.Structs,
                    "MeasureCompleteSorter",
                    BuildSorterName(Sorter::SampleSort, measureParams._NetworkType, MeasureType::Ipso, measureParams._BoseNelsonNetworkType, measureParams._Sorter, 3, 3, BlockSizeFromSampleSortType(ssType), baseCaseSize),
                    "external::IpsoWrapper<" + opt + ">"
                );
            },
            [=] {
                if (extraAction)
                {
                    if (stdSort)
                    {
                        WriteCompleteSorterWrapperMeasureLine(
                            ipsoGen,
                            &sRef,
                            "MeasureCompleteSorter",
                            BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Ipso),
                            "measurement::StdSortWrapper",
                            "",
                            false
                        );
                    }
                    else 
                    {
                        WriteCompleteSorterWrapperMeasureLine(
                            ipsoGen,
                            ssType == IpsoSampleSortType::INSERTION_SORT_NETWORK_HYBRID ? &csRef : &sRef,
                            "MeasureCompleteSorter",
                            BuildSorterName(
                                Sorter::InsertionSort, 
                                NetworkType::None, 
                                MeasureType::Ipso, 
                                BoseNelsonNetworkType::None, 
                                Sorter::InsertionSort, 
                                0, 0, 0, 
                                baseCaseSize, 
                                ssType == IpsoSampleSortType::INSERTION_SORT_NETWORK_HYBRID,
                                bcType),
                            BuildIpsoWrapperName(bcType, ssType, baseCaseSize)
                        );
                    }
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
        "../sorters/StaticSorters.h",
        "../conditional_swap/ConditionalSwap.h",
        "../sorters/InsertionSort.h"
    );
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
            "static_sorters::BestNetworks", 
            Sorter::SortNetwork, 
            NetworkType::Best),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
            "networks::bosenelson::sortN",
            "static_sorters::BoseNelsonNetworks", 
            Sorter::SortNetwork, 
            NetworkType::BoseNelson, 
            BoseNelsonNetworkType::Locality),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
            "networks::bosenelsonparallel::sortN",
            "static_sorters::BoseNelsonParallelNetworks", 
            Sorter::SortNetwork, 
            NetworkType::BoseNelson, 
            BoseNelsonNetworkType::Parallelism),
        // GetParams(
        //     VectorWhere<SortableStruct*>(
        //         sortableStructs(), 
        //         [](SortableStruct* ss){return ss->UseForNetworkSort();}), 
        //     "networks::bosenelsonparameter::sortN", 
        //     "static_sorters::BoseNelsonParameter",
        //     Sorter::SortNetwork, 
        //     NetworkType::BoseNelson, 
        //     BoseNelsonNetworkType::Parameter),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(), 
                [](SortableStruct* ss){return ss->UseForInsertionSort();}),
            "insertionsort::InsertionSort",
            "static_sorters::InsertionSort", 
            Sorter::InsertionSort, 
            NetworkType::None),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(),
                [](SortableStruct* ss){return ss->UseForNetworkSort();}),
            "networks::bosenelsonrecursive::sortN",
            "static_sorters::BoseNelsonRecursiveNetworks", 
            Sorter::SortNetwork,
            NetworkType::BoseNelson,
            BoseNelsonNetworkType::Recursive),
        GetParams(
            VectorWhere<SortableStruct*>(
                sortableStructs(),
                [](SortableStruct* ss){return ss->UseForNetworkSort();}),
            "networks::bosenelson_2::sortN",
            "static_sorters::BoseNelsonUnrolledNetworks", 
            Sorter::SortNetwork,
            NetworkType::BoseNelson,
            BoseNelsonNetworkType::Constexpr)
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
            for (std::string type : {"_Def16", "_Def32", "_Hybrid_Best", "_Hybrid_BN_R", "_Std"})
            {
                WriteMeasureMethodName(headerGen, ipsoMeasureName + type, true);
            }
            for (std::string samplesort : {"331", "332"})
            {
                for (std::string basecase : {"Best", "BN_L", "BN_R"})
                {
                    for (std::string bcSize : {"16", "32", "64"})
                    {
                        std::string measureMethodName = ipsoMeasureName + "_" + basecase + "_" + samplesort + "_" + bcSize;
                        WriteMeasureMethodName(headerGen, measureMethodName, true);
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
                        measureParams.SortMethodPointer);
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
                        measureParams.SortMethodPointer,
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
            std::vector<SortableStruct*> sRef = {IfSwapSortable()}; // ISwp
            std::vector<SortableStruct*> bRef = {FourCSSortable()}; // 4CmS
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
                        measureParams.StaticSortMethod);
                    completeGen->WriteLine("");
                },
                [=]{
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Complete),
                        "measurement::StdSortWrapper",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::QuicksortCopy, NetworkType::None, MeasureType::Complete),
                        "measurement::QuicksortCopyWrapper",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::RadixSortThrill, NetworkType::BoseNelson, MeasureType::Complete, BoseNelsonNetworkType::Locality, Sorter::SampleSort, 3, 3, 2),
                        "measurement::RadixSortThrillWrapper<static_sorters::SampleSort>",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::RadixSortThrill, NetworkType::None, MeasureType::Complete, BoseNelsonNetworkType::None, Sorter::StdSort),
                        "measurement::RadixSortThrillWrapper<static_sorters::StdSort>",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::RadixSortThrill, NetworkType::None, MeasureType::Complete, BoseNelsonNetworkType::None, Sorter::StdSort),
                        "measurement::RadixSortThrillWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::SkaSort, NetworkType::BoseNelson, MeasureType::Complete, BoseNelsonNetworkType::Locality, Sorter::SampleSort, 3, 3, 2),
                        "measurement::SkaSortWrapper<static_sorters::SampleSort>",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::SkaSort, NetworkType::None, MeasureType::Complete, BoseNelsonNetworkType::None, Sorter::StdSort),
                        "measurement::SkaSortWrapper<static_sorters::StdSort>",
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        completeGen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::SkaSort, NetworkType::None, MeasureType::Complete, BoseNelsonNetworkType::None, Sorter::StdSort),
                        "measurement::SkaSortWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>",
                        "",
                        false
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
                    "static_sorters::BestNetworks", 
                    Sorter::SortNetwork, 
                    NetworkType::Best),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                    "networks::bosenelson::sortN",
                    "static_sorters::BoseNelsonNetworks", 
                    Sorter::SortNetwork, 
                    NetworkType::BoseNelson, 
                    BoseNelsonNetworkType::Locality),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                    "networks::bosenelsonparallel::sortN",
                    "static_sorters::BoseNelsonParallelNetworks", 
                    Sorter::SortNetwork, 
                    NetworkType::BoseNelson, 
                    BoseNelsonNetworkType::Parallelism),
                // GetParams(
                //     VectorWhere<SortableStruct*>(
                //         sortableStructs(), 
                //         [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), 
                //     "networks::bosenelsonparameter::sortN", 
                //     "static_sorters::BoseNelsonParameter",
                //     Sorter::SortNetwork, 
                //     NetworkType::BoseNelson, 
                //     BoseNelsonNetworkType::Parameter),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(), 
                        [](SortableStruct* ss){return ss->Name.compare("PointerOptimized") == 0;}), 
                    "insertionsort::InsertionSort",
                    "static_sorters::InsertionSort", 
                    Sorter::InsertionSort, 
                    NetworkType::None),
                GetParams(
                    VectorWhere<SortableStruct*>(
                        sortableStructs(),
                        [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}),
                    "networks::bosenelsonrecursive::sortN",
                    "static_sorters::BoseNelsonRecursiveNetworks",
                    Sorter::SortNetwork,
                    NetworkType::BoseNelson,
                    BoseNelsonNetworkType::Recursive)
            };
            std::vector<SortableStruct*> sRef = {IfSwapSortable()}; // ISwp
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
                                    measureParams.StaticSortMethod);
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
                                measureParams.StaticSortMethod);
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
                        "",
                        false
                    );
                    WriteCompleteSorterWrapperMeasureLine(
                        sampleSortGen,
                        &sPOp,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::InsertionSort, NetworkType::None, MeasureType::SampleSort),
                        "measurement::InsertionSortWrapper"
                    );
                }
            );

            Dispose(sampleSortMeasureParams);
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
                "static_sort::BestNetworks",
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
                "static_sort::BoseNelsonNetworks",
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
                "static_sort::BoseNelsonRecursiveNetworks", 
                "networks::bosenelsonrecursive::sortN", 
                Sorter::SortNetwork, 
                NetworkType::BoseNelson, 
                BoseNelsonNetworkType::Recursive)
        };
        for (IpsoSampleSortType samplesort : {IpsoSampleSortType::SAMPLE_SORT_331, IpsoSampleSortType::SAMPLE_SORT_332})
        {
            for (auto mp : ipsoMeasureParamsList)
            {
                for (int bcSize : {16, 32, 64})
                {
                    std::string bcSizeStr = std::to_string(bcSize);
                    auto bcType = GetIpsoBaseCaseType(mp);
                    std::string opt = BaseCaseTypeToString(bcType) + "," + SampleSortTypeToString(samplesort) + "," + bcSizeStr;
                    std::string postfix = GetNetworkDisplayName(mp) + "_" + GetSampleSortDisplayName(samplesort) + "_" + bcSizeStr;
                    WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_" + postfix + ".generated.cpp", ipsoMeasureName + "_" + postfix, {mp}, opt, bcSize, false, false, bcType, samplesort);
                }
            }
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_Hybrid_BN_R.generated.cpp", ipsoMeasureName + "_Hybrid_BN_R", {}, "0", 16, true, false, IpsoBaseCaseType::BOSE_NELSON_RECURSIVE, IpsoSampleSortType::INSERTION_SORT_NETWORK_HYBRID);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_Hybrid_Best.generated.cpp", ipsoMeasureName + "_Hybrid_Best", {}, "0", 16, true, false, IpsoBaseCaseType::BEST_NETWORKS, IpsoSampleSortType::INSERTION_SORT_NETWORK_HYBRID);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_Def32.generated.cpp", ipsoMeasureName + "_Def32", {}, "0", 32, true, false, IpsoBaseCaseType::INSERTION_SORT, IpsoSampleSortType::NONE);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_Def16.generated.cpp", ipsoMeasureName + "_Def16", {}, "0", 16, true, false, IpsoBaseCaseType::INSERTION_SORT, IpsoSampleSortType::NONE);
            WriteIndividualIpsoMethod("../../measurement/measurement_ipso/MeasurementIpso_Std.generated.cpp", ipsoMeasureName + "_Std", {}, "0", 0, true, true);
        }

        Dispose(ipsoMeasureParamsList);
    });

    Dispose(measureParamsList);
}

}