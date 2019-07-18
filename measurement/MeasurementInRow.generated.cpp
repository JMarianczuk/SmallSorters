//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "Measure.h"
#include "../environment/Performancing.h"
#include "../Networks_Fwd.h"
#include "../conditional_swap/ConditionalSwapGeneric.h"
#include "../conditional_swap/ConditionalSwapX86.h"
#include "../sorters/InsertionSort.h"
namespace measurement
{
void MeasureSortingInRow(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Def", &networks::best::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR 4Cm", &networks::best::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR 4CS", &networks::best::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Cla", &networks::best::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR CPr", &networks::best::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Tie", &networks::best::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Def", &networks::bosenelson::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR 4Cm", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR 4CS", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Cla", &networks::bosenelson::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR CPr", &networks::bosenelson::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Tie", &networks::bosenelson::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Def", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR 4Cm", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR 4CS", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Cla", &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR CPr", &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Tie", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR Def", &insertionsort::InsertionSort<insertionsort::InsertionSort_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR STL", &insertionsort::InsertionSort<insertionsort::InsertionSort_StlVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR POp", &insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR AIF", &insertionsort::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Def", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR 4Cm", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR 4CS", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Cla", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR CPr", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Tie", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Tie, SortableRef>);
	
}
} // namespace measurement
