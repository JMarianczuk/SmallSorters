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
void MeasureIpso21_16(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 16_331 KR 4CS", &external::IpsoWrapper<2,1,16>, &measurement::BaseCaseSortBlank<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "S+N BNLoc -4 16_331 KR 4CS");
}
} // namespace measurement