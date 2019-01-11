
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
            throw std::logic_error("Missing Performance Metric!");
    }

    printf(
        "RESULT\tsorter=%s\tmetric=%s\tvalue=%" PRIu64 "\tcommit_id=%s\tcomputer_name=%s\tstruct_size=%i\tarray_size=%i\tnumber_of_iterations=%i\tnumber_of_bad_sorts=%i\n", 

        sorter.c_str(), 
        metric_name.c_str(), 
        perf->GetValue(), 
        info.commit.c_str(), 
        info.hostname.c_str(),
        structSize,
        arraySize,
        numberOfIterations, 
        numberOfBadSorts); 
}

#endif