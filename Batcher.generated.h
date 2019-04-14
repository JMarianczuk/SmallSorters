//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef BATCHER_GENERATED_H
#define BATCHER_GENERATED_H

#include "NetworkSort.h"
namespace networks
{
template <typename TValueType> static
void sort2batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
}
template <typename TValueType> static
void sort3batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[1], A[2]);
}
template <typename TValueType> static
void sort4batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
}
template <typename TValueType> static
void sort5batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
}
template <typename TValueType> static
void sort6batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
}
template <typename TValueType> static
void sort7batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
}
template <typename TValueType> static
void sort8batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
}
template <typename TValueType> static
void sort9batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
}
template <typename TValueType> static
void sort10batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
}
template <typename TValueType> static
void sort11batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
}
template <typename TValueType> static
void sort12batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
}
template <typename TValueType> static
void sort13batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[11], A[12]);
}
template <typename TValueType> static
void sort14batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[5], A[13]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[7], A[13]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[11], A[12]);
}
template <typename TValueType> static
void sort15batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[5], A[13]);
	networks::ConditionalSwap(A[6], A[14]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[10], A[14]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[12], A[14]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[7], A[13]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[7], A[14]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[11], A[14]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[13], A[14]);
}
template <typename TValueType> static
void sort16batcher(TValueType* A)
{
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[5], A[13]);
	networks::ConditionalSwap(A[6], A[14]);
	networks::ConditionalSwap(A[7], A[15]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[10], A[14]);
	networks::ConditionalSwap(A[11], A[15]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[12], A[14]);
	networks::ConditionalSwap(A[13], A[15]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[7], A[13]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[14], A[15]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[7], A[14]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[11], A[14]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[13], A[14]);
}

template <typename TValueType> static inline
void sortNbatcher(TValueType* A, size_t n)
{
	switch(n)
	{
		case 0: break;
		case 1: break;
		case 2:
			sort2batcher(A);
			break;
		case 3:
			sort3batcher(A);
			break;
		case 4:
			sort4batcher(A);
			break;
		case 5:
			sort5batcher(A);
			break;
		case 6:
			sort6batcher(A);
			break;
		case 7:
			sort7batcher(A);
			break;
		case 8:
			sort8batcher(A);
			break;
		case 9:
			sort9batcher(A);
			break;
		case 10:
			sort10batcher(A);
			break;
		case 11:
			sort11batcher(A);
			break;
		case 12:
			sort12batcher(A);
			break;
		case 13:
			sort13batcher(A);
			break;
		case 14:
			sort14batcher(A);
			break;
		case 15:
			sort15batcher(A);
			break;
		case 16:
			sort16batcher(A);
			break;
		default:
			abort();
			break;
	}
}
} // namespace networks

#endif // BATCHER_GENERATED_H
