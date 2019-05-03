//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#include "Measurement.generated.h"
#include "QuickSort.h"
#include "StdSortWrapper.h"
namespace measurement
{
void MeasureCompleteSorting(Performancing* perf, uint64_t seed, int numberOfIterations, size_t arraySize, int measureIteration)
{
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Def", &quicksort::sort<SortableRef>, &networks::sortNbest<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR JXc", &quicksort::sort<SortableRef_JumpXchg>, &networks::sortNbest<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4Cm", &quicksort::sort<SortableRef_FourCmovTemp>, &networks::sortNbest<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4CS", &quicksort::sort<SortableRef_FourCmovTemp_Split>, &networks::sortNbest<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 6Cm", &quicksort::sort<SortableRef_SixCmovRegisterTemp>, &networks::sortNbest<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Cla", &quicksort::sort<SortableRef_ClangVersion>, &networks::sortNbest<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR CPr", &quicksort::sort<SortableRef_ClangPredicate>, &networks::sortNbest<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Tie", &quicksort::sort<SortableRef_Tie>, &networks::sortNbest<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR QMa", &quicksort::sort<SortableRef_QMark>, &networks::sortNbest<SortableRef_QMark>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N Best  -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Def", &quicksort::sort<SortableRef>, &networks::sortNbosenelson<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR JXc", &quicksort::sort<SortableRef_JumpXchg>, &networks::sortNbosenelson<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 4Cm", &quicksort::sort<SortableRef_FourCmovTemp>, &networks::sortNbosenelson<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 4CS", &quicksort::sort<SortableRef_FourCmovTemp_Split>, &networks::sortNbosenelson<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 6Cm", &quicksort::sort<SortableRef_SixCmovRegisterTemp>, &networks::sortNbosenelson<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Cla", &quicksort::sort<SortableRef_ClangVersion>, &networks::sortNbosenelson<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR CPr", &quicksort::sort<SortableRef_ClangPredicate>, &networks::sortNbosenelson<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Tie", &quicksort::sort<SortableRef_Tie>, &networks::sortNbosenelson<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR QMa", &quicksort::sort<SortableRef_QMark>, &networks::sortNbosenelson<SortableRef_QMark>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeL -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Def", &quicksort::sort<SortableRef>, &networks::sortNbosenelsonparallel<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR JXc", &quicksort::sort<SortableRef_JumpXchg>, &networks::sortNbosenelsonparallel<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 4Cm", &quicksort::sort<SortableRef_FourCmovTemp>, &networks::sortNbosenelsonparallel<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 4CS", &quicksort::sort<SortableRef_FourCmovTemp_Split>, &networks::sortNbosenelsonparallel<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 6Cm", &quicksort::sort<SortableRef_SixCmovRegisterTemp>, &networks::sortNbosenelsonparallel<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Cla", &quicksort::sort<SortableRef_ClangVersion>, &networks::sortNbosenelsonparallel<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR CPr", &quicksort::sort<SortableRef_ClangPredicate>, &networks::sortNbosenelsonparallel<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Tie", &quicksort::sort<SortableRef_Tie>, &networks::sortNbosenelsonparallel<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR QMa", &quicksort::sort<SortableRef_QMark>, &networks::sortNbosenelsonparallel<SortableRef_QMark>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeP -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Def", &quicksort::sort<SortableRef>, &networks::sortNbosenelsonparameter<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR JXc", &quicksort::sort<SortableRef_JumpXchg>, &networks::sortNbosenelsonparameter<SortableRef_JumpXchg>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 4Cm", &quicksort::sort<SortableRef_FourCmovTemp>, &networks::sortNbosenelsonparameter<SortableRef_FourCmovTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 4CS", &quicksort::sort<SortableRef_FourCmovTemp_Split>, &networks::sortNbosenelsonparameter<SortableRef_FourCmovTemp_Split>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 6Cm", &quicksort::sort<SortableRef_SixCmovRegisterTemp>, &networks::sortNbosenelsonparameter<SortableRef_SixCmovRegisterTemp>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Cla", &quicksort::sort<SortableRef_ClangVersion>, &networks::sortNbosenelsonparameter<SortableRef_ClangVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR CPr", &quicksort::sort<SortableRef_ClangPredicate>, &networks::sortNbosenelsonparameter<SortableRef_ClangPredicate>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Tie", &quicksort::sort<SortableRef_Tie>, &networks::sortNbosenelsonparameter<SortableRef_Tie>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR QMa", &quicksort::sort<SortableRef_QMark>, &networks::sortNbosenelsonparameter<SortableRef_QMark>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR JXc");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 4Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 4CS");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR 6Cm");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Cla");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ClangPredicate>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR CPr");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_Tie>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR Tie");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_QMark>(perf, numberOfIterations, arraySize, measureIteration, "N BoNeM -Q KR QMa");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR Def", &quicksort::sort<SortableRef>, &insertionsort::InsertionSort<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_StlVersion>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR STL", &quicksort::sort<SortableRef_StlVersion>, &insertionsort::InsertionSort<SortableRef_StlVersion>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_PointerOptimized>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR POp", &quicksort::sort<SortableRef_PointerOptimized>, &insertionsort::InsertionSort<SortableRef_PointerOptimized>);
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef_ArrayIndex_FirstCheck>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR AIF", &quicksort::sort<SortableRef_ArrayIndex_FirstCheck>, &insertionsort::InsertionSort<SortableRef_ArrayIndex_FirstCheck>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_StlVersion>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR STL");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_PointerOptimized>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR POp");
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef_ArrayIndex_FirstCheck>(perf, numberOfIterations, arraySize, measureIteration, "I       -Q KR AIF");
	
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q KR Def", &measurement::StdSortWrapper, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "StdSort -Q KR Def");
	randomisation::SetSeed(seed);
	measurement::MeasureCompleteSorter<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q KR Def", &measurement::QuicksortCopyWrapper, &measurement::BaseCaseSortBlank<SortableRef>);
	randomisation::SetSeed(seed);
	measurement::MeasureRandomGeneration<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "QSort   -Q KR Def");
}
} // namespace measurement
