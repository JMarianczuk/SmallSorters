//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef MEASUREMENT_GENERATED_H
#define MEASUREMENT_GENERATED_H

#include <inttypes.h>
#include "Sortable.generated.h"
#include "Performancing.h"
#include "Measure.h"
#include "BestNetworks.generated.h"
#include "BoseNelson.generated.h"
#include "BoseNelsonParallel.generated.h"
#include "BoseNelsonParameter.generated.h"
#include "InsertionSort.h"
#include "Randomisation.h"

namespace measurement
{
void MeasureSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureSortingInRow(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureCompleteSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureSampleSort(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso0(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso1(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso10(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso20(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso30(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso50(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso11(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso21(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso31(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
void MeasureIpso51(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration);
} // namespace measurement

#endif // MEASUREMENT_GENERATED_H
