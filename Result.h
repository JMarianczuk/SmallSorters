
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include <stdexcept>
#include "Enumerations.h"

void WriteResultLine(
    Sorter sorter, 
    Performancing* perf,
    int iteration);

#endif