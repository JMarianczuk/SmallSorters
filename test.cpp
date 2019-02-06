
#include <iostream>

#include "Sortable.generated.h"
#include "BestNetworks.generated.h"
#include "NetworkSort.h"



void Test(SortableRef_ClangVersion& left, SortableRef_ClangVersion& right)
{
    networks::ConditionalSwap(left, right);
    printf("Correctly Sorted: %s", left > right ? "false" : "true");
}