//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
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
#include "BestNetworks.generated.h"
#include "BoseNelson.generated.h"
#include "InsertionSort.h"

namespace measurement
{
void MeasureSorting(Performancing* perf, int numberOfIterations, size_t arraySize, int measureIteration)
{
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-Default", &networks::sortNbest<SortableRef>);
	measurement::Measure<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-JumpXchg", &networks::sortNbest<SortableRef_JumpXchg>);
	measurement::Measure<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-FourCmovTemp", &networks::sortNbest<SortableRef_FourCmovTemp>);
	measurement::Measure<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-FourCmovTemp-Split", &networks::sortNbest<SortableRef_FourCmovTemp_Split>);
	measurement::Measure<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-SixCmovRegisterTemp", &networks::sortNbest<SortableRef_SixCmovRegisterTemp>);
	measurement::Measure<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "Netw. Best KR-ClangVersion", &networks::sortNbest<SortableRef_ClangVersion>);
	
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-Default", &networks::sortNbosenelson<SortableRef>);
	measurement::Measure<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-JumpXchg", &networks::sortNbosenelson<SortableRef_JumpXchg>);
	measurement::Measure<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-FourCmovTemp", &networks::sortNbosenelson<SortableRef_FourCmovTemp>);
	measurement::Measure<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-FourCmovTemp-Split", &networks::sortNbosenelson<SortableRef_FourCmovTemp_Split>);
	measurement::Measure<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-SixCmovRegisterTemp", &networks::sortNbosenelson<SortableRef_SixCmovRegisterTemp>);
	measurement::Measure<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelson KR-ClangVersion", &networks::sortNbosenelson<SortableRef_ClangVersion>);
	
	measurement::Measure<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Ins. KR-Default", &insertionsort::InsertionSort<SortableRef>);
	measurement::Measure<SortableRef_StlVersion>(perf, numberOfIterations, arraySize, measureIteration, "Ins. KR-StlVersion", &insertionsort::InsertionSort<SortableRef_StlVersion>);
	measurement::Measure<SortableRef_PointerOptimized>(perf, numberOfIterations, arraySize, measureIteration, "Ins. KR-PointerOptimized", &insertionsort::InsertionSort<SortableRef_PointerOptimized>);
	
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-Default", &networks::sortNbest<SortableRef>);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-JumpXchg", &networks::sortNbest<SortableRef_JumpXchg>);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-FourCmovTemp", &networks::sortNbest<SortableRef_FourCmovTemp>);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-FourCmovTemp-Split", &networks::sortNbest<SortableRef_FourCmovTemp_Split>);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-SixCmovRegisterTemp", &networks::sortNbest<SortableRef_SixCmovRegisterTemp>);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BestInRow KR-ClangVersion", &networks::sortNbest<SortableRef_ClangVersion>);
	
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-Default", &networks::sortNbosenelson<SortableRef>);
	measurement::MeasureInRow<SortableRef_JumpXchg>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-JumpXchg", &networks::sortNbosenelson<SortableRef_JumpXchg>);
	measurement::MeasureInRow<SortableRef_FourCmovTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-FourCmovTemp", &networks::sortNbosenelson<SortableRef_FourCmovTemp>);
	measurement::MeasureInRow<SortableRef_FourCmovTemp_Split>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-FourCmovTemp-Split", &networks::sortNbosenelson<SortableRef_FourCmovTemp_Split>);
	measurement::MeasureInRow<SortableRef_SixCmovRegisterTemp>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-SixCmovRegisterTemp", &networks::sortNbosenelson<SortableRef_SixCmovRegisterTemp>);
	measurement::MeasureInRow<SortableRef_ClangVersion>(perf, numberOfIterations, arraySize, measureIteration, "Netw. BoseNelsonInRow KR-ClangVersion", &networks::sortNbosenelson<SortableRef_ClangVersion>);
	
	measurement::MeasureInRow<SortableRef>(perf, numberOfIterations, arraySize, measureIteration, "Ins.InRow KR-Default", &insertionsort::InsertionSort<SortableRef>);
	measurement::MeasureInRow<SortableRef_StlVersion>(perf, numberOfIterations, arraySize, measureIteration, "Ins.InRow KR-StlVersion", &insertionsort::InsertionSort<SortableRef_StlVersion>);
	measurement::MeasureInRow<SortableRef_PointerOptimized>(perf, numberOfIterations, arraySize, measureIteration, "Ins.InRow KR-PointerOptimized", &insertionsort::InsertionSort<SortableRef_PointerOptimized>);
	
}
}

#endif
