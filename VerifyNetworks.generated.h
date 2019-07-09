//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#ifndef VERIFY_NETWORKS_GENERATED_H
#define VERIFY_NETWORKS_GENERATED_H

#include <inttypes.h>
#include <ostream>

#include "networks/BestNetworks.generated.h"
#include "networks/BoseNelson.generated.h"
#include "networks/BoseNelsonParallel.generated.h"
#include "networks/BoseNelsonParameter.generated.h"
#include "networks/BoseNelsonRecursive.generated.h"
#include "networks/Batcher.generated.h"
#include "conditional_swap/ConditionalSwapX86.h"
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
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::best::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'best' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelson networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelson::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelson' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonparallel networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonparallel::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonparallel' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonparameter networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonparameter::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonparameter' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying bosenelsonrecursive networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::bosenelsonrecursive::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonrecursive' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying batcher networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::batcher::sortN<conditional_swap::CS_Int, int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'batcher' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("finished verification. ", std::to_string(90 - numberOfIncorrectNetworks), " networks out of 90 sorted correctly.");
}
} // namespace verification

#endif // VERIFY_NETWORKS_GENERATED_H
