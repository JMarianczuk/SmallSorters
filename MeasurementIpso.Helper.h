
#ifndef MEASUREMENT_IPSO_HELPER_H
#define MEASUREMENT_IPSO_HELPER_H

#include "Measurement.generated.h"

namespace measurement
{

void MeasureIpsoAll0(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
    MeasureIpso1(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso2(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso3(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso4(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso10(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso20(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso30(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso50(perf, seed, numberOfIterations, arraySize, measureIteration);
}

void MeasureIpsoAll1(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
    MeasureIpso1(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso2(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso3(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso4(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso11(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso21(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso31(perf, seed, numberOfIterations, arraySize, measureIteration);
    // MeasureIpso51(perf, seed, numberOfIterations, arraySize, measureIteration);
}

}

#endif