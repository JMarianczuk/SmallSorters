#include "Measure.h"
#include "Performancing.h"
#include "BestNetworks.generated.h"

void MeasureTest()
{
    auto perf = new Performancing(PerformanceMetric::CPU_CYCLES);
    // measurement::Measure<SortableRef_ClangVersion>(perf, 100, 2, 4, "Test", &networks::sortNbest<SortableRef_ClangVersion>);
    measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, 100, 2, 4, "Test");
}