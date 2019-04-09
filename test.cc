
#include <iostream>

#include "Sortable.generated.h"
#include "BestNetworks.generated.h"
#include "BoseNelson.generated.h"
#include "BoseNelsonParallel.generated.h"
#include "BoseNelsonParameter.generated.h"
#include "NetworkSort.h"
#include "Randomisation.generated.h"
#include "Quicksort_Copy.h"
#include "Measure.h"
#include "DebugHelper.h"



void Test()
{
    int arraySize = 1024 * 16;
    SortableRef* arr = (SortableRef*) malloc(sizeof(SortableRef) * arraySize);
    randomisation::GenerateRandomArray(arr, arraySize);
    quicksortcopy::Quicksort_Copy_Stl(arr, arr + arraySize, &measurement::IteratorCompare<SortableRef>);
    if (!IsSorted(arr, arraySize))
    {
        debug::WriteLine("Wrong sort qs copy");
    }
    else
    {
        debug::WriteLine("Correct sort qs copy");
    }
    randomisation::GenerateRandomArray(arr, arraySize);
    std::sort(arr, arr + arraySize, &measurement::NormalCompare<SortableRef>);
    if (!IsSorted(arr, arraySize))
    {
        debug::WriteLine("Wrong sort std sort");
    }
    else
    {
        debug::WriteLine("Correct sort std sort");
    }
}
