//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "../Measurement.generated.h"
#include "../StdSortWrapper.h"
#include "../Ipso.h"
namespace measurement
{
void MeasureIpso0(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 64 KR Def", &external::IpsoWrapper<0,0>, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 64 KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 32 KR Def", &external::IpsoWrapper<10,0>, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 32 KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 16 KR Def", &external::IpsoWrapper<20,0>, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -4 16 KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -4 KR Def", &measurement::StdSortWrapper, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -4 KR Def");
}
} // namespace measurement
