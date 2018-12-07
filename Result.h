
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include <stdexcept>
#include "Enumerations.h"
#include "Performancing.h"
#include "EnvironmentInfo.h"

void WriteResultLine(
    std::string sorter, 
    Performancing* perf, 
    EnvironmentInfo info,
    int arraySize,
    int numberOfIterations, 
    int numberOfBadSorts);

#endif