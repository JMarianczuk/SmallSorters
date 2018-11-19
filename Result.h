
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include "Enumerations.h"

void WriteResultLine(
    Sorter sorter, 
    PerformanceMetric metric, 
    uint64_t metric_value,
    int iteration);

#endif