
#include "Result.h"

using namespace std;

void WriteResultLine(Sorter sorter, PerformanceMetric metric, uint64_t metric_value, int iteration) {
    string sorter_name, metric_name;
    switch (sorter) {
        case Sorter::INSERTION_SORT:
            sorter_name = "Insertion Sort";
            break;
        case Sorter::SORTING_NETWORK_NAIVE:
            sorter_name = "Sorting Network Naive";
            break;
        case Sorter::SORTING_NETWORK_OPTIMISED:
            sorter_name = "Sorting Network Optimised";
            break;
        default:
            throw logic_error("Missing Sorter!");
    };

    switch (metric) {
        case PerformanceMetric::CPU_CYCLES:
            metric_name = "Cpu Cycles";
            break;
        default:
            throw logic_error("Missing Performance Metric!");
    }

    printf("RESULT\tsorter=%s\tmetric=%s\tvalue=%"PRIu64"\titeration=%i\n", sorter_name.c_str(), metric_name.c_str(), metric_value, iteration); 
}