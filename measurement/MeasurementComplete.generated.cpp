//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "Measure.h"
#include "../Performancing.h"
#include "../Networks_Fwd.h"
#include "../conditional_swap/ConditionalSwapGeneric.h"
#include "../conditional_swap/ConditionalSwapX86.h"
#include "../InsertionSort.h"
#include "../QuickSort.h"
#include "../StdSortWrapper.h"
namespace measurement
{
void MeasureCompleteSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Def", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR JXc", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4Cm", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4CS", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 6Cm", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Cla", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR CPr", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Tie", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR QMa", &quicksort::sort<SortableRef>, &networks::best::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Def", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR JXc", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 4Cm", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 4CS", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 6Cm", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Cla", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR CPr", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Tie", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR QMa", &quicksort::sort<SortableRef>, &networks::bosenelson::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Def", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR JXc", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 4Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 4CS", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 6Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Cla", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR CPr", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Tie", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR QMa", &quicksort::sort<SortableRef>, &networks::bosenelsonparallel::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Def", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR JXc", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 4Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 4CS", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 6Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Cla", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR CPr", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Tie", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR QMa", &quicksort::sort<SortableRef>, &networks::bosenelsonparameter::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR Def", &quicksort::sort<SortableRef>, &insertionsort::InsertionSort<insertionsort::InsertionSort_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR STL", &quicksort::sort<SortableRef>, &insertionsort::InsertionSort<insertionsort::InsertionSort_StlVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR POp", &quicksort::sort<SortableRef>, &insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR AIF", &quicksort::sort<SortableRef>, &insertionsort::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR STL");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR POp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR AIF");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Def", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR JXc", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 4Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 4CS", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 6Cm", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Cla", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR CPr", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Tie", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR QMa", &quicksort::sort<SortableRef>, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q KR Def", &measurement::StdSortWrapper, &measurement::BaseCaseSortBlank<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q KR Def", &measurement::QuicksortCopyWrapper, &measurement::BaseCaseSortBlank<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q KR Def");
}
} // namespace measurement
