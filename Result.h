
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include <stdexcept>
#include "Enumerations.h"
#include "Performancing.h"

void WriteResultLine(
    std::string sorter, 
    Performancing* perf, 
    int numberOfIterations, 
    int numberOfBadSorts);

#endif