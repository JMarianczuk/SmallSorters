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
void MeasureIpso11(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Def", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4Cm", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4CS", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Cla", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR CPr", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Tie", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Tie");
}
} // namespace measurement
