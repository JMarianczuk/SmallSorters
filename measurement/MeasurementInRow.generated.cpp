//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "Measurement.generated.h"
namespace measurement
{
void MeasureSortingInRow(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Def", &networks::best::sortN<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR JXc", &networks::best::sortN<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR 4Cm", &networks::best::sortN<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR 4CS", &networks::best::sortN<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR 6Cm", &networks::best::sortN<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Cla", &networks::best::sortN<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR CPr", &networks::best::sortN<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR Tie", &networks::best::sortN<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -I KR QMa", &networks::best::sortN<SortableRef_QMark>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Def", &networks::bosenelson::sortN<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR JXc", &networks::bosenelson::sortN<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR 4Cm", &networks::bosenelson::sortN<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR 4CS", &networks::bosenelson::sortN<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR 6Cm", &networks::bosenelson::sortN<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Cla", &networks::bosenelson::sortN<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR CPr", &networks::bosenelson::sortN<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR Tie", &networks::bosenelson::sortN<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BNLoc -I KR QMa", &networks::bosenelson::sortN<SortableRef_QMark>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Def", &networks::bosenelsonparallel::sortN<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR JXc", &networks::bosenelsonparallel::sortN<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR 4Cm", &networks::bosenelsonparallel::sortN<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR 4CS", &networks::bosenelsonparallel::sortN<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR 6Cm", &networks::bosenelsonparallel::sortN<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Cla", &networks::bosenelsonparallel::sortN<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR CPr", &networks::bosenelsonparallel::sortN<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR Tie", &networks::bosenelsonparallel::sortN<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BNPL  -I KR QMa", &networks::bosenelsonparallel::sortN<SortableRef_QMark>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR Def", &networks::bosenelsonparameter::sortN<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR JXc", &networks::bosenelsonparameter::sortN<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR 4Cm", &networks::bosenelsonparameter::sortN<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR 4CS", &networks::bosenelsonparameter::sortN<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR 6Cm", &networks::bosenelsonparameter::sortN<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR Cla", &networks::bosenelsonparameter::sortN<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR CPr", &networks::bosenelsonparameter::sortN<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR Tie", &networks::bosenelsonparameter::sortN<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BNPM  -I KR QMa", &networks::bosenelsonparameter::sortN<SortableRef_QMark>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR Def", &insertionsort::InsertionSort<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_StlVersion>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR STL", &insertionsort::InsertionSort<SortableRef_StlVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_PointerOptimized>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR POp", &insertionsort::InsertionSort<SortableRef_PointerOptimized>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ArrayIndex_FirstCheck>(perf, numberOfIterations, arraySize, measureIteration, "I       -I KR AIF", &insertionsort::InsertionSort<SortableRef_ArrayIndex_FirstCheck>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Def", &networks::bosenelsonrecursive::sortN<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR JXc", &networks::bosenelsonrecursive::sortN<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR 4Cm", &networks::bosenelsonrecursive::sortN<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR 4CS", &networks::bosenelsonrecursive::sortN<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR 6Cm", &networks::bosenelsonrecursive::sortN<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Cla", &networks::bosenelsonrecursive::sortN<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR CPr", &networks::bosenelsonrecursive::sortN<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR Tie", &networks::bosenelsonrecursive::sortN<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BNRec -I KR QMa", &networks::bosenelsonrecursive::sortN<SortableRef_QMark>);
	
}
} // namespace measurement
