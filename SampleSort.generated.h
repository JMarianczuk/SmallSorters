




//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated from a T4 template
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#ifndef SAMPLESORT_GENERATED_H
#define SAMPLESORT_GENERATED_H

template <typename TValueType>
static inline
void SampleSort3Splitters2BlockSize(TValueType* A, int elementCount, TValueType* splitters)
{
	register TValueType splitter0 = splitters[0];
	register TValueType splitter1 = splitters[1];
	register TValueType splitter2 = splitters[2];

	TValueType rawbuckets[4 * elementCount];
	TValueType* buckets[4];
	for (int i = 0; i < 4; i += 1)
	{
		buckets[i] = &rawbuckets[i * elementCount];
	}
	register TValueType element0;
	register uint8_t state0;
	register TValueType splitter00x;
	register TValueType element1;
	register uint8_t state1;
	register TValueType splitter01x;

	int max = elementCount - blockSize;
	int current = 0;
	for ( ; current < max; current += blockSize)
	{
		element0 = A[current];
		state0 = 0;
		splitter00x = splitter1;
		element1 = A[current + 1];
		state1 = 0;
		splitter01x = splitter1;
		__asm__(
			"cmp %[ele],%[splitter2]\n\t"
			"cmovc %[splitter3],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [splitterx] "+r"(splitter00x), [state] "=r"(state0)
			: [ele] "r"(element0), [splitter2] "r"(splitter2), [splitter3] "r"(splitter3)
			"cc"
		);
		__asm__(
			"cmp %[ele],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [state] "=r"(state0)
			: [ele] "r"(element0), [splitterx] "r"(splitter00x)
			"cc"
		);
		__asm__(
			"cmp %[ele],%[splitter2]\n\t"
			"cmovc %[splitter3],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [splitterx] "+r"(splitter01x), [state] "=r"(state1)
			: [ele] "r"(element1), [splitter2] "r"(splitter2), [splitter3] "r"(splitter3)
			"cc"
		);
		__asm__(
			"cmp %[ele],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [state] "=r"(state1)
			: [ele] "r"(element1), [splitterx] "r"(splitter01x)
			"cc"
		);
		*buckets[state0] = element0;
		buckets[state0]++;
		*buckets[state1] = element1;
		buckets[state1]++;
	}

	for ( ; current < elementCount; current += 1)
	{
		element0 = A[current];
		state0 = 0;
		splitter00x = splitter1;
		__asm__(
			"cmp %[ele],%[splitter2]\n\t"
			"cmovc %[splitter3],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [splitterx] "+r"(splitter00x), [state] "=r"(state0)
			: [ele] "r"(element0), [splitter2] "r"(splitter2), [splitter3] "r"(splitter3)
			"cc"
		);
		__asm__(
			"cmp %[ele],%[splitterx]\n\t"
			"rcl $1,%[state]\n\t"
			: [state] "=r"(state0)
			: [ele] "r"(element0), [splitterx] "r"(splitter00x)
			"cc"
		);
		*buckets[state0] = element0;
		buckets[state0]++;
	}
}

#endif