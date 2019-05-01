
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <inttypes.h>

namespace randomisation 
{

void SetSeed(uint64_t seed);
uint64_t GenerateRandomUint64();

} // namespace randomisation

#endif // RANDOMISATION_H