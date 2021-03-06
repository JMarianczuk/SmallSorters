//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#ifndef VERIFY_NETWORKS_GENERATED_H
#define VERIFY_NETWORKS_GENERATED_H

#include <inttypes.h>
#include <ostream>

#include "Networks_Fwd.h"
#include "conditional_swap/ConditionalSwap.h"
#include "VerifyNetworks.h"
#include "DebugHelper.h"

namespace verification
{

void VerifyNetworks()
{
	int numberOfIncorrectNetworks = 0;
	debug::WriteLine("verifying best networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::best::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'best' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelson networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelson::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelson' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelson_2 networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelson_2::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelson_2' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonparallel networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonparallel::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonparallel' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonparameter networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonparameter::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonparameter' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonrecursive networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonrecursive' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying batcher networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", arraySize);
		bool result = verification::VerifyNetwork(arraySize, &networks::batcher::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'batcher' for size '", arraySize, "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("finished verification. ", 105 - numberOfIncorrectNetworks, " networks out of 105 sorted correctly.");
}
void VerifySwaps()
{
	int numberOfIncorrectSwaps = 0;
	bool result = false;
	debug::WriteLine("verifying conditional_swap::CS_IfSwap swap");
	result = verification::VerifySwap<conditional_swap::CS_IfSwap>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_IfSwap'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_JumpXchg_Ref swap");
	result = verification::VerifySwap<conditional_swap::CS_JumpXchg_Ref>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_JumpXchg_Ref'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_FourCmovTemp swap");
	result = verification::VerifySwap<conditional_swap::CS_FourCmovTemp>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_FourCmovTemp'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_FourCmovTemp_Split swap");
	result = verification::VerifySwap<conditional_swap::CS_FourCmovTemp_Split>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_FourCmovTemp_Split'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_TwoConditionalPointerMove swap");
	result = verification::VerifySwap<conditional_swap::CS_TwoConditionalPointerMove>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_TwoConditionalPointerMove'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_TwoConditionalPointerMovePredicate swap");
	result = verification::VerifySwap<conditional_swap::CS_TwoConditionalPointerMovePredicate>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_TwoConditionalPointerMovePredicate'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_Tie swap");
	result = verification::VerifySwap<conditional_swap::CS_Tie>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_Tie'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("verifying conditional_swap::CS_CmovXor swap");
	result = verification::VerifySwap<conditional_swap::CS_CmovXor>();
	if (!result)
	{
		debug::WriteLine("incorrect swap: 'conditional_swap::CS_CmovXor'.");
		numberOfIncorrectSwaps += 1;
	}
	debug::WriteLine("finished verification. ", 8 - numberOfIncorrectSwaps, " swaps out of 8 swapped correctly.");
}
} // namespace verification

#endif // VERIFY_NETWORKS_GENERATED_H
