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
#include "../sorters/QuickSort.h"
#include "../sorters/StdSortWrapper.h"
namespace measurement
{
void MeasureCompleteSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q ISwp", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_IfSwap>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q JXhg", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_JumpXchg_Ref>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 4Cm ", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_FourCmovTemp>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 4CmS", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 2CPm", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_TwoConditionalPointerMove>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 2CPp", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_TwoConditionalPointerMovePredicate>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q Tie ", &quicksort::sort<static_sorters::BestNetworks<conditional_swap::CS_Tie>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN Best -Q Tie ");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q ISwp", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_IfSwap>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q JXhg", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_JumpXchg_Ref>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 4Cm ", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_FourCmovTemp>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 4CmS", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 2CPm", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_TwoConditionalPointerMove>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 2CPp", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_TwoConditionalPointerMovePredicate>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q Tie ", &quicksort::sort<static_sorters::BoseNelsonNetworks<conditional_swap::CS_Tie>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-L -Q Tie ");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q ISwp", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_IfSwap>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q JXhg", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_JumpXchg_Ref>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 4Cm ", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_FourCmovTemp>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 4CmS", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 2CPm", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_TwoConditionalPointerMove>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 2CPp", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_TwoConditionalPointerMovePredicate>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q Tie ", &quicksort::sort<static_sorters::BoseNelsonParallelNetworks<conditional_swap::CS_Tie>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-P -Q Tie ");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q Def ", &quicksort::sort<static_sorters::InsertionSort<insertionsort::InsertionSort_Default>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q STL ", &quicksort::sort<static_sorters::InsertionSort<insertionsort::InsertionSort_StlVersion>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q POp ", &quicksort::sort<static_sorters::InsertionSort<insertionsort::InsertionSort_PointerOptimized>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q AIF ", &quicksort::sort<static_sorters::InsertionSort<insertionsort::InsertionSort_ArrayIndex_FirstCheck>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q Def ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q STL ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q POp ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "IS      -Q AIF ");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q ISwp", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_IfSwap>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q JXhg", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_JumpXchg_Ref>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 4Cm ", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_FourCmovTemp>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 4CmS", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_FourCmovTemp_Split>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 2CPm", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_TwoConditionalPointerMove>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 2CPp", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_TwoConditionalPointerMovePredicate>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q Tie ", &quicksort::sort<static_sorters::BoseNelsonRecursiveNetworks<conditional_swap::CS_Tie>, SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q ISwp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q JXhg");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 4Cm ");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 4CmS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 2CPm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q 2CPp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SN BN-R -Q Tie ");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q ", &measurement::StdSortWrapper);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q ");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q ", &measurement::QuicksortCopyWrapper);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q ");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q RSS", &measurement::RadixSortThrillWrapper<static_sorters::SampleSort>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q RSS");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q Std", &measurement::RadixSortThrillWrapper<static_sorters::StdSort>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q Std");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q Std", &measurement::RadixSortThrillWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "RadixT  -Q Std");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q RSS", &measurement::SkaSortWrapper<static_sorters::SampleSort>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q RSS");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q Std", &measurement::SkaSortWrapper<static_sorters::StdSort>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q Std");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q Std", &measurement::SkaSortWrapper<static_sorters::InsertionSortPred<insertionsort::InsertionSort_Default>>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef, RandomisationMode::DEFAULT>(perf, numberOfIterations, arraySize, measureIteration, "SkaSort -Q Std");
}
} // namespace measurement
