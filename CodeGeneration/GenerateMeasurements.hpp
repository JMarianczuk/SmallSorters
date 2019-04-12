
#ifndef GENERATE_MEASUREMENTS_H
#define GENERATE_MEASUREMENTS_H

#include <string>
#include <vector>

#include "VectorHelpers.hpp"
#include "FunctionalHelpers.hpp"
#include "SortableDefinitions.hpp"
#include "CodeGeneration.hpp"

namespace codegeneration
{

enum class Sorter
{
    InsertionSort,
    SortNetwork,
    StdSort,
    QuicksortCopy,
    QuicksortCopyMsvc,
    SampleSort
};

enum class NetworkType
{
    Best,
    BoseNelson,
    None
};
enum class BoseNelsonNetworkType
{
    Locality,
    Parallelism,
    Parameter,
    None
};
enum class MeasureType
{
    Normal,
    InRow,
    Complete,
    Complete2,
    SampleSort
};

struct MeasureParams
{
    std::vector<SortableStruct*>* Structs;
    std::string SortMethod;
    Sorter _Sorter;
    NetworkType _NetworkType;
    BoseNelsonNetworkType _BoseNelsonNetworkType;
};

void GenerateMeasurementMethod(CPlusPlusCodeGenerator* headerGen, CPlusPlusCodeGenerator* normalGen, CPlusPlusCodeGenerator* inrowGen, CPlusPlusCodeGenerator* completeGen, CPlusPlusCodeGenerator* sampleSortGen);

}

#endif