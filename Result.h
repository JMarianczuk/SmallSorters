
#ifndef RESULT_H
#define RESULT_H

#include <inttypes.h>
#include <string>
#include <stdexcept>
#include <iostream>

#include "Enumerations.h"
#include "Performancing.h"
#include "EnvironmentInfo.h"

void WriteAbbreviationExplanatoryLine()
{
    printf(
        "s = sorter, 
        m = metric, 
        v = value, 
        ss = struct_size, 
        as = array_size, 
        n = number_of_iterations, 
        b = number_of_bad_sorts, 
        c = compensation_measurement");
}

void WriteResultLine(
    std::string sorter, 
    Performancing* perf, 
    int structSize,
    int arraySize,
    int numberOfIterations, 
    int numberOfBadSorts,
    bool isActualSorterMeasurement) 
{
    std::string metric_name;

    switch (perf->GetMetric()) {
        case PerformanceMetric::CPU_CYCLES:
            metric_name = "Cpu Cycles";
            break;
        case PerformanceMetric::CACHE_MISSES:
            metric_name = "Cache Misses";
            break;
        case PerformanceMetric::BRANCH_MISSES:
            metric_name = "Branch Misses";
            break;
        default:
            throw std::logic_error("Result_h::WriteResultLine => Missing Performance Metric!");
    }

    printf(
        "RESULT\ts=%s\tm=%s\tv=%" PRIu64 "\tss=%i\tas=%i\tn=%i\tb=%i\tc=%i\n", 

        sorter.c_str(), 
        metric_name.c_str(), 
        perf->GetValue(), 
        structSize,
        arraySize,
        numberOfIterations, 
        numberOfBadSorts,
        isActualSorterMeasurement ? 0 : 1); 
}

#endif