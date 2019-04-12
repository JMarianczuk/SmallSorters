
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>

#include "Performancing.h"

namespace result
{
    
void WriteAbbreviationExplanatoryLine();
void WriteResultLine(
    std::string sorter, 
    Performancing* perf, 
    int structSize,
    size_t arraySize,
    int measureIteration,
    int numberOfIterations, 
    int numberOfBadSorts,
    bool isActualSorterMeasurement);

}

#endif