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
void MeasureSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N ISwp", &networks::best::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N JXhg", &networks::best::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 4Cm ", &networks::best::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 4CmS", &networks::best::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 2CPm", &networks::best::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 2CPp", &networks::best::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N Tie ", &networks::best::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N CmX", &networks::best::sortN<conditional_swap::CS_CmovXor, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N Tie ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -N CmX");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N ISwp", &networks::bosenelson::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N JXhg", &networks::bosenelson::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 4Cm ", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 4CmS", &networks::bosenelson::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 2CPm", &networks::bosenelson::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 2CPp", &networks::bosenelson::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N Tie ", &networks::bosenelson::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N CmX", &networks::bosenelson::sortN<conditional_swap::CS_CmovXor, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N Tie ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -N CmX");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N ISwp", &networks::bosenelsonparallel::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N JXhg", &networks::bosenelsonparallel::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 4Cm ", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 4CmS", &networks::bosenelsonparallel::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 2CPm", &networks::bosenelsonparallel::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 2CPp", &networks::bosenelsonparallel::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N Tie ", &networks::bosenelsonparallel::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N CmX", &networks::bosenelsonparallel::sortN<conditional_swap::CS_CmovXor, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N Tie ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -N CmX");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N Def ", &insertionsort::InsertionSort<insertionsort::InsertionSort_Default, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N STL ", &insertionsort::InsertionSort<insertionsort::InsertionSort_StlVersion, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N POp ", &insertionsort::InsertionSort<insertionsort::InsertionSort_PointerOptimized, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N AIF ", &insertionsort::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N Def ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N STL ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N POp ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -N AIF ");
	
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N ISwp", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_IfSwap, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N JXhg", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_JumpXchg_Ref, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 4Cm ", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 4CmS", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_FourCmovTemp_Split, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 2CPm", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_TwoConditionalPointerMove, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 2CPp", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_TwoConditionalPointerMovePredicate, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N Tie ", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Tie, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::Measure<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N CmX", &networks::bosenelsonrecursive::sortN<conditional_swap::CS_CmovXor, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N Tie ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -N CmX");
	
}
} // namespace measurement
