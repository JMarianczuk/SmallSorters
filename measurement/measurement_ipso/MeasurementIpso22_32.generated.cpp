//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "../Measurement.generated.h"
#include "../../StdSortWrapper.h"
#include "../../Ipso.h"
namespace measurement
{
void MeasureIpso22_32(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 32_332 KR 4CS", &external::IpsoWrapper<2,2,32>, &measurement::BaseCaseSortBlank<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 32_332 KR 4CS");
}
} // namespace measurement
