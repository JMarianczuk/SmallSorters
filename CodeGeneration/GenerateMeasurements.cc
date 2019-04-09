
#include "GenerateMeasurements.hpp"

namespace codegeneration
{

std::string BuildSorterName(Sorter sorter, NetworkType networkType, MeasureType measureType, BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None, int sampleSortSplits = 0, int sampleSortOversample = 0, int sampleSortBlockSize = 0)
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
            result += "StdSort -C ";
            return result;
        case Sorter::QuicksortCopy:
            result += "QSort   -C ";
            return result;
        case Sorter::QuicksortCopyMsvc:
            result += "QSortMs -C ";
            return result;
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
            result += "-C";
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

void WriteMeasureMethod(
    CodeGenerator *gen,
    std::string measureMethodName,
    std::vector<MeasureParams> measureParamsList,
    std::function<void(MeasureParams)> multicallAction,
    std::function<void()> additionalAction = nullptr)
{
    gen->WriteLine("void ", measureMethodName, "(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)");
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

void GenerateMeasurementMethod(CPlusPlusCodeGenerator* gen)
{
    std::vector<MeasureParams> measureParamsList = 
    {
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbest", Sorter::SortNetwork, NetworkType::Best),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelson", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Locality),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelsonparallel", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parallelism),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForNetworkSort();}), "networks::sortNbosenelsonparameter", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parameter),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->UseForInsertionSort();}), "insertionsort::InsertionSort", Sorter::InsertionSort, NetworkType::None)
    };
    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteLine("");

    gen->WriteHeaderPragma("MEASUREMENT_GENERATED_H", [=](){
        gen->WriteIncludeBrackets("inttypes.h");
        gen->WriteIncludeQuotes(
            "Sortable.generated.h",
            "Performancing.h",
            "EnvironmentInfo.h",
            "Measure.h",
            "BestNetworks.generated.h",
            "BoseNelson.generated.h",
            "BoseNelsonParallel.generated.h",
            "BoseNelsonParameter.generated.h",
            "InsertionSort.h",
            "QuickSort.h",
            "Randomisation.h");
        gen->WriteLine("");

        gen->WriteNamespace("measurement", [=](){
            WriteMeasureMethod(
                gen, 
                "MeasureSorting", 
                measureParamsList, 
                [=](MeasureParams measureParams){
                    WriteMeasureLine(
                        gen, 
                        measureParams.Structs, 
                        "Measure", 
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::Normal, measureParams._BoseNelsonNetworkType), 
                        measureParams.SortMethod);
                    gen->WriteLine("");
                }
            );
            WriteMeasureMethod(
                gen,
                "MeasureSortingInRow",
                measureParamsList,
                [=](MeasureParams measureParams){
                    WriteMeasureLine(
                        gen,
                        measureParams.Structs,
                        "MeasureInRow",
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::InRow, measureParams._BoseNelsonNetworkType),
                        measureParams.SortMethod,
                        false);
                    gen->WriteLine("");
                }
            );
            std::vector<MeasureParams> sampleSortMeasureParams = 
            {
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbest", Sorter::SortNetwork, NetworkType::Best),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelson", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Locality),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelsonparallel", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parallelism),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("FourCmovTemp") == 0;}), "networks::sortNbosenelsonparameter", Sorter::SortNetwork, NetworkType::BoseNelson, BoseNelsonNetworkType::Parameter),
                GetParams(VectorWhere<SortableStruct*>(sortableStructs(), [](SortableStruct* ss){return ss->Name.compare("PointerOptimized") == 0;}), "insertionsort::InsertionSort", Sorter::InsertionSort, NetworkType::None)
            };
            WriteMeasureMethod(
                gen,
                "MeasureSampleSort",
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
                                    gen,
                                    measureParams.Structs,
                                    "MeasureSampleSort",
                                    BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::SampleSort, measureParams._BoseNelsonNetworkType, splits, oversample, blockSize),
                                    "samplesort::" + sampleSortName,
                                    ", uint64_t",
                                    measureParams.SortMethod);
                                gen->WriteLine("");
                            }
                        }
                    }
                }
            );
            std::vector<SortableStruct*> sRef = {(*sortableStructs())[0]};
            WriteMeasureMethod(
                gen,
                "MeasureCompleteSorting",
                measureParamsList,
                [=](MeasureParams measureParams) {
                    WriteCompleteSorterMeasureLine(
                        gen,
                        measureParams.Structs,
                        "MeasureCompleteSorter",
                        BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::Complete, measureParams._BoseNelsonNetworkType),
                        "quicksort::QS_Stl",
                        "",
                        measureParams.SortMethod);
                    gen->WriteLine("");
                    // WriteCompleteSorterMeasureLine(
                    //     gen,
                    //     measureParams.Structs,
                    //     "MeasureCompleteSorter",
                    //     BuildSorterName(measureParams._Sorter, measureParams._NetworkType, MeasureType::Complete2, measureParams._BoseNelsonNetworkType),
                    //     "quicksortcopy::Quicksort_Copy_Msvc",
                    //     "",
                    //     measureParams.SortMethod);
                    // gen->WriteLine("");
                },
                [=]{
                    WriteCompleteSorterMeasureLine(
                        gen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::StdSort, NetworkType::None, MeasureType::Complete),
                        "measurement::StdSortWrapper",
                        "",
                        "measurement::BaseCaseSortBlank"
                    );
                    WriteCompleteSorterMeasureLine(
                        gen,
                        &sRef,
                        "MeasureCompleteSorter",
                        BuildSorterName(Sorter::QuicksortCopy, NetworkType::None, MeasureType::Complete),
                        "measurement::QuicksortCopyWrapper",
                        "",
                        "measurement::BaseCaseSortBlank"
                    );
                }
            );
        }, "");
    });
}

}