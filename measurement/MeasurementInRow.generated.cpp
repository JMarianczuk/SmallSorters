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
#include "../sorters/StaticSorters.h"
#include "../conditional_swap/ConditionalSwap.h"
#include "../sorters/InsertionSort.h"
namespace measurement
{
void MeasureSortingInRow(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I ISwp", &networks::best::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I JXhg", &networks::best::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I 4Cm ", &networks::best::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I 4CmS", &networks::best::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I 2CPm", &networks::best::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I 2CPp", &networks::best::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -I Tie ", &networks::best::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I ISwp", &networks::bosenelson::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I JXhg", &networks::bosenelson::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I 4Cm ", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I 4CmS", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I 2CPm", &networks::bosenelson::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I 2CPp", &networks::bosenelson::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_L -I Tie ", &networks::bosenelson::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I ISwp", &networks::bosenelsonparallel::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I JXhg", &networks::bosenelsonparallel::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I 4Cm ", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I 4CmS", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I 2CPm", &networks::bosenelsonparallel::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I 2CPp", &networks::bosenelsonparallel::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_P -I Tie ", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS  -I Def", &insertionsort::InsertionSort<insertionsort::InsertionSort_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS  -I STL", &insertionsort::InsertionSort<insertionsort::InsertionSort_StlVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS  -I POp", &insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS  -I AIF", &insertionsort::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I ISwp", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I JXhg", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I 4Cm ", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I 4CmS", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I 2CPm", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I 2CPp", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN_R -I Tie ", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Tie, SortableRef>);
	
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I ISwp", &networks::bosenelson_2::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I JXhg", &networks::bosenelson_2::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I 4Cm ", &networks::bosenelson_2::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I 4CmS", &networks::bosenelson_2::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I 2CPm", &networks::bosenelson_2::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I 2CPp", &networks::bosenelson_2::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureInRow<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN -I Tie ", &networks::bosenelson_2::sortN<conditional_swap::CS_Tie, SortableRef>);
	
}
} // namespace measurement
