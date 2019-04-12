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

#include "BestNetworks.generated.h"
#include "BoseNelson.generated.h"
#include "BoseNelsonParallel.generated.h"
#include "BoseNelsonParameter.generated.h"
#include "Batcher.generated.h"
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
		bool result = verification::VerifyNetwork(arraySize, &networks::sortNbest<int>);
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
		bool result = verification::VerifyNetwork(arraySize, &networks::sortNbosenelson<int>);
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
		bool result = verification::VerifyNetwork(arraySize, &networks::sortNbosenelsonparallel<int>);
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
		bool result = verification::VerifyNetwork(arraySize, &networks::sortNbosenelsonparameter<int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'bosenelsonparameter' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("verifying batcher networks");
	for (int arraySize = 2; arraySize < 17; arraySize += 1)
	{
		debug::WriteLine("verifying size ", std::to_string(arraySize));
		bool result = verification::VerifyNetwork(arraySize, &networks::sortNbatcher<int>);
		if (!result)
		{
			debug::WriteLine("incorrect network: 'batcher' for size '", std::to_string(arraySize), "'.");
			numberOfIncorrectNetworks += 1;
		}
	}
	debug::WriteLine("finished verification. ", std::to_string(75 - numberOfIncorrectNetworks), " networks out of 75 sorted correctly.");
}
} // namespace verification

#endif // VERIFY_NETWORKS_GENERATED_H
