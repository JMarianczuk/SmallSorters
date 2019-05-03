//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#include "Randomisation.generated.h"
namespace randomisation
{
template<>
void GenerateRandomArray<SortableRef>(SortableRef* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<Sortable_JumpXchg>(Sortable_JumpXchg* arr, size_t arraySize)
{
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
	}
}
template<>
void GenerateRandomArray<SortableRef_JumpXchg>(SortableRef_JumpXchg* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<Sortable_TwoCmovTemp>(Sortable_TwoCmovTemp* arr, size_t arraySize)
{
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
	}
}
template<>
void GenerateRandomArray<SortableRef_FourCmovTemp>(SortableRef_FourCmovTemp* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_FourCmovTemp_Split>(SortableRef_FourCmovTemp_Split* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<Sortable_ThreeCmovRegisterTemp>(Sortable_ThreeCmovRegisterTemp* arr, size_t arraySize)
{
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
	}
}
template<>
void GenerateRandomArray<SortableRef_SixCmovRegisterTemp>(SortableRef_SixCmovRegisterTemp* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_ClangVersion>(SortableRef_ClangVersion* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_ClangPredicate>(SortableRef_ClangPredicate* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_Tie>(SortableRef_Tie* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_QMark>(SortableRef_QMark* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_StlVersion>(SortableRef_StlVersion* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_PointerOptimized>(SortableRef_PointerOptimized* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_ArrayIndex_FirstCheck>(SortableRef_ArrayIndex_FirstCheck* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
template<>
void GenerateRandomArray<SortableRef_IpsoDef>(SortableRef_IpsoDef* arr, size_t arraySize)
{
	uint64_t reference = randomisation::GenerateRandomUint64();
	for (int i = 0; i < arraySize; i += 1)
	{
		arr[i].key = randomisation::GenerateRandomUint64();
		arr[i].reference = reference + i;
	}
}
} // namespace randomisation
