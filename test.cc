
#include "sorters/SampleSort.generated.h"
#include "networks/BestNetworks.generated.h"
#include "StructHelpers.generated.h"
#include "Randomisation.h"
#include "Randomisation.Sortable.h"
#include "ArrayHelpers.h"

bool PredicateLess(uint64_t& key, SortableRef& value)
{
    return key < value.key;
}


void Test()
{
    int arraySize = 1024 * 16;
    SortableRef* arr = (SortableRef*) malloc(sizeof(SortableRef) * arraySize);
    randomisation::GenerateRandomArray<SortableRef, RandomisationMode::Default>(arr, arraySize);
    samplesort::SampleSort3Splitters3OversamplingFactor2BlockSize(arr, arraySize, 16, &networks::sortNbest<SortableRef>, &PredicateLess, &GetKey<SortableRef>);
    if (!IsSorted(arr, arraySize))
    {
        debug::WriteLine("Wrong sort qs copy");
    }
    else
    {
        debug::WriteLine("Correct sort qs copy");
    }
}
