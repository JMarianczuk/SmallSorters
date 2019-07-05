//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef BOSENELSON_RECURSIVE_GENERATED_H
#define BOSENELSON_RECURSIVE_GENERATED_H

#include "NetworkSort.h"
namespace networks
{
template <typename TValueType> static
inline
void merge1_1bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::ConditionalSwap(left[0], right[0]);
}
template <typename TValueType> static
inline
void sort2bosenelsonrecursive(TValueType* A)
{
	networks::merge1_1bosenelsonrecursive(A, A + 1);
}

template <typename TValueType> static
inline
void merge1_2bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::ConditionalSwap(left[0], right[1]);
	networks::ConditionalSwap(left[0], right[0]);
}
template <typename TValueType> static
void sort3bosenelsonrecursive(TValueType* A)
{
	networks::sort2bosenelsonrecursive(A + 1);
	networks::merge1_2bosenelsonrecursive(A, A + 1);
}

template <typename TValueType> static
void merge2_2bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge1_1bosenelsonrecursive(left, right);
	networks::merge1_1bosenelsonrecursive(left + 1, right + 1);
	networks::merge1_1bosenelsonrecursive(left + 1, right);
}

template <typename TValueType> static
void sort4bosenelsonrecursive(TValueType* A)
{
	networks::sort2bosenelsonrecursive(A);
	networks::sort2bosenelsonrecursive(A + 2);
	networks::merge2_2bosenelsonrecursive(A, A + 2);
}

template <typename TValueType> static
void merge2_3bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge1_2bosenelsonrecursive(left, right);
	networks::merge1_1bosenelsonrecursive(left + 1, right + 2);
	networks::merge1_2bosenelsonrecursive(left + 1, right);
}

template <typename TValueType> static
void sort5bosenelsonrecursive(TValueType* A)
{
	networks::sort2bosenelsonrecursive(A);
	networks::sort3bosenelsonrecursive(A + 2);
	networks::merge2_3bosenelsonrecursive(A, A + 2);
}

template <typename TValueType> static
inline
void merge2_1bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::ConditionalSwap(left[0], right[0]);
	networks::ConditionalSwap(left[1], right[0]);
}
template <typename TValueType> static
void merge3_3bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge1_1bosenelsonrecursive(left, right);
	networks::merge2_2bosenelsonrecursive(left + 1, right + 1);
	networks::merge2_1bosenelsonrecursive(left + 1, right);
}

template <typename TValueType> static
void sort6bosenelsonrecursive(TValueType* A)
{
	networks::sort3bosenelsonrecursive(A);
	networks::sort3bosenelsonrecursive(A + 3);
	networks::merge3_3bosenelsonrecursive(A, A + 3);
}

template <typename TValueType> static
void merge3_4bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge1_2bosenelsonrecursive(left, right);
	networks::merge2_2bosenelsonrecursive(left + 1, right + 2);
	networks::merge2_2bosenelsonrecursive(left + 1, right);
}

template <typename TValueType> static
void sort7bosenelsonrecursive(TValueType* A)
{
	networks::sort3bosenelsonrecursive(A);
	networks::sort4bosenelsonrecursive(A + 3);
	networks::merge3_4bosenelsonrecursive(A, A + 3);
}

template <typename TValueType> static
void merge4_4bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge2_2bosenelsonrecursive(left, right);
	networks::merge2_2bosenelsonrecursive(left + 2, right + 2);
	networks::merge2_2bosenelsonrecursive(left + 2, right);
}

template <typename TValueType> static
void sort8bosenelsonrecursive(TValueType* A)
{
	networks::sort4bosenelsonrecursive(A);
	networks::sort4bosenelsonrecursive(A + 4);
	networks::merge4_4bosenelsonrecursive(A, A + 4);
}

template <typename TValueType> static
void merge4_5bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge2_3bosenelsonrecursive(left, right);
	networks::merge2_2bosenelsonrecursive(left + 2, right + 3);
	networks::merge2_3bosenelsonrecursive(left + 2, right);
}

template <typename TValueType> static
void sort9bosenelsonrecursive(TValueType* A)
{
	networks::sort4bosenelsonrecursive(A);
	networks::sort5bosenelsonrecursive(A + 4);
	networks::merge4_5bosenelsonrecursive(A, A + 4);
}

template <typename TValueType> static
void merge3_2bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge1_1bosenelsonrecursive(left, right);
	networks::merge2_1bosenelsonrecursive(left + 1, right + 1);
	networks::merge2_1bosenelsonrecursive(left + 1, right);
}

template <typename TValueType> static
void merge5_5bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge2_2bosenelsonrecursive(left, right);
	networks::merge3_3bosenelsonrecursive(left + 2, right + 2);
	networks::merge3_2bosenelsonrecursive(left + 2, right);
}

template <typename TValueType> static
void sort10bosenelsonrecursive(TValueType* A)
{
	networks::sort5bosenelsonrecursive(A);
	networks::sort5bosenelsonrecursive(A + 5);
	networks::merge5_5bosenelsonrecursive(A, A + 5);
}

