//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef BOSENELSON_GENERATED_H
#define BOSENELSON_GENERATED_H

#include "../conditional_swap/NetworkSort.h"
namespace networks
{
namespace bosenelson
{
template <typename ValueType> static
void sort2(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
}
template <typename ValueType> static
void sort3(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
}
template <typename ValueType> static
void sort4(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
}
template <typename ValueType> static
void sort5(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
}
template <typename ValueType> static
void sort6(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[3]);
}
template <typename ValueType> static
void sort7(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
}
template <typename ValueType> static
void sort8(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
}
template <typename ValueType> static
void sort9(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[0], A[5]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[6]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[3], A[8]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
}
template <typename ValueType> static
void sort10(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[0], A[5]);
	networks::ConditionalSwap(A[1], A[6]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[3], A[8]);
	networks::ConditionalSwap(A[4], A[9]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[4], A[5]);
}
template <typename ValueType> static
void sort11(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[0], A[6]);
	networks::ConditionalSwap(A[0], A[5]);
	networks::ConditionalSwap(A[1], A[7]);
	networks::ConditionalSwap(A[1], A[6]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[4], A[10]);
	networks::ConditionalSwap(A[4], A[9]);
	networks::ConditionalSwap(A[3], A[8]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[4], A[5]);
}
template <typename ValueType> static
void sort12(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[8], A[11]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[0], A[6]);
	networks::ConditionalSwap(A[1], A[7]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[1], A[6]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[4], A[10]);
	networks::ConditionalSwap(A[5], A[11]);
	networks::ConditionalSwap(A[5], A[10]);
	networks::ConditionalSwap(A[4], A[9]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[6]);
}
template <typename ValueType> static
void sort13(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[8], A[11]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[0], A[7]);
	networks::ConditionalSwap(A[0], A[6]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[2], A[9]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[1], A[6]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[4], A[11]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[5], A[11]);
	networks::ConditionalSwap(A[4], A[10]);
	networks::ConditionalSwap(A[5], A[10]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[5], A[6]);
}
template <typename ValueType> static
void sort14(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[0], A[7]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[2], A[9]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[1], A[7]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[4], A[11]);
	networks::ConditionalSwap(A[4], A[10]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[6], A[13]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[5], A[10]);
	networks::ConditionalSwap(A[6], A[11]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
}
template <typename ValueType> static
void sort15(ValueType* A)
{
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[0], A[3]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[2], A[5]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[7], A[8]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[13], A[14]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[12], A[14]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[8], A[11]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[10], A[14]);
	networks::ConditionalSwap(A[10], A[13]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[0], A[7]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[2], A[9]);
	networks::ConditionalSwap(A[1], A[7]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[2], A[7]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[4], A[11]);
	networks::ConditionalSwap(A[5], A[13]);
	networks::ConditionalSwap(A[6], A[14]);
	networks::ConditionalSwap(A[6], A[13]);
	networks::ConditionalSwap(A[5], A[11]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[6], A[11]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[4], A[7]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[6], A[9]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[6], A[7]);
}
template <typename ValueType> static
void sort16(ValueType* A)
{
	networks::ConditionalSwap(A[0], A[1]);
	networks::ConditionalSwap(A[2], A[3]);
	networks::ConditionalSwap(A[0], A[2]);
	networks::ConditionalSwap(A[1], A[3]);
	networks::ConditionalSwap(A[1], A[2]);
	networks::ConditionalSwap(A[4], A[5]);
	networks::ConditionalSwap(A[6], A[7]);
	networks::ConditionalSwap(A[4], A[6]);
	networks::ConditionalSwap(A[5], A[7]);
	networks::ConditionalSwap(A[5], A[6]);
	networks::ConditionalSwap(A[0], A[4]);
	networks::ConditionalSwap(A[1], A[5]);
	networks::ConditionalSwap(A[1], A[4]);
	networks::ConditionalSwap(A[2], A[6]);
	networks::ConditionalSwap(A[3], A[7]);
	networks::ConditionalSwap(A[3], A[6]);
	networks::ConditionalSwap(A[2], A[4]);
	networks::ConditionalSwap(A[3], A[5]);
	networks::ConditionalSwap(A[3], A[4]);
	networks::ConditionalSwap(A[8], A[9]);
	networks::ConditionalSwap(A[10], A[11]);
	networks::ConditionalSwap(A[8], A[10]);
	networks::ConditionalSwap(A[9], A[11]);
	networks::ConditionalSwap(A[9], A[10]);
	networks::ConditionalSwap(A[12], A[13]);
	networks::ConditionalSwap(A[14], A[15]);
	networks::ConditionalSwap(A[12], A[14]);
	networks::ConditionalSwap(A[13], A[15]);
	networks::ConditionalSwap(A[13], A[14]);
	networks::ConditionalSwap(A[8], A[12]);
	networks::ConditionalSwap(A[9], A[13]);
	networks::ConditionalSwap(A[9], A[12]);
	networks::ConditionalSwap(A[10], A[14]);
	networks::ConditionalSwap(A[11], A[15]);
	networks::ConditionalSwap(A[11], A[14]);
	networks::ConditionalSwap(A[10], A[12]);
	networks::ConditionalSwap(A[11], A[13]);
	networks::ConditionalSwap(A[11], A[12]);
	networks::ConditionalSwap(A[0], A[8]);
	networks::ConditionalSwap(A[1], A[9]);
	networks::ConditionalSwap(A[1], A[8]);
	networks::ConditionalSwap(A[2], A[10]);
	networks::ConditionalSwap(A[3], A[11]);
	networks::ConditionalSwap(A[3], A[10]);
	networks::ConditionalSwap(A[2], A[8]);
	networks::ConditionalSwap(A[3], A[9]);
	networks::ConditionalSwap(A[3], A[8]);
	networks::ConditionalSwap(A[4], A[12]);
	networks::ConditionalSwap(A[5], A[13]);
	networks::ConditionalSwap(A[5], A[12]);
	networks::ConditionalSwap(A[6], A[14]);
	networks::ConditionalSwap(A[7], A[15]);
	networks::ConditionalSwap(A[7], A[14]);
	networks::ConditionalSwap(A[6], A[12]);
	networks::ConditionalSwap(A[7], A[13]);
	networks::ConditionalSwap(A[7], A[12]);
	networks::ConditionalSwap(A[4], A[8]);
	networks::ConditionalSwap(A[5], A[9]);
	networks::ConditionalSwap(A[5], A[8]);
	networks::ConditionalSwap(A[6], A[10]);
	networks::ConditionalSwap(A[7], A[11]);
	networks::ConditionalSwap(A[7], A[10]);
	networks::ConditionalSwap(A[6], A[8]);
	networks::ConditionalSwap(A[7], A[9]);
	networks::ConditionalSwap(A[7], A[8]);
}

template <typename ValueType> static
void sortN(ValueType* A, size_t n)
{
	switch(n)
	{
		case 0: break;
		case 1: break;
		case 2:
			sort2(A);
			break;
		case 3:
			sort3(A);
			break;
		case 4:
			sort4(A);
			break;
		case 5:
			sort5(A);
			break;
		case 6:
			sort6(A);
			break;
		case 7:
			sort7(A);
			break;
		case 8:
			sort8(A);
			break;
		case 9:
			sort9(A);
			break;
		case 10:
			sort10(A);
			break;
		case 11:
			sort11(A);
			break;
		case 12:
			sort12(A);
			break;
		case 13:
			sort13(A);
			break;
		case 14:
			sort14(A);
			break;
		case 15:
			sort15(A);
			break;
		case 16:
			sort16(A);
			break;
		default:
			abort();
			break;
	}
}
} // namespace bosenelson
} // namespace networks

#endif // BOSENELSON_GENERATED_H
