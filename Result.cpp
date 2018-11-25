
#include "Result.h"

using namespace std;

void WriteResultLine(
    string sorter, 
    Performancing* perf, 
    int numberOfIterations, 
    int numberOfBadSorts) 
{
    string metric_name;

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
            throw logic_error("Missing Performance Metric!");
    }

    printf("RESULT\tsorter=%s\tmetric=%s\tvalue=%"PRIu64"\tnumber_of_iterations=%i\tnumber_of_bad_sorts=%i\n", sorter.c_str(), metric_name.c_str(), perf->GetValue(), numberOfIterations, numberOfBadSorts); 
}