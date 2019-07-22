
#ifndef GENERATE_SAMPLESORT_H
#define GENERATE_SAMPLESORT_H

#include <string>
#include <functional>

#include "CodeGeneration.hpp"

namespace codegeneration
{

void WriteSplitterComparisonRoutine(CodeGenerator* gen);
void WriteFindSplitters(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor);
void WriteRegisterSampleSort(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor, int blockSize);

}

#endif