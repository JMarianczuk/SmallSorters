//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------


#ifndef BOSENELSON_GENERATED_H
#define BOSENELSON_GENERATED_H

namespace networks
{
namespace bosenelson
{
template <typename CSwap, typename ValueType> static
void sort2(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
}
template <typename CSwap, typename ValueType> static
void sort3(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
}
template <typename CSwap, typename ValueType> static
void sort4(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
}
template <typename CSwap, typename ValueType> static
void sort5(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
}
template <typename CSwap, typename ValueType> static
void sort6(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[3]);
}
template <typename CSwap, typename ValueType> static
void sort7(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
}
template <typename CSwap, typename ValueType> static
void sort8(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
}
template <typename CSwap, typename ValueType> static
void sort9(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[0], A[5]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[1], A[6]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[3], A[8]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
}
template <typename CSwap, typename ValueType> static
void sort10(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[0], A[5]);
	CSwap::swap(A[1], A[6]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[3], A[8]);
	CSwap::swap(A[4], A[9]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[4], A[5]);
}
template <typename CSwap, typename ValueType> static
void sort11(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[7], A[10]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[0], A[6]);
	CSwap::swap(A[0], A[5]);
	CSwap::swap(A[1], A[7]);
	CSwap::swap(A[1], A[6]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[3], A[9]);
	CSwap::swap(A[4], A[10]);
	CSwap::swap(A[4], A[9]);
	CSwap::swap(A[3], A[8]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[4], A[5]);
}
template <typename CSwap, typename ValueType> static
void sort12(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[10], A[11]);
	CSwap::swap(A[9], A[11]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[7], A[10]);
	CSwap::swap(A[8], A[11]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[0], A[6]);
	CSwap::swap(A[1], A[7]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[1], A[6]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[3], A[9]);
	CSwap::swap(A[4], A[10]);
	CSwap::swap(A[5], A[11]);
	CSwap::swap(A[5], A[10]);
	CSwap::swap(A[4], A[9]);
	CSwap::swap(A[5], A[9]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[5], A[6]);
}
template <typename CSwap, typename ValueType> static
void sort13(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[11], A[12]);
	CSwap::swap(A[9], A[11]);
	CSwap::swap(A[10], A[12]);
	CSwap::swap(A[10], A[11]);
	CSwap::swap(A[6], A[10]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[7], A[11]);
	CSwap::swap(A[8], A[12]);
	CSwap::swap(A[8], A[11]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[0], A[7]);
	CSwap::swap(A[0], A[6]);
	CSwap::swap(A[1], A[8]);
	CSwap::swap(A[2], A[9]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[1], A[6]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[3], A[10]);
	CSwap::swap(A[4], A[11]);
	CSwap::swap(A[5], A[12]);
	CSwap::swap(A[5], A[11]);
	CSwap::swap(A[4], A[10]);
	CSwap::swap(A[5], A[10]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[5], A[9]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[5], A[6]);
}
template <typename CSwap, typename ValueType> static
void sort14(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[10], A[11]);
	CSwap::swap(A[12], A[13]);
	CSwap::swap(A[10], A[12]);
	CSwap::swap(A[11], A[13]);
	CSwap::swap(A[11], A[12]);
	CSwap::swap(A[7], A[11]);
	CSwap::swap(A[7], A[10]);
	CSwap::swap(A[8], A[12]);
	CSwap::swap(A[9], A[13]);
	CSwap::swap(A[9], A[12]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[9], A[11]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[0], A[7]);
	CSwap::swap(A[1], A[8]);
	CSwap::swap(A[2], A[9]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[1], A[7]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[3], A[10]);
	CSwap::swap(A[4], A[11]);
	CSwap::swap(A[4], A[10]);
	CSwap::swap(A[5], A[12]);
	CSwap::swap(A[6], A[13]);
	CSwap::swap(A[6], A[12]);
	CSwap::swap(A[5], A[10]);
	CSwap::swap(A[6], A[11]);
	CSwap::swap(A[6], A[10]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[5], A[9]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
}
template <typename CSwap, typename ValueType> static
void sort15(ValueType* A)
{
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[0], A[3]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[2], A[5]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[7], A[8]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[11], A[12]);
	CSwap::swap(A[13], A[14]);
	CSwap::swap(A[11], A[13]);
	CSwap::swap(A[12], A[14]);
	CSwap::swap(A[12], A[13]);
	CSwap::swap(A[7], A[11]);
	CSwap::swap(A[8], A[12]);
	CSwap::swap(A[8], A[11]);
	CSwap::swap(A[9], A[13]);
	CSwap::swap(A[10], A[14]);
	CSwap::swap(A[10], A[13]);
	CSwap::swap(A[9], A[11]);
	CSwap::swap(A[10], A[12]);
	CSwap::swap(A[10], A[11]);
	CSwap::swap(A[0], A[8]);
	CSwap::swap(A[0], A[7]);
	CSwap::swap(A[1], A[9]);
	CSwap::swap(A[2], A[10]);
	CSwap::swap(A[2], A[9]);
	CSwap::swap(A[1], A[7]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[2], A[7]);
	CSwap::swap(A[3], A[11]);
	CSwap::swap(A[4], A[12]);
	CSwap::swap(A[4], A[11]);
	CSwap::swap(A[5], A[13]);
	CSwap::swap(A[6], A[14]);
	CSwap::swap(A[6], A[13]);
	CSwap::swap(A[5], A[11]);
	CSwap::swap(A[6], A[12]);
	CSwap::swap(A[6], A[11]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[4], A[7]);
	CSwap::swap(A[5], A[9]);
	CSwap::swap(A[6], A[10]);
	CSwap::swap(A[6], A[9]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[6], A[7]);
}
template <typename CSwap, typename ValueType> static
void sort16(ValueType* A)
{
	CSwap::swap(A[0], A[1]);
	CSwap::swap(A[2], A[3]);
	CSwap::swap(A[0], A[2]);
	CSwap::swap(A[1], A[3]);
	CSwap::swap(A[1], A[2]);
	CSwap::swap(A[4], A[5]);
	CSwap::swap(A[6], A[7]);
	CSwap::swap(A[4], A[6]);
	CSwap::swap(A[5], A[7]);
	CSwap::swap(A[5], A[6]);
	CSwap::swap(A[0], A[4]);
	CSwap::swap(A[1], A[5]);
	CSwap::swap(A[1], A[4]);
	CSwap::swap(A[2], A[6]);
	CSwap::swap(A[3], A[7]);
	CSwap::swap(A[3], A[6]);
	CSwap::swap(A[2], A[4]);
	CSwap::swap(A[3], A[5]);
	CSwap::swap(A[3], A[4]);
	CSwap::swap(A[8], A[9]);
	CSwap::swap(A[10], A[11]);
	CSwap::swap(A[8], A[10]);
	CSwap::swap(A[9], A[11]);
	CSwap::swap(A[9], A[10]);
	CSwap::swap(A[12], A[13]);
	CSwap::swap(A[14], A[15]);
	CSwap::swap(A[12], A[14]);
	CSwap::swap(A[13], A[15]);
	CSwap::swap(A[13], A[14]);
	CSwap::swap(A[8], A[12]);
	CSwap::swap(A[9], A[13]);
	CSwap::swap(A[9], A[12]);
	CSwap::swap(A[10], A[14]);
	CSwap::swap(A[11], A[15]);
	CSwap::swap(A[11], A[14]);
	CSwap::swap(A[10], A[12]);
	CSwap::swap(A[11], A[13]);
	CSwap::swap(A[11], A[12]);
	CSwap::swap(A[0], A[8]);
	CSwap::swap(A[1], A[9]);
	CSwap::swap(A[1], A[8]);
	CSwap::swap(A[2], A[10]);
	CSwap::swap(A[3], A[11]);
	CSwap::swap(A[3], A[10]);
	CSwap::swap(A[2], A[8]);
	CSwap::swap(A[3], A[9]);
	CSwap::swap(A[3], A[8]);
	CSwap::swap(A[4], A[12]);
	CSwap::swap(A[5], A[13]);
	CSwap::swap(A[5], A[12]);
	CSwap::swap(A[6], A[14]);
	CSwap::swap(A[7], A[15]);
	CSwap::swap(A[7], A[14]);
	CSwap::swap(A[6], A[12]);
	CSwap::swap(A[7], A[13]);
	CSwap::swap(A[7], A[12]);
	CSwap::swap(A[4], A[8]);
	CSwap::swap(A[5], A[9]);
	CSwap::swap(A[5], A[8]);
	CSwap::swap(A[6], A[10]);
	CSwap::swap(A[7], A[11]);
	CSwap::swap(A[7], A[10]);
	CSwap::swap(A[6], A[8]);
	CSwap::swap(A[7], A[9]);
	CSwap::swap(A[7], A[8]);
}

template <typename CSwap, typename ValueType> static
void sortN(ValueType* A, size_t n)
{
	switch(n)
	{
		case 0: break;
		case 1: break;
		case 2:
			sort2<CSwap>(A);
			break;
		case 3:
			sort3<CSwap>(A);
			break;
		case 4:
			sort4<CSwap>(A);
			break;
		case 5:
			sort5<CSwap>(A);
			break;
		case 6:
			sort6<CSwap>(A);
			break;
		case 7:
			sort7<CSwap>(A);
			break;
		case 8:
			sort8<CSwap>(A);
			break;
		case 9:
			sort9<CSwap>(A);
			break;
		case 10:
			sort10<CSwap>(A);
			break;
		case 11:
			sort11<CSwap>(A);
			break;
		case 12:
			sort12<CSwap>(A);
			break;
		case 13:
			sort13<CSwap>(A);
			break;
		case 14:
			sort14<CSwap>(A);
			break;
		case 15:
			sort15<CSwap>(A);
			break;
		case 16:
			sort16<CSwap>(A);
			break;
		default:
			abort();
			break;
	}
}
} // namespace bosenelson
} // namespace networks

#endif // BOSENELSON_GENERATED_H
