
#include <stdexcept>
#include <iostream>

#include "Enumerations.h"
#include "Result.h"

namespace result 
{

void WriteAbbreviationExplanatoryLine()
{
    printf("Result Mapping: s = sorter, m = metric, v = value, ss = struct_size, a = array_size, i = measureIteration, n = number_of_iterations, b = number_of_bad_sorts, c = compensation_measurement\n");
}

void WriteResultLine(
    std::string sorter, 
    Performancing* perf, 
    int structSize,
    size_t arraySize,
    int measureIteration,
    int numberOfIterations, 
    int numberOfBadSorts,
    bool isActualSorterMeasurement) 
{
    std::string metric_name;

    switch (perf->GetMetric()) {
        case PerformanceMetric::CPU_CYCLES:
            metric_name = "Cpu Cycles";
            break;
        case PerformanceMetric::L1_INSTR_CACHE_MISSES:
            metric_name = "L1 Instr. Cache Misses";
            break;
        case PerformanceMetric::BRANCH_MISSES:
            metric_name = "Branch Misses";
            break;
        default:
            throw std::logic_error("Result_h::WriteResultLine => Missing Performance Metric!");
    }

    auto [v1, v2] = perf->GetValues();

    printf(
        "RESULT\ts=%s\tm=%s\tv=%" PRIu64 "\tv2=%" PRIu64 "\tss=%i\ta=%zu\ti=%i\tn=%i\tb=%i\tc=%i\n", 

        sorter.c_str(), 
        metric_name.c_str(), 
        v1,
        v2,
        structSize,
        arraySize,
        measureIteration,
        numberOfIterations, 
        numberOfBadSorts,
        isActualSorterMeasurement ? 0 : 1); 
}

} // namespace result