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
#include "../../Enumerations.h"
#include "../../environment/Performancing.h"
#include "../../sorters/StdSortWrapper.h"
#include "../../sorters/Ipso.h"
namespace measurement
{
void MeasureIpso_Best_331_32(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SS+SN Best -4 32_331 4CmS", &external::IpsoWrapper<IpsoBaseCaseType::BEST_NETWORKS,IpsoSampleSortType::SAMPLE_SORT_331,32>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SS+SN Best -4 32_331 4CmS");
}
} // namespace measurement
