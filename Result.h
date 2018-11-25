
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include <stdexcept>
#include "Enumerations.h"
#include "Performancing.h"

using namespace std;

void WriteResultLine(
    string sorter, 
    Performancing* perf, 
    int numberOfIterations, 
    int numberOfBadSorts);

#endif