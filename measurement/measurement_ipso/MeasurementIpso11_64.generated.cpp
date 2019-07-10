//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include <inttypes.h>
#include "../Measure.h"
#include "../../Performancing.h"
#include "../../StdSortWrapper.h"
#include "../../Ipso.h"
namespace measurement
{
void MeasureIpso11_64(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 64_331 KR 4CS", &external::IpsoWrapper<1,1,64>, &measurement::BaseCaseSortBlank<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 64_331 KR 4CS");
}
} // namespace measurement
