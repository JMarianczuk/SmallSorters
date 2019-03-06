
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

struct MeasureParams
{
    std::vector<SortableStruct*>* Structs;
    std::string Sorter;
    std::string SortMethod;
};

void GenerateMeasurementMethod(CPlusPlusCodeGenerator* gen);

}

#endif