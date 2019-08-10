
#ifndef RANDOMISATION_GENERATED_H
#define RANDOMISATION_GENERATED_H

#include <stdexcept>
#include <cstddef>
#include "Randomisation.h"
#include "Sortable.generated.h"
namespace randomisation
{
	
template<RandomisationMode rMode>
void GenerateRandomArray(Sortable* arr, size_t arraySize) {
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64<rMode>();
	}
}
template<RandomisationMode rMode>
void GenerateRandomArray(SortableRef* arr, size_t arraySize) {
	uint64_t reference = randomisation::GenerateRandomUint64<rMode>();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64<rMode>();
		arr[i].reference = reference + i;
	}
}

} // namespace randomisation

#endif // RANDOMISATION_GENERATED_H
