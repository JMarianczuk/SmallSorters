//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include <inttypes.h>
#include "../Measure.h"
#include "../../environment/Performancing.h"
#include "../../sorters/StdSortWrapper.h"
#include "../../sorters/Ipso.h"
namespace measurement
{
void MeasureIpsoIpsoBaseCaseType::BOSE_NELSON_NETWORKSIpsoSampleSortType::SAMPLE_SORT_332_32(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 32_332 KR 4CS", &external::IpsoWrapper<IpsoBaseCaseType::BOSE_NELSON_NETWORKS,IpsoSampleSortType::SAMPLE_SORT_332,32>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 32_332 KR 4CS");
}
} // namespace measurement