template <typename TValueType> static
void merge5_6bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge2_3bosenelsonrecursive(left, right);
	networks::merge3_3bosenelsonrecursive(left + 2, right + 3);
	networks::merge3_3bosenelsonrecursive(left + 2, right);
}

template <typename TValueType> static
void sort11bosenelsonrecursive(TValueType* A)
{
	networks::sort5bosenelsonrecursive(A);
	networks::sort6bosenelsonrecursive(A + 5);
	networks::merge5_6bosenelsonrecursive(A, A + 5);
}

template <typename TValueType> static
void merge6_6bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge3_3bosenelsonrecursive(left, right);
	networks::merge3_3bosenelsonrecursive(left + 3, right + 3);
	networks::merge3_3bosenelsonrecursive(left + 3, right);
}

template <typename TValueType> static
void sort12bosenelsonrecursive(TValueType* A)
{
	networks::sort6bosenelsonrecursive(A);
	networks::sort6bosenelsonrecursive(A + 6);
	networks::merge6_6bosenelsonrecursive(A, A + 6);
}

template <typename TValueType> static
void merge6_7bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge3_4bosenelsonrecursive(left, right);
	networks::merge3_3bosenelsonrecursive(left + 3, right + 4);
	networks::merge3_4bosenelsonrecursive(left + 3, right);
}

template <typename TValueType> static
void sort13bosenelsonrecursive(TValueType* A)
{
	networks::sort6bosenelsonrecursive(A);
	networks::sort7bosenelsonrecursive(A + 6);
	networks::merge6_7bosenelsonrecursive(A, A + 6);
}

template <typename TValueType> static
void merge4_3bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge2_2bosenelsonrecursive(left, right);
	networks::merge2_1bosenelsonrecursive(left + 2, right + 2);
	networks::merge2_2bosenelsonrecursive(left + 2, right);
}

template <typename TValueType> static
void merge7_7bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge3_3bosenelsonrecursive(left, right);
	networks::merge4_4bosenelsonrecursive(left + 3, right + 3);
	networks::merge4_3bosenelsonrecursive(left + 3, right);
}

template <typename TValueType> static
void sort14bosenelsonrecursive(TValueType* A)
{
	networks::sort7bosenelsonrecursive(A);
	networks::sort7bosenelsonrecursive(A + 7);
	networks::merge7_7bosenelsonrecursive(A, A + 7);
}

template <typename TValueType> static
void merge7_8bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge3_4bosenelsonrecursive(left, right);
	networks::merge4_4bosenelsonrecursive(left + 3, right + 4);
	networks::merge4_4bosenelsonrecursive(left + 3, right);
}

template <typename TValueType> static
void sort15bosenelsonrecursive(TValueType* A)
{
	networks::sort7bosenelsonrecursive(A);
	networks::sort8bosenelsonrecursive(A + 7);
	networks::merge7_8bosenelsonrecursive(A, A + 7);
}

template <typename TValueType> static
void merge8_8bosenelsonrecursive(TValueType* left, TValueType* right)
{
	networks::merge4_4bosenelsonrecursive(left, right);
	networks::merge4_4bosenelsonrecursive(left + 4, right + 4);
	networks::merge4_4bosenelsonrecursive(left + 4, right);
}

template <typename TValueType> static
void sort16bosenelsonrecursive(TValueType* A)
{
	networks::sort8bosenelsonrecursive(A);
	networks::sort8bosenelsonrecursive(A + 8);
	networks::merge8_8bosenelsonrecursive(A, A + 8);
}


template <typename TValueType> static
void sortNbosenelsonrecursive(TValueType* A, size_t n)
{
	switch(n)
	{
		case 0: break;
		case 1: break;
		case 2:
			sort2bosenelsonrecursive(A);
			break;
		case 3:
			sort3bosenelsonrecursive(A);
			break;
		case 4:
			sort4bosenelsonrecursive(A);
			break;
		case 5:
			sort5bosenelsonrecursive(A);
			break;
		case 6:
			sort6bosenelsonrecursive(A);
			break;
		case 7:
			sort7bosenelsonrecursive(A);
			break;
		case 8:
			sort8bosenelsonrecursive(A);
			break;
		case 9:
			sort9bosenelsonrecursive(A);
			break;
		case 10:
			sort10bosenelsonrecursive(A);
			break;
		case 11:
			sort11bosenelsonrecursive(A);
			break;
		case 12:
			sort12bosenelsonrecursive(A);
			break;
		case 13:
			sort13bosenelsonrecursive(A);
			break;
		case 14:
			sort14bosenelsonrecursive(A);
			break;
		case 15:
			sort15bosenelsonrecursive(A);
			break;
		case 16:
			sort16bosenelsonrecursive(A);
			break;
	}
}
} // namespace networks

#endif // BOSENELSON_RECURSIVE_GENERATED_H