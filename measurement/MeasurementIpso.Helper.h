
#ifndef MEASUREMENT_IPSO_HELPER_H
#define MEASUREMENT_IPSO_HELPER_H

#include "Measurement.generated.h"

namespace measurement
{

void MeasureIpsoAll(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
    MeasureIpso1(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso2(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso3(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso4(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso11_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso11_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso11_64(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso12_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso12_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso12_64(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso21_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso21_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso21_64(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso22_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso22_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso22_64(perf, seed, numberOfIterations, arraySize, measureIteration);
}

}

#endif