



//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated from a T4 template
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef MEASUREMENT_GENERATED_H
#define MEASUREMENT_GENERATED_H

#include "Sortable.generated.h"
#include "Performancing.h"
#include "EnvironmentInfo.h"
#include "Measure.h"

namespace measurement
{

void MeasureSorting(Performancing* perf, EnvironmentInfo info, int numberOfIterations, size_t arraySize)
{
	measurement::MeasureNetworkSort<SortableRef>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-Tuple");
	measurement::MeasureNetworkSort<SortableRef_JumpXchg>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-JumpXchg");
	measurement::MeasureNetworkSort<SortableRef_FourCmovTemp>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-FourCmovTemp");
	measurement::MeasureNetworkSort<SortableRef_FourCmovTemp_Split>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-FourCmovTemp_Split");
	measurement::MeasureNetworkSort<SortableRef_SixCmovRegisterTemp>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-SixCmovRegisterTemp");
	measurement::MeasureNetworkSort<SortableRef_ClangVersion>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-ClangVersion");

	measurement::MeasureInsertionSort<SortableRef>(perf, info, numberOfIterations, arraySize, "Insertion Sort Key-Reference-Tuple");
}

void MeasureRandomGenerationAndSortedChecking(Performancing* perf, EnvironmentInfo info, int numberOfIterations, size_t arraySize)
{
	measurement::MeasureRandomGeneration<SortableRef>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-Tuple");
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-JumpXchg");
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-FourCmovTemp");
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-FourCmovTemp_Split");
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-SixCmovRegisterTemp");
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, info, numberOfIterations, arraySize, "Network Sort Key-Reference-ClangVersion");

	measurement::MeasureRandomGeneration<SortableRef>(perf, info, numberOfIterations, arraySize, "Insertion Sort Key-Reference-Tuple");
}

}

#endif

