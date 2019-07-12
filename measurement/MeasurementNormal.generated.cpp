//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
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
#include "../sorters/InsertionSort.h"
namespace measurement
{
void MeasureSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Def", &networks::best::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR JXc", &networks::best::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 4Cm", &networks::best::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 4CS", &networks::best::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 6Cm", &networks::best::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Cla", &networks::best::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR CPr", &networks::best::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Tie", &networks::best::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR QMa", &networks::best::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -N KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Def", &networks::bosenelson::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR JXc", &networks::bosenelson::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 4Cm", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 4CS", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 6Cm", &networks::bosenelson::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Cla", &networks::bosenelson::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR CPr", &networks::bosenelson::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Tie", &networks::bosenelson::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR QMa", &networks::bosenelson::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -N KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Def", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR JXc", &networks::bosenelsonparallel::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 4Cm", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 4CS", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 6Cm", &networks::bosenelsonparallel::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Cla", &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR CPr", &networks::bosenelsonparallel::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Tie", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR QMa", &networks::bosenelsonparallel::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -N KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Def", &networks::bosenelsonparameter::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR JXc", &networks::bosenelsonparameter::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 4Cm", &networks::bosenelsonparameter::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 4CS", &networks::bosenelsonparameter::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 6Cm", &networks::bosenelsonparameter::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Cla", &networks::bosenelsonparameter::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR CPr", &networks::bosenelsonparameter::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Tie", &networks::bosenelsonparameter::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR QMa", &networks::bosenelsonparameter::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -N KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR Def", &insertionsort::InsertionSort<insertionsort::InsertionSort_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR STL", &insertionsort::InsertionSort<insertionsort::InsertionSort_StlVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR POp", &insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR AIF", &insertionsort::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR STL");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR POp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -N KR AIF");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Def", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR JXc", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 4Cm", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 4CS", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 6Cm", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_SixCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Cla", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR CPr", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_ClangPredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Tie", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR QMa", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_QMark, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -N KR QMa");
	
}
} // namespace measurement
