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
	measurement::MeasureCompleteSorter<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR JXc", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4Cm", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4CS", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 6Cm", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Cla", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR CPr", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Tie", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR QMa", &external::IpsoWrapper<1,1>, &measurement::BaseCaseSortBlank<SortableRef_QMark>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "S+N Best  -4 KR QMa");
}
} // namespace measurement
