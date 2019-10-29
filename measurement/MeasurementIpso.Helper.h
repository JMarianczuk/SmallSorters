
#ifndef MEASUREMENT_IPSO_HELPER_H
#define MEASUREMENT_IPSO_HELPER_H

#include "Measurement.generated.h"

namespace measurement
{

void MeasureIpsoAll(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
    MeasureIpso_Def16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Def32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Hybrid_Best(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Hybrid_BN_R(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Std(perf, seed, numberOfIterations, arraySize, measureIteration);

    MeasureIpso_Best_331_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Best_331_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Best_331_64(perf, seed, numberOfIterations, arraySize, measureIteration);

    MeasureIpso_BN_L_331_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_L_331_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_L_331_64(perf, seed, numberOfIterations, arraySize, measureIteration);

    MeasureIpso_BN_R_331_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_R_331_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_R_331_64(perf, seed, numberOfIterations, arraySize, measureIteration);

    MeasureIpso_Best_332_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Best_332_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_Best_332_64(perf, seed, numberOfIterations, arraySize, measureIteration);

    MeasureIpso_BN_L_332_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_L_332_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_L_332_64(perf, seed, numberOfIterations, arraySize, measureIteration);
    
    MeasureIpso_BN_R_332_16(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_R_332_32(perf, seed, numberOfIterations, arraySize, measureIteration);
    MeasureIpso_BN_R_332_64(perf, seed, numberOfIterations, arraySize, measureIteration);
}

}

#endif