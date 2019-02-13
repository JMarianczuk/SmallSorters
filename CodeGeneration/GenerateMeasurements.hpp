
#ifndef GENERATE_MEASUREMENTS_H
#define GENERATE_MEASUREMENTS_H

#include <string>

#include "CodeGeneration.hpp"
#include "SortableDefinitions.hpp"
#include "VectorHelpers.hpp"
#include "FunctionalHelpers.hpp"

namespace codegeneration
{

struct MeasureParams
{
    std::vector<SortableStruct*>* Structs;
    std::string Sorter;
    std::string SortMethod;
};

MeasureParams GetParams(std::vector<SortableStruct*>* structs, std::string sorter, std::string sortMethod)
{
    MeasureParams result =
    {
        structs, sorter, sortMethod
    };
    return result;
}

void WriteMeasureLine(
    CodeGenerator* gen, 
    std::vector<SortableStruct*>* structs, 
    std::string measureMethod, 
    std::string sorter, 
    std::string sortMethod)
{
    for (SortableStruct *sortableStruct : *structs)
    {
        gen->Write("measurement::");
        gen->Write(measureMethod);
        gen->Write("<");
        gen->Write(sortableStruct->FullName());
        gen->Write(">(perf, numberOfIterations, arraySize, measureIteration, \"");
        gen->Write(sorter);
        gen->Write(" ");
        gen->Write(sortableStruct->DisplayName);
        gen->Write("\", &");
        gen->Write(sortMethod);
        gen->Write("<");
        gen->Write(sortableStruct->FullName());
        gen->WriteLine(">);");
    }
}

void GenerateMeasurementMethod(CodeGenerator* gen)
{
    std::vector<MeasureParams> measureParams = 
    {
        GetParams(VectorWhere<SortableStruct*>(sortableStructs, [](SortableStruct* ss){return ss->UseForNetworkSort();}), "Netw. Best", "networks::sortNbest"),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs, [](SortableStruct* ss){return ss->UseForNetworkSort();}), "Netw. BoseNelson", "networks::sortNbosenelson"),
        GetParams(VectorWhere<SortableStruct*>(sortableStructs, [](SortableStruct* ss){return ss->UseForInsertionSort();}), "Ins.", "insertionsort::InsertionSort")
    };
    gen->WriteLine(AutogeneratedPreamble);
    gen->WriteLine("");

    gen->WriteHeaderPragma("MEASUREMENT_GENERATED_H", [=](){
        gen->WriteIncludeQuotes("Sortable.generated.h");
        gen->WriteIncludeQuotes("Performancing.h");
        gen->WriteIncludeQuotes("EnvironmentInfo.h");
        gen->WriteIncludeQuotes("Measure.h");
        gen->WriteIncludeQuotes("BestNetworks.generated.h");
        gen->WriteIncludeQuotes("BoseNelson.generated.h");
        gen->WriteIncludeQuotes("InsertionSort.h");
        gen->WriteLine("");

        gen->WriteNamespace("measurement", [=](){
            gen->WriteLine("void MeasureSorting(Performancing* perf, int numberOfIterations, size_t arraySize, int measureIteration)");
            gen->WriteBlock([=](){
                Multicall<MeasureParams>(
                    [=](MeasureParams measureParams){
                        WriteMeasureLine(
                            gen, 
                            measureParams.Structs, 
                            "Measure", 
                            measureParams.Sorter, 
                            measureParams.SortMethod);
                        gen->WriteLine("");
                    }, 
                    measureParams);
                Multicall<MeasureParams>(
                    [=](MeasureParams measureParams){
                        WriteMeasureLine(
                            gen,
                            measureParams.Structs,
                            "MeasureInRow",
                            measureParams.Sorter + "InRow",
                            measureParams.SortMethod);
                        gen->WriteLine("");
                    },
                    measureParams);
            });
        }, "");
    });
}

}

#endif